INC=inc
SRC=src
BIN=bin
OBJ=obj

$(BIN)/usoguia : $(SRC)/usoguia.cpp
	g++ -g -o $@ $< -I./$(INC)


clean:
	-rm -rf $(BIN)/*

all: clean $(BIN)/usoguia

documentacion:
	doxygen doc/Doxyfile