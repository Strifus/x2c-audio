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
#ifndef RECTANGLEWAVE_FIP32_H
#define RECTANGLEWAVE_FIP32_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CommonFcts.h"

#if !defined(RECTANGLEWAVE_FIP32_ISLINKED)
#define RECTANGLEWAVE_FIP32_ID ((uint16)60834)

typedef struct {
    uint16          ID;
    int32           u;
    int32           delta_phi;
    uint32          duty;
    int32           offset;
    int32           phi;
    int32           amplitude;
} RECTANGLEWAVE_FIP32;

#define RECTANGLEWAVE_FIP32_FUNCTIONS { \
    RECTANGLEWAVE_FIP32_ID, \
    (void (*)(void*))RectangleWave_FiP32_Update, \
    (void (*)(void*))RectangleWave_FiP32_Init, \
    (tLoadImplementationParameter)RectangleWave_FiP32_Load, \
    (tSaveImplementationParameter)RectangleWave_FiP32_Save, \
    (void* (*)(const void*, uint16))RectangleWave_FiP32_GetAddress }

/**********************************************************************************************************************/
/** Public prototypes                                                                                                **/
/**********************************************************************************************************************/
void RectangleWave_FiP32_Update(RECTANGLEWAVE_FIP32 *pTRectangleWave_FiP32);
void RectangleWave_FiP32_Init(RECTANGLEWAVE_FIP32 *pTRectangleWave_FiP32);
uint8 RectangleWave_FiP32_Load(const RECTANGLEWAVE_FIP32 *pTRectangleWave_FiP32, uint8 data[], uint16 *dataLength, uint16 maxSize);
uint8 RectangleWave_FiP32_Save(RECTANGLEWAVE_FIP32 *pTRectangleWave_FiP32, const uint8 data[], uint16 dataLength);
void* RectangleWave_FiP32_GetAddress(const RECTANGLEWAVE_FIP32 *block, uint16 elementId);

#endif

#ifdef __cplusplus
}
#endif

#endif
