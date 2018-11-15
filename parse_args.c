#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

char** parse_args(char* line) {
  char** args = malloc(5 * sizeof(char *));
  int i = 0;
  while(line) {
    args[i] = strsep(&line, " ");
    i++;
  }
  return args;
}

int main() {
  printf("cmd: \"ls -a -l\"\n");
  char cmd[16] = "ls -a -l";
  char** args = parse_args(cmd);
  execvp(args[0], args);
  return 0;
}
