SRC = $(wildcard *.cpp) $(wildcard **/*.cpp) ./libraries/src/glad.c $(wildcard libraries/src/*.cpp)
OPTIONS = -Wall
TARGET = a.exe
LIBS = -lglfw3 -lglfw3dll -lgdi32
INCLUDE_PATH = ./libraries/include/

default: build run
	
build:
	g++ $(OPTIONS) -I $(INCLUDE_PATH) $(SRC) -L ./libraries/lib/ $(LIBS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)