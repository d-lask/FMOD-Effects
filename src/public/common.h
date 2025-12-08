//
//  common.h
//  FmodPlugins
//
//  Created by David Laskey on 12/6/25.
//

#ifndef common_h
#define common_h

#define DECLARE_FMOD_DESCRIPTION_FUNCS(object)                                  \
    FMOD_RESULT F_CALL FMOD_## object ##_dspcreate(FMOD_DSP_STATE *dsp_state);  \
    FMOD_RESULT F_CALL FMOD_## object ##_dsprelease(FMOD_DSP_STATE *dsp_state); \
    FMOD_RESULT F_CALL FMOD_## object ##_dspreset(FMOD_DSP_STATE *dsp_state);   \
    FMOD_RESULT F_CALL FMOD_## object ##_dspread(FMOD_DSP_STATE *dsp_state, float *inbuffer, float *outbuffer, unsigned int length, int inchannels, int *outchannels);                              \
    FMOD_RESULT F_CALL FMOD_## object ##_dspsetparamfloat(FMOD_DSP_STATE *dsp_state, int index, float value); \
    FMOD_RESULT F_CALL FMOD_## object ##_dspgetparamfloat(FMOD_DSP_STATE *dsp_state, int index, float *value, char *valuestr); \
    FMOD_RESULT F_CALL FMOD_## object ##_dspsetparamint(FMOD_DSP_STATE *dsp_state, int index, int value); \
    FMOD_RESULT F_CALL FMOD_## object ##_dspgetparamint(FMOD_DSP_STATE *dsp_state, int index, int *value, char *valuestr); \
    FMOD_RESULT F_CALL FMOD_## object ##_shouldiprocess(FMOD_DSP_STATE *dsp_state, FMOD_BOOL inputsidle, unsigned int length, FMOD_CHANNELMASK inmask, int inchannels, FMOD_SPEAKERMODE speakermode);


#define DECLARE_FMOD_DESCRIPTION(object, name, version, numParams, paramArray)          \
    FMOD_DSP_DESCRIPTION FMOD_## object ##_Desc =                                       \
    {                                                                                   \
        FMOD_PLUGIN_SDK_VERSION,                                                        \
        name,                                                                           \
        version,                                                                        \
        1,                                                                              \
        1,                                                                              \
        FMOD_## object ##_dspcreate,                                                    \
        FMOD_## object ##_dsprelease,                                                   \
        FMOD_## object ##_dspreset,                                                     \
        FMOD_## object ##_dspread,                                                      \
        0,                                                                              \
        0,                                                                              \
        numParams,                                                                      \
        paramArray,                                                                     \
        FMOD_## object ##_dspsetparamfloat,                                             \
        FMOD_## object ##_dspsetparamint,                                               \
        0,                                                                              \
        0,                                                                              \
        FMOD_## object ##_dspgetparamfloat,                                             \
        FMOD_## object ##_dspgetparamint,                                               \
        0,                                                                              \
        0,                                                                              \
        FMOD_## object ##_shouldiprocess,                                               \
        0,                                                                              \
        0,                                                                              \
        0,                                                                              \
        0                                                                               \
    }

#endif /* common_h */
