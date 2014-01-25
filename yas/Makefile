LDFLAGS = -lantlr3c
CFLAGS = -g3 -O0

all: main

main: main.o yaslexer.o yasparser.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

main.o: main.c yaslexer.h yasparser.h
yaslexer.o: yaslexer.c yaslexer.h
yasparser.o: yasparser.c yasparser.h

# Generate C files from an ANTLR grammar
%.tokens %.h %.c: %.g
	antlr3 $*.g

# Lexer and parser generation
yaslexer.tokens yaslexer.h yaslexer.c: yaslexer.g
yasparser.tokens yasparser.h yasparser.c: yasparser.g

# To generate the parser, we need to know what tokens the lexer will generate
yasparser.g: yaslexer.tokens


.PHONY: clean

clean:
	rm -f *.tokens *.o main yaslexer.h yaslexer.c yasparser.h yasparser.c

