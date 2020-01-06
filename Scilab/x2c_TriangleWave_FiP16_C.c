// This file was generated by createCFunction.sci on 06-01-2020 12:06

// Computational function for X2C block TriangleWave

#define SCILAB_SIM_FILE /* mark this file as Scilab simulation file */

/* include Scicos / Xcos headers */
#include <scicos.h>
#include <scicos_block4.h>
#include <scicos_malloc.h>
#include <scicos_free.h>
#include <Simulation_PortConversion.h>
//#define DEBUG // uncomment to enable debugging
#ifdef DEBUG
    #include <stdio.h>
#endif

/* include block implementation */
#include <TriangleWave_FiP16.h>
#include <TriangleWave_FiP16.c>

/* */
#define BLOCK_ERROR_INPUT_OUT_OF_DOMAIN (-1)
#define BLOCK_ERROR_SINGULARITY (-2)
#define BLOCK_ERROR_INTERNAL (-3)
#define BLOCK_ERROR_CANNOT_ALLOCATE_MEMORY (-16)

/* */
void x2c_TriangleWave_FiP16_C(scicos_block* block, scicos_flag flag);
static void x2c_TriangleWave_FiP16_C__OutputUpdate(scicos_block* block);
static void x2c_TriangleWave_FiP16_C__StateUpdate(scicos_block* block);
static void x2c_TriangleWave_FiP16_C__Initialization(scicos_block* block);
static void x2c_TriangleWave_FiP16_C__Ending(scicos_block* block);


void x2c_TriangleWave_FiP16_C(scicos_block* block, scicos_flag flag) {
    /*
     * This function will be called by Xcos
     */
    switch (flag) {
        case DerivativeState:  /* 0 */
        {
            break;
        }
        case OutputUpdate:     /* 1 */
        {
            x2c_TriangleWave_FiP16_C__OutputUpdate(block);
            break;
        }
        case StateUpdate:      /* 2 */
        {
            x2c_TriangleWave_FiP16_C__StateUpdate(block);
            break;
        }
        case OutputEventTiming: /* 3 */
        {
            break;
        }
        case Initialization:   /* 4 */
        {
            x2c_TriangleWave_FiP16_C__Initialization(block);
            break;
        }
        case Ending:           /* 5 */
        {
            x2c_TriangleWave_FiP16_C__Ending(block);
            break;
        }
        case ReInitialization: /* 6 */
        {
            break;
        }
        case ZeroCrossing:     /* 9 */
        {
           break;
        }
        default:     /* ContinousPropertiesUpdate (v5.5.x) Jacobian (v5.5.x) or Residute (v5.4.1) or something else */
        {
           break;
        }
    }
}


static void x2c_TriangleWave_FiP16_C__set_parameter(scicos_block* block, TRIANGLEWAVE_FIP16 *blockParam) {
    int *paramI;
    double *paramR;
    TRIANGLEWAVE_FIP16 *pTTriangleWave_FiP16;
    
    /* *** */
    paramI = GetIparPtrs(block);  /* integer parameters  */
    paramR = GetRparPtrs(block);  /* real parameters     */
    pTTriangleWave_FiP16 = GetWorkPtrs(block);
    blockParam->delta_phi = (int16)paramI[0];
    blockParam->phase = (int16)paramI[1];
    blockParam->offset = (int16)paramI[2];
    blockParam->amplitude = (int16)paramI[3];
}


static void x2c_TriangleWave_FiP16_C__Initialization(scicos_block* block) {
    TRIANGLEWAVE_FIP16 *pTTriangleWave_FiP16;
    int16 arrayStart = 0;

    /* Declaration of inports */

    /* Declaration of outports */
    double *outport_u;

    /* *** */
    pTTriangleWave_FiP16 = scicos_malloc(sizeof(TRIANGLEWAVE_FIP16));
    GetWorkPtrs(block) = pTTriangleWave_FiP16;
    x2c_TriangleWave_FiP16_C__set_parameter(block, pTTriangleWave_FiP16);

    /* Assignment of inports */

    /* Assignment of parameter arrays */
    arrayStart = 0;

    /* Initialization */
    TriangleWave_FiP16_Init(pTTriangleWave_FiP16);

    /* Assignment of outports */
    outport_u = GetOutPortPtrs(block, 1);
    *outport_u = convert_Q15_to_double(pTTriangleWave_FiP16->u);
}


static void x2c_TriangleWave_FiP16_C__Ending(scicos_block* block) {
    TRIANGLEWAVE_FIP16 *pTTriangleWave_FiP16;
    pTTriangleWave_FiP16 = GetWorkPtrs(block);
    scicos_free(pTTriangleWave_FiP16);
}


static void x2c_TriangleWave_FiP16_C__StateUpdate_f(scicos_block* block) {
/* Do nothing, calling of update function and writing to outputs is done in OutputUpdate */
}


static void x2c_TriangleWave_FiP16_C__StateUpdate(scicos_block* block) {
    if (GetNevIn(block) > 0) {
        /*
        * GetNevIn(block) returns -1 in case this function was called due to an internal zero-crossing.
        * GetNevIn(block)  ... activation index
        */
        x2c_TriangleWave_FiP16_C__StateUpdate_f(block);
    }
}


static void x2c_TriangleWave_FiP16_C__OutputUpdate(scicos_block* block) {
    TRIANGLEWAVE_FIP16 *pTTriangleWave_FiP16;
    int16 arrayStart = 0;

    /* Declaration of inports */

    /* Declaration of outports */
    double *outport_u;

    /* *** */
    pTTriangleWave_FiP16 = GetWorkPtrs(block);

    /* Assignment of inports */

    /* Assignment of parameter arrays */

    /* Update */
    TriangleWave_FiP16_Update(pTTriangleWave_FiP16);

    /* Assignment of outports */
    outport_u = GetOutPortPtrs(block, 1);
    *outport_u = convert_Q15_to_double(pTTriangleWave_FiP16->u);
}


