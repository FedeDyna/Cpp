#ifndef PARTICLE_H
#define PARTICLE_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <stdlib.h>
#include <iostream>

const int MAX_PARTICLES = 1;

class Particle
{
public:
	Particle(int Ex, int Ey, int Evx, int Evy, int ParticleType, SDL_Renderer * renderer);
	~Particle();
	void draw();
	bool isDead();
	void update();
    void collisions();
    void checkDead();
    bool checkEntityCollision( SDL_Rect* activeRect, SDL_Rect* collider );

private:
	float m_posX, m_posY;
	float m_velX, m_velY;
	float m_accX, m_accY;
	int m_frame;
	Uint8 alphaParticle;
	Uint8 alphaBox;
	Uint8 redParticle;
	Uint8 greenParticle;
	Uint8 blueParticle;
	bool dead;
    float x, y, vx, vy, ax, ay;
	float angle, speed;
	SDL_Renderer * m_rend;
	SDL_Renderer * m_box;
	SDL_Rect dstrect;
	SDL_Rect dstbox;
	SDL_Rect r;
	SDL_Color color;
	SDL_Color colorBox;
};

#endif // !PARTICLE_H

