#include <SDL2/SDL.h>
#include <stdio.h>
#include "texture.h"
#include "character.h"

const int SCREEN_H= 640;
const int SCREEN_W= 1080;

//The rendering window
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image to load and show on screen
SDL_Surface* gXOut = NULL;

bool init()
{
	//init flag
	bool success = true;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL cout not init! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow("WINDOW", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN);
		if(gWindow==NULL)
		{
			printf("WINDOW COULD NOT BE CREATED SDL_ERROR: %s\n", SDL_GetError());
			success = false;
		}
		else
			SDL_UpdateWindowSurface(gWindow);

	}
	return success;
}

void close()
{
	//Dealocate surface
	SDL_FreeSurface(gXOut);
	gXOut = NULL;

	//Destroy Window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main(int argc, char* args[])
{
	if(!init())
		printf("FAILED TO INITIALIZE\n");
	else
	{
		if(!loadMedia())
			printf("FAILED TO LOAD MEDIA\n");
		else
		{
			bool quit = false;


			while(!quit)
			{
				quit=true;
			}
		}
	}
	close();
	return 0;
}
