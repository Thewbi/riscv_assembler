        .global loadb, loadh, loadw, loadd

        .text
loadb:  lb      a0, byte            # load a byte
#        ret
#loadh:  lh      a0, hword           # load half word
#        ret
#loadw:  lw      a0, word            # load a word
#        ret
#loadd:  lw      a0, dword           # load lower word of dword
#        lw      a1, dword+4         # load upper word of dword
#        ret                         # return value in a0

        .data
#byte:   .byte   1
#hword:  .half   0xF509
#word:   .word   0x0708090A
#dword:  .dword  0xCCBBAA99887766