include ../../.env
export $(shell sed 's/=.*//' ../../.env)

DEBUG_CFLAGS = -g3 -Og -fsanitize=address -DDEBUG
RELEASE_CFLAGS = -O2
CFLAGS = -Wall -Wextra -Wno-unused-result -I$$INCLUDE_PATH
LDFLAGS = 
DEBUG_LDFLAGS = r
RELEASE_LDFLAGS = rcs
OUTDIR = ../../lib
TARGET = $(OUTDIR)/libcommon.a
SRCS = common.c
OBJS = ${SRCS:.c=.o}

all: CFLAGS += $(RELEASE_CFLAGS)
all: $(TARGET) 

debug: CFLAGS += $(DEBUG_CFLAGS)
debug: $(TARGET) 

$(TARGET): $(OBJS)
	ar rcs $(LDFLAGS) $(TARGET) $(OBJS)

%.o: %.c
	cc -c $(CFLAGS) $^

clean:
	rm -f $(OBJS)
	rm -f $(TARGET)

re: clean all