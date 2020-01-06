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
#ifndef SINEWAVE_FLOAT32_H
#define SINEWAVE_FLOAT32_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CommonFcts.h"

#if !defined(SINEWAVE_FLOAT32_ISLINKED)
#define SINEWAVE_FLOAT32_ID ((uint16)60803)

typedef struct {
    uint16          ID;
    float32         u;
    int32           delta_phi;
    int32           phase;
    float32         offset;
    int32           phi;
    float32         amplitude;
} SINEWAVE_FLOAT32;

#define SINEWAVE_FLOAT32_FUNCTIONS { \
    SINEWAVE_FLOAT32_ID, \
    (void (*)(void*))SineWave_Float32_Update, \
    (void (*)(void*))SineWave_Float32_Init, \
    (tLoadImplementationParameter)SineWave_Float32_Load, \
    (tSaveImplementationParameter)SineWave_Float32_Save, \
    (void* (*)(const void*, uint16))SineWave_Float32_GetAddress }

/**********************************************************************************************************************/
/** Public prototypes                                                                                                **/
/**********************************************************************************************************************/
void SineWave_Float32_Update(SINEWAVE_FLOAT32 *pTSineWave_Float32);
void SineWave_Float32_Init(SINEWAVE_FLOAT32 *pTSineWave_Float32);
uint8 SineWave_Float32_Load(const SINEWAVE_FLOAT32 *pTSineWave_Float32, uint8 data[], uint16 *dataLength, uint16 maxSize);
uint8 SineWave_Float32_Save(SINEWAVE_FLOAT32 *pTSineWave_Float32, const uint8 data[], uint16 dataLength);
void* SineWave_Float32_GetAddress(const SINEWAVE_FLOAT32 *block, uint16 elementId);

#endif

#ifdef __cplusplus
}
#endif

#endif
