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
	rm -rf $(TARGET) bin/*.o -I./SFML-2.5.1/include -DSFML_STATIC

.PHONY: all clean
