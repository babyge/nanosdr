//
// Frequency translator
//
// Copyright 2010-2013 Moe Wheatley
// Copyright 2014      Alexandru Csete
// All rights reserved.
//
// This software is released under the Simplified BSD License, see
// license.txt for details.
//
#ifndef TRANSLATE_H
#define TRANSLATE_H

#include "datatypes.h"


/// Class for performing frequency translation.
///
/// This class takes I/Q baseband data and performs frequency translation
/// using an NCO. In addition to the NCO frequency a CW offset can be
/// specified to aid CW operations.
class Translate
{
public:
    Translate();

    /// Set NCO frequency
    /// @param  freq_hz  The NCO frequency in Hz.
    ///
    /// The NCO frequency corresponds to the frequency translation. For
    /// example, a value of -20000 means that the spectrum will be shifted
    /// 20 kHz in the negative direction and the channel originally located
    /// at +20 kHz is now at the center.
    void set_nco_frequency(real_t freq_hz);

    /// Set additional CW offset.
    /// @param  offset_hz  Additional CW offset.
    void set_cw_offset(real_t offset_hz);

    /// Process data.
    /// @param  length  The length of the input array.
    /// @param  data    Pointer to the input data which is also use for
    ///                 output.
    void process(int length, complex_t* data);

    /// Set Sample input and output sample rates.
    /// @param rate The new sample rate in Hz.
    void set_sample_rate(real_t rate);


private:

    real_t     sample_rate;   // sample rate.
    real_t     nco_freq;      // NCO frequency in Hz.
    real_t     cw_offset;     // Additional CW offset.
    real_t     nco_inc;
    real_t     osc_cos;
    real_t     osc_sin;
    complex_t  osc1;

};

#endif // TRANSLATE_H
