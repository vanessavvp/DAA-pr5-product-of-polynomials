TARGET = $(BIN_DIR)/main
OBJ_DIR = ./obj
BIN_DIR = ./bin
INC_DIR = ./include
SRC_DIR = ./src
OBJS =  $(OBJ_DIR)/monomial.o \
		$(OBJ_DIR)/dyvMultiply.o \
		$(OBJ_DIR)/multiplyStrategy.o \
		$(OBJ_DIR)/polynomial.o \
		$(OBJ_DIR)/classicMultiply.o \
		$(OBJ_DIR)/main.o \

CFLAGS = -O2 -I$(INC_DIR)

$(TARGET) : $(OBJS)
		mkdir -p $(BIN_DIR)
		g++ $(CFLAGS) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
  	mkdir -p $(OBJ_DIR)
  	g++ -c $(CFLAGS) $< -o $@

.PHONY: clean