#include <stdio.h>
#include "SDL.h"
#include "Navigation.h"

int main(int argc, char** argv)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL_Init failed: %s\n", SDL_GetError());
	}
	else
	{
		Navigation();
	}
	return 0;
}