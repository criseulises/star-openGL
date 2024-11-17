CC = g++
CFLAGS = -std=c++17 -w
LDFLAGS = -L. -L./lib -lglew32 -lglfw3 -lopengl32 -lgdi32
INCLUDE = -I./includes
SRC = src/main.cpp
OBJ = main.o
EXEC = main.exe  

all:
	$(CC) -c $(SRC) $(INCLUDE) $(CFLAGS)  
	$(CC) $(OBJ) $(LDFLAGS) -o $(EXEC) $(CFLAGS)  

clean:
	del /f $(OBJ) $(EXEC)