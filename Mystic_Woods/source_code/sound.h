#pragma once
#include<iostream>
#include<map>
#include<string>
#include<SDL.h>
#include<SDL_mixer.h>
using namespace std;
class sound 
{
private:
	map<string, Mix_Chunk*> sound_map;
	map<string, Mix_Music*>	music_map;
	static sound* s_pInstance;
public:
	void init()
	{
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
			cout << "loi";
		}

	}
	static sound* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new sound();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void loadMusic(const char* path, string name);
	void play_music(string name);

	void loadSound(const char* path, string name);
	void play_sound(string name);
};