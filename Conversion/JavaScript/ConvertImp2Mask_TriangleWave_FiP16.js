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

/* USERCODE-BEGIN:Description                                                                                         */
/* Description: */
/* USERCODE-END:Description                                                                                           */

/* USERCODE-BEGIN:ExternalModules                                                                                     */
QFormat = Packages.at.lcm.x2c.utils.QFormat;
/* USERCODE-END:ExternalModules                                                                                       */

/* Block sample time                                                                                                  */
/* bp_ts                                                                                                              */

/* Implementation Parameter values                                                                                    */
/* cp_delta_phi                                                                                                       */
/* cp_phase                                                                                                           */
/* cp_offset                                                                                                          */
/* cp_amplitude                                                                                                       */

/* USERCODE-BEGIN:Revert                                                                                              */
BITS = 16;

mp_Frequency = QFormat.getDecValue(cp_delta_phi, BITS -1, BITS, true)/2/bp_ts;
mp_Amplitude = QFormat.getDecValue(cp_amplitude, BITS -1, BITS, true);
mp_Offset = QFormat.getDecValue(cp_offset, BITS -1, BITS, true);
mp_Phase = QFormat.getDecValue(cp_phase, BITS -1, BITS, true)*Math.PI;
/* USERCODE-END:Revert                                                                                                */

/* Mask parameter values                                                                                              */
/* mp_Amplitude (Number)                                                                                              */
/* mp_Frequency (Number)                                                                                              */
/* mp_Offset (Number)                                                                                                 */
/* mp_Phase (Number)                                                                                                  */
/* mp_ts_fact (Number)                                                                                                */

