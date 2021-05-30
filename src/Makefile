CC=gcc
CFLAGS=-Wall -Wformat=0
ODIR=obj
IDIR=../include
LDIR=../lib
PROGRAM=client server

_DEPS = error_functions.o get_num.o inet_sockets.o become_daemon.o
DEPS = $(patsubst %, $(ODIR)/%,$(_DEPS))

all: $(PROGRAM)

# compile
$(ODIR)/%.o: $(LDIR)/%.c
	$(CC) -c -o $@ $<

$(ODIR)/%.o: %.c
	$(CC) -c -o $@ $<

# link

$(PROGRAM): $(patsubst %, $(ODIR)/%,$(addsuffix .o,$(PROGRAM))) $(DEPS)
	$(CC) -o $@ $(ODIR)/$@.o $(DEPS) 

.PHONY: clean
clean: 
	rm $(ODIR)/*.o $(PROGRAM)