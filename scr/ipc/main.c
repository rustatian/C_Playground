//
// Created by valery on 04/07/19.
//

#include "main.h"

#include <pthread.h>
#include <stdio.h>
#include "chan.h"

chan_t* chan;

void* ping()
{
    // Send blocks until receiver is ready.
    chan_send(chan, "ping");
    return NULL;
}

int main()
{
    // Initialize unbuffered channel.
    chan = chan_init(0);

    pthread_t th;
    pthread_create(&th, NULL, ping, NULL);

    // Receive blocks until sender is ready.
    void* msg;
    chan_recv(chan, &msg);
    printf("%s\n", msg);

    // Clean up channel.
    chan_dispose(chan);
}