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
#include    "nRF24.h"
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
    
    /* Initialisation comm nRF24 - nécessite l'extension MIDI */
    //initNRF24();
    
    // Initialisation périphériques
    initDMX();
    initMIDI();
    //initMIDI2();
    //initProjectors();
    //initController();
    
    dmx_data[0] = 0;
    dmx_data[3] = 255;
    dmx_data[4] = 255;
    dmx_data[5] = 100;
    dmx_data[6] = 50;

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
        wait_us(10000);
        
    }
}

