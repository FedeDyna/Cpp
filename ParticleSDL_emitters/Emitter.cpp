#include "Emitter.h"
#include <math.h>

Emitter::Emitter(int ex, int ey,  float evx, float evy, int ParticleType, SDL_Renderer * renderer)
{
	m_rend = renderer;
	m_EposX = ex;
	m_EposY = ey;
	m_EvelX = evx;
	m_EvelY = evy;
	m_ParticleType = ParticleType;

    // create one particle each time you create an emitter
    m_particles.push_back (new Particle(m_EposX, m_EposY, m_EvelX, m_EvelY, m_ParticleType, m_rend));

}

Emitter::~Emitter()
{
	//Delete particles
	for (uint i = 0; i < m_particles.size(); ++i)
	{
		delete m_particles.at(i);
	}
}

void Emitter::update()
{
	m_EposX += m_EvelX;
	m_EposY += m_EvelY;

	for (uint i = 0; i < m_particles.size(); i++)
	{
		m_particles.at(i)->update();
	}
    // add more particles each time you call the update, means how many particles to create each FPS
    for (uint i = 0; i < 10; i++)
	{
		m_particles.push_back (new Particle(m_EposX, m_EposY, m_EvelX, m_EvelY, m_ParticleType, m_rend));
	}
    checkCollisions();
}

void Emitter::draw()
{
	drawParticles();
}

void Emitter::drawParticles()
{
	for (uint i = 0; i < m_particles.size(); ++i)
	{
		//Delete and replace dead particles
		if (m_particles[i]->isDead())
		{
			delete m_particles.at(i);
			m_particles.erase(std::remove(m_particles.begin(), m_particles.end(), m_particles.at(i)), m_particles.end());
		}
	}
	std::cout << m_particles.size() << std::endl; // COUNT HOW MANY ACTIVE PARTICLES I HAVE
	//Show particles
	for (uint i = 0; i < m_particles.size(); ++i)
	{
		m_particles.at(i)->draw();
	}
}

void Emitter::checkCollisions()
{
    if (m_EposX <= 0.0f || m_EposX >= 800.0f)
        m_EvelX = - m_EvelX;
    if (m_EposY <= 0.0f || m_EposY >= 600.0f)
        m_EvelY = - m_EvelY;
}
