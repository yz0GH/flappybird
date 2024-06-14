all:
	cc src/main.c -o output/main -Wall -lm -lSDL2
	./output/main
