#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Emitter.h"
#include<iostream>

const int FRAMES_PER_SECOND = 30;
const int DELAY_TIME = 1000.0f / FRAMES_PER_SECOND;
const int VIDEO_WIDTH = 800;
const int VIDEO_HEIGHT = 600;

class Screen {
public:
	Screen();
	~Screen();
	void InitGame(const char* title, const int EffectType);

	void HandleEvents();
	void Update();
	void Draw();
	void Sleep();
	void Clean();
	bool Running();

private:
	bool isRunning;
	Uint32 frameStart;
	Uint32 frameTime;
	SDL_Window *window;
	SDL_Renderer *renderer;
    int emitterNumber = 1;
    int xPosEmitter = 100;
    int yPosEmitter = 200;
    float xVelEmitter = 1.2f;
    float yVelEmitter = 1.2f;
    int ParticleType = 1;

	std::vector<Particle *> m_particles;
	std::vector<Emitter *> emitters;
};
