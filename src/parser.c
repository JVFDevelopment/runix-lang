#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokens.h"
#include "ast.h"

extern Token current_token;
Token get_next_token(const char** input);

ASTNode* parse_expression(const char** input);
ASTNode* parse_statement(const char** input);
ASTNode* parse_if_statement(const char** input);

// Parse an interface declaration
ASTNode* parse_interface_declaration(const char** input) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = AST_INTERFACE_DECLARATION;

    current_token = get_next_token(input);

    if (current_token.type != TOKEN_IDENTIFIER) {
        printf("Error: Expected interface name\n");
        exit(1);
    }
    strncpy(node->name, current_token.value, sizeof(node->name));
    current_token = get_next_token(input);

    if (current_token.type != TOKEN_LBRACE) {
        printf("Error: Expected '{'\n");
        exit(1);
    }
    current_token = get_next_token(input);

    node->body = NULL;

    while (current_token.type != TOKEN_RBRACE) {
        current_token = get_next_token(input);
    }

    current_token = get_next_token(input);

    return node;
}

// Parse a class that implements interfaces
ASTNode* parse_class_declaration(const char** input) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = AST_CLASS_DECLARATION;

    current_token = get_next_token(input);

    if (current_token.type != TOKEN_IDENTIFIER) {
        printf("Error: Expected class name\n");
        exit(1);
    }
    strncpy(node->name, current_token.value, sizeof(node->name));
    current_token = get_next_token(input);

    if (current_token.type == TOKEN_EXTENDS) {
        current_token = get_next_token(input);
        if (current_token.type != TOKEN_IDENTIFIER) {
            printf("Error: Expected parent class name\n");
            exit(1);
        }
        ASTNode* parent_class_node = (ASTNode*)malloc(sizeof(ASTNode));
        parent_class_node->type = AST_IDENTIFIER;
        strncpy(parent_class_node->name, current_token.value, sizeof(parent_class_node->name));
        node->parent_class = parent_class_node;
        current_token = get_next_token(input);
    } else {
        node->parent_class = NULL;
    }

    if (current_token.type == TOKEN_IMPLEMENTS) {
        current_token = get_next_token(input);
        node->interfaces = NULL;

        while (current_token.type == TOKEN_IDENTIFIER) {
            ASTNode* interface_node = (ASTNode*)malloc(sizeof(ASTNode));
            interface_node->type = AST_IDENTIFIER;
            strncpy(interface_node->name, current_token.value, sizeof(interface_node->name));

            interface_node->body = node->interfaces;
            node->interfaces = interface_node;

            current_token = get_next_token(input);

            if (current_token.type == TOKEN_COMMA) {
                current_token = get_next_token(input);
            }
        }
    }

    if (current_token.type != TOKEN_LBRACE) {
        printf("Error: Expected '{'\n");
        exit(1);
    }
    current_token = get_next_token(input);

    node->body = NULL;

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
        ASTNode* statement = parse_statement(input);
    }

    return root;
}
