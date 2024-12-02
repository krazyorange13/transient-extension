OBJ_FILES = src/main.o src/graphics.o
TARGET = out

BUILDDIR = build
BUILD_DIRS = $(shell find build/ -type d)
BUILD_FILES = $(shell find build/ -type f -name "*")

WFLAGS = -Wall -Wextra -Wno-unused-command-line-argument
IFLAGS = -Isrc/
LFLAGS = -ltransientfoundation
MFLAGS = -Ofast -march=native
FLAGS = $(IFLAGS) $(LFLAGS) $(WFLAGS) $(MFLAGS)

# TODO: check if this is right
ifeq ($(PREFIX),)
	PREFIX = /usr/local
endif

$(TARGET): $(OBJ_FILES)
	gcc -o $(TARGET) $(OBJ_FILES) $(FLAGS)

$(OBJ_FILES): %.o: %.c
	gcc -c $^ -o $@ $(FLAGS)

clean:
	rm -rf src/*.o
	rm -rf *.o
	rm -rf libtransientextension.a

build: $(OBJ_FILES)
	mkdir -p build
	ar -rcs build/libtransientextension.a $(OBJ_FILES)
	cp src/*.h build/transientextension/

install: $(BUILD_DIRS) $(BUILD_FILES)
	mkdir -p $(PREFIX)/include/transientextension
	cp build/*.a $(PREFIX)/lib
	cp build/transientextension/*.h $(PREFIX)/include/transientextension
