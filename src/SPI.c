#include<avr/io.h>

/* Define SPI Constants */
const int DDR_SPI = DDRB;
const int DD_SS = DDB4;
const int DD_MOSI = DDB5;
const int DD_MISO = DDB6;
const int DD_SCK = DDB7;

void SPI_MasterInit(void){
	/* Set MOSI and SCK as output */
	DDR_SPI = (1<<DD_MOSI) | (1<<DD_SCK);
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1<<SPE) | (1<<MSTR) | (1<<SPR0);
}

void SPI_SlaveInit(void){
	/* Set MISO as output */
	DDR_SPI = (1<<DD_MISO);
	/* Enable SPI */
	SPCR =  (1<<SPE);
}

void SPI_MasterTransmit(char cData){
	/* Start transmission */
	SPDR = cData;
	/* Wait for transmission complete */
	while( !(SPSR & (1<<SPIF)) ){
		;
	}
}

char SPI_SlaveRecieve(void){
	/* Wait for reception complete */
	while( !(SPSR & 1 (1<<SPIF)) ){
		;
	}
	
	return SPDR;
}
