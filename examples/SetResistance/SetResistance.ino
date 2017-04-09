/**
 * Simple MCP41xxx Library Example - Set A Resistance
 *
 * First increases resistance from zero to max, and then from max to zero
 * and then repeats, in other words, a fade-up and fade-down.
 * 
 * Wiring:
 * 
 *   MCP41xxx Pin 1 (CS)  => Arduino Pin 10
 *   MCP41xxx Pin 2 (SCK) => Arduino Pin SCK  (13 on Uno/Pro-Mini etc) 
 *   MCP41xxx Pin 3 (SI)  => Arduino Pin MOSI (11 on Uno/Pro-Mini etc)
 *   MCP41xxx Pin 4 (Vss) => Gnd
 *   MCP41xxx Pin 5 (Potentiometer B) => MCP41xxx Pin 6 (Potentiometer Wiper) 
 *   MCP41xxx Pin 6 (Potentiometer Wiper) => Multimeter Common Socket (Multimeter in resistance mode)
 *   MCP41xxx Pin 7 (Potentiometer A) => Multimeter Ohm's Socket  (Multimeter in resistance mode)
 *   MCP41xxx Pin 8 (Vdd) => 5v
 * 
 * Upload sketch and observe the resistance.
 * 
 * Copyright (C) 2017 James Sleeman
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a 
 * copy of this software and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including without limitation 
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the 
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in 
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN 
 * THE SOFTWARE.
 * 
 * @author James Sleeman, http://sparks.gogo.co.nz/
 * @license MIT License
 */

#include <MCP41_Simple.h>

MCP41_Simple MyPot;

// Which pin is connected to CS
const uint8_t  CS_PIN      = 10;

// What is the total nominal resistance
//  note that these chips have about 20% tolerance, so the actual value 
//  could be 20% +/- from the advertised nominal, you can measure and tweak it
//  here.
const float    MAX_RESISTANCE   = 10000;
const uint16_t WIPER_RESISTANCE = 80;

void setup() {
  // put your setup code here, to run once:
  MyPot.begin(CS_PIN);

  uint16_t desiredResistance = 3000;
  
  MyPot.setWiper( ((desiredResistance-WIPER_RESISTANCE)/MAX_RESISTANCE) * 255 );
}

void loop() {
  // Nothing To Do
}