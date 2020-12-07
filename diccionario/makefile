INC=inc
SRC=src
BIN=bin
OBJ=obj

$(BIN)/usodiccionario: $(SRC)/usodiccionario.cpp
	g++ -g -o $@ $< -I./$(INC) -I./$(SRC)

clean: 
	-rm -f $(BIN)/usodiccionario

all: clean $(BIN)/usodiccionario