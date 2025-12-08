//
//  plugins.cpp
//  FmodPlugins
//
//  Created by David Laskey on 12/6/25.
//

#include "plugins.hpp"

#include <string.h>
#include "common.h"

enum
{
    FMOD_RINGMOD_WAVETYPE_SIN,
    FMOD_RINGMOD_WAVETYPE_SQAURE,
    FMOD_RINGMOD_WAVETYPE_TRIANGLE,
    FMOD_RINGMOD_WAVETYPE_SAWTOOTH
};

enum
{
    FMOD_RINGMOD_PARAM_ENABLED,
    FMOD_RINGMOD_PARAM_WAVETYPE,
    FMOD_RINGMOD_PARAM_WAVEFREQ,
    FMOD_RINGMOD_PARAM_COUNT
};

class FMODRingModulator
{
public:
    
    int wave_type;
    float wave_frequency;
};

static FMOD_DSP_PARAMETER_DESC p_ringmod_enabled;
static FMOD_DSP_PARAMETER_DESC p_ringmod_wavetype;
static FMOD_DSP_PARAMETER_DESC p_ringmod_wavefreq;

FMOD_DSP_PARAMETER_DESC *ringmod_params[FMOD_RINGMOD_PARAM_COUNT]
{
    &p_ringmod_enabled,
    &p_ringmod_wavetype,
    &p_ringmod_wavefreq
};

DECLARE_FMOD_DESCRIPTION_FUNCS(BitCrusher);
DECLARE_FMOD_DESCRIPTION(BitCrusher, "Lasko_BitCrusher", 0x00001000, FMOD_RINGMOD_PARAM_COUNT, ringmod_params);

const float FMOD_RINGMOD_WAVEFREQ_MIN = 1.0f;
const float FMOD_RINGMOD_WAVEFREQ_MAX = 1000.0f;
const float FMOD_RINGMOD_WAVEFREQ_DEFAULT = 400.0f;

FMOD_DSP_DESCRIPTION *FMODGetDSPDescription() {
    
    static const char *wave_shape_names[4] =
    {
        "sin", "square", "triangle", "sawtooth"
    };
    
    FMOD_DSP_INIT_PARAMDESC_FLOAT(p_ringmod_enabled, "Enabled", "", "Is the ringmod effect enabled", 0.0f, 1.0f, 1.0f);
    FMOD_DSP_INIT_PARAMDESC_INT(p_ringmod_wavetype, "Wave Type", "", "Shape of modulating wave", FMOD_RINGMOD_WAVETYPE_SIN, FMOD_RINGMOD_WAVETYPE_SAWTOOTH, FMOD_RINGMOD_WAVETYPE_SIN, false, wave_shape_names);
    FMOD_DSP_INIT_PARAMDESC_FLOAT(p_ringmod_wavefreq, "Wave Freq", "hz", "Frequency of modulating wave", FMOD_RINGMOD_WAVEFREQ_MIN, FMOD_RINGMOD_WAVEFREQ_MAX, FMOD_RINGMOD_WAVEFREQ_DEFAULT);
    return &FMOD_BitCrusher_Desc;
}

class FMODRingModState
{
public:
    FMODRingModState() { }
    
    bool enabled = false;
    float wave_frequency = FMOD_RINGMOD_WAVEFREQ_DEFAULT;
    int wave_type = FMOD_RINGMOD_WAVETYPE_SIN;
    float wave_offset = 0.0f;
};

FMOD_RESULT FMOD_BitCrusher_dspcreate(FMOD_DSP_STATE *dsp_state) {
    
    FMODRingModState* state = (FMODRingModState *)FMOD_DSP_ALLOC(dsp_state, sizeof(FMODRingModState));
    dsp_state->plugindata = state;
    if (!state)
    {
        return FMOD_ERR_MEMORY;
    }
    
    return FMOD_OK;
}

FMOD_RESULT FMOD_BitCrusher_dsprelease(FMOD_DSP_STATE *dsp_state) {
    
    FMODRingModState *state = (FMODRingModState *)dsp_state->plugindata;
    FMOD_DSP_FREE(dsp_state, state);
    return FMOD_OK;
}

FMOD_RESULT FMOD_BitCrusher_dspreset(FMOD_DSP_STATE *dsp_state) {
    return FMOD_OK;
}

float generate_sin_wave(float offset)
{
    return 0.0f;
}

float generate_square_wave(float offset)
{
    return 0.0f;
}

float generate_triangle_wave(float offset)
{
    return 0.0f;
}

float generate_sawtooth_wave(float offset)
{
    return 0.0f;
}

FMOD_RESULT FMOD_BitCrusher_dspread(FMOD_DSP_STATE *dsp_state, float *inbuffer, float *outbuffer, unsigned int length, int inchannels, int *outchannels) {
    
    const int TOTAL_SIZE = length * inchannels;
    
    FMODRingModState *state = (FMODRingModState *)dsp_state->plugindata;
    if(!state->enabled)
    {
        memcpy(outbuffer, inbuffer, TOTAL_SIZE * sizeof(float));
        return FMOD_OK;
    }
    
    for(int b = 0; b < length; b++)
    {
        
        for(int c = 0; c < inchannels; c++)
        {
            
        }
    }
    
    return FMOD_OK;
}

FMOD_RESULT FMOD_BitCrusher_dspsetparamfloat(FMOD_DSP_STATE *dsp_state, int index, float value) {
    FMODRingModState *state = (FMODRingModState *)dsp_state->plugindata;
    
    switch (index)
    {
    case FMOD_RINGMOD_PARAM_WAVEFREQ:
    {
        state->wave_frequency = value;
        return FMOD_OK;
    }
    case FMOD_RINGMOD_PARAM_ENABLED:
    {
        state->enabled = value > 0.5f ? true : false;
        return FMOD_OK;
    }
    }
    
    return FMOD_ERR_INVALID_PARAM;
}

FMOD_RESULT FMOD_BitCrusher_dspgetparamfloat(FMOD_DSP_STATE *dsp_state, int index, float *value, char *valuestr) {
    FMODRingModState *state = (FMODRingModState *)dsp_state->plugindata;
    
    switch (index)
    {
    case FMOD_RINGMOD_PARAM_WAVEFREQ:
    {
        *value = state->wave_frequency;
        return FMOD_OK;
    }
    case FMOD_RINGMOD_PARAM_ENABLED:
    {
        *value = state->enabled ? 1.0f : 0.0f;
        return FMOD_OK;
    }
    }
    
    return FMOD_ERR_INVALID_PARAM;
}

FMOD_RESULT FMOD_BitCrusher_dspsetparamint(FMOD_DSP_STATE *dsp_state, int index, int value) {
    FMODRingModState *state = (FMODRingModState *)dsp_state->plugindata;
    
    switch (index)
    {
    case FMOD_RINGMOD_PARAM_WAVETYPE:
    {
        state->wave_type = value;
        return FMOD_OK;
    }
    }
    
    return FMOD_ERR_INVALID_PARAM;
}

FMOD_RESULT FMOD_BitCrusher_dspgetparamint(FMOD_DSP_STATE *dsp_state, int index, int *value, char *valuestr) {
    FMODRingModState *state = (FMODRingModState *)dsp_state->plugindata;
    
    switch (index)
    {
    case FMOD_RINGMOD_PARAM_WAVETYPE:
    {
        *value = state->wave_type;
        return FMOD_OK;
    }
    }
    
    return FMOD_ERR_INVALID_PARAM;
}

FMOD_RESULT FMOD_BitCrusher_shouldiprocess(FMOD_DSP_STATE *dsp_state, FMOD_BOOL inputsidle, unsigned int length, FMOD_CHANNELMASK inmask, int inchannels, FMOD_SPEAKERMODE speakermode) {
    
    if (inputsidle)
    {
        return FMOD_ERR_DSP_DONTPROCESS;
    }
    
    return FMOD_OK;
}
