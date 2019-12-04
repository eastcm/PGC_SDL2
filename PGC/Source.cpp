/*This source code copyrighted by Lazy Foo' Productions (2004-2019)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "Timer.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int FRAMES_PER_SECOND = 60;

int main(int argc, char* args[])
{
	bool quit = false;
	SDL_Event event;

	Timer fps;
	Timer update;

	update.start();
	while (!quit)
	{
		int frame = 0;
		fps.start();

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}

		frame++;

		if (fps.get_ticks() < 1000 / FRAMES_PER_SECOND)
		{
			SDL_Delay((1000 / FRAMES_PER_SECOND) - fps.get_ticks());
		}
		if (update.get_ticks() > 1000)
		{
			std::string caption;

			caption = "FPS: ";
			caption += std::to_string((int)(frame / (fps.get_ticks() / 1000.f)));

			//SDL_SetWindowTitle(window, caption.c_str());

			update.start();
		}
	}

	return 0;
}