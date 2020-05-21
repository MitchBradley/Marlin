/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

#define ADC_VREF_MV  3300

// ESP32 ADCs are quite noisy, even with a good external reference
// and hardware low-pass filtering.  It might be caused by internal
// noise from the WiFi and BT radios.  Whatever the reason, with a
// rock-solid input voltage, consecutive ADC samples can vary by
// quite a bit.  The noise can cause instability in PID loops, as
// they try to correct for short-term temperature variations that
// are not real.
// Marlin's built-in oversampling is not enough to
// account for this because the calculation uses too few bits to
// allow large oversample ratios.  So we do some extra oversampling
// in the ESP32 HAL.  Doubling the ADC_EXTRA_OVERSAMPLE ratio
// halves the noise, roughly.  On my system, with an external
// low-noise regulator for Vref, the temperature jitter at
// ADC_EXTRA_OVERSAMPLING = 1 is about +- 2 degrees C at room
// temperature, while ADC_EXTRA_OVERSAMPLING = 32 results in
// about +- 0.25 C jitter.
#define HAL_ESP32_OVERSAMPLENR 32
#define HAL_ADC_FILTERED