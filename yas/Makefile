LDFLAGS = -lantlr3c
CFLAGS = -g3 -O0

all: main

main: main.o yaslexer.o yasparser.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

main.o: main.c
main.c: yaslexer.h yasparser.h
yaslexer.o: yaslexer.c
yasparser.o: yasparser.c

yaslexer.h yaslexer.c: yaslexer.g
	antlr3 yaslexer.g


yasparser.h yasparser.c: yasparser.g
	antlr3 yasparser.g

.PHONY: clean

clean:
	rm -f *.tokens *.o main yaslexer.h yaslexer.c yasparser.h yasparser.c

