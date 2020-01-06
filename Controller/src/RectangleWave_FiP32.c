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
#include "RectangleWave_FiP32.h"

/* all used update functions to ram for c2000                                                                         */
#if defined(__ALL_UPDATE_FUNC_2_RAM_C2000__)
    #pragma CODE_SECTION(RectangleWave_FiP32_Update, "ramfuncs")
#endif

/* USERCODE-BEGIN:PreProcessor                                                                                        */
/* Input */

/* Output */
#define OUT		 	(pTRectangleWave_FiP32->u)

/* Parameter */
#define AMPLITUDE	(pTRectangleWave_FiP32->amplitude)
#define OFFSET		(pTRectangleWave_FiP32->offset)
#define DUTY		(pTRectangleWave_FiP32->duty)
#define DELTA_PHI	(pTRectangleWave_FiP32->delta_phi)

/* Variables */
#define PHI			(pTRectangleWave_FiP32->phi)
/* USERCODE-END:PreProcessor                                                                                          */

/**********************************************************************************************************************/
/** Update                                                                                                           **/
/**********************************************************************************************************************/
void RectangleWave_FiP32_Update(RECTANGLEWAVE_FIP32 *pTRectangleWave_FiP32)
{
/* USERCODE-BEGIN:UpdateFnc                                                                                           */
	int64	temp;

    /* angle */
    PHI = PHI + DELTA_PHI;
        
    /* determination of sign of amplitude */
    if ((uint32)PHI < DUTY)
    {
        temp = AMPLITUDE;
    }
    else
    {
        temp = -AMPLITUDE;
    }
	
    /* offset */
	temp += (int64)OFFSET;						/* A + Offset */
	
    /* output */
	LIMIT(temp, INT32_MAX);                     /* output limitation */
	OUT = (int32)temp;
    
/* USERCODE-END:UpdateFnc                                                                                             */

}

/**********************************************************************************************************************/
/** Initialization                                                                                                   **/
/**********************************************************************************************************************/
void RectangleWave_FiP32_Init(RECTANGLEWAVE_FIP32 *pTRectangleWave_FiP32)
{
    pTRectangleWave_FiP32->ID = RECTANGLEWAVE_FIP32_ID;
    pTRectangleWave_FiP32->u = 0;
/* USERCODE-BEGIN:InitFnc                                                                                             */
    PHI = 0; 
/* USERCODE-END:InitFnc                                                                                               */
}

/**********************************************************************************************************************/
/** Load block data                                                                                                  **/
/**********************************************************************************************************************/
uint8 RectangleWave_FiP32_Load(const RECTANGLEWAVE_FIP32 *pTRectangleWave_FiP32, uint8 data[], uint16 *dataLength, uint16 maxSize)
{
    uint8 error = (uint8)0;
    if ((uint16)16 > maxSize)
    {
        error = (uint8)1;
    }
    else
    {
        data[0] = (uint8)(pTRectangleWave_FiP32->delta_phi & 0x000000FF);
        data[1] = (uint8)((pTRectangleWave_FiP32->delta_phi >> 8) & 0x000000FF);
        data[2] = (uint8)((pTRectangleWave_FiP32->delta_phi >> 16) & 0x000000FF);
        data[3] = (uint8)((pTRectangleWave_FiP32->delta_phi >> 24) & 0x000000FF);
        data[4] = (uint8)(pTRectangleWave_FiP32->duty & 0x000000FF);
        data[5] = (uint8)((pTRectangleWave_FiP32->duty >> 8) & 0x000000FF);
        data[6] = (uint8)((pTRectangleWave_FiP32->duty >> 16) & 0x000000FF);
        data[7] = (uint8)((pTRectangleWave_FiP32->duty >> 24) & 0x000000FF);
        data[8] = (uint8)(pTRectangleWave_FiP32->offset & 0x000000FF);
        data[9] = (uint8)((pTRectangleWave_FiP32->offset >> 8) & 0x000000FF);
        data[10] = (uint8)((pTRectangleWave_FiP32->offset >> 16) & 0x000000FF);
        data[11] = (uint8)((pTRectangleWave_FiP32->offset >> 24) & 0x000000FF);
        data[12] = (uint8)(pTRectangleWave_FiP32->amplitude & 0x000000FF);
        data[13] = (uint8)((pTRectangleWave_FiP32->amplitude >> 8) & 0x000000FF);
        data[14] = (uint8)((pTRectangleWave_FiP32->amplitude >> 16) & 0x000000FF);
        data[15] = (uint8)((pTRectangleWave_FiP32->amplitude >> 24) & 0x000000FF);
        *dataLength = (uint16)16;
/* USERCODE-BEGIN:LoadFnc                                                                                             */
/* USERCODE-END:LoadFnc                                                                                               */
    }
    return (error);
}

/**********************************************************************************************************************/
/** Save block data                                                                                                  **/
/**********************************************************************************************************************/
uint8 RectangleWave_FiP32_Save(RECTANGLEWAVE_FIP32 *pTRectangleWave_FiP32, const uint8 data[], uint16 dataLength)
{
    uint8 error;

    if (dataLength != (uint16)16)
    {
        error = (uint8)1;
    }
    else
    {
        pTRectangleWave_FiP32->delta_phi = UINT32_TO_INT32((uint32)data[0] + \
            ((uint32)data[1] << 8) + ((uint32)data[2] << 16) + \
            ((uint32)data[3] << 24));
        pTRectangleWave_FiP32->duty = ((uint32)data[4] + \
            ((uint32)data[5] << 8) + ((uint32)data[6] << 16) + \
            ((uint32)data[7] << 24));
        pTRectangleWave_FiP32->offset = UINT32_TO_INT32((uint32)data[8] + \
            ((uint32)data[9] << 8) + ((uint32)data[10] << 16) + \
            ((uint32)data[11] << 24));
        pTRectangleWave_FiP32->amplitude = UINT32_TO_INT32((uint32)data[12] + \
            ((uint32)data[13] << 8) + ((uint32)data[14] << 16) + \
            ((uint32)data[15] << 24));
        error = (uint8)0;
/* USERCODE-BEGIN:SaveFnc                                                                                             */
/* USERCODE-END:SaveFnc                                                                                               */
    }
    return (error);
}

/**********************************************************************************************************************/
/** Get block element address                                                                                        **/
/**********************************************************************************************************************/
#if !defined(RECTANGLEWAVE_FIP32_ISLINKED)
void* RectangleWave_FiP32_GetAddress(const RECTANGLEWAVE_FIP32* block, uint16 elementId)
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
