LOGIC_FILES = ./src/app/logic/auth.c ./src/app/logic/events-file.c ./src/app/logic/stats.c ./src/app/logic/money.c
MAIN_FILES = ./src/app/main.c ./src/app/utils.c
FORMS_FILES = ./src/app/forms/forms.c ./src/app/forms/prompts/login.c ./src/app/forms/prompts/main-menu.c ./src/app/forms/prompts/buy-ticket.c ./src/app/forms/prompts/tickets.c ./src/app/forms/prompts/checkout.c

FILES = $(LOGIC_FILES) $(MAIN_FILES) $(FORMS_FILES)

build:
	gcc -o ./out/program.exe -I./src/includes $(FILES)

run:
	./out/program.exe

build-run: build run