#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"
#include "ast.h"

extern Token current_token;
Token get_next_token(const char** input);

ASTNode* parse_expression(const char** input);
ASTNode* parse_statement(const char** input);
ASTNode* parse_condition(const char** input);

// Parse a while loop
ASTNode* parse_while_loop(const char** input) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = AST_WHILE_LOOP;

    // Expect 'while'
    current_token = get_next_token(input);
    
    // Expect condition in parentheses
    if (current_token.type != TOKEN_LPAREN) {
        printf("Error: Expected '('\n");
        exit(1);
    }
    current_token = get_next_token(input);

    // Parse the loop condition
    node->condition = parse_condition(input);

    // Expect ')'
    if (current_token.type != TOKEN_RPAREN) {
        printf("Error: Expected ')'\n");
        exit(1);
    }
    current_token = get_next_token(input);

    // Expect the loop body in braces
    if (current_token.type != TOKEN_LBRACE) {
        printf("Error: Expected '{'\n");
        exit(1);
    }
    current_token = get_next_token(input);

    // Parse the body
    node->body = parse_statement(input);

    // Expect '}'
    if (current_token.type != TOKEN_RBRACE) {
        printf("Error: Expected '}'\n");
        exit(1);
    }
    current_token = get_next_token(input);

    return node;
}

// Parse a condition
ASTNode* parse_condition(const char** input) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = AST_CONDITION;

    // Parse left-hand side (number or identifier)
    node->left = parse_expression(input);

    // Parse the comparison operator
    if (current_token.type == TOKEN_LT || current_token.type == TOKEN_GT || current_token.type == TOKEN_EQEQ) {
        node->type = current_token.type == TOKEN_LT ? AST_LT : AST_GT; // Add more operators as needed
        current_token = get_next_token(input);
    } else {
        printf("Error: Expected comparison operator\n");
        exit(1);
    }

    // Parse right-hand side
    node->right = parse_expression(input);

ASTNode* parse_statement(const char** input) {
    if (current_token.type == TOKEN_WHILE) {
        return parse_while_loop(input);
    }
    // Add more cases for assignment statements and others
    return NULL;
}


    return node;
}
