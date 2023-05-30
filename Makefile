CC := gcc
CFLAGS := -Wall -Wextra $(shell sdl2-config --cflags)
LIBS := $(shell sdl2-config --libs) -lSDL2_image

SRCDIR := cfiles
INCDIR := headers
OBJDIR := obj

SRCS := $(wildcard $(SRCDIR)/**/*.c)
OBJS := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

TARGET := main

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ $(LIBS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TARGET)