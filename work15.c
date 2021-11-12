#include <unistd.h>
#include "work15.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char ** parse_args(char * line) {
	char *str = malloc(strlen(line));
	strcpy(str, line);
	char * curr = str;
	char ** args = malloc(strlen(line) * 8);
	int i = 0;
	while (curr != 0) {
		args[i] = strsep(&curr, " ");
		i++;
	}
	return args;
}

int main(int argc, char *argv[]) {
	char ** args = parse_args("cd home/Joshua/Documents");
	execvp(args[0], args);
//	printf("args[0]: %s\targs[1]: %s\targs[2]: %s\t\n", args[0], args[1], args[2]);
	free(args);
	return 0;
}
