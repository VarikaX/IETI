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

//TEST

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
    
    dmx_data[32] = 150;
    dmx_data[33] = 255;
    dmx_data[34] = 100;
    dmx_data[35] = 0;
    dmx_data[36] = 0;
    dmx_data[37] = 0;
    dmx_data[38] = 0;

    dmx_data[40] = 150;
    dmx_data[41] = 255;
    dmx_data[42] = 100;
    dmx_data[43] = 0;
    dmx_data[44] = 0;
    dmx_data[45] = 0;
    dmx_data[46] = 0;

    dmx_data[48] = 150;
    dmx_data[49] = 255;
    dmx_data[50] = 100;
    dmx_data[51] = 0;
    dmx_data[52] = 0;
    dmx_data[53] = 0;
    dmx_data[54] = 0;

    dmx_data[56] = 150;
    dmx_data[57] = 255;
    dmx_data[58] = 100;
    dmx_data[59] = 0;
    dmx_data[60] = 0;
    dmx_data[61] = 0;
    dmx_data[62] = 0;

    while(1)
    {
        wait_us(1000000);
    }



//    while(1) { 
//        /* MIDI */
//        if(isNoteMIDIdetected()){
//            //updateProjFromMidi(note_data);
//            playNoteMIDI2(note_data, velocity_data);
//            if(note_data == 0x3C){
//                dmx_data[4] = 2*velocity_data;
//                dmx_data[5] = 0;
//                dmx_data[6] = 0;
//            }
//            if(note_data == 0x3E){
//                dmx_data[4] = 0;
//                dmx_data[5] = velocity_data;
//                dmx_data[6] = 0;
//            }
//            printf("Ca marche");                
//           resetNoteMIDI();
//        }
//        
//        if(isCCMIDIdetected()){
//            playNoteMIDI2(control_ch,control_value);
//            if(control_ch == 1){
//                dmx_data[4] = 2 * control_value;
//                dmx_data[12] = 2 * control_value;
//            }
//           resetCCMIDI();
//        }
//        
//        updateDMX();
//        wait_us(1000);
//    }
}
