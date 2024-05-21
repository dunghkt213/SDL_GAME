#include"sound.h"
sound* sound::s_pInstance = nullptr;
void sound:: loadMusic(const char* path, string name)
{

	Mix_Music* gMusic = Mix_LoadMUS(path);
	music_map[name] = gMusic;
	if (gMusic == nullptr) {
		SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
			"Could not load music! SDL_mixer Error: %s", Mix_GetError());
	}
}
void sound:: play_music(string name)
{
	Mix_Music* gMusic = music_map[name];
	if (gMusic == nullptr) return;

	if (Mix_PlayingMusic() == 0) {
		Mix_PlayMusic(gMusic, -1);
	}
	else if (Mix_PausedMusic() == 1) {
		Mix_ResumeMusic();
	}
}

void sound::loadSound(const char* path, string name) {
	Mix_Chunk* gChunk = Mix_LoadWAV(path);
	sound_map[name] = gChunk;
	if (gChunk == nullptr) {
		SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
			"Could not load sound! SDL_mixer Error: %s", Mix_GetError());
	}
}
void sound::play_sound(string name) {
	Mix_Chunk* gChunk = sound_map[name];
	if (gChunk != nullptr) {
		Mix_PlayChannel(-1, gChunk, 0);
	}
}