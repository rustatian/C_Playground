# Define the compiler
CC = gcc

# Get the includes, library paths and rpath from php-config
PHP_INCLUDES = $(shell php-config --includes)
PHP_LIB_PATH = $(shell php-config --prefix)/lib
PHP_RPATH = -Wl,-rpath,$(PHP_LIB_PATH)

# Define the source and target file
SOURCE = main.c
TARGET = main

# The build target executable
all: $(SOURCE)
	$(CC) $(PHP_INCLUDES) -L$(PHP_LIB_PATH) $(SOURCE) -lphp $(PHP_RPATH) -o $(TARGET)

# Define the clean command
clean:
	rm -f $(TARGET)
