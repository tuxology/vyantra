VYantra
=======

VYantra or Virtual Yantra is a minimalistic virtual machine. 'Yantra' is Sanskrit for a machine.

But why??
---------

Because we want to learn some shit.

Usage
-----

    make
    ./yas test.ys
    ./yantra test.yex

What all can it do
------------------

For now, it justs loads 40 and 2 and adds them to get the answer to life universe and everything. Eventually we plan to make it really useful and not boring as its now

What all it can't do
--------------------

It can't solve any of the real life problems yet. Its like a zygote now - not even an embryo.

Specifications
--------------

### Instruction Set

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

### Instruction Word

An instruction word is 32 bit long. First 2 bytes are for the instruction opcode The next byte is the register number and the remaining bytes are for immediate values. Bits 11-7 are undefined at the moment.

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


### Sample Program

    !start
      load B #28
      load C #2
      add  A B C
      halt
    !end

It will translate to something like -

    unsigned program[] = { 0x02000028, 0x02100002, 0x03201000, 0x00000000 };

