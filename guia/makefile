INC=inc
SRC=src
BIN=bin
OBJ=obj

$(BIN)/usoguia : $(SRC)/usoguia.cpp 
	g++  -o $@ -I./$(INC) -I./$(SRC) $< 

clean:
	-rm -rf $(BIN)/*

all: clean $(BIN)/usoguia