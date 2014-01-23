all: yas yantra

yantra: yantra.o
	gcc -std=gnu99 -g $^ -o $@

yantra.o: yantra.c
	gcc -std=gnu99 -g $< -c -o $@

yas: yas.o
	gcc -std=gnu99 -g $^ -o $@

yas.o: yas.c
	gcc -std=gnu99 -g $< -c -o $@

.PHONY: clean
clean:
	rm -f *.o yas yantra
