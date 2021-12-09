#include "headers.h"


int main(int argc, char *argv[])
{
	USSR();
	return 0;
}


int USSR(void)
{
	/* inits SDL2 */
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);


	/* window stuff */
	SDL_Window *window = NULL;
	window = SDL_CreateWindow("IT'S NOT YOUR BUT OUR WORLD COMRADE !", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 680, SDL_WINDOW_SHOWN);

	SDL_Renderer *renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Surface *img = NULL;
	img = SDL_LoadBMP("USSR.bmp");

	SDL_Texture *textureIMG = NULL;
	textureIMG = SDL_CreateTextureFromSurface(renderer, img);

	SDL_FreeSurface(img);


	if(img == NULL)
	{
		fprintf(stderr, "Error SDL_LoadBMP: %s\n",SDL_GetError());
		goto exit;
	}


	if(textureIMG == NULL)
	{
		fprintf(stderr, "Error SDL_CreateTextureFromSurface: %s\n", SDL_GetError());
		goto exit;
	}


/* *************************************************************************************** */


	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) != 0)
	{
		fprintf(stderr, "Error Mix_OpenAudio: %s\n", SDL_GetError());
	}
	Mix_Music *bgm = Mix_LoadMUS("USSR.mp3");


	Mix_PlayMusic(bgm, -1);


/* *************************************************************************************** */

	/* program loop */
	unsigned int running = 1;
	while(running = true)
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT)
		{
			running = false;
			goto exit;
		}

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, textureIMG, NULL, NULL);
		SDL_RenderPresent(renderer);
	}

/* *************************************************************************************** */

	exit:
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	Mix_FreeMusic(bgm);
	Mix_Quit();
	SDL_Quit();

	return 0;
}