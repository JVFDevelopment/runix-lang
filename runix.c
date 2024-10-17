#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "parser.h"
#include "interpreter.h"

// Entry point for Runix interpreter
int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <source_file>\n", argv[0]);
        return 1;
    }

    // Open the source file
    FILE* source_file = fopen(argv[1], "r");
    if (!source_file) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    // Read the source code into a buffer
    fseek(source_file, 0, SEEK_END);
    long file_size = ftell(source_file);
    fseek(source_file, 0, SEEK_SET);

    char* source_code = (char*)malloc(file_size + 1);
    fread(source_code, 1, file_size, source_file);
    source_code[file_size] = '\0';
    fclose(source_file);

    // Initialize lexer and parser
    const char* input = source_code;
    current_token = get_next_token(&input);  // Initialize the first token
    ASTNode* program_node = parse_program(&input);

    // Interpret the program
    interpret(program_node);

    // Cleanup
    free(source_code);
    return 0;
}
