#include "utilities.h"

#ifdef __AVR__
    int freeRam()
    {
      extern int __heap_start, *__brkval;
      int v;
      return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
    }
#else
    char bin_to_ascii(uint8_t bin)
    {
        if (bin)
            return 49; //'1'
        else
            return 48; //'0'
    }

    uint8_t ascii_to_bin(char bin)
    {
        if (bin == 48)
            return 0;
        else
            return 1;
    }
#endif

#ifdef DEBUG
    void print_var_bits(uint16_t var, uint8_t n)
    {
        #ifdef __AVR__
            uart_tx_str("0b");
            for(int8_t i = 1; i <= n; i++)
                uart_tx_char((var >> (n - i)) & 1 + 0x30); // 0x30 is the offset needed to print the appropriate number
        #else
            printf("0b");
            for(int8_t i = 1; i <= n; i++)
                printf("%d", (var >> (n - i)) & 1);
        #endif
    }


    void error(char* str)
    {
        #ifdef __AVR__
            uart_tx_str(str);
            uart_newline();
        #else
            fprintf(stderr, str);
            fprintf(stderr, "\r\n"); // New line
        #endif // __AVR__
    }
#endif

uint16_t int_pow(uint16_t a, uint16_t b)
{
    uint16_t r = 1;

    for(uint16_t i = 0; i < b; i++)
        r = r * a;

    return r;
}
