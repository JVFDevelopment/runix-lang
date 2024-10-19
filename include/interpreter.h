#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "parser.h"

// Define structures and function prototypes for the interpreter
typedef struct {
    int result;
} Interpreter;

// Function prototypes
Interpreter* create_interpreter();
void interpret(Parser* parser, Interpreter* interpreter);
void free_interpreter(Interpreter* interpreter);

#endif
