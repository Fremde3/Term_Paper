#pragma once

void Load_Backgroung_Image(struct Pointer_On* Pointer_On, int variant_of_background_image);

int clickability_of_titul_list(Pointer_On Pointer_On, int number_of_picture, SDL_Event user_click);

int clickability_of_main_menu(Its Its, Pointer_On Pointer_On, int number_of_picture, SDL_Event user_click);

int clickability_of_game_1(Pointer_On Pointer_On, int number_of_picture, SDL_Event user_click);

int clickability_of_game_2(Pointer_On Pointer_On, int number_of_picture, SDL_Event user_click);

void Navigation();
