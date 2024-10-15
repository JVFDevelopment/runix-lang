#include <stdio.h>
#include "lexer.c"
#include "parser.c"
#include "ast.h"

// Evaluate an expression node
int eval(ASTNode* node);

// Evaluate a while loop
void eval_while(ASTNode* node) {
    while (eval(node->condition)) {
        eval(node->body);
    }
}

// Evaluate the AST
int eval(ASTNode* node) {
    switch (node->type) {
        case AST_NUMBER:
            return node->value;
        case AST_ADD:
            return eval(node->left) + eval(node->right);
        case AST_SUBTRACT:
            return eval(node->left) - eval(node->right);
        case AST_WHILE_LOOP:
            eval_while(node);
            return 0;
        case AST_CONDITION:
            if (node->type == AST_LT) {
                return eval(node->left) < eval(node->right);
            } else if (node->type == AST_GT) {
                return eval(node->left) > eval(node->right);
            }
            return 0;
        default:
            return 0;
    }
}

int main() {
    const char* input = "while (x < 10) { x = x + 1; }";  // Example code
    current_token = get_next_token(&input);
    
    ASTNode* ast = parse_statement(&input);
    eval(ast);  // Execute the program
    
    return 0;
}
