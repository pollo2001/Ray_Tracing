# Compiler and flags
CC = gcc
CFLAGS = -std=c99 -Wall -I./include -I/opt/homebrew/opt/sdl2/include #for mac M!
 #using c99 and enable all warning with Wall
LDFLAGS = -L/opt/homebrew/lib -lSDL2 #linker flags

# Source files
SRC = src/main.c src/vectors.c src/helpers.c src/ray.c src/shapes.c

# Object files (compiled .c to .o)
OBJ = $(SRC:.c=.o) 

# The target executable
TARGET = RAY_TRACING_PROJECT

# Default target: compile the program
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJ) $(TARGET)
