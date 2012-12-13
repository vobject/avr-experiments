#ifndef SONG_HPP
#define SONG_HPP

#include <stdint.h>

class Note;

class Song
{
   friend class MusicPlayer;

public:
   explicit Song(const Note* const notes, const uint8_t notes_cnt)
      : mNotes(notes)
      , mNotesCnt(notes_cnt)
   { }

   ~Song()
   { }

private:
   const Note* const mNotes;
   const uint8_t mNotesCnt;
};

#endif // SONG_HPP
