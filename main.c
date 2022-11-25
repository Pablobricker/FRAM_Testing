#include <msp430.h>
#include <eUSCIB0_SPI.h>
#include <FRAM_commands.h>


/**
 * main.c
 */
int main(void)
{
	int i = 0;
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	eUSCIB0_SPI_init();
	FRAM_write(0x00,0x90,0x00,4);
	FRAM_read(0x00,0x90,0x00,4); //Escribe 4 bytes en la localidad 0x00000
	while(1){
		//FRAM_read(0x00,0x20,0x00,4); //Escribe 4 bytes en la localidad 0x00000
		for(i=0;i<=300;i++){
			i++;
		}
		i = 0;
	}
}
