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
#include "SineWave_Float64.h"

/* all used update functions to ram for c2000                                                                         */
#if defined(__ALL_UPDATE_FUNC_2_RAM_C2000__)
    #pragma CODE_SECTION(SineWave_Float64_Update, "ramfuncs")
#endif

/* USERCODE-BEGIN:PreProcessor                                                                                        */
#include <math.h>

/* Input */

/* Output */
#define OUT		 	(pTSineWave_Float64->u)

/* Parameter */
#define AMPLITUDE	(pTSineWave_Float64->amplitude)
#define OFFSET		(pTSineWave_Float64->offset)
#define PHASE		(pTSineWave_Float64->phase)
#define DELTA_PHI	(pTSineWave_Float64->delta_phi)

/* Variables */
#define PHI			(pTSineWave_Float64->phi)

/* Macros */
#define PI          PI_R64
/* USERCODE-END:PreProcessor                                                                                          */

/**********************************************************************************************************************/
/** Update                                                                                                           **/
/**********************************************************************************************************************/
void SineWave_Float64_Update(SINEWAVE_FLOAT64 *pTSineWave_Float64)
{
/* USERCODE-BEGIN:UpdateFnc                                                                                           */
    int32 angle;
    float64 sine;
	float64	temp;

    /* angle */
    PHI = PHI + DELTA_PHI;
    
	/* phase */
	angle = PHI + PHASE;                                /* phi+phase */
    
    /* sine interpolation */
	sine = sin((float64)angle/(float64)2147483648.0*PI);/* sin(phi+phase) */
    
	/* amplification */
	temp  = AMPLITUDE * sine;                           /* A*sin(phi+phase) */
	
    /* offset */
	temp += OFFSET;                                     /* A*sin(phi+phase) + Offset */
	
    /* output */
	OUT = temp;
/* USERCODE-END:UpdateFnc                                                                                             */

}

/**********************************************************************************************************************/
/** Initialization                                                                                                   **/
/**********************************************************************************************************************/
void SineWave_Float64_Init(SINEWAVE_FLOAT64 *pTSineWave_Float64)
{
    pTSineWave_Float64->ID = SINEWAVE_FLOAT64_ID;
    pTSineWave_Float64->u = 0;
/* USERCODE-BEGIN:InitFnc                                                                                             */
    PHI = 0;
/* USERCODE-END:InitFnc                                                                                               */
}

/**********************************************************************************************************************/
/** Load block data                                                                                                  **/
/**********************************************************************************************************************/
uint8 SineWave_Float64_Load(const SINEWAVE_FLOAT64 *pTSineWave_Float64, uint8 data[], uint16 *dataLength, uint16 maxSize)
{
    uint8 error = (uint8)0;
    if ((uint16)24 > maxSize)
    {
        error = (uint8)1;
    }
    else
    {
        data[0] = (uint8)(pTSineWave_Float64->delta_phi & 0x000000FF);
        data[1] = (uint8)((pTSineWave_Float64->delta_phi >> 8) & 0x000000FF);
        data[2] = (uint8)((pTSineWave_Float64->delta_phi >> 16) & 0x000000FF);
        data[3] = (uint8)((pTSineWave_Float64->delta_phi >> 24) & 0x000000FF);
        data[4] = (uint8)(pTSineWave_Float64->phase & 0x000000FF);
        data[5] = (uint8)((pTSineWave_Float64->phase >> 8) & 0x000000FF);
        data[6] = (uint8)((pTSineWave_Float64->phase >> 16) & 0x000000FF);
        data[7] = (uint8)((pTSineWave_Float64->phase >> 24) & 0x000000FF);
        data[8] = (uint8)((*(uint64*)&(pTSineWave_Float64->offset)) & 0x00000000000000FF);
        data[9] = (uint8)((*(uint64*)&(pTSineWave_Float64->offset) >> 8) & 0x00000000000000FF);
        data[10] = (uint8)((*(uint64*)&(pTSineWave_Float64->offset) >> 16) & 0x00000000000000FF);
        data[11] = (uint8)((*(uint64*)&(pTSineWave_Float64->offset) >> 24) & 0x00000000000000FF);
        data[12] = (uint8)((*(uint64*)&(pTSineWave_Float64->offset) >> 32) & 0x00000000000000FF);
        data[13] = (uint8)((*(uint64*)&(pTSineWave_Float64->offset) >> 40) & 0x00000000000000FF);
        data[14] = (uint8)((*(uint64*)&(pTSineWave_Float64->offset) >> 48) & 0x00000000000000FF);
        data[15] = (uint8)((*(uint64*)&(pTSineWave_Float64->offset) >> 56) & 0x00000000000000FF);
        data[16] = (uint8)((*(uint64*)&(pTSineWave_Float64->amplitude)) & 0x00000000000000FF);
        data[17] = (uint8)((*(uint64*)&(pTSineWave_Float64->amplitude) >> 8) & 0x00000000000000FF);
        data[18] = (uint8)((*(uint64*)&(pTSineWave_Float64->amplitude) >> 16) & 0x00000000000000FF);
        data[19] = (uint8)((*(uint64*)&(pTSineWave_Float64->amplitude) >> 24) & 0x00000000000000FF);
        data[20] = (uint8)((*(uint64*)&(pTSineWave_Float64->amplitude) >> 32) & 0x00000000000000FF);
        data[21] = (uint8)((*(uint64*)&(pTSineWave_Float64->amplitude) >> 40) & 0x00000000000000FF);
        data[22] = (uint8)((*(uint64*)&(pTSineWave_Float64->amplitude) >> 48) & 0x00000000000000FF);
        data[23] = (uint8)((*(uint64*)&(pTSineWave_Float64->amplitude) >> 56) & 0x00000000000000FF);
        *dataLength = (uint16)24;
/* USERCODE-BEGIN:LoadFnc                                                                                             */
/* USERCODE-END:LoadFnc                                                                                               */
    }
    return (error);
}

/**********************************************************************************************************************/
/** Save block data                                                                                                  **/
/**********************************************************************************************************************/
uint8 SineWave_Float64_Save(SINEWAVE_FLOAT64 *pTSineWave_Float64, const uint8 data[], uint16 dataLength)
{
    uint8 error;
    uint64 tmp64;

    if (dataLength != (uint16)24)
    {
        error = (uint8)1;
    }
    else
    {
        pTSineWave_Float64->delta_phi = UINT32_TO_INT32((uint32)data[0] + \
            ((uint32)data[1] << 8) + ((uint32)data[2] << 16) + \
            ((uint32)data[3] << 24));
        pTSineWave_Float64->phase = UINT32_TO_INT32((uint32)data[4] + \
            ((uint32)data[5] << 8) + ((uint32)data[6] << 16) + \
            ((uint32)data[7] << 24));
        tmp64 = (uint64)data[8] + \
            ((uint64)data[9] << 8) + ((uint64)data[10] << 16) + \
            ((uint64)data[11] << 24) + ((uint64)data[12] << 32) + \
            ((uint64)data[13] << 40) + ((uint64)data[14] << 48) + \
            ((uint64)data[15] << 56);
        pTSineWave_Float64->offset = (float64)(*(float64*)&tmp64);
        tmp64 = (uint64)data[16] + \
            ((uint64)data[17] << 8) + ((uint64)data[18] << 16) + \
            ((uint64)data[19] << 24) + ((uint64)data[20] << 32) + \
            ((uint64)data[21] << 40) + ((uint64)data[22] << 48) + \
            ((uint64)data[23] << 56);
        pTSineWave_Float64->amplitude = (float64)(*(float64*)&tmp64);
        error = (uint8)0;
/* USERCODE-BEGIN:SaveFnc                                                                                             */
/* USERCODE-END:SaveFnc                                                                                               */
    }
    return (error);
}

/**********************************************************************************************************************/
/** Get block element address                                                                                        **/
/**********************************************************************************************************************/
#if !defined(SINEWAVE_FLOAT64_ISLINKED)
void* SineWave_Float64_GetAddress(const SINEWAVE_FLOAT64* block, uint16 elementId)
{
    void* addr;
    switch (elementId)
    {
        case 1:
            addr = (void*)&block->u;
            break;
        default:
            addr = (void*)0;
            break;
    }
    return (addr);
}
#endif
