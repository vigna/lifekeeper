/* lifekeeper: a program that keeps your connections alive

   Copyright (C) 2000 Sebastiano Vigna

   This library is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or (at your
   option) any later version.

   This library is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
   for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, see <http://www.gnu.org/licenses/>.  */


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