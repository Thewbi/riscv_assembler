.PHONY: test install

CMOCKA_DIR=cmocka-1.1.7
CMOCKA_BUILD_DIR=$(CMOCKA_DIR)/build
CMOCKA_OUT_DIR=$(CMOCKA_BUILD_DIR)/output

all: test

test: unit_tests/main.c \
	../decoder/decoder.h \
	../encoder/encoder.h \
	unit_tests/add_encode_test.c \
	unit_tests/add_encode_test.h \
	unit_tests/add_decode_test.c \
	unit_tests/addi_encode_test.h \
	unit_tests/addi_decode_test.c \
	unit_tests/add_decode_test.h \
	unit_tests/lb_with_offset_test.c \
	unit_tests/lb_with_offset_test.h \
	../data/asm_line.c \
	../parser.c \
	../parser.h
	gcc unit_tests/main.c \
	unit_tests/add_encode_test.c \
	unit_tests/add_decode_test.c \
	unit_tests/addi_encode_test.c \
	unit_tests/addi_decode_test.c \
	unit_tests/lb_with_offset_test.c \
	../data/asm_line.c \
	../decoder/decoder.c \
	../encoder/encoder.c \
	../parser.c \
	../lex.yy.c \
	-L./lib -I./ -I./include -I./unit_tests -I../data -I../encoder -I../decoder -I../ -lcmocka \
	-o cmockatest

install:
	mkdir -p $(CMOCKA_OUT_DIR)
	cd $(CMOCKA_BUILD_DIR) && \
		 cmake -DWITH_STATIC_LIB=1 -DCMAKE_INSTALL_PREFIX=$(CMOCKA_OUT_DIR) .. && \
		 make && \
		 make install
	mkdir -p lib include
	cp $(CMOCKA_OUT_DIR)/lib/libcmocka.a lib
	cp $(CMOCKA_OUT_DIR)/include/*.h include