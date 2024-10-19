#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "parser.h"
#include "interpreter.h"

int main() {
    const char* input = "class Greeting { function sayHello() { print(\"Hello, World!\"); } } "
                        "new Greeting(); "
                        "Greeting.sayHello();";
    const char* input_ptr = input;

    current_token = get_next_token(&input_ptr); // Initialize the lexer

    ASTNode* root = parse_program(&input_ptr); // Parse the input into an AST

    run(root); // Interpret the AST

    return 0;
}
