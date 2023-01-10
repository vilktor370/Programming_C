#include <stdint.h>
#include <stdio.h>

int main(){
    uint8_t a = ~0b00001101;
    uint8_t answer = 0b11110010;
    printf("%x, answer: %x, value: %d\n", a,answer, a);
}