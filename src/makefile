OBJS = main.cpp controller.cpp gui.cpp rocket.cpp

HEADERS =  -I./headers
OBJ_NAME = ./debug/test
INCLUDE = -IC:\MinGW\i686-w64-mingw32\include
LIBRARY = -LC:\MinGW\i686-w64-mingw32\lib
THEL = -lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_ttf

all : $(OBJS)
	g++ $(OBJS) $(HEADERS) $(INCLUDE) $(LIBRARY) $(THEL) -o $(OBJ_NAME)
