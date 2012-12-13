#ifndef BTN7_HPP
#define BTN7_HPP

#include "Note.hpp"
#include "Song.hpp"

// Oh du froehliche
static Note btn7_notes[] =
{
   Note( nt_G_1, nl_Half       ),
   Note( nt_A_1, nl_Half       ),
   Note( nt_G_1, nl_QuarterDot ),
   Note( nt_F_1, nl_Eighth     ),
   Note( nt_E_1, nl_Quarter    ),
   Note( nt_F_1, nl_Quarter    ),
   Note( nt_G_1, nl_Half       ),
   Note( nt_A_1, nl_Half       ),
   Note( nt_G_1, nl_QuarterDot ),
   Note( nt_F_1, nl_Eighth     ),
   Note( nt_E_1, nl_Quarter    ),
   Note( nt_F_1, nl_Quarter    ),

   Note( nt_G_1, nl_Half       ),
   Note( nt_G_1, nl_Half       ),
   Note( nt_A_1, nl_Half       ),
   Note( nt_H_1, nl_Quarter    ),
   Note( nt_C_2, nl_Quarter    ),
   Note( nt_H_1, nl_Half       ),
   Note( nt_A_1, nl_Half       ),
   Note( nt_G_1, nl_Full       ),

   Note( nt_D_1, nl_QuarterDot ),
   Note( nt_E_1, nl_Eighth     ),
   Note( nt_D_1, nl_Quarter    ),
   Note( nt_E_1, nl_Quarter    ),
   Note( nt_F_1, nl_QuarterDot ),
   Note( nt_G_1, nl_Eighth     ),
   Note( nt_F_1, nl_Half       ),
   Note( nt_E_1, nl_QuarterDot ),
   Note( nt_F_1, nl_Eighth     ),
   Note( nt_E_1, nl_Quarter    ),
   Note( nt_F_1, nl_Quarter    ),
   Note( nt_G_1, nl_QuarterDot ),
   Note( nt_A_1, nl_Eighth     ),
   Note( nt_G_1, nl_Half       ),

   Note( nt_C_2, nl_Quarter    ),
   Note( nt_H_1, nl_Quarter    ),
   Note( nt_A_1, nl_Quarter    ),
   Note( nt_G_1, nl_Quarter    ),
   Note( nt_C_2, nl_Quarter    ),
   Note( nt_A_1, nl_Quarter    ),
   Note( nt_G_1, nl_Quarter    ),
   Note( nt_F_1, nl_Quarter    ),
   Note( nt_E_1, nl_Half       ),
   Note( nt_D_1, nl_Half       ),
   Note( nt_C_1, nl_Full       )
};

static const Song btn7_song(btn7_notes, sizeof(btn7_notes) / sizeof(btn7_notes[0]));

#endif // BTN7_HPP