#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <setjmp.h>
#include <cmocka.h>

#include <add_encode_test.h>
#include <add_decode_test.h>

#include <addi_encode_test.h>
#include <addi_decode_test.h>

#include <beq_encode_test.h>
#include <beq_decode_test.h>

#include <srli_decode_test.h>
#include <srli_encode_test.h>

#include <slli_decode_test.h>
#include <slli_encode_test.h>

#include <lb_with_offset_test.h>

int main(void)
{
    asm_line_t parser_asm_line;

    const struct CMUnitTest tests[] = {

        cmocka_unit_test(add_encode_valid_input_test),
        cmocka_unit_test(add_decode_valid_input_test),
        cmocka_unit_test(add_decode_2_valid_input_test),

        cmocka_unit_test(addi_encode_valid_input_test),
        cmocka_unit_test(addi_decode_valid_input_test),

        cmocka_unit_test(beq_encode_valid_input_test),
        cmocka_unit_test(beq_decode_valid_input_test),

        cmocka_unit_test(ld_with_offset_valid_input_test),

        cmocka_unit_test(srli_encode_valid_input_test),
        cmocka_unit_test(srli_decode_valid_input_test),

        cmocka_unit_test(slli_encode_valid_input_test),
        cmocka_unit_test(slli_decode_valid_input_test)

    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}