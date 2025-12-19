//
//  plugins.hpp
//  FmodPlugins
//
//  Created by David Laskey on 12/6/25.
//

#ifndef plugins_hpp
#define plugins_hpp

#include <stdio.h>
#include "common.h"
#include "fmod.hpp"

DECLARE_PLUGIN_BINDINGS(RingModulator)

static FMOD_PLUGINLIST Plugin_List[] =
{
    { FMOD_PLUGINTYPE_DSP, &FMOD_RingModulator_Desc },
    { FMOD_PLUGINTYPE_MAX, NULL }
};

extern "C"
{
    F_EXPORT FMOD_PLUGINLIST* F_CALL FMODGetPluginDescriptionList()
    {
        RingModulator_PluginInit();
        return (FMOD_PLUGINLIST *)&Plugin_List;
    }
}

#endif /* plugins_hpp */
