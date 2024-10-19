#ifndef AST_H
#define AST_H

typedef enum {
    AST_NUMBER,
    AST_IDENTIFIER,
    AST_IF_STATEMENT,
    AST_FUNCTION_DECLARATION,
    AST_FUNCTION_CALL,
    AST_CLASS_DECLARATION,
    AST_CLASS_INHERITANCE,
    AST_INTERFACE_DECLARATION,
    AST_INTERFACE_IMPLEMENTATION
} ASTNodeType;

typedef struct ASTNode {
    ASTNodeType type;
    char name[100];             
    struct ASTNode* parameters;
    struct ASTNode* body;
    struct ASTNode* return_value;
    struct ASTNode* left;
    struct ASTNode* right;
    struct ASTNode* parent_class; 
    struct ASTNode* interfaces;
} ASTNode;

#endif
