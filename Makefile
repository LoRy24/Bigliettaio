FILES = ./src/main.c ./src/forms/forms.c

build:
	gcc -o ./out/program.exe -I./src/includes $(FILES)

run:
	./out/program.exe

build-run: build run