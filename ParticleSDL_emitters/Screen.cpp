#include "Screen.h"
#include<iostream>
#include <time.h>

Screen::Screen()
{
	srand(time(NULL));
}

Screen::~Screen()
{
}

void Screen::InitGame(const char* title, const int EffectType)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, VIDEO_WIDTH, VIDEO_HEIGHT, 0);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 16, 255, 255, 255);
		}
		isRunning = true;
	} else {
		isRunning = false;
	}


	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    switch (EffectType)
    {
        case 1:
            emitterNumber = 2;
            xPosEmitter = 150;
            yPosEmitter = 300;
            xVelEmitter = 4.2f;
            yVelEmitter = 0.2f;
            ParticleType = 1;
        break;
        case 2:
            emitterNumber = 1;
            xPosEmitter = 100;
            yPosEmitter = 200;
            xVelEmitter = 1.2f;
            yVelEmitter = 1.2f;
            ParticleType = 2;
        break;
    }

    std::cout << xPosEmitter << " " << yVelEmitter  << std::endl;

	// create the emitter location
	for (int i = 0; i < emitterNumber; i++) {
        emitters.push_back(new Emitter(xPosEmitter+5*i, yPosEmitter+15*i, xVelEmitter, yVelEmitter, ParticleType, renderer));
        std::cout << "HOW MANY EMITTERS" << std::endl;
    }
}

// handle quit events or key press events
void Screen::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN: // do nothing
		break;
	}
}

void Screen::Update()
{
	for (auto & p : m_particles) // loop on the particles emitted
	{
		p->update(); // check the position
		if (p->isDead())
		{
			m_particles.erase(std::remove(m_particles.begin(), m_particles.end(), p), m_particles.end());
			delete p;
		}
	}
	for (auto & e : emitters) // loop on the sourcers/emitters of the particles
	{
		e->update();
	}
}

void Screen::Draw()
{
	SDL_SetRenderDrawColor(renderer, 102, 138, 238, 255); // screen background color
	SDL_RenderClear(renderer);
	//this is where we draw stuff
	for (auto & p : m_particles)
	{
		p->draw();
	}
	for (auto & e : emitters)
	{
		e->draw();
	}
	SDL_RenderPresent(renderer);
}

void Screen::Sleep()
{
    frameStart = SDL_GetTicks();
    frameTime = SDL_GetTicks() - frameStart;
    if( frameTime < DELAY_TIME )
        SDL_Delay((int) (DELAY_TIME - frameTime));
}

void Screen::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Screen cleaned!" << std::endl;
}

bool Screen::Running()
{
	return isRunning;
}
