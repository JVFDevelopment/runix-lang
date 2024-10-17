#ifndef TOKENS_H
#define TOKENS_H

typedef enum {
    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_IF,
    TOKEN_THEN,
    TOKEN_ELSE,
    TOKEN_FUNCTION,
    TOKEN_CLASS,
    TOKEN_EXTENDS,
    TOKEN_INTERFACE,
    TOKEN_IMPLEMENTS,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_COMMA
} TokenType;

typedef struct {
    TokenType type;
    char value[100];
} Token;

#endif
