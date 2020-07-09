#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Input_Buffer_t {
    char *buffer;
    size_t buffer_lenght;
    ssize_t input_lenght;
};

typedef struct Input_Buffer_t InputBuffer;

InputBuffer *newInputBuffer() {
    InputBuffer *input_buffer = malloc(sizeof(InputBuffer));
    input_buffer->buffer = NULL;
    input_buffer->buffer_lenght = 0;
    input_buffer->input_lenght = 0;
    return input_buffer;
}

void print_promt() {
    printf("db > ");
}

// to read a line of input
// **lineptr is a pointer to the variable we use to point to the buffer
// containing the read line
// n is a pointer to the variable we use to save the size of allocated buffer
// stream is a input stream we read from. We'll be reading from the stdout
// return value: the number of bytes read
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

void read_input(InputBuffer *input_buffer) {
    ssize_t bytes_read = getline(&(input_buffer->buffer), &(input_buffer->buffer_lenght), stdin);
    if (bytes_read <= 0) {
        printf("Error reading input\n");
        exit(EXIT_FAILURE);
    }
    input_buffer->input_lenght = bytes_read - 1;
    input_buffer->buffer[bytes_read - 1] = 0;
}

void close_input_buffer(InputBuffer *input_buffer) {
    free(input_buffer->buffer);
    free(input_buffer);
}

int main(int argc, char *argv[]) {
    InputBuffer *input_buffer = newInputBuffer();
    while (true) {
        print_promt();
        read_input(input_buffer);
        if (strcmp(input_buffer->buffer, ".exit") == 0) {
            close_input_buffer(input_buffer);
            exit(EXIT_SUCCESS);
        } else {
            printf("Unrecognized command '%s' \n", input_buffer->buffer);
        }

    }
}