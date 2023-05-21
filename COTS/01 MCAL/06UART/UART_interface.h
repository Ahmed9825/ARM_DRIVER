





void UART_init() ;
//enable transmitter
void UART_enableTX(void) ;

void UART_disableTX(void) ;
//enable receiver
void UART_enableRX(void) ;

void UART_disableRX(void) ;
//transmit data
void UART_TXdata(u8 data) ;
//receive data
void UART_RXdata (u8 *data)  ;
void UART1_voidSendString(u8 *  str) ;

u8 * const UART1_StrReceiveString() ;
