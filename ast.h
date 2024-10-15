#ifndef AST_H
#define AST_H

typedef enum {
    AST_NUMBER,
    AST_IDENTIFIER,
    AST_ADD,
    AST_SUBTRACT,
    AST_WHILE_LOOP,     // New node type for `while` loops
    AST_CONDITION       // Node type for conditions like <, >
} ASTNodeType;

typedef struct ASTNode {
    ASTNodeType type;
    int value;   // If it's a number node
    char name[100]; // If it's an identifier
    struct ASTNode* left;  // Left child
    struct ASTNode* right; // Right child
    struct ASTNode* condition; // For while loops, stores the loop condition
    struct ASTNode* body;      // For while loops, stores the loop body
} ASTNode;

#endif
