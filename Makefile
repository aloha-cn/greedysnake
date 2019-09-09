CC=gcc

CFLAGS += -O2 -Wall

LIBS =
#LIBS += -lrt

OBJS += snake.o main.o

LDFLAGS =

all: snake

snake: $(OBJS)
	$(CC) $(LDFLAGS) -o snake $(OBJS) $(LIBS)

%.o: %.c
	$(CC) -c -o $@ $(CFLAGS) $<

install: $(addprefix $(DESTDIR)$(BINDIR)/,$(ALL))

clean:
	rm -f core ./*~ ./*.o snake

