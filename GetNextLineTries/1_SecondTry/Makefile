# Compiler
CC = gcc

# Compiler flags
CFLAGS = -g -Wall -Wextra

# Source files
SRC = get_next_line.c get_next_line_utils.c main.c

# Output executable
OUTPUT = my_program

# Default rule
all: $(OUTPUT)

# Linking
$(OUTPUT): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Clean rule
clean:
	rm -f $(OUTPUT) *.o

# Phony targets
.PHONY: all clean
