#ifndef HALUART_H_
#define HALUART_H_

void    Hal_uart_init(void);
void    Hal_uart_put_char(uint8_t ch);
uint8_t Hal_uart_get_char(void);

#endif /* HALUART_H_ */
