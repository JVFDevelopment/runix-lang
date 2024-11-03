#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FUNCTIONS 10
#define MAX_NAMESPACES 10

// Define a function pointer type for namespace functions.
typedef int (*FunctionPtr)(int, int);

// Define a Namespace struct.
typedef struct {
    char name[50];
    FunctionPtr functions[MAX_FUNCTIONS];
    char function_names[MAX_FUNCTIONS][50];
    int function_count;
} Namespace;

// Define a Module struct to hold multiple namespaces.
typedef struct {
    char name[50];
    Namespace* namespaces[MAX_NAMESPACES];
    int namespace_count;
} Module;

// Function to create a new namespace.
Namespace* create_namespace(const char* name) {
    Namespace* ns = (Namespace*)malloc(sizeof(Namespace));
    strncpy(ns->name, name, 50);
    ns->function_count = 0;
    return ns;
}

// Function to add a function to a namespace.
void add_function(Namespace* ns, const char* func_name, FunctionPtr func) {
    if (ns->function_count < MAX_FUNCTIONS) {
        ns->functions[ns->function_count] = func;
        strncpy(ns->function_names[ns->function_count], func_name, 50);
        ns->function_count++;
    }
}

// Function to create a new module.
Module* create_module(const char* name) {
    Module* mod = (Module*)malloc(sizeof(Module));
    strncpy(mod->name, name, 50);
    mod->namespace_count = 0;
    return mod;
}

// Function to add a namespace to a module.
void add_namespace(Module* mod, Namespace* ns) {
    if (mod->namespace_count < MAX_NAMESPACES) {
        mod->namespaces[mod->namespace_count] = ns;
        mod->namespace_count++;
    }
}

// Sample function to add.
int add(int x, int y) {
    return x + y;
}

// Sample function to subtract.
int subtract(int x, int y) {
    return x - y;
}

// Function to retrieve a function from a namespace by name.
FunctionPtr get_function(Namespace* ns, const char* func_name) {
    for (int i = 0; i < ns->function_count; i++) {
        if (strcmp(ns->function_names[i], func_name) == 0) {
            return ns->functions[i];
        }
    }
    return NULL;  // Function not found
}

int main() {
    // Create a module and a namespace.
    Module* math_module = create_module("math");
    Namespace* basic_ops = create_namespace("basic_operations");

    // Add functions to the namespace.
    add_function(basic_ops, "add", add);
    add_function(basic_ops, "subtract", subtract);

    // Add namespace to module.
    add_namespace(math_module, basic_ops);

    // Retrieve and call the "add" function.
    FunctionPtr add_func = get_function(basic_ops, "add");
    if (add_func) {
        printf("Result of add(5, 3): %d\n", add_func(5, 3));  // Should print 8
    }

    // Clean up.
    free(basic_ops);
    free(math_module);

    return 0;
}
