#include <msp430.h>
#include <eUSCIB0_SPI.h>
#include <FRAM_commands.h>


/**
 * main.c
 */

//Pendiente desarrollar funcion de borrado
//no es necesario modificar el eUSCI0_SPI
//Checar datasheet de la FRAM cypres
int main(void)
{
    int FRAM_dataW[]={0x10,0x20,0x30,0x40};
    int FRAM_WdataSize = sizeof(FRAM_dataW)/sizeof(FRAM_dataW[0]);  //sizeof(FRAM_dataW/FRAM_dataW[0]);
    uint16_t FRAM_dataR[4];
    int FRAM_RdataSize = sizeof(FRAM_dataR)/sizeof(FRAM_dataR[0]);  //sizeof(FRAM_dataR/FRAM_dataR[0]);
    //FRAM_RdataSize =4;
	int t = 0;
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	eUSCIB0_SPI_init();
	FRAM_write(0x00,0x90,0x00,FRAM_dataW,FRAM_WdataSize);
	FRAM_read(0x00,0x90,0x00,FRAM_dataR,FRAM_RdataSize); //Escribe 4 bytes en la localidad 0x00000
	while(1){
		//FRAM_read(0x00,0x20,0x00,4); //Escribe 4 bytes en la localidad 0x00000
		for(t=0;t<=300;t++){
			t++;
		}
		t = 0;
	}
}
