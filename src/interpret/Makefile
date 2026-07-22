# DEBUG_FLAGS = -g -O0 -fsanitize=address
DEBUG_FLAGS = -g -O0
RELEASE_FLAGS = -O2
CFLAGS = -Wall -Wextra
LDFLAGS =
OUTDIR = ../../cmd
TARGET = genparam-interpreter
SRCS = main.c arithm-parser.c basic-ds.c
OBJS = ${SRCS:.c=.o}

all: CFLAGS += $(RELEASE_FLAGS)
all: $(TARGET) 

debug: CFLAGS += $(DEBUG_FLAGS)
debug: LDFLAGS += $(DEBUG_FLAGS)
debug: $(TARGET) 

$(TARGET): $(OBJS)
	cc -o $(OUTDIR)/$@ $(CFLAGS) $^

clean:
	rm -f $(OBJS)
