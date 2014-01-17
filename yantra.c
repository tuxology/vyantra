#include <stdio.h>

#define NUM_REGS 4
unsigned regs[NUM_REGS];

/* Spec Sheet

## Instruction Set

------------------
Mnemonic    Opcode
------------------
halt    -   00
mov     -   01
load    -   02
add     -   03
sub     -   04
mul     -   05
div     -   06
and     -   07
not     -   08
jmp     -   09
eq      -   0A
lt      -   0B
le      -   0C
call    -   0D
ret     -   0E
------------------

## Instruction Word

An instruction word is 32 bit long.
First 2 bytes are for the instruction opcode The next byte is the register
number and the remaining bytes are for immediate values. Bits 11-7 are
undefined at the moment.

31   23 19    11          7    0
+------------------------------+
| 01 | 2 | 01 | UNDEFINED | 64 |
+------------------------------+
   |   |    |              |
   |   |    |              +-------> Immediate value
   |   |    |
   |   |    +----------------------> Operating Registers
   |   |
   |   +---------------------------> Load/Store Register
   |
   +-------------------------------> Instruction ()

*/

/* sample program

load B #28      // 0x02000028
load C #2       // 0x02100002
add  A B C      // 0x03201000
halt            // 0x00000000

*/

unsigned program[] = { 0x02000028, 0x02100002, 0x03201000, 0x00000000 };

/* program counter */
int pc = 0;

/* fetch the next word from the program */
int fetch(){
    FILE *fp;
    fp = fopen()
    return program[pc++];
}

/* instruction fields */
int instr_num   = 0;
int r1          = 0;
int r2          = 0;
int r3          = 0;
int val         = 0;

/* decode a word */
void decode(int64_t instr){
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
    showRegs();
}

int main(int argc, const char * argv[]){
    run();
    return 0;
}
