// Code modified/updated by Ryan Sowers
// Submitted: 04/23/2018
// CS4678 Assignment 1
// Assemble:      nasm -f bin assn1.asm
// Compile:       gcc -z execstack -o assn1_harness assn1_harness.c 
// Run:           ./assn1_harness assn1 

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{  
        char code[1024];
        FILE *file;
        size_t data_read;

        file = fopen(argv[1], "rb");
        data_read = fread(code, 1, sizeof(code), file);

        (*(void(*)()) code)();

        return 0;
}