.PHONY: test install

CMOCKA_DIR=cmocka-1.1.7
CMOCKA_BUILD_DIR=$(CMOCKA_DIR)/build
CMOCKA_OUT_DIR=$(CMOCKA_BUILD_DIR)/output

all: test

# compile executable that runs all tests
test: unit_tests/main.c \
	../common/common.h \
	../common/common.c \
	../decoder/decoder.h \
	../decoder/decoder.c \
	../encoder/encoder.h \
	../encoder/encoder.c \
	unit_tests/add_encode_test.h \
	unit_tests/add_encode_test.c \
	unit_tests/addi_encode_test.h \
	unit_tests/addi_decode_test.c \
	unit_tests/add_decode_test.h \
	unit_tests/add_decode_test.c \
	unit_tests/beq_decode_test.c \
	unit_tests/beq_decode_test.h \
	unit_tests/beq_encode_test.c \
	unit_tests/beq_encode_test.h \
	unit_tests/call_encode_test.c \
	unit_tests/call_encode_test.h \
	unit_tests/call_decode_test.c \
	unit_tests/call_decode_test.h \
	unit_tests/j_encode_test.c \
	unit_tests/j_encode_test.h \
	unit_tests/j_decode_test.c \
	unit_tests/j_decode_test.h \
	unit_tests/lb_with_offset_test.c \
	unit_tests/lb_with_offset_test.h \
	unit_tests/lw_encode_test.c \
	unit_tests/lw_encode_test.h \
	unit_tests/lw_decode_test.c \
	unit_tests/lw_decode_test.h \
	unit_tests/lui_encode_test.c \
	unit_tests/lui_encode_test.h \
	unit_tests/lui_decode_test.c \
	unit_tests/lui_decode_test.h \
	unit_tests/li_encode_test.c \
	unit_tests/li_encode_test.h \
	unit_tests/li_decode_test.c \
	unit_tests/li_decode_test.h \
	unit_tests/mul_encode_test.c \
	unit_tests/mul_encode_test.h \
	unit_tests/mul_decode_test.c \
	unit_tests/mul_decode_test.h \
	unit_tests/mv_encode_test.c \
	unit_tests/mv_encode_test.h \
	unit_tests/mv_decode_test.c \
	unit_tests/mv_decode_test.h \
	unit_tests/srli_decode_test.c \
	unit_tests/srli_decode_test.h \
	unit_tests/srli_encode_test.c \
	unit_tests/srli_encode_test.h \
	unit_tests/slli_decode_test.c \
	unit_tests/slli_decode_test.h \
	unit_tests/slli_encode_test.c \
	unit_tests/slli_encode_test.h \
	unit_tests/sw_encode_test.c \
	unit_tests/sw_encode_test.h \
	unit_tests/sw_decode_test.c \
	unit_tests/sw_decode_test.h \
	../data/asm_line.c \
	../parser.c \
	../parser.h
	gcc unit_tests/main.c \
	unit_tests/add_encode_test.c \
	unit_tests/add_decode_test.c \
	unit_tests/addi_encode_test.c \
	unit_tests/addi_decode_test.c \
	unit_tests/beq_encode_test.c \
	unit_tests/beq_decode_test.c \
	unit_tests/call_encode_test.c \
	unit_tests/call_decode_test.c \
	unit_tests/j_encode_test.c \
	unit_tests/j_decode_test.c \
	unit_tests/lb_with_offset_test.c \
	unit_tests/lw_encode_test.c \
	unit_tests/lw_decode_test.c \
	unit_tests/lui_encode_test.c \
	unit_tests/lui_decode_test.c \
	unit_tests/li_encode_test.c \
	unit_tests/li_decode_test.c \
	unit_tests/mul_encode_test.c \
	unit_tests/mul_decode_test.c \
	unit_tests/mv_encode_test.c \
	unit_tests/mv_decode_test.c \
	unit_tests/srli_decode_test.c \
	unit_tests/srli_encode_test.c \
	unit_tests/slli_decode_test.c \
	unit_tests/slli_encode_test.c \
	unit_tests/sw_encode_test.c \
	unit_tests/sw_decode_test.c \
	../common/common.c \
	../data/asm_line.c \
	../decoder/decoder.c \
	../encoder/encoder.c \
	../parser.c \
	../lex.yy.c \
	-L./lib -I./ -I./include -I./unit_tests -I../common -I../data -I../encoder -I../decoder -I../ -lcmocka \
	-o cmockatest

# compile mocka libraries
install:
	mkdir -p $(CMOCKA_OUT_DIR)
	cd $(CMOCKA_BUILD_DIR) && \
		 cmake -DWITH_STATIC_LIB=true -DBUILD_SHARED_LIBS=OFF -DCMAKE_INSTALL_PREFIX=$(CMOCKA_OUT_DIR) .. && \
		 make && \
		 make install
	mkdir -p lib include
	cp $(CMOCKA_BUILD_DIR)/$(CMOCKA_DIR)/build/output/lib/libcmocka.a lib
	cp $(CMOCKA_BUILD_DIR)/$(CMOCKA_DIR)/build/output/include/*.h include