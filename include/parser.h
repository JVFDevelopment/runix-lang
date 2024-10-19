#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

// Define structures and function prototypes for the parser
typedef struct {
    Token* current_token;
} Parser;

// Function prototypes
Parser* create_parser();
void parse_program(Parser* parser);
void parse_expression(Parser* parser);
void free_parser(Parser* parser);

#endif
