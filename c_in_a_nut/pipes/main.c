#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUF_SIZE 10

int main(int argc, char *argv[]) {
	int pfd[2];
	char buf[BUF_SIZE];
	size_t numRead;

	if (argc != 2 || strcmp(argv[1], "--help") == 0) {
		printf("%s string\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (pipe(pfd) == -1) {
		printf("pipe\n");
		exit(EXIT_FAILURE);
	}

	switch(fork()) {
		case -1:
			printf("fork\n");
			exit(EXIT_FAILURE);
		case 0:
			if (close(pfd[1]) == -1) {
				printf("close-child\n");
				exit(EXIT_FAILURE);
			}

			for(;;) {
				// read data from the pipe
				numRead = read(pfd[0], buf, BUF_SIZE);
				if (numRead == -1) {
					printf("read\n");
					exit(EXIT_FAILURE);
				}
				if (numRead == 0) {
					break;
				}

				if (write(STDOUT_FILENO, buf, numRead) != numRead) {
					printf("child-write\n");
					exit(EXIT_FAILURE);
				}
			}

			write(STDOUT_FILENO, "\n", 1);
			if (close(pfd[0]) == -1) {
				printf("close\n");
				exit(EXIT_FAILURE);
			}

			_exit(EXIT_SUCCESS);
		default:
			// parent - write to pipes
			if (close(pfd[0]) == -1 ) {
				printf("close-parent\n");
				exit(EXIT_FAILURE);
			}

			if (write(pfd[1], argv[1], strlen(argv[1])) != strlen(argv[1])) {
				printf("write\n");
				exit(EXIT_FAILURE);
			}

			if (close(pfd[1]) == -1) {
				printf("close\n");
				exit(EXIT_FAILURE);
			}

			wait(NULL);
			exit(EXIT_SUCCESS);
	}

	return 0;
}
