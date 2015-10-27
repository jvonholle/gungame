#filenames go here
OBJS= main.cpp

#compiler, if you need to add -std=c++11 or whatever here i guess or maybe in COMPILER_FLAGS 
CC= g++

#comp flags like -wall for warnings n shit or -w to turn off warnings
COMPILER_FLAGS= -w

#Link flags for all the sdl libraries needed to compile ex: -lSDL2 -lSDL_mix 
LINKER_FLAGS= -lSDL2

#output name so its not a.out because why not, we're here anyway
OBJ_NAME= gungame

#this compiles all the stuff so I don't have to type it out everytime
all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
