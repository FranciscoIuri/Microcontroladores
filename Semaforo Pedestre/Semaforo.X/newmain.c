#include <delays.h>
#include <p18F4550.h>


#pragma config WDT = OFF //Desabilita o Watchdog Timer (WDT).
#pragma config PWRT = ON //Habilita o Power-up Timer (PWRT).


#pragma config PBADEN = OFF //RB0,1,2,3 e 4 configurado como I/O digital.
#pragma config LVP = OFF //Desabilita o Low Voltage Program.
#pragma code int_h = 0x000008 //vetor de interrupção de baixa prioridade
#pragma interrupt interrupcao /*define a função INT_EXT0 como rotina de
 ....tratamento da interrupção externa*/



#define _XTAL_FREQ 40000000 //frequencia de clock do processador


#define SEMAFORO PORTD //porta de entrada no processador (porta D)
#define BOTAO PORTBbits.RB0

//sequência a ser seguida
#define VERDE1 0b0001001100
#define AMARELO1 0b0001001010
#define VERMELHOTOTAL 0b0001001001
#define VERDE2 0b0001100001
#define AMARELO2 0b0001010001
#define PEDESTRE 0b0010001001
#define ATENCAO 0b0000001001




void interrupcao(void){
    INTCONbits.INT0IF = 0; //Limpa o flag de interrupção externa
    SEMAFORO = PEDESTRE;
    Delay10KTCYx(200);
    SEMAFORO = ATENCAO;
    Delay10KTCYx(20);
    SEMAFORO = PEDESTRE;
    Delay10KTCYx(20);
    SEMAFORO = ATENCAO;
    Delay10KTCYx(20);
    SEMAFORO = PEDESTRE;
    Delay10KTCYx(20);
}


void main() {
    TRISBbits.TRISB0 = 1; //Configura o pino 0 da porta B como entrada
	TRISD = 0x00;
    //PORTD = 0x00;
    INTCONbits.INT0IE = 1; //Habilita interrupção externa INT0
    INTCON2bits.INTEDG0 = 0; //Habilita interrupção na borda de descida
    INTCONbits.GIE = 1; //Habilita todas as interrupções
    
    
	
	while(1){
        SEMAFORO = VERDE1;
        Delay10KTCYx(100);
        SEMAFORO = AMARELO1;
        Delay10KTCYx(100);
        SEMAFORO = VERMELHOTOTAL;
        Delay10KTCYx(100);
        SEMAFORO = VERDE2;
        Delay10KTCYx(100);
        SEMAFORO = AMARELO2;
        Delay10KTCYx(100);
        SEMAFORO = VERMELHOTOTAL;
        Delay10KTCYx(100);
    
	} 

}



