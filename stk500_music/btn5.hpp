#ifndef BTN5_HPP
#define BTN5_HPP

#include "Note.hpp"
#include "Song.hpp"

// The Imperial March
static Note btn5_notes[] =
{
   Note( nt_G_1, nl_Quarter ),
   Note( nt_G_1, nl_Quarter ),
   Note( nt_G_1, nl_Quarter ),
   Note( nt_E_1, nl_EighthDot ),
   Note( nt_AIS_1, nl_Sixteenth ),
   Note( nt_G_1, nl_Quarter ),
   Note( nt_E_1, nl_EighthDot ),
   Note( nt_AIS_1, nl_Sixteenth ),
   Note( nt_G_1, nl_Half ),
   Note( nt_D_2, nl_Quarter ),
   Note( nt_D_2, nl_Quarter ),
   Note( nt_D_2, nl_Quarter ),
   Note( nt_DIS_2, nl_EighthDot ),
   Note( nt_AIS_1, nl_Sixteenth ),
   
   Note( nt_FIS_1, nl_Quarter ),
   Note( nt_E_1, nl_EighthDot ),
   Note( nt_AIS_1, nl_Sixteenth ),
   Note( nt_G_1, nl_Half ),
   Note( nt_G_2, nl_Quarter ),
   Note( nt_G_1, nl_EighthDot ),
   Note( nt_G_1, nl_Sixteenth ),
   Note( nt_G_2, nl_Quarter ),
   Note( nt_FIS_2, nl_EighthDot ),
   Note( nt_F_2, nl_Sixteenth ),
   Note( nt_E_2, nl_Sixteenth ),
   Note( nt_DIS_2, nl_Sixteenth ),
   Note( nt_E_2, nl_Eighth ),
   Note( nt_GIS_1, nl_Eighth ),
   Note( nt_CIS_2, nl_Quarter ),
   Note( nt_C_2, nl_Eighth ),
   Note( nt_H_1, nl_Sixteenth )
};

static const Song btn5_song(btn5_notes, sizeof(btn5_notes) / sizeof(btn5_notes[0]));

#endif // BTN6_HPP
