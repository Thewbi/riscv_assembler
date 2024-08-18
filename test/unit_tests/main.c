#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include <setjmp.h>
#include <cmocka.h>

#include <add_encode_test.h>
#include <add_decode_test.h>
#include <addi_encode_test.h>
#include <addi_decode_test.h>

int main(void)
{
    asm_line_t parser_asm_line;
    
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(add_encode_valid_input_test),
        cmocka_unit_test(add_decode_valid_input_test),
        cmocka_unit_test(add_decode_2_valid_input_test),
        cmocka_unit_test(addi_encode_valid_input_test),
        cmocka_unit_test(addi_decode_valid_input_test),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}