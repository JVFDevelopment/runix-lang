#ifndef MODULE_H
#define MODULE_H

typedef struct {
    char *name;
    char **functions;
    char **variables;
} Module;

typedef struct {
    char *namespace;
    Module *module;
} Namespace;

void load_module(const char *filename);
void register_namespace(const char *name, Module *module);

#endif // MODULE_H
