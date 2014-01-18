all: yas yantra

yantra: yantra.o
	g++ -g $^ -o $@

yantra.o: yantra.c
	g++ -g $< -c -o $@

yas: yas.o
	g++ -g $^ -o $@

yas.o: yas.c
	g++ -g $< -c -o $@

.PHONY: clean
clean:
	rm -f *.o yas yantra
