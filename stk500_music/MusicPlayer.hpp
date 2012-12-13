#ifndef MUSIC_PLAYER_HPP
#define MUSIC_PLAYER_HPP

#include "Note.hpp"
#include "Song.hpp"

#include <util/delay.h>

#include <stdlib.h>
#include <stdint.h>

class MusicPlayer
{
public:
   explicit MusicPlayer()
      : mSongs()
      , mCurrentSong(NULL) // Pause at startup.
      , mCurrentNoteIndex(0)
   { }
   
   ~MusicPlayer()
   { }

   // Add song to the playlist and bind it to button 1-7.
   void SetSong(const uint8_t nr, const Song* const song)
   {
      mSongs[nr - 1] = song;
   }
   
   void SwitchTo(const uint8_t nr)
   {
      mCurrentSong = mSongs[nr - 1];
      mCurrentNoteIndex = 0;
   }
   
   void PlayMusic(volatile uint16_t& hertz_ps,
                  volatile uint16_t& note_ps,
                  volatile uint8_t& port)
   {
      if (!mCurrentSong) {
         return; // No valid song selected.
      }
      
      const Note& cur_note = mCurrentSong->mNotes[mCurrentNoteIndex];
      HandleHertzToggle(cur_note.GetHertz(), hertz_ps, port);
      HandleNoteSwitch(cur_note.GetLength(), note_ps);
   }

private:
   void HandleHertzToggle(const uint16_t& note_hz,
                          volatile uint16_t& hertz_ps,
                          volatile uint8_t& port)
   {
      if (hertz_ps < note_hz) {
         return; // No need to toggle the output pin, yet.
      }
      
      port = !port;
      hertz_ps = 0;
   }
   
   void HandleNoteSwitch(const uint16_t& note_len,
                         volatile uint16_t& note_ps)
   {
      if (note_ps < note_len) {
         return; // No need to switch to the next note, yet.
      }

      mCurrentNoteIndex++;
      if (mCurrentNoteIndex == mCurrentSong->mNotesCnt) {
         mCurrentNoteIndex = 0;
      }

      _delay_ms(10); // Delay in your face!
      note_ps = 0;
   }

   const Song* mSongs[7]; // MusicPlayer supports up to 7 songs.
   const Song* mCurrentSong;
   uint8_t mCurrentNoteIndex;
};

#endif // MUSIC_PLAYER_HPP
