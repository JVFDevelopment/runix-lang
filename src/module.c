#include "module.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void load_module(const char *filename) {
    printf("Loading module: %s\n", filename);
}

void register_namespace(const char *name, Module *module) {
    printf("Registering namespace: %s\n", name);
    module->name = strdup(name);
}
 
 