DEBUG_FLAGS = -g -O0 -fsanitize=address
RELEASE_FLAGS = -O2
CFLAGS = -Wall -Wextra
LDFLAGS =
OUTDIR = ../../cmd
TARGET = genparam-interpreter
SRCS = main.c arithm-parser.c basic-ds.c
OBJS = ${SRCS:.c=.o}

all: CFLAGS += $(RELEASE_FLAGS)
all: $(TARGET) clean

debug: CFLAGS += $(DEBUG_FLAGS)
debug: LDFLAGS += $(DEBUG_FLAGS)
debug: $(TARGET) clean

$(TARGET): $(OBJS)
	cc -o $(OUTDIR)/$@ $(CFLAGS) $^

clean:
	rm -r *.o