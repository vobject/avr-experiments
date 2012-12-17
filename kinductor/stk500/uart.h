#ifndef UART_H
#define UART_H

#include <stdint.h>
#include <stdbool.h>

#define BAUD         (38400UL)
#define UBRR_VAL     ((F_CPU + BAUD * 8) / (BAUD * 16) - 1)
#define BAUD_REAL    (F_CPU / (16 * (UBRR_VAL + 1)))
#define BAUD_ERROR   ((BAUD_REAL * 1000) / BAUD)

#if ((BAUD_ERROR < 990) || (BAUD_ERROR > 1010))
#error systemastic baud rate error rate higher than 1%!
#endif

void uart_init(void);
bool uart_has_input(void);
uint8_t uart_read(void);

#endif /* UART_H */