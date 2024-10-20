#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokens.h"
#include "ast.h"

// Global variable to hold the current token
extern Token current_token;

// Function prototypes for token handling and parsing
Token get_next_token(const char** input);
ASTNode* parse_expression(const char** input);
ASTNode* parse_statement(const char** input);
ASTNode* parse_if_statement(const char** input);
void handle_parse_error(const char *message);

// Function to parse a module declaration
ASTNode* parse_module_declaration(const char** input) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = AST_MODULE_DECLARATION;

    current_token = get_next_token(input);
    
    if (current_token.type != TOKEN_IDENTIFIER) {
        handle_parse_error("Expected module name");
    }
    strncpy(node->name, current_token.value, sizeof(node->name));

    current_token = get_next_token(input);
    if (current_token.type != TOKEN_LBRACE) {
        handle_parse_error("Expected '{' after module name");
    }

    // Parse the contents of the module here (e.g., functions, classes)
    node->body = NULL; // Initialize the body (linked list, etc.)

    while (current_token.type != TOKEN_RBRACE) {
        current_token = get_next_token(input);
    }

    current_token = get_next_token(input);
    return node;
}

// Function to parse a namespace declaration
ASTNode* parse_namespace_declaration(const char** input) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = AST_NAMESPACE_DECLARATION;

    current_token = get_next_token(input);
    
    if (current_token.type != TOKEN_IDENTIFIER) {
        handle_parse_error("Expected namespace name");
    }
    strncpy(node->name, current_token.value, sizeof(node->name));

    current_token = get_next_token(input);
    if (current_token.type != TOKEN_LBRACE) {
        handle_parse_error("Expected '{' after namespace name");
    }

    // Parse the contents of the namespace here (e.g., classes, interfaces)
    node->body = NULL; // Initialize the body (linked list, etc.)

    while (current_token.type != TOKEN_RBRACE) {
        current_token = get_next_token(input);
    }

    current_token = get_next_token(input);
    return node;
}

// Main parser function
ASTNode* parse_program(const char** input) {
    ASTNode* root = (ASTNode*)malloc(sizeof(ASTNode));
    root->type = AST_PROGRAM; 
    root->body = NULL;

    while (current_token.type != TOKEN_EOF) {
        if (current_token.type == TOKEN_MODULE) {
            ASTNode* module_node = parse_module_declaration(input);
            // Add module_node to root->body
        } else if (current_token.type == TOKEN_NAMESPACE) {
            ASTNode* namespace_node = parse_namespace_declaration(input);
            // Add namespace_node to root->body
        } else {
            ASTNode* statement = parse_statement(input);
            // Add the statement to the program's body (linked list, array, etc.)
        }
    }

    return root;
}

// Function to handle parsing errors
void handle_parse_error(const char *message) {
    fprintf(stderr, "Parse Error: %s\n", message);
    exit(EXIT_FAILURE);
}
