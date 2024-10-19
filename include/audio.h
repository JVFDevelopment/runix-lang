#ifndef AUDIO_H
#define AUDIO_H

// Function prototypes for audio system
void initialize_audio();
void play_sound(const char* sound_path);
void stop_sound(const char* sound_path);
void shutdown_audio();

#endif
