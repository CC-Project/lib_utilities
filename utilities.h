#ifndef UTILITIES_H
    #define UTILITIES_H
    #pragma once

    #ifdef __AVR__
        #include "../lib_uart/uart.h"
    #endif
    #include <stdlib.h>
    #include <stdio.h>
    #include <inttypes.h>
    #include <string.h>

    #ifdef __AVR__
        int freeRam(); // Returns the memory available
    #else
        char bin_to_ascii(uint8_t bin);
        uint8_t ascii_to_bin(char bin);
    #endif

    #ifdef DEBUG
        void print_var_bits(uint8_t var);

    #endif
    void error(char* str); // Exit the program with the error code EXIT_FAILED

    uint16_t int_pow(uint16_t a, uint16_t b);   // Computes a^b
    uint8_t opposite_bit(uint8_t bit);
#endif // UTILITIES_H
