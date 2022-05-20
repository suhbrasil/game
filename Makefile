# # this variable will contain the names of all cpp source files
# SRCS:=$(wildcard /src/.cpp)

# # this will contain the names of all intermediate object files
# OBJECTS:=$(patsubst /src/%.cpp,bin/%.o,$(SRCS))

# # $< are the names of all prerequisites (the object files)
# # $@ is the name of the target (obj/myprogram in this case)
# main: $(OBJECTS)
# 	# g++ $^ -o $@ -L./SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
# 	g++ $^ -o $@ -I include -L SFML-2.5.1/lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath ./SFML-2.5.1/lib


# # -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main
# # but now we have to tell make how to build the object files
# # -c option tells g++ to only compile one source file at a tile
# #  $< is the name of the first prerequisite (the cpp file in this case)
# bin/%.o: src/%.cpp
# 	g++ $< -c -o $@ -I./SFML-2.5.1/include

# clean:
# 	rm main -f bin/.o

all: compile link

compile:
	g++ -c src/main.cpp -I./SFML-2.5.1/include -DSFML_STATIC
link:
	g++ bin/main.o -o main -L./SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
clean:
	rm -f main.o
