#include <delays.h>
#include <p18F4550.h>

#define _XTAL_FREQ 40000000 //frequencia de clock do processador
#define NOP() {_asm nop _endasm} //nop para funcao delay

#define SEMAFORO PORTD //porta de entrada no processador (porta D)

//sequência a ser seguida
#define VERDE1 0b0001001100
#define AMARELO1 0b0001001010
#define VERMELHOTOTAL 0b0001001001
#define VERDE2 0b0001100001
#define AMARELO2 0b0001010001





void delay_ms(unsigned int duration);




void main() {
	
	TRISD = 0x00;
	
	
	while(1){
        SEMAFORO = VERDE1;
        delay_ms(1000);
        SEMAFORO = AMARELO1;
        delay_ms(1000);
        SEMAFORO = VERMELHOTOTAL;
        delay_ms(1000);
        SEMAFORO = VERDE2;
        delay_ms(1000);
        SEMAFORO = AMARELO2;
        delay_ms(1000);
        SEMAFORO = VERMELHOTOTAL;
        delay_ms(1000);
        
	} 

}

//funcao delay
void delay_ms(unsigned int duration) {
	unsigned int i;
	for(;duration!=0;duration--)
	{
		for(i=0;i<=50;i++){
			NOP();
			NOP();
			NOP();
		}
			NOP();
			NOP();
			NOP();
	}
}
