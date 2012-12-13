#ifndef NOTE_HPP
#define NOTE_HPP

#include <stdint.h>

#define ONE_SECOND                     (F_CPU / 256)
#define INTERRUPTS_FROM_HERTZ(hz)      (ONE_SECOND / hz / 2)

#define HERTZ_C1     (261)
#define HERTZ_CIS1   (277)
#define HERTZ_D1     (293)
#define HERTZ_DIS1   (311)
#define HERTZ_E1     (329)
#define HERTZ_F1     (349)
#define HERTZ_FIS1   (370)
#define HERTZ_G1     (392)
#define HERTZ_GIS1   (415)
#define HERTZ_A1     (440)
#define HERTZ_AIS1   (466)
#define HERTZ_H1     (494)

#define HERTZ_C2     (HERTZ_C1   * 2)
#define HERTZ_CIS2   (HERTZ_CIS1 * 2)
#define HERTZ_D2     (HERTZ_D1   * 2)
#define HERTZ_DIS2   (HERTZ_DIS1 * 2)
#define HERTZ_E2     (HERTZ_E1   * 2)
#define HERTZ_F2     (HERTZ_F1   * 2)
#define HERTZ_FIS2   (HERTZ_FIS1 * 2)
#define HERTZ_G2     (HERTZ_G1   * 2)
#define HERTZ_GIS2   (HERTZ_GIS1 * 2)
#define HERTZ_A2     (HERTZ_A1   * 2)
#define HERTZ_AIS2   (HERTZ_AIS1 * 2)
#define HERTZ_H2     (HERTZ_H1   * 2)

#define HERTZ_C3     (HERTZ_C2   * 2)
#define HERTZ_CIS3   (HERTZ_CIS2 * 2)
#define HERTZ_D3     (HERTZ_D2   * 2)
#define HERTZ_DIS3   (HERTZ_DIS2 * 2)
#define HERTZ_E3     (HERTZ_E2   * 2)
#define HERTZ_F3     (HERTZ_F2   * 2)
#define HERTZ_FIS3   (HERTZ_FIS2 * 2)
#define HERTZ_G3     (HERTZ_G2   * 2)
#define HERTZ_GIS3   (HERTZ_GIS2 * 2)
#define HERTZ_A3     (HERTZ_A2   * 2)
#define HERTZ_AIS3   (HERTZ_AIS2 * 2)
#define HERTZ_H3     (HERTZ_H2   * 2)

// All possible tone types.
enum NoteTone
{
   nt_C_1,
   nt_CIS_1,
   nt_D_1,
   nt_DIS_1,
   nt_E_1,
   nt_F_1,
   nt_FIS_1,
   nt_G_1,
   nt_GIS_1,
   nt_A_1,
   nt_AIS_1,
   nt_H_1,

   nt_C_2,
   nt_CIS_2,
   nt_D_2,
   nt_DIS_2,
   nt_E_2,
   nt_F_2,
   nt_FIS_2,
   nt_G_2,
   nt_GIS_2,
   nt_A_2,
   nt_AIS_2,
   nt_H_2,

   nt_C_3,
   nt_CIS_3,
   nt_D_3,
   nt_DIS_3,
   nt_E_3,
   nt_F_3,
   nt_FIS_3,
   nt_G_3,
   nt_GIS_3,
   nt_A_3,
   nt_AIS_3,
   nt_H_3
};

// All possible note lengths.
enum NoteLength
{
   nl_FullDot,
   nl_Full,
   nl_HalfDot,
   nl_Half,
   nl_QuarterDot,
   nl_Quarter,
   nl_EighthDot,
   nl_Eighth,
   nl_SixteenthDot,
   nl_Sixteenth
};

class Note
{
public:
   explicit Note(const NoteTone tone, const NoteLength len)
      : mTone(tone)
      , mLength(len)
   { }

   ~Note()
   { }

   uint16_t GetHertz() const
   {
      switch (mTone)
      {
         case nt_C_1:   return INTERRUPTS_FROM_HERTZ(HERTZ_C1);
         case nt_CIS_1: return INTERRUPTS_FROM_HERTZ(HERTZ_CIS1);
         case nt_D_1:   return INTERRUPTS_FROM_HERTZ(HERTZ_D1);
         case nt_DIS_1: return INTERRUPTS_FROM_HERTZ(HERTZ_DIS1);
         case nt_E_1:   return INTERRUPTS_FROM_HERTZ(HERTZ_E1);
         case nt_F_1:   return INTERRUPTS_FROM_HERTZ(HERTZ_F1);
         case nt_FIS_1: return INTERRUPTS_FROM_HERTZ(HERTZ_FIS1);
         case nt_G_1:   return INTERRUPTS_FROM_HERTZ(HERTZ_G1);
         case nt_GIS_1: return INTERRUPTS_FROM_HERTZ(HERTZ_GIS1);
         case nt_A_1:   return INTERRUPTS_FROM_HERTZ(HERTZ_A1);
         case nt_AIS_1: return INTERRUPTS_FROM_HERTZ(HERTZ_AIS1);
         case nt_H_1:   return INTERRUPTS_FROM_HERTZ(HERTZ_H1);

         case nt_C_2:   return INTERRUPTS_FROM_HERTZ(HERTZ_C2);
         case nt_CIS_2: return INTERRUPTS_FROM_HERTZ(HERTZ_CIS2);
         case nt_D_2:   return INTERRUPTS_FROM_HERTZ(HERTZ_D2);
         case nt_DIS_2: return INTERRUPTS_FROM_HERTZ(HERTZ_DIS2);
         case nt_E_2:   return INTERRUPTS_FROM_HERTZ(HERTZ_E2);
         case nt_F_2:   return INTERRUPTS_FROM_HERTZ(HERTZ_F2);
         case nt_FIS_2: return INTERRUPTS_FROM_HERTZ(HERTZ_FIS2);
         case nt_G_2:   return INTERRUPTS_FROM_HERTZ(HERTZ_G2);
         case nt_GIS_2: return INTERRUPTS_FROM_HERTZ(HERTZ_GIS2);
         case nt_A_2:   return INTERRUPTS_FROM_HERTZ(HERTZ_A2);
         case nt_AIS_2: return INTERRUPTS_FROM_HERTZ(HERTZ_AIS2);
         case nt_H_2:   return INTERRUPTS_FROM_HERTZ(HERTZ_H2);

         case nt_C_3:   return INTERRUPTS_FROM_HERTZ(HERTZ_C3);
         case nt_CIS_3: return INTERRUPTS_FROM_HERTZ(HERTZ_CIS3);
         case nt_D_3:   return INTERRUPTS_FROM_HERTZ(HERTZ_D3);
         case nt_DIS_3: return INTERRUPTS_FROM_HERTZ(HERTZ_DIS3);
         case nt_E_3:   return INTERRUPTS_FROM_HERTZ(HERTZ_E3);
         case nt_F_3:   return INTERRUPTS_FROM_HERTZ(HERTZ_F3);
         case nt_FIS_3: return INTERRUPTS_FROM_HERTZ(HERTZ_FIS3);
         case nt_G_3:   return INTERRUPTS_FROM_HERTZ(HERTZ_G3);
         case nt_GIS_3: return INTERRUPTS_FROM_HERTZ(HERTZ_GIS3);
         case nt_A_3:   return INTERRUPTS_FROM_HERTZ(HERTZ_A3);
         case nt_AIS_3: return INTERRUPTS_FROM_HERTZ(HERTZ_AIS3);
         case nt_H_3:   return INTERRUPTS_FROM_HERTZ(HERTZ_H3);
         default:       return 0; // Should never happen.
      };
   }

   uint16_t GetLength() const
   {
      switch (mLength)
      {
//         case nl_FullDot:      return ONE_SECOND * 3.0f;
         case nl_Full:         return ONE_SECOND * 2.0f;
         case nl_HalfDot:      return ONE_SECOND * 1.5f;
         case nl_Half:         return ONE_SECOND * 1.0f;
         case nl_QuarterDot:   return ONE_SECOND * .75f;
         case nl_Quarter:      return ONE_SECOND * .50f;
         case nl_EighthDot:    return ONE_SECOND * .375f;
         case nl_Eighth: 	    return ONE_SECOND * .25f;
         case nl_SixteenthDot: return ONE_SECOND * .1875f;
         case nl_Sixteenth:    return ONE_SECOND * .125f;
         default:              return 0; // Should never happen.
      };
   }

private:
   const NoteTone mTone;
   const NoteLength mLength;
};

#endif // NOTE_HPP
