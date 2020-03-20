#include <p18F4550.h>
#include<delays.h>

#pragma config FOSC = HS //Configura o oscilador a cristal
#pragma config CPUDIV = OSC1_PLL2
#pragma config WDT = OFF //Desabilita o Watchdog Timer (WDT).
#pragma config PWRT = ON //Habilita o Power-up Timer (PWRT).
#pragma config BOR = ON  //Brown-out Reset (BOR) habilitado somente no hardware.
#pragma config BORV = 1    //Voltagem do BOR é 4,33V.
#pragma config PBADEN = OFF   //RB0,1,2,3 e 4 configurado como I/O digital.
#pragma config LVP = OFF   //Desabilita o Low Voltage Program.

#define botao PORTBbits.RB0
#define display PORTD

//gfedcba
char tabela[10] = {0b0111111, //0
    0b0000110, //1
    0b1011011, //2
    0b1001111, //3
    0b1100110, //4
    0b1101101, //5
    0b1111101, //6
    0b0000111, //7
    0b1111111, //8
    0b1101111 //9
};

int i = 0;

void main(void) {
    TRISB = 0b00000001;
    TRISD = 0b00000000;
    while (1) {
        for (i; i < 10; i++) { //vai até 10, i inicia com 0
            display = tabela[i]; //exibe na porta D 
            Delay10KTCYx(15); 
            if (!botao) { //caso o botão seja pressionado
                for (i; i >= 0; i--) { //assume o valor de i e vai até 0
                    display = tabela[i]; //exibe o valor na porta D
                    Delay10KTCYx(15);
                }
            }
        }
        i=0; //i recebe 0 para exibir novamente a partir do 0
    }
    return;
} 