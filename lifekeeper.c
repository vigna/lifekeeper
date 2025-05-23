#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define DEFAULT_INTERVAL 5

int main(int argc, char *argv[]) {
	int secs = 0;

	if (argc == 2 && !strcmp(argv[1], "-h")) {
		fprintf(stderr, "%s [-h] [-s interval]\nPrints an ASCII NUL character every 5 (or interval) seconds.\n", argv[0]);
		exit(0);
	}

	if (argc == 3 && (strcmp(argv[1], "-s") || !(secs = atoi(argv[2]))) || argc != 1 && !secs) {
		fprintf(stderr, "Wrong parameters\n");
		exit(1);
	}

	if (!secs) secs = DEFAULT_INTERVAL;

	for(;;) {
		sleep(secs);
		putchar(0);
		fflush(stdout);
		if (feof(stdin)) exit(0);
	}
}