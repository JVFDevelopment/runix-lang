#ifndef MODULES_H
#define MODULES_H

typedef int (*FunctionPtr)(int, int);

// Define the Namespace struct
typedef struct {
    char name[50];
    FunctionPtr functions[MAX_FUNCTIONS];
    char function_names[MAX_FUNCTIONS][50];
    int function_count;
} Namespace;

// Define the Module struct
typedef struct {
    char name[50];
    Namespace* namespaces[MAX_NAMESPACES];
    int namespace_count;
} Module;

// Function declarations
Namespace* create_namespace(const char* name);
void add_function(Namespace* ns, const char* func_name, FunctionPtr func);
Module* create_module(const char* name);
void add_namespace(Module* mod, Namespace* ns);
FunctionPtr get_function(Namespace* ns, const char* func_name);

#endif // MODULES_H
