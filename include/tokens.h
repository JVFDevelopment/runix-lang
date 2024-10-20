#ifndef TOKENS_H
#define TOKENS_H

typedef enum {
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
    TOKEN_COMMA,
    TOKEN_MODULE,
    TOKEN_NAMESPACE,
    TOKEN_EOF,
    // Add other tokens as necessary
} TokenType;

typedef struct {
    TokenType type;
    char value[100];
} Token;

// Function to create a new token
Token create_token(TokenType type, const char* value);

#endif // TOKENS_H
