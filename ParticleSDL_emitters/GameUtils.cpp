#include "GameUtils.h"
#include <iostream>

void Particle::checkCollisions()
{
    if (m_posX <= 0.0f || m_posX >= 800.0f)
        m_velX = - m_velX;
    if (m_posY <= 0.0f || m_posY >= 600.0f)
        m_velY = - m_velY;
}

void Particle::checkDead()
{
	Uint8 decrement = 40;
	if (m_frame > 30) // when to kill a particle
	{
		if (alpha > 0)
		{
			if (alpha <= decrement) // if the alpha is smaller than some value, kill the particle
			{
				alpha = 0;
				dead = true;
			}
			else
			{
				alpha -= decrement;
			}
		}
	}
}
