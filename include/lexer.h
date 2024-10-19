#ifndef LEXER_H
#define LEXER_H

// Include necessary libraries
#include <stdio.h>

// Define token types, structures, and function prototypes
typedef enum {
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_KEYWORD,
    TOKEN_OPERATOR,
    TOKEN_END_OF_FILE
} TokenType;

typedef struct {
    TokenType type;
    char* value;
} Token;

// Function prototypes
Token* create_token(TokenType type, char* value);
Token* get_next_token();
void free_token(Token* token);

#endif
