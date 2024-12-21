FILES = ./src/app/main.c ./src/app/utils.c ./src/app/forms/forms.c ./src/app/forms/prompts/login.c ./src/app/forms/prompts/main-menu.c

build:
	gcc -o ./out/program.exe -I./src/includes $(FILES)

run:
	./out/program.exe

build-run: build run