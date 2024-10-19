#include "game_loop.h"
#include "graphics.h"
#include "input.h"
#include "physics.h"
#include "audio.h"
#include "assets.h"

void run_game_loop() {
    bool isRunning = true;
    while (isRunning) {
        handle_input();
        

        update_physics();
        

        render_frame();
        

        play_audio();
        
        if (should_exit()) {
            isRunning = false;
        }
    }
}
