SRC = src/journal.c\
src/main.c

INC = -Iinclude\

PROJECT_NAME = journal.out

$(PROJECT_NAME): $(SRC)
	gcc $(SRC) $(INC) -o $(PROJECT_NAME)

run:$(PROJECT_NAME)
	./${PROJECT_NAME}
