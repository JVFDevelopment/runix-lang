#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"      // Include lexer header
#include "parser.h"     // Include parser header
#include "interpreter.h" // Include interpreter header

typedef struct Error {
    char *message;
} Error;

// Function to handle errors
void handleError(Error *error) {
    if (error != NULL) {
        printf("An error occurred: %s\n", error->message);
        free(error);
    }
}

// Function to simulate a risky operation
void riskyOperation() {
    Error *error = malloc(sizeof(Error));
    // Simulate an error
    error->message = "Something went wrong!";
    handleError(error);
}

// Function that divides two numbers and throws an error if the denominator is zero
Error* divide(int numerator, int denominator) {
    if (denominator == 0) {
        Error *error = malloc(sizeof(Error));
        error->message = "Error: Division by zero!";
        return error; // Return the error
    }
    // Return NULL if no error occurs (successful division)
    return NULL;
}

// Main function for executing code
int main() {
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

    return 0;
}
