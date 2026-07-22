include ../../.env
export $(shell sed 's/=.*//' ../../.env)

INCLUDE_FLAGS = -I$$INCLUDE_PATH
LIBRARY_FLAGS = -L$$LIB_PATH -lcommon
DEFINE_FLAGS = -DTARGET_PATH="/path/to/file.c" -DSTUB_C_MD5="this_string_will_be_md5_hash_of_stub"
CFLAGS = -Wall -Wextra -Wno-unused-result 

DEBUG_CFLAGS = -g3 -Og -fsanitize=address -DDEBUG
RELEASE_CFLAGS = -O2

OUTDIR = .
TARGET = $(OUTDIR)/test.out
SRCS = dummy.c ../../entrypoint.c

all: CFLAGS += $(RELEASE_CFLAGS)
all: $(TARGET) 

debug: CFLAGS += $(DEBUG_CFLAGS)
debug: $(TARGET) 

$(TARGET): $(SRCS)
	cc -o $(TARGET) $(CFLAGS) $(SRCS) $(INCLUDE_FLAGS) $(LIBRARY_FLAGS) $(DEFINE_FLAGS);

clean:
	rm -f $(OBJS)
	rm $(TARGET)

re: clean all