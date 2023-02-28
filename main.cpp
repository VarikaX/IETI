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

AnalogIn        Entree1(PA_0);
AnalogIn        Entree2(PA_1);
AnalogIn        Entree3(PA_4);
AnalogIn        Entree4(PB_0);
AnalogIn        Entree5(PC_1);
AnalogIn        Entree6(PC_0);

double meas1, meas2, meas3, meas4, meas5, meas6;

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
        meas1 = Entree1.read();
        meas2 = Entree2.read();
        meas3 = Entree3.read();
        meas4 = Entree4.read();
        meas5 = Entree5.read();
        meas6 = Entree6.read();
        printf("Mesure 1 : %lf\n", meas1);
        printf("Mesure 2 : %lf\n", meas2);
        printf("Mesure 3 : %lf\n", meas3);
        printf("Mesure 4 : %lf\n", meas4);
        printf("Mesure 5 : %lf\n", meas5);
        printf("Mesure 6 : %lf\n", meas6);

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
