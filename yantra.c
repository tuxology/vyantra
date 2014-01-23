/*
 * yantra.c
 * This is the core of our VM - the translator
 *
 * Inspired by https://en.wikibooks.org/wiki/Creating_a_Virtual_Machine/Register_VM_in_C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_REGS 4
unsigned regs[NUM_REGS];

#define BINARY "./test.yex"
/*unsigned program[] = { 0x02000028, 0x02100002, 0x03201000, 0x00000000 };*/
unsigned insn_buff[1024] = { 0 };

/* program counter */
int pc = 0;

/* fetch the next word from the program */
int fetch(){
    return insn_buff[pc++];
    /*return program[pc++];*/
}

/* Prepare binary */
void prep_binary(char* bin){
    unsigned int i = 0;
    FILE *fp;
    unsigned char insn[4];
    ssize_t read;
    fp = fopen(bin, "rb");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while(read){
        read = fread(&insn, sizeof(insn), 1, fp);
        memcpy(&insn_buff[i], &insn, sizeof(insn));
        i++;
    }
}


/* instruction fields */
int instr_num   = 0;
int r1          = 0;
int r2          = 0;
int r3          = 0;
int val         = 0;

/* decode a word */
void decode(int instr){
    instr_num   = (instr & 0xFF000000) >> 24;
    r1          = (instr & 0x00F00000) >> 20;
    r2          = (instr & 0x000F0000) >> 16;   // For operating on regs
    r3          = (instr & 0x0000F000) >> 12;   // Same as above
    val         = (instr & 0x000000FF);         // Immediate values for loads
}

/* the VM runs until this flag becomes 0 */
int running = 1;

/* evaluate the last decoded instruction */
void eval(){
    switch(instr_num)
    {
        case 0:
            /* halt */
            running = 0;
            break;
        case 1:
            /* move */
            regs[r2] = regs[r3];
            break;
        case 2:
            /* load */
            regs[r1] = val;
            break;
        case 3:
            /* add */
            regs[r1] = regs[r2] + regs[r3];
            break;
        case 4:
            /* sub */
            regs[r1] = regs[r2] - regs[r3];
            break;
        case 5:
            /* mul */
            regs[r1] = regs[r2] * regs[r3];
            break;
        case 6:
            /* div */
            regs[r1] = regs[r2] / regs[r3];
            break;
    }
}

/* display all registers as 4-digit hexadecimal words */
void showRegs(){
    int i;
    printf("regs = ");
    for( i=0; i<NUM_REGS; i++ )
        printf( "%08X ", regs[i]);
    printf( "\n" );
}

void run(){
    while(running){
        showRegs();
        int instr = fetch();
        decode(instr);
        eval();
    }
}

int main(int argc, const char * argv[]){
    prep_binary(BINARY);
    int j = 0;
    run();
    return 0;
}
