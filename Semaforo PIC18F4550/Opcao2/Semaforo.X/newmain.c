#include <delays.h>
#include <p18F4550.h>




#define _XTAL_FREQ 40000000 //clock frequencia processador
#define NOP() {_asm nop _endasm} //nop para funcao delay

#define SEMAFORO PORTDbits 

void delay_ms(unsigned int duration);




void main() {
	
	TRISD = 0x00; //define que será usada a porta  D do processador
	
	
	while(1){
        
		SEMAFORO.RD2 = 1; //RD2 Verde1
		SEMAFORO.RD1 = 0; //RD1 Amarelo1
		SEMAFORO.RD0 = 0; //RD0 vermelho1
		SEMAFORO.RD5 = 0; // RD5 Verde2
		SEMAFORO.RD4 = 0; //RD4 Amarelo2
		SEMAFORO.RD3 = 1; //Vermelho2
		delay_ms(1000);
		
		SEMAFORO.RD2 = 0; //RD2 Verde1
		SEMAFORO.RD1 = 1; //RD1 Amarelo1
		SEMAFORO.RD0 = 0; //RD0 vermelho1
		SEMAFORO.RD5 = 0; // RD5 Verde2
		SEMAFORO.RD4 = 0; //RD4 Amarelo2
		SEMAFORO.RD3 = 1; //Vermelho2
		delay_ms(1000);
		
		SEMAFORO.RD2 = 0; //RD2 Verde1
		SEMAFORO.RD1 = 0; //RD1 Amarelo1
		SEMAFORO.RD0 = 1; //RD0 vermelho1
		SEMAFORO.RD5 = 0; // RD5 Verde2
		SEMAFORO.RD4 = 0; //RD4 Amarelo2
		SEMAFORO.RD3 = 1; //Vermelho2
		delay_ms(1000);
		
		SEMAFORO.RD2 = 0; //RD2 Verde1
		SEMAFORO.RD1 = 0; //RD1 Amarelo1
		SEMAFORO.RD0 = 1; //RD0 vermelho1
		SEMAFORO.RD5 = 1; // RD5 Verde2
		SEMAFORO.RD4 = 0; //RD4 Amarelo2
		SEMAFORO.RD3 = 0; //Vermelho2
		delay_ms(1000);
		
        
		SEMAFORO.RD2 = 0; //RD2 Verde1
		SEMAFORO.RD1 = 0; //RD1 Amarelo1
		SEMAFORO.RD0 = 1; //RD0 vermelho1
		SEMAFORO.RD5 = 0; // RD5 Verde2
		SEMAFORO.RD4 = 1; //RD4 Amarelo2
		SEMAFORO.RD3 = 0; //Vermelho2
		delay_ms(1000);
		
		SEMAFORO.RD2 = 0; //RD2 Verde1
		SEMAFORO.RD1 = 0; //RD1 Amarelo1
		SEMAFORO.RD0 = 1; //RD0 vermelho1
		SEMAFORO.RD5 = 0; // RD5 Verde2
		SEMAFORO.RD4 = 0; //RD4 Amarelo2
		SEMAFORO.RD3 = 1; //Vermelho2
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
