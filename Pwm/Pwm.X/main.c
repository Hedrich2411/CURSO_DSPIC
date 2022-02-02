/*
 * File:   main.c
 * Author: Vland
 *
 * Created on 30 January 2022, 19:17
 */


#include <xc.h>
#include "config.h"
#define FCY 4000000UL
#include <libpic30.h>

void PWM_init(void);
int i;

int main() {
    
    TRISB = 0x0000;
    PWM_init();
    
    while(1){
        
        for(i=0;i<=4000;i++){
            P1DC1 = i;
            __delay_ms(10);
        }
        
    }
    return 0;
}

void PWM_init(void){
    
    //FREE RUNNING MODE
    P1TCONbits.PTMOD = 0b00;
    //POSTSCALE 1:1
    P1TCONbits.PTOPS = 0b0000;
    //PRESCALE 1:1
    P1TCONbits.PTCKPS = 0b00;
    //PWM COUNTER = 0
    P1TMR = 0;
    //FPWM-> 2KHz
    P1TPER = 1999;
    //COMPLEMENTARY OUTPUT MODE
    PWM1CON1bits.PMOD1 = 0;
    //HABILITA PWM1H
    PWM1CON1bits.PEN1H = 1;
    PWM1CON1bits.PEN1L = 1;
    PWM1CON2bits.IUE = 1;
    
    P1TCONbits.PTEN = 1;
    P1DC1 = 0;
}