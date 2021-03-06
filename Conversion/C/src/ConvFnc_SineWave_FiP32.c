/*
 * Copyright (c) 2019, Strifus
 * All rights reserved.
 */
/*
 * This file is licensed according to the BSD 3-clause license as follows:
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of "Strifus" nor
 *     the names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL "{ORGANIZATION_NAME}" BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/* USERCODE-BEGIN:Description                                                                                         */
/* Description: */
/* USERCODE-END:Description                                                                                           */
#include "ConvFnc_SineWave_FiP32.h"

/* USERCODE-BEGIN:PreProcessor                                                                                        */
/* USERCODE-END:PreProcessor                                                                                          */

extern uint8 MaskParamBuffer[];
extern uint8 ImplParamBuffer[];
extern uint8 SaveFncDataBuffer[];

/** Implementation parameter data structure */
typedef struct {
    int32 delta_phi;
    int32 phase;
    int32 offset;
    int32 amplitude;
} SINEWAVE_FIP32_IMPL_PARAM;

/** Private prototypes */
static uint8 convertM2I(const SINEWAVE_FIP32_MASK_PARAM *maskParam, SINEWAVE_FIP32_IMPL_PARAM *impParam, float_CoT ts);

/**
 * @brief Converts Mask parameters to Implementation parameters.
 *
 * @param[in] maskParam Mask parameters
 * @param[out] impParam Implementation parameters
 * @param[in] ts Block sample time
 *
 * @return Error: zero on success, not zero in case of conversion error
 */
static uint8 convertM2I(const SINEWAVE_FIP32_MASK_PARAM *maskParam, SINEWAVE_FIP32_IMPL_PARAM *impParam, float_CoT ts)
{
    uint8 error = (uint8)0;
/* USERCODE-BEGIN:Conversion                                                                                          */
#error CONVERSION-ON-TARGET CURRENTLY NOT SUPPORTED / MASK-TO-IMPLEMENTATION CONVERSION MISSING
/* USERCODE-END:Conversion                                                                                            */
    return (error);
}

/**
 * @brief Load block mask parameter data.
 *
 * @param[in] maskParam Mask parameter data structure
 * @param[out] data Data
 * @param[out] dataLen Data length
 * @param[in] maxSize Maximum Service data length
 *
 * @return Error: zero on success, not zero in case of load- or conversion error
 */
uint8 SineWave_FiP32_LoadMP(const SINEWAVE_FIP32_MASK_PARAM *maskParam, uint8 data[], uint16* dataLen, uint16 maxSize)
{
    uint8 error = (uint8)0;
    if ((uint16)40 > maxSize)
    {
        error = (uint8)1;
    }
    else
    {
        data[0] = (uint8)((*(uint64*)&(maskParam->Amplitude)) & 0x00000000000000FF);
        data[1] = (uint8)((*(uint64*)&(maskParam->Amplitude) >> 8) & 0x00000000000000FF);
        data[2] = (uint8)((*(uint64*)&(maskParam->Amplitude) >> 16) & 0x00000000000000FF);
        data[3] = (uint8)((*(uint64*)&(maskParam->Amplitude) >> 24) & 0x00000000000000FF);
        data[4] = (uint8)((*(uint64*)&(maskParam->Amplitude) >> 32) & 0x00000000000000FF);
        data[5] = (uint8)((*(uint64*)&(maskParam->Amplitude) >> 40) & 0x00000000000000FF);
        data[6] = (uint8)((*(uint64*)&(maskParam->Amplitude) >> 48) & 0x00000000000000FF);
        data[7] = (uint8)((*(uint64*)&(maskParam->Amplitude) >> 56) & 0x00000000000000FF);
        data[8] = (uint8)((*(uint64*)&(maskParam->Frequency)) & 0x00000000000000FF);
        data[9] = (uint8)((*(uint64*)&(maskParam->Frequency) >> 8) & 0x00000000000000FF);
        data[10] = (uint8)((*(uint64*)&(maskParam->Frequency) >> 16) & 0x00000000000000FF);
        data[11] = (uint8)((*(uint64*)&(maskParam->Frequency) >> 24) & 0x00000000000000FF);
        data[12] = (uint8)((*(uint64*)&(maskParam->Frequency) >> 32) & 0x00000000000000FF);
        data[13] = (uint8)((*(uint64*)&(maskParam->Frequency) >> 40) & 0x00000000000000FF);
        data[14] = (uint8)((*(uint64*)&(maskParam->Frequency) >> 48) & 0x00000000000000FF);
        data[15] = (uint8)((*(uint64*)&(maskParam->Frequency) >> 56) & 0x00000000000000FF);
        data[16] = (uint8)((*(uint64*)&(maskParam->Offset)) & 0x00000000000000FF);
        data[17] = (uint8)((*(uint64*)&(maskParam->Offset) >> 8) & 0x00000000000000FF);
        data[18] = (uint8)((*(uint64*)&(maskParam->Offset) >> 16) & 0x00000000000000FF);
        data[19] = (uint8)((*(uint64*)&(maskParam->Offset) >> 24) & 0x00000000000000FF);
        data[20] = (uint8)((*(uint64*)&(maskParam->Offset) >> 32) & 0x00000000000000FF);
        data[21] = (uint8)((*(uint64*)&(maskParam->Offset) >> 40) & 0x00000000000000FF);
        data[22] = (uint8)((*(uint64*)&(maskParam->Offset) >> 48) & 0x00000000000000FF);
        data[23] = (uint8)((*(uint64*)&(maskParam->Offset) >> 56) & 0x00000000000000FF);
        data[24] = (uint8)((*(uint64*)&(maskParam->Phase)) & 0x00000000000000FF);
        data[25] = (uint8)((*(uint64*)&(maskParam->Phase) >> 8) & 0x00000000000000FF);
        data[26] = (uint8)((*(uint64*)&(maskParam->Phase) >> 16) & 0x00000000000000FF);
        data[27] = (uint8)((*(uint64*)&(maskParam->Phase) >> 24) & 0x00000000000000FF);
        data[28] = (uint8)((*(uint64*)&(maskParam->Phase) >> 32) & 0x00000000000000FF);
        data[29] = (uint8)((*(uint64*)&(maskParam->Phase) >> 40) & 0x00000000000000FF);
        data[30] = (uint8)((*(uint64*)&(maskParam->Phase) >> 48) & 0x00000000000000FF);
        data[31] = (uint8)((*(uint64*)&(maskParam->Phase) >> 56) & 0x00000000000000FF);
        data[32] = (uint8)((*(uint64*)&(maskParam->ts_fact)) & 0x00000000000000FF);
        data[33] = (uint8)((*(uint64*)&(maskParam->ts_fact) >> 8) & 0x00000000000000FF);
        data[34] = (uint8)((*(uint64*)&(maskParam->ts_fact) >> 16) & 0x00000000000000FF);
        data[35] = (uint8)((*(uint64*)&(maskParam->ts_fact) >> 24) & 0x00000000000000FF);
        data[36] = (uint8)((*(uint64*)&(maskParam->ts_fact) >> 32) & 0x00000000000000FF);
        data[37] = (uint8)((*(uint64*)&(maskParam->ts_fact) >> 40) & 0x00000000000000FF);
        data[38] = (uint8)((*(uint64*)&(maskParam->ts_fact) >> 48) & 0x00000000000000FF);
        data[39] = (uint8)((*(uint64*)&(maskParam->ts_fact) >> 56) & 0x00000000000000FF);
        *dataLen = (uint16)40;
    }
    return (error);
}

/**
 * @brief Save block mask parameter data.
 *
 * @param[in] block Pointer to block structure
 * @param[out] maskParam Mask parameter data structure
 * @param[in] data Data
 * @param dataLen Length of mask parameter data stream
 *
 * @return Error: zero on success, not zero in case of save- or conversion error
 */
uint8 SineWave_FiP32_SaveMP(SINEWAVE_FIP32 *block, SINEWAVE_FIP32_MASK_PARAM *maskParam, const uint8 data[], uint16 dataLen)
{
    uint8 error = (uint8)0;

    if (dataLen != (uint16)40)
    {
        error = (uint8)1;
    }
    else
    {
        uint64 tmp64;
        float_CoT block_ts;
        SINEWAVE_FIP32_IMPL_PARAM *implParam = (SINEWAVE_FIP32_IMPL_PARAM*)ImplParamBuffer;

        /** - Cache old mask parameters */
        memcpy(MaskParamBuffer, maskParam, sizeof(*maskParam));

        /** - Save new mask parameters */
        tmp64 = (uint64)data[0] + \
            ((uint64)data[1] << 8) + ((uint64)data[2] << 16) + \
            ((uint64)data[3] << 24) + ((uint64)data[4] << 32) + \
            ((uint64)data[5] << 40) + ((uint64)data[6] << 48) + \
            ((uint64)data[7] << 56);
        maskParam->Amplitude = (float64)(*(float64*)&tmp64);
        tmp64 = (uint64)data[8] + \
            ((uint64)data[9] << 8) + ((uint64)data[10] << 16) + \
            ((uint64)data[11] << 24) + ((uint64)data[12] << 32) + \
            ((uint64)data[13] << 40) + ((uint64)data[14] << 48) + \
            ((uint64)data[15] << 56);
        maskParam->Frequency = (float64)(*(float64*)&tmp64);
        tmp64 = (uint64)data[16] + \
            ((uint64)data[17] << 8) + ((uint64)data[18] << 16) + \
            ((uint64)data[19] << 24) + ((uint64)data[20] << 32) + \
            ((uint64)data[21] << 40) + ((uint64)data[22] << 48) + \
            ((uint64)data[23] << 56);
        maskParam->Offset = (float64)(*(float64*)&tmp64);
        tmp64 = (uint64)data[24] + \
            ((uint64)data[25] << 8) + ((uint64)data[26] << 16) + \
            ((uint64)data[27] << 24) + ((uint64)data[28] << 32) + \
            ((uint64)data[29] << 40) + ((uint64)data[30] << 48) + \
            ((uint64)data[31] << 56);
        maskParam->Phase = (float64)(*(float64*)&tmp64);
        tmp64 = (uint64)data[32] + \
            ((uint64)data[33] << 8) + ((uint64)data[34] << 16) + \
            ((uint64)data[35] << 24) + ((uint64)data[36] << 32) + \
            ((uint64)data[37] << 40) + ((uint64)data[38] << 48) + \
            ((uint64)data[39] << 56);
        maskParam->ts_fact = (float64)(*(float64*)&tmp64);

        /** - Get Block Sample Time */
        block_ts = maskParam->ts_fact * getModelSampleTime();
        /** - Convert mask parameters to implementation parameters */
        error = convertM2I(maskParam, implParam, block_ts);

        /** - Prepare implementation parameters for save function */
        SaveFncDataBuffer[0] = (uint8)(implParam->delta_phi & 0x000000FF);
        SaveFncDataBuffer[1] = (uint8)((implParam->delta_phi >> 8) & 0x000000FF);
        SaveFncDataBuffer[2] = (uint8)((implParam->delta_phi >> 16) & 0x000000FF);
        SaveFncDataBuffer[3] = (uint8)((implParam->delta_phi >> 24) & 0x000000FF);
        SaveFncDataBuffer[4] = (uint8)(implParam->phase & 0x000000FF);
        SaveFncDataBuffer[5] = (uint8)((implParam->phase >> 8) & 0x000000FF);
        SaveFncDataBuffer[6] = (uint8)((implParam->phase >> 16) & 0x000000FF);
        SaveFncDataBuffer[7] = (uint8)((implParam->phase >> 24) & 0x000000FF);
        SaveFncDataBuffer[8] = (uint8)(implParam->offset & 0x000000FF);
        SaveFncDataBuffer[9] = (uint8)((implParam->offset >> 8) & 0x000000FF);
        SaveFncDataBuffer[10] = (uint8)((implParam->offset >> 16) & 0x000000FF);
        SaveFncDataBuffer[11] = (uint8)((implParam->offset >> 24) & 0x000000FF);
        SaveFncDataBuffer[12] = (uint8)(implParam->amplitude & 0x000000FF);
        SaveFncDataBuffer[13] = (uint8)((implParam->amplitude >> 8) & 0x000000FF);
        SaveFncDataBuffer[14] = (uint8)((implParam->amplitude >> 16) & 0x000000FF);
        SaveFncDataBuffer[15] = (uint8)((implParam->amplitude >> 24) & 0x000000FF);

        /** - Execute save function of block */
        error = SineWave_FiP32_Save(block, SaveFncDataBuffer, 16);

        /** - Check for errors during execution of save function */
        if (error != 0)
        {
            /* Restore old mask parameter */
            memcpy(maskParam, MaskParamBuffer, sizeof(*maskParam));
        }

    }
    return (error);
}

/**
 * @brief Initializes Implementation parameters from Mask parameters.
 *
 * @param[out] block Block
 * @param[in] maskParam Mask parameters
 *
 * @return Error: zero on success, not zero in case of initialization error
 */
uint8 SineWave_FiP32_InitMP(SINEWAVE_FIP32 *block, const SINEWAVE_FIP32_MASK_PARAM *maskParam)
{
    uint8 error = (uint8)0;
    float_CoT block_ts;

    SINEWAVE_FIP32_IMPL_PARAM *implParam = (SINEWAVE_FIP32_IMPL_PARAM*)ImplParamBuffer;

    /** - Get Block Sample Time */
    block_ts = maskParam->ts_fact * getModelSampleTime();
    /** - Convert mask parameters to implementation parameters */
    error = convertM2I(maskParam, implParam, block_ts);

    /** - Prepare implementation parameters for save function */
    SaveFncDataBuffer[0] = (uint8)(implParam->delta_phi & 0x000000FF);
    SaveFncDataBuffer[1] = (uint8)((implParam->delta_phi >> 8) & 0x000000FF);
    SaveFncDataBuffer[2] = (uint8)((implParam->delta_phi >> 16) & 0x000000FF);
    SaveFncDataBuffer[3] = (uint8)((implParam->delta_phi >> 24) & 0x000000FF);
    SaveFncDataBuffer[4] = (uint8)(implParam->phase & 0x000000FF);
    SaveFncDataBuffer[5] = (uint8)((implParam->phase >> 8) & 0x000000FF);
    SaveFncDataBuffer[6] = (uint8)((implParam->phase >> 16) & 0x000000FF);
    SaveFncDataBuffer[7] = (uint8)((implParam->phase >> 24) & 0x000000FF);
    SaveFncDataBuffer[8] = (uint8)(implParam->offset & 0x000000FF);
    SaveFncDataBuffer[9] = (uint8)((implParam->offset >> 8) & 0x000000FF);
    SaveFncDataBuffer[10] = (uint8)((implParam->offset >> 16) & 0x000000FF);
    SaveFncDataBuffer[11] = (uint8)((implParam->offset >> 24) & 0x000000FF);
    SaveFncDataBuffer[12] = (uint8)(implParam->amplitude & 0x000000FF);
    SaveFncDataBuffer[13] = (uint8)((implParam->amplitude >> 8) & 0x000000FF);
    SaveFncDataBuffer[14] = (uint8)((implParam->amplitude >> 16) & 0x000000FF);
    SaveFncDataBuffer[15] = (uint8)((implParam->amplitude >> 24) & 0x000000FF);

    /** - Execute save function of block */
    error = SineWave_FiP32_Save(block, SaveFncDataBuffer, 16);

    return (error);
}
