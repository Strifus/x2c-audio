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

/* USERCODE-BEGIN:ExternalModules                                                                                     */
QFormat = Packages.at.lcm.x2c.utils.QFormat;
/* USERCODE-END:ExternalModules                                                                                       */

/* Block sample time                                                                                                  */
/* bp_ts                                                                                                              */

/* Mask parameter values                                                                                              */
/* mp_Amplitude (Number)                                                                                              */
/* mp_Frequency (Number)                                                                                              */
/* mp_Offset (Number)                                                                                                 */
/* mp_Duty (Number)                                                                                                   */
/* mp_ts_fact (Number)                                                                                                */

/* USERCODE-BEGIN:Convert                                                                                             */
BITS = 16;

delta_phi = 2 * bp_ts * mp_Frequency;	// Ts*fmax has to be smaller than 0.5 (Nyquist criteria!), otherwise limitation to 0.5

cp_delta_phi = QFormat.getQValue(delta_phi, BITS - 1, BITS, true);
cp_amplitude = QFormat.getQValue(mp_Amplitude, BITS - 1, BITS, true);
cp_offset = QFormat.getQValue(mp_Offset, BITS - 1, BITS, true);
cp_duty = QFormat.getQValue(mp_Duty/100*2, BITS - 1, BITS, false);
/* USERCODE-END:Convert                                                                                               */

/* Implementation Parameter values                                                                                    */
/* cp_delta_phi                                                                                                       */
/* cp_duty                                                                                                            */
/* cp_offset                                                                                                          */
/* cp_amplitude                                                                                                       */

