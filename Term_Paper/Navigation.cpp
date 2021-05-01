#include <stdio.h>
#include "SDL.h"
#include "Navigation.h"

struct Pointer_On
{
	SDL_Window* Window;
	SDL_Surface* Window_Surface;
	SDL_Surface* Background_Image;
};


void Load_Backgroung_Image(struct Pointer_On* Pointer_On, int variant_of_background_image)
{
	Pointer_On->Background_Image = SDL_GetWindowSurface(Pointer_On->Window);
	Pointer_On->Background_Image = SDL_LoadBMP("title_image.bmp");
	SDL_UpdateWindowSurface(Pointer_On->Window);
}

void Navigation()
{
	struct Pointer_On Pointer_On;
	Pointer_On.Window = SDL_CreateWindow("Curs Project",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600,
		600, SDL_WINDOW_SHOWN);
	SDL_Delay(1000);
	SDL_DestroyWindow(Pointer_On.Window);
	SDL_Quit();
}