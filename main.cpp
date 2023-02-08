/****************************************************************************/
/*  Test DMX512 + MOD-24LR / nrf24L01                                       */
/****************************************************************************/
/*  LEnsE / Julien VILLEMEJANE       /   Institut d'Optique Graduate School */
/****************************************************************************/
/*  Brochage                                                                */
/*      TO COMPLETE                                                         */
/****************************************************************************/
/*  Test réalisé sur Nucléo-L476RG                                          */
/****************************************************************************/

#include    "mbed.h"
#include    "DMX_MIDI.h"
#include    "projecteurs.h"
#include    "controleurs.h"

Serial          debug_pc(USBTX, USBRX);
InterruptIn     bp_int(USER_BUTTON);
DigitalOut      debug_out(D13);

// Main
int main() {
    debug_pc.baud(115200);
    debug_pc.printf("Test\r\n");
    
    // Initialisation périphériques
    initDMX();
    initMIDI();
    //initMIDI2();
    initProjectors();
    //initController();
    
    dmx_data[0] = 150;
    dmx_data[1] = 255;
    dmx_data[2] = 100;
    dmx_data[3] = 0;
    dmx_data[4] = 0;
    dmx_data[5] = 0;
    dmx_data[6] = 0;

    dmx_data[8] = 150;
    dmx_data[9] = 255;
    dmx_data[10] = 100;
    dmx_data[11] = 0;
    dmx_data[12] = 0;
    dmx_data[13] = 0;
    dmx_data[14] = 0;

    dmx_data[16] = 150;
    dmx_data[17] = 255;
    dmx_data[18] = 100;
    dmx_data[19] = 0;
    dmx_data[20] = 0;
    dmx_data[21] = 0;
    dmx_data[22] = 0;

    dmx_data[24] = 150;
    dmx_data[25] = 255;
    dmx_data[26] = 100;
    dmx_data[27] = 0;
    dmx_data[28] = 0;
    dmx_data[29] = 0;
    dmx_data[30] = 0;


    while(1) { 
        /* MIDI */
        if(isNoteMIDIdetected()){
            //updateProjFromMidi(note_data);
            playNoteMIDI2(note_data, velocity_data);
            if(note_data == 0x3C){
                dmx_data[4] = 2*velocity_data;
                dmx_data[5] = 0;
                dmx_data[6] = 0;
            }
            if(note_data == 0x3E){
                dmx_data[4] = 0;
                dmx_data[5] = velocity_data;
                dmx_data[6] = 0;
            }
            printf("Ca marche");                
            resetNoteMIDI();
        }
        
        if(isCCMIDIdetected()){
            playNoteMIDI2(control_ch,control_value);
            if(control_ch == 1){
                dmx_data[4] = 2 * control_value;
                dmx_data[12] = 2 * control_value;
            }
            resetCCMIDI();
        }
        
        updateDMX();
        wait_us(1000);
    }
}

