#include "Particle.h"


Particle::Particle(int Ex, int Ey, int Evx, int Evy, int ParticleType, SDL_Renderer * renderer)
{
	m_rend = renderer;
	m_box = renderer;

    switch (ParticleType)
        {
            case 1:
                x = 150;
                y = 200;
                speed = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (2.f))) + 0.7f;
                angle = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (3 * acos(-1))));
                vx = speed * cos(angle);
                vy = speed * sin(angle) + 4.f;
                ax = 0.0f;
                ay = 0.0f;
            break;
            case 2:
                x = Ex;
                y = Ey;
                speed = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (5.f))) + 0.2f;
                angle = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (2 * acos(-1))));
                vx = speed * cos(angle);
                vy = speed * sin(angle) - 14.f;
                ax =  0.0f;
                ay =  0.9f;
            break;
        }

	m_posX = x;
	m_posY = y;
	m_velX = vx;
	m_velY = vy;
	m_accX = ax;
	m_accY = ay;

	dstrect = { 0, 0, 10, 10 };

	m_frame = 0;
	alphaBox = 255;
	alphaParticle = 0 + (rand() /(RAND_MAX/(255 - 0)));
	redParticle = 0 + (rand() /(RAND_MAX/(255 - 0)));
	greenParticle =  0 + (rand() /(RAND_MAX/(255 - 0)));
	blueParticle = 0 + (rand() /(RAND_MAX/(255 - 0)));
	color = { redParticle, greenParticle, blueParticle, alphaParticle };
	colorBox = { 32, 178, 170, alphaBox };
	dead = false;
}

Particle::~Particle()
{
}

void Particle::draw()
{
	dstrect = { (int)m_posX, (int)m_posY, 5, 5 }; // btmp size
	SDL_SetRenderDrawColor(m_rend, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(m_rend, &dstrect);

    dstbox = { 400, 50, 150, 250 }; // btmp size
	SDL_SetRenderDrawColor(m_box, colorBox.r, colorBox.g, colorBox.b, colorBox.a );
	SDL_RenderFillRect(m_box, &dstbox);
}

bool Particle::isDead()
{
	return dead;
}

void Particle::update()
{
	m_frame++;

    m_posX += m_velX; //+ m_accX;
    m_posY += m_velY; //+ m_accY;
    m_velX += m_accX;
    m_velY += m_accY;

	collisions();
	checkDead();
}

void Particle::collisions()
{
    if (m_posX <= 0.0f || m_posX >= 800.0f )
        m_velX = - m_velX;
    if (m_posY <= 0.0f || m_posY >= 600.0f )
        m_velY = - m_velY;
    if (checkEntityCollision(&dstrect, &dstbox))
    {
        dead = true;
    }
}

bool Particle::checkEntityCollision( SDL_Rect* activeRect, SDL_Rect* collider )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect activeRect
    leftA = activeRect->x;
    rightA = activeRect->x + activeRect->w;
    topA = activeRect->y;
    bottomA = activeRect->y + activeRect->h;

    //Calculate the sides of rect collider
    leftB = collider->x;
    rightB = collider->x + collider->w;
    topB = collider->y;
    bottomB = collider->y + collider->h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )  return false;
    if( topA >= bottomB )  return false;
    if( rightA <= leftB )  return false;
    if( leftA >= rightB )  return false;

    //If no collisions
    return true;
}

void Particle::checkDead()
{
	Uint8 decrement = 40;
	if (m_frame > 30) // when to kill a particle
	{
		if (alphaParticle > 0)
		{
			if (alphaParticle <= decrement) // if the alpha is smaller than some value, kill the particle
			{
				alphaParticle = 0;
				dead = true;
			}
			else
			{
				alphaParticle -= decrement;
			}
		}
	}
}
