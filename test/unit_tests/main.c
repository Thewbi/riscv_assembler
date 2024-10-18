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

#include <j_encode_test.h>
#include <j_decode_test.h>

#include <lw_encode_test.h>
#include <lw_decode_test.h>

#include <lui_encode_test.h>
#include <lui_decode_test.h>

#include <li_encode_test.h>
#include <li_decode_test.h>

#include <mul_encode_test.h>
#include <mul_decode_test.h>

#include <mv_encode_test.h>
#include <mv_decode_test.h>

#include <srli_decode_test.h>
#include <srli_encode_test.h>

#include <slli_decode_test.h>
#include <slli_encode_test.h>

#include <sw_encode_test.h>
#include <sw_decode_test.h>

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

        cmocka_unit_test(lui_encode_valid_input_test),
        cmocka_unit_test(lui_decode_valid_input_test),

        cmocka_unit_test(li_encode_valid_input_test),
        cmocka_unit_test(li_decode_valid_input_test),

        cmocka_unit_test(j_encode_valid_input_test),
        cmocka_unit_test(j_decode_valid_input_test),

        cmocka_unit_test(lw_encode_valid_input_test),
        cmocka_unit_test(lw_decode_valid_input_test),

        cmocka_unit_test(mul_encode_valid_input_test),
        cmocka_unit_test(mul_decode_valid_input_test),

        cmocka_unit_test(mv_encode_valid_input_test),
        cmocka_unit_test(mv_decode_valid_input_test),

        cmocka_unit_test(srli_encode_valid_input_test),
        cmocka_unit_test(srli_decode_valid_input_test),

        cmocka_unit_test(slli_encode_valid_input_test),
        cmocka_unit_test(slli_decode_valid_input_test),

        cmocka_unit_test(sw_encode_valid_input_test),
        cmocka_unit_test(sw_decode_valid_input_test)

    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}