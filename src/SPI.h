/* SPI constants */
extern const int DDR_SPI;
extern const int DD_SS;
extern const int DD_MOSI;
extern const int DD_MISO;
extern const int DD_SCK;

void SPI_MasterInit(void);
void SPI_SlaveInit(void);
void SPI_MasterTransmit(char cData);
char SPI_SlaveRecieve(void);