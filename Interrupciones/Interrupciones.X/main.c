/*
 * File:   main.c
 * Author: Vland
 *
 * Created on 29 December 2021, 22:06
 */


#include "xc.h"
#include "config.h"
#define FCY 4000000UL
#define SUBIDA 0
#define BAJADA 1

void Init_Interrup_cero(uint8_t flanco);
void Init_Interrup_one(uint8_t flanco);
void Init_Interrup_two(uint8_t flanco);

int main(void) {
        
    AD1PCFGL = 0xFFFF; //Entradas digitales
    TRISB = 0; //Puerto B -> Salida
    
    Init_Interrup_cero(SUBIDA);
    Init_Interrup_one(SUBIDA);
    Init_Interrup_two(SUBIDA);
    
    while(1){
        
        
    }
    
    return 0;
}

void Init_Interrup_cero(uint8_t flanco){

    TRISBbits.TRISB7 = 1; //Pin como entrada
    INTCON2bits.INT0EP=flanco;//Flanco de interrupción
    IPC0bits.INT0IP=1;// Prioridad 1
    IEC0bits.INT0IE=1;// Activamos interrupcion
    IFS0bits.INT0IF=0;// Bandera en 0

}


void Init_Interrup_one(uint8_t flanco){
    //Map Pin
    RPINR0bits.INT1R=0b01000;//INT1->RB8
    TRISBbits.TRISB8=1; //RB8 -> entrada
    
    INTCON2bits.INT1EP=flanco;//Flanco de interrupción
    IPC5bits.INT1IP=2;//Prioridad 2
    IEC1bits.INT1IE=1;//Activamos interrupcion
    IFS1bits.INT1IF=0;//Bandera en 0

}

void Init_Interrup_two(uint8_t flanco){
    //Map Pin
    RPINR1bits.INT2R=0B01001;//INT1->RB9
    TRISBbits.TRISB9=1; //RB9 -> entrada
    
    INTCON2bits.INT2EP=flanco;//Flanco de interrupción
    IPC7bits.INT2IP=3;//Prioridad 3
    IEC1bits.INT2IE=1;//Activamos interrupcion
    IFS1bits.INT2IF=0;//Bandera en 0

}



void __attribute__(( __interrupt__,no_auto_psv))_INT0Interrupt(void)
{
    IFS0bits.INT0IF=0;//Limpiamos bandera
    LATBbits.LATB0 = ~(LATBbits.LATB0);
    
}

    void __attribute__(( __interrupt__,no_auto_psv))_INT1Interrupt(void)
{
    IFS1bits.INT1IF=0;//Limpiamos bandera
    LATBbits.LATB1 = ~(LATBbits.LATB1);
  
} 
    
    void __attribute__(( __interrupt__,no_auto_psv))_INT2Interrupt(void)
{
    IFS1bits.INT2IF=0;//Limpiamos bandera
    LATBbits.LATB2 = ~(LATBbits.LATB2);
  
} 