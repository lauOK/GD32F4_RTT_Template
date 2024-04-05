#ifndef _UART0_H
#define _UART0_H

#ifdef __cplusplus
extern "C" {
#endif

int uart0_init(void);
int uart0_print(const char* str);

#ifdef __cplusplus
}
#endif

#endif
