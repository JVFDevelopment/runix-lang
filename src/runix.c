#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"      // Include lexer header
#include "parser.h"     // Include parser header
#include "interpreter.h" // Include interpreter header
#include "module.h"      // Include module header

typedef struct Error {
    char *message;
} Error;

// Function to handle errors
void handleError(Error *error) {
    if (error != NULL) {
        printf("An error occurred: %s\n", error->message);
        free(error->message); // Free the message string
        free(error);          // Free the error struct
    }
}

// Function that divides two numbers and throws an error if the denominator is zero
Error* divide(int numerator, int denominator) {
    if (denominator == 0) {
        Error *error = malloc(sizeof(Error));
        error->message = strdup("Error: Division by zero!");
        return error; // Return the error
    }
    // Return NULL if no error occurs (successful division)
    return NULL;
}

// Load and execute a Runix script
void load_script(const char *filename) {
    // Initialize the lexer, parser, and interpreter
    Lexer lexer = create_lexer(filename);
    Parser parser = create_parser(&lexer);
    Interpreter interpreter = create_interpreter(&parser);

    // Start interpreting the script
    interpret(&interpreter);
}

// Main function for executing code
int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <script.runix>\n", argv[0]);
        return 1;
    }

    const char *script_filename = argv[1];

    printf("Running Runix program...\n");

    // Example of a simple function
    printf("Hello, World! from Runix.\n");

    // Simulating try-catch with the divide function
    printf("Trying to divide 10 by 0:\n");
    Error *error = divide(10, 0); // This will cause an error
    handleError(error); // Handle the error if it occurred

    printf("Trying to divide 10 by 2:\n");
    error = divide(10, 2); 
    if (error == NULL) {
        printf("Division successful!\n");
    } else {
        handleError(error);
    }

    // Load and interpret the Runix script
    load_script(script_filename);

    return 0;
}
