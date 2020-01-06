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
#include "SineWave_FiP8.h"

/* all used update functions to ram for c2000                                                                         */
#if defined(__ALL_UPDATE_FUNC_2_RAM_C2000__)
    #pragma CODE_SECTION(SineWave_FiP8_Update, "ramfuncs")
#endif

/* USERCODE-BEGIN:PreProcessor                                                                                        */
#include "Sin_Data.h"

/* Input */

/* Output */
#define OUT		 	(pTSineWave_FiP8->u)

/* Parameter */
#define AMPLITUDE	(pTSineWave_FiP8->amplitude)
#define OFFSET		(pTSineWave_FiP8->offset)
#define PHASE		(pTSineWave_FiP8->phase)
#define DELTA_PHI	(pTSineWave_FiP8->delta_phi)

/* Variables */
#define PHI			(pTSineWave_FiP8->phi)
/* USERCODE-END:PreProcessor                                                                                          */

/**********************************************************************************************************************/
/** Update                                                                                                           **/
/**********************************************************************************************************************/
void SineWave_FiP8_Update(SINEWAVE_FIP8 *pTSineWave_FiP8)
{
/* USERCODE-BEGIN:UpdateFnc                                                                                           */
	int8 	sine, angle;
	int16	temp;

    /* angle */
    PHI = PHI + DELTA_PHI;
    
	/* phase */
	angle = PHI + PHASE;						/* phi+phase */
    
    /* sine interpolation */
	LOOKUP8(Sin_Table8, angle, sine);			/* sin(phi+phase) */
    
	/* amplification */
	temp  = (int16)AMPLITUDE * (int16)sine;		/* A*sin(phi+phase) */
    temp >>= 7;                                /* Q14 -> Q7 */
	
    /* offset */
	temp += (int16)OFFSET;						/* A*sin(phi+phase) + Offset */
	
    /* output */
	LIMIT(temp, INT8_MAX);                     /* output limitation */
	OUT = (int8)temp;
/* USERCODE-END:UpdateFnc                                                                                             */

}

/**********************************************************************************************************************/
/** Initialization                                                                                                   **/
/**********************************************************************************************************************/
void SineWave_FiP8_Init(SINEWAVE_FIP8 *pTSineWave_FiP8)
{
    pTSineWave_FiP8->ID = SINEWAVE_FIP8_ID;
    pTSineWave_FiP8->u = 0;
/* USERCODE-BEGIN:InitFnc                                                                                             */
    PHI = 0;
/* USERCODE-END:InitFnc                                                                                               */
}

/**********************************************************************************************************************/
/** Load block data                                                                                                  **/
/**********************************************************************************************************************/
uint8 SineWave_FiP8_Load(const SINEWAVE_FIP8 *pTSineWave_FiP8, uint8 data[], uint16 *dataLength, uint16 maxSize)
{
    uint8 error = (uint8)0;
    if ((uint16)4 > maxSize)
    {
        error = (uint8)1;
    }
    else
    {
        data[0] = (uint8)pTSineWave_FiP8->delta_phi;
        data[1] = (uint8)pTSineWave_FiP8->phase;
        data[2] = (uint8)pTSineWave_FiP8->offset;
        data[3] = (uint8)pTSineWave_FiP8->amplitude;
        *dataLength = (uint16)4;
/* USERCODE-BEGIN:LoadFnc                                                                                             */
/* USERCODE-END:LoadFnc                                                                                               */
    }
    return (error);
}

/**********************************************************************************************************************/
/** Save block data                                                                                                  **/
/**********************************************************************************************************************/
uint8 SineWave_FiP8_Save(SINEWAVE_FIP8 *pTSineWave_FiP8, const uint8 data[], uint16 dataLength)
{
    uint8 error;

    if (dataLength != (uint16)4)
    {
        error = (uint8)1;
    }
    else
    {
        pTSineWave_FiP8->delta_phi = UINT8_TO_INT8((uint8)data[0]);
        pTSineWave_FiP8->phase = UINT8_TO_INT8((uint8)data[1]);
        pTSineWave_FiP8->offset = UINT8_TO_INT8((uint8)data[2]);
        pTSineWave_FiP8->amplitude = UINT8_TO_INT8((uint8)data[3]);
        error = (uint8)0;
/* USERCODE-BEGIN:SaveFnc                                                                                             */
/* USERCODE-END:SaveFnc                                                                                               */
    }
    return (error);
}

/**********************************************************************************************************************/
/** Get block element address                                                                                        **/
/**********************************************************************************************************************/
#if !defined(SINEWAVE_FIP8_ISLINKED)
void* SineWave_FiP8_GetAddress(const SINEWAVE_FIP8* block, uint16 elementId)
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
