CC=gcc
CFLAGS=-I. -Iinclude
IDIR =./include

_DEPS = main.h utils.h image.h color.h mandelbrot.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS)) config.h

_OBJ = main.o utils.o image.o color.o mandelbrot.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

ODIR=dist
LIBS=-lpng

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/mandelbrot: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*

$(shell mkdir -p $(ODIR))