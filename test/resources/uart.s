# https://matrix89.github.io/writes/writes/experiments-in-riscv/
#
# Compile with https://godbolt.org/ (SourceLanguage: C, TargetLanguage: RISC-V (32-bits) gcc (trunk))
#
#
# typedef unsigned char uint8_t;
#
# static volatile uint8_t *uart = (void *)0x10000000;
#
# static int putchar(char ch) {
#     static uint8_t THR    = 0x00;
#     static uint8_t LSR    = 0x05;
#     static uint8_t LSR_RI = 0x40;
#
#     while ((uart[LSR] & LSR_RI) == 0);
#     return uart[THR] = ch;
# }
#
# void puts(char *s) {
#     while (*s) putchar(*s++);
#     putchar('\n');
# }
#
# void enter() {
#     puts("Hello RISC-V");
# }

uart:
        #.word   268435456
        .word   0x10000000
putchar:
        addi    sp,sp,-32
        sw      ra,28(sp)
        sw      s0,24(sp)
        addi    s0,sp,32
        mv      a5,a0
        sb      a5,-17(s0)
        nop
.L2:
        lui     a5,%hi(uart)
        lw      a5,%lo(uart)(a5)
        lui     a4,%hi(LSR.2)
        lbu     a4,%lo(LSR.2)(a4)
        add     a5,a5,a4
        lbu     a5,0(a5)
        andi    a4,a5,0xff
        lui     a5,%hi(LSR_RI.1)
        lbu     a5,%lo(LSR_RI.1)(a5)
        and     a5,a4,a5
        andi    a5,a5,0xff
        beq     a5,zero,.L2
        lui     a5,%hi(uart)
        lw      a5,%lo(uart)(a5)
        lui     a4,%hi(THR.0)
        lbu     a4,%lo(THR.0)(a4)
        add     a4,a5,a4
        lbu     a5,-17(s0)
        sb      a5,0(a4)
        mv      a0,a5
        lw      ra,28(sp)
        lw      s0,24(sp)
        addi    sp,sp,32
        jr      ra
puts:
        addi    sp,sp,-32
        sw      ra,28(sp)
        sw      s0,24(sp)
        addi    s0,sp,32
        sw      a0,-20(s0)
        j       .L5
.L6:
        lw      a5,-20(s0)
        addi    a4,a5,1
        sw      a4,-20(s0)
        lbu     a5,0(a5)
        mv      a0,a5
        call    putchar
.L5:
        lw      a5,-20(s0)
        lbu     a5,0(a5)
        bne     a5,zero,.L6
        li      a0,10
        call    putchar
        nop
        lw      ra,28(sp)
        lw      s0,24(sp)
        addi    sp,sp,32
        jr      ra
.LC0:
        .string "Hello RISC-V"
enter:
        addi    sp,sp,-16
        sw      ra,12(sp)
        sw      s0,8(sp)
        addi    s0,sp,16
        lui     a5,%hi(.LC0)
        addi    a0,a5,%lo(.LC0)
        call    puts
        nop
        lw      ra,12(sp)
        lw      s0,8(sp)
        addi    sp,sp,16
        jr      ra
THR.0:
        .byte   0
LSR.2:
        .byte   5
LSR_RI.1:
        .byte   64