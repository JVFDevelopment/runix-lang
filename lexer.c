#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKEN_LENGTH 100

// Define token types, including WHILE and comparison operators
typedef enum {
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_ASTERISK,
    TOKEN_SLASH,
    TOKEN_EQUALS,
    TOKEN_SEMICOLON,
    TOKEN_WHILE,        // New token for `while`
    TOKEN_LBRACE,       // {
    TOKEN_RBRACE,       // }
    TOKEN_LT,           // <
    TOKEN_GT,           // >
    TOKEN_EQEQ,         // ==
    TOKEN_EOF
} TokenType;

Token create_token(TokenType type, const char* value);

Token get_next_token(const char** input) {
    while (**input != '\0') {
        if (isspace(**input)) {
            (*input)++; // Skip whitespace
            continue;
        }
        if (isalpha(**input)) { // Identifier or keyword
            char buffer[MAX_TOKEN_LENGTH] = {0};
            int length = 0;
            while (isalnum(**input)) {
                buffer[length++] = *(*input)++;
            }
            // Check if it's a keyword
            if (strcmp(buffer, "while") == 0) {
                return create_token(TOKEN_WHILE, "while");
            }
            return create_token(TOKEN_IDENTIFIER, buffer);
        }
        if (isdigit(**input)) { // Number
            char buffer[MAX_TOKEN_LENGTH] = {0};
            int length = 0;
            while (isdigit(**input)) {
                buffer[length++] = *(*input)++;
            }
            return create_token(TOKEN_NUMBER, buffer);
        }
        switch (**input) {
            case '(': (*input)++; return create_token(TOKEN_LPAREN, "(");
            case ')': (*input)++; return create_token(TOKEN_RPAREN, ")");
            case '+': (*input)++; return create_token(TOKEN_PLUS, "+");
            case '-': (*input)++; return create_token(TOKEN_MINUS, "-");
            case '*': (*input)++; return create_token(TOKEN_ASTERISK, "*");
            case '/': (*input)++; return create_token(TOKEN_SLASH, "/");
            case '=': 
                if (*(*input + 1) == '=') { // Handle '=='
                    (*input) += 2;
                    return create_token(TOKEN_EQEQ, "==");
                }
                (*input)++;
                return create_token(TOKEN_EQUALS, "=");
            case '{': (*input)++; return create_token(TOKEN_LBRACE, "{");
            case '}': (*input)++; return create_token(TOKEN_RBRACE, "}");
            case '<': (*input)++; return create_token(TOKEN_LT, "<");
            case '>': (*input)++; return create_token(TOKEN_GT, ">");
            case ';': (*input)++; return create_token(TOKEN_SEMICOLON, ";");
        }
    }
    return create_token(TOKEN_EOF, "EOF");
}
