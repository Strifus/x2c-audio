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
#include "RectangleWave_FiP16.h"

/* all used update functions to ram for c2000                                                                         */
#if defined(__ALL_UPDATE_FUNC_2_RAM_C2000__)
    #pragma CODE_SECTION(RectangleWave_FiP16_Update, "ramfuncs")
#endif

/* USERCODE-BEGIN:PreProcessor                                                                                        */
/* Input */

/* Output */
#define OUT		 	(pTRectangleWave_FiP16->u)

/* Parameter */
#define AMPLITUDE	(pTRectangleWave_FiP16->amplitude)
#define OFFSET		(pTRectangleWave_FiP16->offset)
#define DUTY		(pTRectangleWave_FiP16->duty)
#define DELTA_PHI	(pTRectangleWave_FiP16->delta_phi)

/* Variables */
#define PHI			(pTRectangleWave_FiP16->phi)
/* USERCODE-END:PreProcessor                                                                                          */

/**********************************************************************************************************************/
/** Update                                                                                                           **/
/**********************************************************************************************************************/
void RectangleWave_FiP16_Update(RECTANGLEWAVE_FIP16 *pTRectangleWave_FiP16)
{
/* USERCODE-BEGIN:UpdateFnc                                                                                           */
	int32	temp;

    /* angle */
    PHI = PHI + DELTA_PHI;
    
    /* determination of sign of amplitude */
    if ((uint16)PHI < DUTY)
    {
        temp = AMPLITUDE;
    }
    else
    {
        temp = -AMPLITUDE;
    }
	
    /* offset */
	temp += (int32)OFFSET;						/* A + Offset */
	
    /* output */
	LIMIT(temp, INT16_MAX);                     /* output limitation */
	OUT = (int16)temp;
    
/* USERCODE-END:UpdateFnc                                                                                             */

}

/**********************************************************************************************************************/
/** Initialization                                                                                                   **/
/**********************************************************************************************************************/
void RectangleWave_FiP16_Init(RECTANGLEWAVE_FIP16 *pTRectangleWave_FiP16)
{
    pTRectangleWave_FiP16->ID = RECTANGLEWAVE_FIP16_ID;
    pTRectangleWave_FiP16->u = 0;
/* USERCODE-BEGIN:InitFnc                                                                                             */
    PHI = 0;
/* USERCODE-END:InitFnc                                                                                               */
}

/**********************************************************************************************************************/
/** Load block data                                                                                                  **/
/**********************************************************************************************************************/
uint8 RectangleWave_FiP16_Load(const RECTANGLEWAVE_FIP16 *pTRectangleWave_FiP16, uint8 data[], uint16 *dataLength, uint16 maxSize)
{
    uint8 error = (uint8)0;
    if ((uint16)8 > maxSize)
    {
        error = (uint8)1;
    }
    else
    {
        data[0] = (uint8)(pTRectangleWave_FiP16->delta_phi & 0x00FF);
        data[1] = (uint8)((pTRectangleWave_FiP16->delta_phi >> 8) & 0x00FF);
        data[2] = (uint8)(pTRectangleWave_FiP16->duty & 0x00FF);
        data[3] = (uint8)((pTRectangleWave_FiP16->duty >> 8) & 0x00FF);
        data[4] = (uint8)(pTRectangleWave_FiP16->offset & 0x00FF);
        data[5] = (uint8)((pTRectangleWave_FiP16->offset >> 8) & 0x00FF);
        data[6] = (uint8)(pTRectangleWave_FiP16->amplitude & 0x00FF);
        data[7] = (uint8)((pTRectangleWave_FiP16->amplitude >> 8) & 0x00FF);
        *dataLength = (uint16)8;
/* USERCODE-BEGIN:LoadFnc                                                                                             */
/* USERCODE-END:LoadFnc                                                                                               */
    }
    return (error);
}

/**********************************************************************************************************************/
/** Save block data                                                                                                  **/
/**********************************************************************************************************************/
uint8 RectangleWave_FiP16_Save(RECTANGLEWAVE_FIP16 *pTRectangleWave_FiP16, const uint8 data[], uint16 dataLength)
{
    uint8 error;

    if (dataLength != (uint16)8)
    {
        error = (uint8)1;
    }
    else
    {
        pTRectangleWave_FiP16->delta_phi = UINT16_TO_INT16((uint16)data[0] + \
            ((uint16)data[1] << 8));
        pTRectangleWave_FiP16->duty = ((uint16)data[2] + \
            ((uint16)data[3] << 8));
        pTRectangleWave_FiP16->offset = UINT16_TO_INT16((uint16)data[4] + \
            ((uint16)data[5] << 8));
        pTRectangleWave_FiP16->amplitude = UINT16_TO_INT16((uint16)data[6] + \
            ((uint16)data[7] << 8));
        error = (uint8)0;
/* USERCODE-BEGIN:SaveFnc                                                                                             */
/* USERCODE-END:SaveFnc                                                                                               */
    }
    return (error);
}

/**********************************************************************************************************************/
/** Get block element address                                                                                        **/
/**********************************************************************************************************************/
#if !defined(RECTANGLEWAVE_FIP16_ISLINKED)
void* RectangleWave_FiP16_GetAddress(const RECTANGLEWAVE_FIP16* block, uint16 elementId)
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
