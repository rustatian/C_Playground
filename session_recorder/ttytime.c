#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "io.h"
#include "ttyrec.h"

int calc_time (const char *filename)
{
    Header start, end;
    FILE *fp = efopen(filename, "r");

    read_header(fp, &start);
    fseek(fp, start.len, SEEK_CUR);
    while (1) {
	Header h;
	if (read_header(fp, &h) == 0) {
	    break;
	}
	end = h;
	fseek(fp, h.len, SEEK_CUR);
    }
    return end.tv.tv_sec - start.tv.tv_sec;
}

int main (int argc, char **argv)
{
    int i;
    set_progname(argv[0]);
    for (i = 1; i < argc; i++) {
	char *filename = argv[i];
	printf("%7d	%s\n", calc_time(filename), filename);
    }
    return 0;
}
