# https://marz.utk.edu/my-courses/cosc230/book/example-risc-v-assembly-programs/

.section .text
.global strlen

strlen:
                        # a0 = const char *str (a0 constains the address of the string input data for which to determine the string length)
    li     t0, 0        # i = 0                                                 (size: 8)  8 pseudo (lui, addi)
                        # initialize the string length to zero
1:                      # Start of for loop
    add    t1, t0, a0   # Add the byte offset for str[i]                        (size: 4) 12
                        # t1 now points to the current character in the string
    lb     t1, 0(t1)    # Dereference str[i]                                    (size: 8) 20
                        # fetch the character from memory into the t1 register
    beqz   t1, 1f       # if str[i] == 0, break for loop                        (size: 4) 24
                        # check for zero termination which marks the end of the string
    addi   t0, t0, 1    # Add 1 to our iterator                                 (size: 4) 28
    j      1b           # Jump back to condition (1 backwards)                  (size: 4) 32
1:                      # End of for loop
    mv     a0, t0       # Move t0 into a0 to return                             (size: 4) 36
                        # place the return value (the string length) into a0
    ret                 # Return back via the return address register