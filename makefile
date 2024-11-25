OBJ_FILES = src/main.o src/graphics.o
TARGET = out

INCLUDE_DIRS = $(shell find include/ -type d)
INCLUDE_FILES = $(shell find include/ -type f -name "*")
LIB_FILES = $(shell find lib/ -type f -name "*")

WFLAGS = -Wall -Wextra -Wno-unused-command-line-argument
IFLAGS = -Isrc/ -Iinclude/
LFLAGS = -Llib/ -ltransientfoundation
MFLAGS = -Ofast -march=native
FLAGS = $(IFLAGS) $(LFLAGS) $(WFLAGS) $(MFLAGS)

$(TARGET): $(OBJ_FILES) $(INCLUDE_DIRS) $(INCLUDE_FILES) $(LIB_FILES)
	gcc -o $(TARGET) $(OBJ_FILES) $(FLAGS)

$(OBJ_FILES): %.o: %.c
	gcc -c $^ -o $@ $(FLAGS)

clean:
	rm -rf src/*.o
	rm -rf *.o
	rm -rf libtransientextension.a

build: $(OBJ_FILES)
	ar -rcs build/libtransientextension.a $(OBJ_FILES)
	cp src/*.h build/transientextension/
