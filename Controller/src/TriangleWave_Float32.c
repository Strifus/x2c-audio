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
#include "TriangleWave_Float32.h"

/* all used update functions to ram for c2000                                                                         */
#if defined(__ALL_UPDATE_FUNC_2_RAM_C2000__)
    #pragma CODE_SECTION(TriangleWave_Float32_Update, "ramfuncs")
#endif

/* USERCODE-BEGIN:PreProcessor                                                                                        */
/* Input */

/* Output */
#define OUT		 	(pTTriangleWave_Float32->u)

/* Parameter */
#define AMPLITUDE	(pTTriangleWave_Float32->amplitude)
#define OFFSET		(pTTriangleWave_Float32->offset)
#define PHASE		(pTTriangleWave_Float32->phase)
#define DELTA_PHI	(pTTriangleWave_Float32->delta_phi)

/* Variables */
#define PHI			(pTTriangleWave_Float32->phi)

/* Macros */
#define PI_1HALF     ((uint32)0x40000000)
#define PI_2HALF     ((uint32)0x80000000)
#define PI_3HALF     (PI_1HALF + PI_2HALF)
/* USERCODE-END:PreProcessor                                                                                          */

/**********************************************************************************************************************/
/** Update                                                                                                           **/
/**********************************************************************************************************************/
void TriangleWave_Float32_Update(TRIANGLEWAVE_FLOAT32 *pTTriangleWave_Float32)
{
/* USERCODE-BEGIN:UpdateFnc                                                                                           */
    int32 angle;
    float32 triangle;
	float32	temp;

    /* angle */
    PHI = PHI + DELTA_PHI;
    
	/* phase */
	angle = PHI + PHASE;						/* phi+phase */
    
    /* calculation of normalized triangle value */
    if ((uint32)angle < PI_1HALF)
    {   
        /* angle is in first quadrant (0..pi/2)*/
        triangle = angle << 1;
    }
    else if ((uint32)angle < PI_2HALF)
    {
        /* angle is in second quadrant (pi/2..pi) */
        triangle = -(angle << 1)-1;
    }
    else if ((uint32)angle < PI_3HALF)
    {
        /* angle is in third quadrant (pi..3/2*pi) */
        triangle = (-INT32_MAX - angle) << 1;
    }
    else
    {
        /* angle is in fourth quadrant (pi..3/2*pi) */
        triangle =  angle << 1;
    }
    
	/* amplification */
	temp  = AMPLITUDE * triangle/(float32)2147483648.0; /* A*triangle(phi+phase) */
	
    /* offset */
	temp += OFFSET;                                     /* A*sin(phi+phase) + Offset */
	
    /* output */
	OUT = temp;
/* USERCODE-END:UpdateFnc                                                                                             */

}

/**********************************************************************************************************************/
/** Initialization                                                                                                   **/
/**********************************************************************************************************************/
void TriangleWave_Float32_Init(TRIANGLEWAVE_FLOAT32 *pTTriangleWave_Float32)
{
    pTTriangleWave_Float32->ID = TRIANGLEWAVE_FLOAT32_ID;
    pTTriangleWave_Float32->u = 0;
/* USERCODE-BEGIN:InitFnc                                                                                             */
    PHI = 0;
/* USERCODE-END:InitFnc                                                                                               */
}

/**********************************************************************************************************************/
/** Load block data                                                                                                  **/
/**********************************************************************************************************************/
uint8 TriangleWave_Float32_Load(const TRIANGLEWAVE_FLOAT32 *pTTriangleWave_Float32, uint8 data[], uint16 *dataLength, uint16 maxSize)
{
    uint8 error = (uint8)0;
    if ((uint16)16 > maxSize)
    {
        error = (uint8)1;
    }
    else
    {
        data[0] = (uint8)(pTTriangleWave_Float32->delta_phi & 0x000000FF);
        data[1] = (uint8)((pTTriangleWave_Float32->delta_phi >> 8) & 0x000000FF);
        data[2] = (uint8)((pTTriangleWave_Float32->delta_phi >> 16) & 0x000000FF);
        data[3] = (uint8)((pTTriangleWave_Float32->delta_phi >> 24) & 0x000000FF);
        data[4] = (uint8)(pTTriangleWave_Float32->phase & 0x000000FF);
        data[5] = (uint8)((pTTriangleWave_Float32->phase >> 8) & 0x000000FF);
        data[6] = (uint8)((pTTriangleWave_Float32->phase >> 16) & 0x000000FF);
        data[7] = (uint8)((pTTriangleWave_Float32->phase >> 24) & 0x000000FF);
        data[8] = (uint8)((*(uint32*)&(pTTriangleWave_Float32->offset)) & 0x000000FF);
        data[9] = (uint8)((*(uint32*)&(pTTriangleWave_Float32->offset) >> 8) & 0x000000FF);
        data[10] = (uint8)((*(uint32*)&(pTTriangleWave_Float32->offset) >> 16) & 0x000000FF);
        data[11] = (uint8)((*(uint32*)&(pTTriangleWave_Float32->offset) >> 24) & 0x000000FF);
        data[12] = (uint8)((*(uint32*)&(pTTriangleWave_Float32->amplitude)) & 0x000000FF);
        data[13] = (uint8)((*(uint32*)&(pTTriangleWave_Float32->amplitude) >> 8) & 0x000000FF);
        data[14] = (uint8)((*(uint32*)&(pTTriangleWave_Float32->amplitude) >> 16) & 0x000000FF);
        data[15] = (uint8)((*(uint32*)&(pTTriangleWave_Float32->amplitude) >> 24) & 0x000000FF);
        *dataLength = (uint16)16;
/* USERCODE-BEGIN:LoadFnc                                                                                             */
/* USERCODE-END:LoadFnc                                                                                               */
    }
    return (error);
}

/**********************************************************************************************************************/
/** Save block data                                                                                                  **/
/**********************************************************************************************************************/
uint8 TriangleWave_Float32_Save(TRIANGLEWAVE_FLOAT32 *pTTriangleWave_Float32, const uint8 data[], uint16 dataLength)
{
    uint8 error;
    uint32 tmp32;

    if (dataLength != (uint16)16)
    {
        error = (uint8)1;
    }
    else
    {
        pTTriangleWave_Float32->delta_phi = UINT32_TO_INT32((uint32)data[0] + \
            ((uint32)data[1] << 8) + ((uint32)data[2] << 16) + \
            ((uint32)data[3] << 24));
        pTTriangleWave_Float32->phase = UINT32_TO_INT32((uint32)data[4] + \
            ((uint32)data[5] << 8) + ((uint32)data[6] << 16) + \
            ((uint32)data[7] << 24));
        tmp32 = (uint32)data[8] + \
            ((uint32)data[9] << 8) + ((uint32)data[10] << 16) + \
            ((uint32)data[11] << 24);
        pTTriangleWave_Float32->offset = (float32)(*(float32*)&tmp32);
        tmp32 = (uint32)data[12] + \
            ((uint32)data[13] << 8) + ((uint32)data[14] << 16) + \
            ((uint32)data[15] << 24);
        pTTriangleWave_Float32->amplitude = (float32)(*(float32*)&tmp32);
        error = (uint8)0;
/* USERCODE-BEGIN:SaveFnc                                                                                             */
/* USERCODE-END:SaveFnc                                                                                               */
    }
    return (error);
}

/**********************************************************************************************************************/
/** Get block element address                                                                                        **/
/**********************************************************************************************************************/
#if !defined(TRIANGLEWAVE_FLOAT32_ISLINKED)
void* TriangleWave_Float32_GetAddress(const TRIANGLEWAVE_FLOAT32* block, uint16 elementId)
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
