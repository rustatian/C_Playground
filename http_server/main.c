#include "main.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <signal.h>

#define CONNMAX 1000

static int listenfd, clients[CONNMAX];
static void error(char *);
static void startServer(const char *);
static void respond(int);

typedef struct { char *name, *value; } header_t;
static header_t reqhdr[17] = { {"\0", "\0"} };
static int clientfd;

static char *buf;

void serve_forever(const char *PORT) {
}

int main() {

}