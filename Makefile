FILES = ./src/main.c ./src/utils.c ./src/forms/forms.c ./src/forms/prompts/login.c

build:
	gcc -o ./out/program.exe -I./src/includes $(FILES)

run:
	./out/program.exe

build-run: build run