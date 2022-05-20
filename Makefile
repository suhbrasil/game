CC := g++
TARGET := main

# $(wildcard *.cpp /xxx/xxx/*.cpp): get all .cpp files from the current directory and dir "/xxx/xxx/"
SRCS := $(wildcard src/*.cpp)
# $(patsubst %.cpp,%.o,$(SRCS)): substitute all ".cpp" file name strings to ".o" file name strings
OBJS := $(patsubst src/%.cpp,bin/%.o,$(SRCS))

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ -L./SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
bin/%.o: src/%.cpp
	$(CC) $< -c -o $@ -I./SFML-2.5.1/include -DSFML_STATIC
clean:
	rm -rf $(TARGET) *.o -I./SFML-2.5.1/include -DSFML_STATIC

.PHONY: all clean




# # this variable will contain the names of all cpp source files
# SRCS:=$(wildcard src/.cpp)

# # this will contain the names of all intermediate object files
# OBJECTS:=$(patsubst src/%.cpp,bin/%.o,$(SRCS))

# # $< are the names of all prerequisites (the object files)
# # $@ is the name of the target (obj/myprogram in this case)
# main.exe: $(OBJECTS)
#     g++ $^ -o $@ -L./SFML-2.5.1/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main

# # but now we have to tell make how to build the object files
# # -c option tells g++ to only compile one source file at a tile
# #  $< is the name of the first prerequisite (the cpp file in this case)
# bin/%.o: src/%.cpp
#     g++ $< -c -o $@ -I./SFML-2.5.1/include -DSFML_STATIC

# clean:
#     rm main.exe -f bin/.o
