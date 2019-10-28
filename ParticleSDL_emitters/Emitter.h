#ifndef EMITTER_H
#define EMITTER_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include"Particle.h"
#include<vector>
#include<algorithm>

class Emitter
{
public:
	Emitter(int ex, int ey, float evx, float evy, int ParticleType, SDL_Renderer * renderer);
	~Emitter();
	void update();
	void draw();
    void checkCollisions();

private:
	std::vector<Particle *> m_particles;
	void drawParticles();
	SDL_Renderer * m_rend;
    float m_EposX, m_EposY;
	float m_EvelX, m_EvelY;
	int m_ParticleType;

};

#endif // !EMITTER_H

