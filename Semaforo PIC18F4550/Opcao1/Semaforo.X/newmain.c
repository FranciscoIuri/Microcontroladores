#include <delays.h>
#include <p18F4550.h>

#define _XTAL_FREQ 40000000 //frequencia de clock do processador

#define SEMAFORO PORTD //porta de entrada no processador (porta D)

//sequência a ser seguida
#define VERDE1 0b0001001100
#define AMARELO1 0b0001001010
#define VERMELHOTOTAL 0b0001001001
#define VERDE2 0b0001100001
#define AMARELO2 0b0001010001




void main() {
	
	TRISD = 0x00;
	
	
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

