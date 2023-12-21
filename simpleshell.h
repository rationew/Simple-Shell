#ifndef SIMPLESHELL_H
#define SIMPLESHELl_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

void prompt_display(void);
void shell_print(const char *str);
ssize_t getline(char **ptr, size_t *k);
void execute_command(const char *message);
void parsing_input(char *string, char **args);

#endif/*SIMPLESHELL_H*/
