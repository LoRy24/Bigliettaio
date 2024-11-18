build:
	gcc -o ./out/program.exe ./src/main.c

run:
	./out/program.exe

build-run: build run