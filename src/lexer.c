#include <stdio.h>
#include <string.h>
#include "tokens.h"

// Function to create a new token
Token create_token(TokenType type, const char* value);

// Lexer function to identify and return tokens
Token get_next_token(const char** input) {
    char buffer[100];
    int index = 0;

    // Skip white spaces
    while (**input == ' ' || **input == '\n' || **input == '\t') (*input)++;

    // Identifier or keyword
    if ((**input >= 'a' && **input <= 'z') || (**input >= 'A' && **input <= 'Z')) {
        while ((**input >= 'a' && **input <= 'z') || (**input >= 'A' && **input <= 'Z')) {
            buffer[index++] = **input;
            (*input)++;
        }
        buffer[index] = '\0';

        // Keywords
        if (strcmp(buffer, "if") == 0) return create_token(TOKEN_IF, "if");
        if (strcmp(buffer, "then") == 0) return create_token(TOKEN_THEN, "then");
        if (strcmp(buffer, "else") == 0) return create_token(TOKEN_ELSE, "else");
        if (strcmp(buffer, "function") == 0) return create_token(TOKEN_FUNCTION, "function");
        if (strcmp(buffer, "class") == 0) return create_token(TOKEN_CLASS, "class");
        if (strcmp(buffer, "extends") == 0) return create_token(TOKEN_EXTENDS, "extends");
        if (strcmp(buffer, "interface") == 0) return create_token(TOKEN_INTERFACE, "interface");
        if (strcmp(buffer, "implements") == 0) return create_token(TOKEN_IMPLEMENTS, "implements");
        
        return create_token(TOKEN_IDENTIFIER, buffer);
    }

    // Operators and symbols
    if (**input == '{') return create_token(TOKEN_LBRACE, "{"), (*input)++;
    if (**input == '}') return create_token(TOKEN_RBRACE, "}"), (*input)++;
    if (**input == '(') return create_token(TOKEN_LPAREN, "("), (*input)++;
    if (**input == ')') return create_token(TOKEN_RPAREN, ")"), (*input)++;
    if (**input == ',') return create_token(TOKEN_COMMA, ","), (*input)++;

    return create_token(TOKEN_EOF, "EOF"); // End of input
}
