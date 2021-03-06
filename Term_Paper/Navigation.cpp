#include <stdio.h>
#include <stdbool.h>
#include "SDL.h"
#include "Demo_Move.h"
#include "Navigation.h"

struct Pointer_On
{
	SDL_Window * Window;
	SDL_Surface* Window_Surface;
	SDL_Surface* Screen_Surface;
	SDL_Surface* Image;
};

struct Its
{
	/*1 - demo game 1
	2 - game 1
	3 - demo game 2
	4 - game 2*/
	bool Demo_Or_Game_Not_Started;
	int type_of_game;
};

void Load_Backgroung_Image(struct Pointer_On* Pointer_On, int variant_of_background_image)
{
	SDL_Rect dest;
	dest.x = 0;
	dest.y = 0;
	switch (variant_of_background_image)
	{
		case 1:
		{
			Pointer_On->Screen_Surface = SDL_GetWindowSurface(Pointer_On->Window);
			Pointer_On->Image = SDL_LoadBMP("title_image.bmp");
			SDL_BlitSurface(Pointer_On->Image, NULL, Pointer_On->Screen_Surface, &dest);
			SDL_UpdateWindowSurface(Pointer_On->Window);
			break;
		}
		case 2:
		{
			Pointer_On->Screen_Surface = SDL_GetWindowSurface(Pointer_On->Window);
			Pointer_On->Image = SDL_LoadBMP("FAQ.bmp");
			SDL_BlitSurface(Pointer_On->Image, NULL, Pointer_On->Screen_Surface, &dest);
			SDL_UpdateWindowSurface(Pointer_On->Window);
			break;
		}
		case 3:
		{
			Pointer_On->Screen_Surface = SDL_GetWindowSurface(Pointer_On->Window);
			Pointer_On->Image = SDL_LoadBMP("main_menu.bmp");
			SDL_BlitSurface(Pointer_On->Image, NULL, Pointer_On->Screen_Surface, &dest);
			SDL_UpdateWindowSurface(Pointer_On->Window);
			break;
		}
		case 4:
		{
			Pointer_On->Screen_Surface = SDL_GetWindowSurface(Pointer_On->Window);
			Pointer_On->Image = SDL_LoadBMP("game_1.bmp");
			SDL_BlitSurface(Pointer_On->Image, NULL, Pointer_On->Screen_Surface, &dest);
			SDL_UpdateWindowSurface(Pointer_On->Window);
			break;
		}
		case 5:
		{
			Pointer_On->Screen_Surface = SDL_GetWindowSurface(Pointer_On->Window);
			Pointer_On->Image = SDL_LoadBMP("game_2.bmp");
			SDL_BlitSurface(Pointer_On->Image, NULL, Pointer_On->Screen_Surface, &dest);
			SDL_UpdateWindowSurface(Pointer_On->Window);
			break;
		}
		case 6:
		{
			Pointer_On->Screen_Surface = SDL_GetWindowSurface(Pointer_On->Window);
			Pointer_On->Image = SDL_LoadBMP("save_position.bmp");
			SDL_BlitSurface(Pointer_On->Image, NULL, Pointer_On->Screen_Surface, &dest);
			SDL_UpdateWindowSurface(Pointer_On->Window);
			break;
		}
	}
}

//clickability_of_titul_list
int clickability_of_titul_list(struct Pointer_On Pointer_On,
	int number_of_picture, SDL_Event user_click)
{
	//click on main menu
	if (user_click.button.button == SDL_BUTTON_LEFT
		&& user_click.button.x >= 235 && user_click.button.x <= 361
		&& user_click.button.y >= 300 && user_click.button.y <= 371
		&& number_of_picture == 1)
	{
		number_of_picture = 3;//main menu
		Load_Backgroung_Image(&Pointer_On, number_of_picture);
	}

	//click on FAQ
	if (user_click.button.button == SDL_BUTTON_LEFT
		&& user_click.button.x >= 201 && user_click.button.x <= 398
		&& user_click.button.y >= 405 && user_click.button.y <= 464
		&& number_of_picture == 1)
	{
		number_of_picture = 2;//FAQ
		Load_Backgroung_Image(&Pointer_On, number_of_picture);
	}

	//click on exit
	if (user_click.button.button == SDL_BUTTON_LEFT
		&& user_click.button.x >= 244 && user_click.button.x <= 355
		&& user_click.button.y >= 498 && user_click.button.y <= 543
		&& number_of_picture == 1)
	{
		SDL_DestroyWindow(Pointer_On.Window);
		SDL_Quit();
	}
	return number_of_picture;
}

//clickability_of_main_menu
int clickability_of_main_menu(struct Its Its, struct Pointer_On Pointer_On,
	int number_of_picture, SDL_Event user_click)
{
	//main_menu
	if (user_click.button.button == SDL_BUTTON_LEFT
		&& user_click.button.x >= 27 && user_click.button.x <= 226
		&& user_click.button.y >= 26 && user_click.button.y <= 80
		&& number_of_picture == 3)
	{
		number_of_picture = 1;
		Load_Backgroung_Image(&Pointer_On, number_of_picture);
	}
	//game_1_demo
	if (user_click.button.button == SDL_BUTTON_LEFT
		&& user_click.button.x >= 16  && user_click.button.x <= 576
		&& user_click.button.y >= 206 && user_click.button.y <= 252
		&& number_of_picture == 3)
	{
		number_of_picture = 4;
		Load_Backgroung_Image(&Pointer_On, number_of_picture);
		Its.type_of_game = 1;
	}
	//game_1
	if (user_click.button.button == SDL_BUTTON_LEFT
		&& user_click.button.x >= 20 && user_click.button.x <= 579
		&& user_click.button.y >= 318 && user_click.button.y <= 363
		&& number_of_picture == 3)
	{
		number_of_picture = 4;
		Load_Backgroung_Image(&Pointer_On, number_of_picture);
		Its.type_of_game = 2;
	}
	//game_2_demo
	if (user_click.button.button == SDL_BUTTON_LEFT
		&& user_click.button.x >= 17 && user_click.button.x <= 575
		&& user_click.button.y >= 419 && user_click.button.y <= 459
		&& number_of_picture == 3)
	{
		number_of_picture = 5;
		Load_Backgroung_Image(&Pointer_On, number_of_picture);
		Its.type_of_game = 3;
	}
	//game_2
	if (user_click.button.button == SDL_BUTTON_LEFT
		&& user_click.button.x >= 7 && user_click.button.x <= 592
		&& user_click.button.y >= 517 && user_click.button.y <= 563
		&& number_of_picture == 3)
	{
		number_of_picture = 5;
		Load_Backgroung_Image(&Pointer_On, number_of_picture);
		Its.type_of_game = 4;
	}
	return number_of_picture;
}

//clickability_of_FAQ
int clickability_of_FAQ(struct Pointer_On Pointer_On,
	int number_of_picture, SDL_Event user_click)
{
	//main_menu
	if (user_click.button.button == SDL_BUTTON_LEFT
		&& user_click.button.x >= 27 && user_click.button.x <= 226
		&& user_click.button.y >= 26 && user_click.button.y <= 80
		&& number_of_picture == 2)
	{
		number_of_picture = 1;
		Load_Backgroung_Image(&Pointer_On, number_of_picture);
	}
	return number_of_picture;
}

//clickability_of_game_1
int clickability_of_game_1(struct Pointer_On Pointer_On,
	int number_of_picture, SDL_Event user_click)
{
	//main_menu
	if (user_click.button.button == SDL_BUTTON_LEFT
		&& user_click.button.x >= 61 && user_click.button.x <= 185
		&& user_click.button.y >= 25 && user_click.button.y <= 77
		&& number_of_picture == 4)
	{
		number_of_picture = 6;
		Load_Backgroung_Image(&Pointer_On, number_of_picture);
	}
	return number_of_picture;
}

//clickability_of_game_2
int clickability_of_game_2(struct Pointer_On Pointer_On,
	int number_of_picture, SDL_Event user_click)
{
	//main_menu
	if (user_click.button.button == SDL_BUTTON_LEFT
		&& user_click.button.x >= 61 && user_click.button.x <= 185
		&& user_click.button.y >= 25 && user_click.button.y <= 77
		&& number_of_picture == 5)
	{
		number_of_picture = 6;
		Load_Backgroung_Image(&Pointer_On, number_of_picture);
	}
	return number_of_picture;
}

int clickability_save_menu(struct Pointer_On Pointer_On,
	int number_of_picture, SDL_Event user_click)
{
	if (user_click.button.button == SDL_BUTTON_LEFT
		&& user_click.button.x >= 242 && user_click.button.x <= 357
		&& user_click.button.y >= 158 && user_click.button.y <= 212
		&& number_of_picture == 5)
	{
		number_of_picture = 3;
		Load_Backgroung_Image(&Pointer_On, number_of_picture);
	}
	return number_of_picture;
}

//making navigation
void Navigation()
{
	/*
		number_of_picture:
		1 - titul list
		2 - FAQ
		3 - main menu
		4 - game 1
		5 - game 2
	*/
	int number_of_picture = 1;
	struct Pointer_On Pointer_On;
	struct Its Its;
	Its.Demo_Or_Game_Not_Started = true;
	Its.type_of_game = NULL;
	Pointer_On.Window = SDL_CreateWindow("Curs Project",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600,
		600, SDL_WINDOW_SHOWN);
	SDL_Event user_click;
	Load_Backgroung_Image(&Pointer_On, number_of_picture);
	//navigation cycle
	while (Its.Demo_Or_Game_Not_Started)
	{
		SDL_PollEvent(&user_click);
		number_of_picture = clickability_of_titul_list
		(Pointer_On, number_of_picture, user_click);
		number_of_picture = clickability_of_main_menu 
		(Its, Pointer_On, number_of_picture, user_click);
		number_of_picture = clickability_of_FAQ       
		(Pointer_On, number_of_picture, user_click);
		number_of_picture = clickability_of_game_1    
		(Pointer_On, number_of_picture, user_click);
		number_of_picture = clickability_of_game_2    
		(Pointer_On, number_of_picture, user_click);
	}
}