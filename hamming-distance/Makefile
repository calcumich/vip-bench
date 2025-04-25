LOCAL_CFLAGS = -I../common
LOCAL_LIBS  =

PROG = hamming-distance
OBJS = hamming-distance.o ../common/utils.o

include ../config.mk
include ../Makefile

test: $(TARGET_EXE)
	-$(TARGET_SIM) ./$(TARGET_EXE) > FOO
	$(TARGET_DIFF) FOO hamming-distance.out
	rm -f FOO
