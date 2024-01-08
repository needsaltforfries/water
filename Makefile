SRC = $(wildcard *.cpp) $(wildcard **/*.cpp) ./libraries/src/glad.c $(wildcard libraries/src/*.cpp)
OPTIONS = -Wall
TARGET = a.exe
LIBS = glfw3
INCLUDE_PATH = ./libraries/include/

default: build run
	
build:
	g++ $(OPTIONS) -I $(INCLUDE_PATH) $(SRC) -l $(LIBS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)