#include "SDL2/SDL.h"
#include "Screen.h"

enum EffectType {
    firework = 1,
    fontain = 2,
    explosion = 3
};

int main()
{

    EffectType effect = fontain;
    Screen *GameScreen = new Screen();
	GameScreen->InitGame("Particle Emitter", effect);

	while (GameScreen->Running())
	{

    //SDL_GetMouseState(&x, &y);
    //if ( SDL_GetMouseState(NULL, NULL) && SDL_BUTTON(SDL_BUTTON_LEFT))
 //   std::cout << "Mouse Position is:" << x << " " <<  y << std::endl;

		GameScreen->HandleEvents();
		GameScreen->Update();
		GameScreen->Draw();
        GameScreen->Sleep();
	}

	GameScreen->Clean();
	return 0;
}
