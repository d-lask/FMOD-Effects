//
//  plugins.hpp
//  FmodPlugins
//
//  Created by David Laskey on 12/6/25.
//

#ifndef plugins_hpp
#define plugins_hpp

#include <stdio.h>

#include "fmod.hpp"

extern "C"
{
    F_EXPORT FMOD_DSP_DESCRIPTION* F_CALL FMODGetDSPDescription();
}

#endif /* plugins_hpp */
