#ifndef GRAPHICS_H
#define GRAPHICS_H

// Function prototypes for graphics rendering
void initialize_graphics();
void load_texture(const char* texture_path);
void draw_sprite(int x, int y, const char* texture);
void clear_screen();
void display_frame();

#endif
