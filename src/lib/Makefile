include ../../.env
export $(shell sed 's/=.*//' ../../.env)

common:	common.o
	ar rcs libcommon.a common.o

common.o: common.c
	cc -c -o common.o -Wall -Wextra -Werror common.c -I$$INCLUDE_PATH

clean:
	rm *.o *.a
