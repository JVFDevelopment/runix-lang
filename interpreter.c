#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

ASTNode* lookup_interface(const char* interface_name);
ASTNode* lookup_class(const char* class_name);

void interpret_interface_declaration(ASTNode* node) {
    printf("Interface %s declared.\n", node->name);
}

void check_interface_implementation(ASTNode* class_node, ASTNode* interface_node) {
    printf("Checking class %s implements interface %s.\n", class_node->name, interface_node->name);
}

void interpret_class_declaration(ASTNode* node) {
    printf("Class %s declared", node->name);

    if (node->parent_class) {
        printf(" with inheritance from %s", node->parent_class->name);
    }

    ASTNode* current_interface = node->interfaces;
    while (current_interface) {
        ASTNode* interface_node = lookup_interface(current_interface->name);
        if (interface_node) {
            check_interface_implementation(node, interface_node);
        } else {
            printf("Error: Interface %s not found\n", current_interface->name);
        }
        current_interface = current_interface->body;
    }

    printf(".\n");
}

void interpret(ASTNode* node) {
    switch (node->type) {
        case AST_INTERFACE_DECLARATION:
            interpret_interface_declaration(node);
            break;
        case AST_CLASS_DECLARATION:
            interpret_class_declaration(node);
            break;
        default:
            printf("Unknown AST node type\n");
    }
}
