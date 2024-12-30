FILES = ./src/app/main.c ./src/app/utils.c ./src/app/forms/forms.c ./src/app/forms/prompts/login.c ./src/app/forms/prompts/main-menu.c ./src/app/logic/auth.c ./src/app/logic/money.c ./src/app/forms/prompts/tickets.c

build:
	gcc -o ./out/program.exe -I./src/includes $(FILES)

run:
	./out/program.exe

build-run: build run