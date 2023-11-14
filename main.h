#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int argc, char *argv[]);
void exec_cmd(const char *pathname, char *const argv[], char *const envp[]);
char *parser(void);
char **tokenizer(char *lineptr, char *delim);
char **wrapper_func(void);
ssize_t _getline(char **lineptr, size_t *n, int fd);
ssize_t _read(char *buffer, int fd, size_t *n);
size_t strlen(const char *str)
int strcmp(const char *str1, const char *str2)


#endif
