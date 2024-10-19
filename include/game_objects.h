#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H

// Define structures for game objects
typedef struct {
    int x;
    int y;
    int width;
    int height;
    char* texture;
} GameObject;

// Function prototypes for managing game objects
GameObject* create_game_object(int x, int y, const char* texture);
void update_game_object(GameObject* object);
void destroy_game_object(GameObject* object);

#endif
