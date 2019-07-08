#include "stdafx.h"

#include "gui_framework.h"
#include <process.h>


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 532;
const int SCREEN_BPP = 32;
const int def_x = 10;
const int def_y = 10;
int tot = 0;
int second_click = 0;
int slots[num_of_slots];

SDL_Surface *chess = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *white = NULL;
SDL_Surface *black = NULL;
SDL_Surface *new_game = NULL;
SDL_Surface *load_game = NULL;
SDL_Surface *player_vs_player = NULL;
SDL_Surface *player_vs_computer = NULL;
SDL_Surface *quit1 = NULL;

SDL_Surface *setting = NULL;
SDL_Surface *difficulty = NULL;
SDL_Surface *set_user_color1 = NULL;
SDL_Surface *cancel = NULL;

SDL_Surface *c1 = NULL;
SDL_Surface *c2 = NULL;
SDL_Surface *c3 = NULL;
SDL_Surface *c4 = NULL;
SDL_Surface *best = NULL;
SDL_Surface *white1 = NULL;
SDL_Surface *black1 = NULL;
SDL_Surface *your_pick = NULL;
SDL_Surface *cancel2 = NULL;
SDL_Surface *start1 = NULL;

SDL_Surface *long_white = NULL;
SDL_Surface *long_black = NULL;
SDL_Surface *nums = NULL;
SDL_Surface *letters = NULL;
SDL_Surface *stripe_hight = NULL;
SDL_Surface *stripe_width = NULL;
SDL_Surface *restart_game = NULL;
SDL_Surface *main_menu2 = NULL;
SDL_Surface *save_game1 = NULL;
SDL_Surface *quit2 = NULL;

SDL_Surface *pick_a_piece_black = NULL;
SDL_Surface *pick_apiece_white = NULL;
SDL_Surface *place_the_piece_black = NULL;
SDL_Surface *place_the_piece_white = NULL;

SDL_Surface *check = NULL;
SDL_Surface *mate = NULL;

SDL_Surface *invalid_move = NULL;
SDL_Surface *empty_square = NULL;
SDL_Surface *not_your_piece = NULL;
SDL_Surface *not_in_board = NULL;


SDL_Surface *slot1 = NULL;
SDL_Surface *slot2 = NULL;
SDL_Surface *slot3 = NULL;
SDL_Surface *slot4 = NULL;
SDL_Surface *slot5 = NULL;
SDL_Surface *slot6 = NULL;
SDL_Surface *slot7 = NULL;
SDL_Surface *slot8 = NULL;
SDL_Surface *slot9 = NULL;
SDL_Surface *slot10 = NULL;
SDL_Surface *slot1g = NULL;
SDL_Surface *slot2g = NULL;
SDL_Surface *slot3g = NULL;
SDL_Surface *slot4g = NULL;
SDL_Surface *slot5g = NULL;
SDL_Surface *slot6g = NULL;
SDL_Surface *slot7g = NULL;
SDL_Surface *slot8g = NULL;
SDL_Surface *slot9g = NULL;
SDL_Surface *slot10g = NULL;

SDL_Surface *queen = NULL;
SDL_Surface *rook = NULL;
SDL_Surface *knight = NULL;
SDL_Surface *bishop = NULL;

SDL_Surface *load_game1 = NULL;

SDL_Surface *save_game2 = NULL;

SDL_Event event;

SDL_Rect clip[24];



int gui(char board[BOARD_SIZE][BOARD_SIZE]){

	if (init() == 0){
		return 1;
	}

	if (load_files() == 0){
		return 1;
	}
	set_clip();
	clear_board(board);
	init_board_(board);

	set_main_menu(board);


	clean_up();
	return tot;
}

void draw_board(char board[BOARD_SIZE][BOARD_SIZE]){
	int i, j, squer_color;
	char piece;

	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 195, 195, 195));



	if (strcmp(curr_turn, "White") == 0){
		if (second_click == 1)
			apply_surface(530, 60, place_the_piece_white, screen);
		else
			apply_surface(530, 60, pick_apiece_white, screen);
	}
	else{
		if (second_click == 1)
			apply_surface(530, 60, place_the_piece_black, screen);
		else
			apply_surface(530, 60, pick_a_piece_black, screen);
	}


	for (j = 0; j < BOARD_SIZE; j++){
		for (i = 0; i < BOARD_SIZE; i++){
			piece = board[i][j];
			squer_color = get_squer_color(i, j);
			if (squer_color){
				print_white_squer(piece, i, j);
			}
			else{
				print_black_squer(piece, i, j);
			}
		}
	}

	apply_surface(0, 0, nums, screen);
	apply_surface(0, 522, letters, screen);
	apply_surface(10, 10, stripe_width, screen);
	apply_surface(10, 10, stripe_hight, screen);
	apply_surface(10, 522, stripe_width, screen);
	apply_surface(522, 10, stripe_hight, screen);
	apply_surface(600, 50, restart_game, screen);
	apply_surface(625, 150, save_game1, screen);
	apply_surface(625, 250, main_menu2, screen);
	apply_surface(625, 450, quit2, screen);

	if (SDL_Flip(screen) == -1){
		tot = 11;
	}
}

void print_white_squer(char piece, int i, int j){

	if (piece == WHITE_PAWN)
		apply_surface2(def_x + 64 * i, def_y + 64 * (7 - j), chess, screen, &W_PAWN_W);
	if (piece == BLACK_PAWN)
		apply_surface2(def_x + 64 * i, def_y + 64 * (7 - j), chess, screen, &B_PAWN_W);

	if (piece == WHITE_ROOK)
		apply_surface2(def_x + 64 * i, def_y + 64 * (7 - j), chess, screen, &W_ROOK_W);
	if (piece == BLACK_ROOK)
		apply_surface2(def_x + 64 * i, def_y + 64 * (7 - j), chess, screen, &B_ROOK_W);

	if (piece == WHITE_KNIGHT)
		apply_surface2(def_x + 64 * i, def_y + 64 * (7 - j), chess, screen, &W_KNIGHT_W);
	if (piece == BLACK_KNIGHT)
		apply_surface2(def_x + 64 * i, def_y + 64 * (7 - j), chess, screen, &B_KNIGHT_W);

	if (piece == WHITE_BISHOP)
		apply_surface2(def_x + 64 * i, def_y + 64 * (7 - j), chess, screen, &W_BISHOP_W);
	if (piece == BLACK_BISHOP)
		apply_surface2(def_x + 64 * i, def_y + 64 * (7 - j), chess, screen, &B_BISHOP_W);

	if (piece == WHITE_QUEEN)
		apply_surface2(def_x + 64 * i, def_y + 64 * (7 - j), chess, screen, &W_QUEEN_W);
	if (piece == BLACK_QUEEN)
		apply_surface2(def_x + 64 * i, def_y + 64 * (7 - j), chess, screen, &B_QUEEN_W);

	if (piece == WHITE_KING)
		apply_surface2(def_x + 64 * i, def_y + 64 * (7 - j), chess, screen, &W_KING_W);
	if (piece == BLACK_KING)
		apply_surface2(def_x + 64 * i, def_y + 64 * (7 - j), chess, screen, &B_KING_W);

	if (piece == EMPTY)
		apply_surface(def_x + 64 * i, def_y + 64 * (7 - j), white, screen);

}

void print_black_squer(char piece, int i, int j){

	if (piece == WHITE_PAWN)
		apply_surface2(def_x + 64 * i, def_y + 64 * (7 - j), chess, screen, &W_PAWN_B);
	if (piece == BLACK_PAWN)
		apply_surface2(def_x + 64 * i, def_y + 64 * (7 - j), chess, screen, &B_PAWN_B);

	if (piece == WHITE_ROOK)
		apply_surface2(def_x + 64 * i, def_y + 64 * (7 - j), chess, screen, &W_ROOK_B);
	if (piece == BLACK_ROOK)
		apply_surface2(def_x + 64 * i, def_y + 64 * (7 - j), chess, screen, &B_ROOK_B);

	if (piece == WHITE_KNIGHT)
		apply_surface2(def_x + 64 * i, def_y + 64 * (7 - j), chess, screen, &W_KNIGHT_B);
	if (piece == BLACK_KNIGHT)
		apply_surface2(def_x + 64 * i, def_y + 64 * (7 - j), chess, screen, &B_KNIGHT_B);

	if (piece == WHITE_BISHOP)
		apply_surface2(def_x + 64 * i, def_y + 64 * (7 - j), chess, screen, &W_BISHOP_B);
	if (piece == BLACK_BISHOP)
		apply_surface2(def_x + 64 * i, def_y + 64 * (7 - j), chess, screen, &B_BISHOP_B);

	if (piece == WHITE_QUEEN)
		apply_surface2(def_x + 64 * i, def_y + 64 * (7 - j), chess, screen, &W_QUEEN_B);
	if (piece == BLACK_QUEEN)
		apply_surface2(def_x + 64 * i, def_y + 64 * (7 - j), chess, screen, &B_QUEEN_B);

	if (piece == WHITE_KING)
		apply_surface2(def_x + 64 * i, def_y + 64 * (7 - j), chess, screen, &W_KING_B);
	if (piece == BLACK_KING)
		apply_surface2(def_x + 64 * i, def_y + 64 * (7 - j), chess, screen, &B_KING_B);

	if (piece == EMPTY)
		apply_surface(def_x + 64 * i, def_y + 64 * (7 - j), black, screen);
}

/*0 is black and 1 in white*/
int get_squer_color(int i, int j){


	if ((i % 2 == 0) && (j % 2 == 1))
		return 1;
	else if ((i % 2 == 1) && (j % 2 == 0))
		return 1;

	else if ((i % 2 == 0) && (j % 2 == 0))
		return 0;
	else if ((i % 2 == 1) && (j % 2 == 1))
		return 0;

	return 0;
}

void set_main_menu(char board[BOARD_SIZE][BOARD_SIZE]){
	int x1, y1;

	tot = 0;

	minimax_depth = 1;
	user_color = "White";
	comp_color = "Black";
	curr_turn = "White";
	game_still_on = 1;
	game_mode = 1;

	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 195, 195, 195));
	apply_surface(250, 80, new_game, screen);
	apply_surface(250, 220, load_game, screen);
	apply_surface(250, 370, quit1, screen);


	x1 = 0;
	y1 = 0;

	while (tot == 0){
		if (SDL_PollEvent(&event)){

			if (SDL_Flip(screen) == -1){
				tot = 11;
				break;
			}

			if (event.type == SDL_QUIT){
				tot = 10;
				clean_up();
				exit(0);
			}

			if (event.type == SDL_MOUSEBUTTONDOWN){
				x1 = event.motion.x;
				y1 = event.motion.y;
			}


			/*click on NEW GAME*/
			if ((250 < x1) && (x1 < 550) && (80 < y1) && (y1 < 160)){
				clear_board(board);
				init_board_(board);
				set_player_selection(board);
				break;
			}

			/*click on LOAD GAME*/
			if ((250 < x1) && (x1 < 550) && (220 < y1) && (y1 < 300)){
				set_load_game(board);
				break;
			}

			/*click on QUIT*/
			if ((250 < x1) && (x1 < 550) && (370 < y1) && (y1 < 450)){
				tot = 12;
				clean_up();
				exit(0);
			}
		}
	}
}


void set_load_game(char board[BOARD_SIZE][BOARD_SIZE]){
	int x1, y1;

	tot = 0;

	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 195, 195, 195));
	apply_surface(200, 10, load_game1, screen);

	set_slots();


	apply_surface(640, 467, cancel, screen);


	x1 = 0;
	y1 = 0;

	while (tot == 0){
		if (SDL_PollEvent(&event)){

			if (SDL_Flip(screen) == -1){
				tot = 11;
				break;
			}


			if (event.type == SDL_QUIT){
				tot = 10;
				clean_up();
				exit(0);
			}

			if (event.type == SDL_MOUSEBUTTONDOWN){
				x1 = event.motion.x;
				y1 = event.motion.y;
			}


			/*click on slot1*/
			if ((100 < x1) && (x1 < 210) && (200 < y1) && (y1 < 50) && 1 < num_of_slots && slots[0]){
				if (slots[0]){
					load2(board, "1.xml");
				}
				tot = 4;
			}

			/*click on slot2*/
			if ((230 < x1) && (x1 < 340) && (200 < y1) && (y1 < 250) && 2 < num_of_slots && slots[1]){
				if (slots[1]){
					load2(board, "2.xml");
				}
				tot = 4;
			}

			/*click on slot3*/
			if ((360 < x1) && (x1 < 470) && (200 < y1) && (y1 < 250) && 3 < num_of_slots && slots[2]){
				if (slots[2]){
					load2(board, "3.xml");
				}
				tot = 4;

			}

			/*click on slot4*/
			if ((490 < x1) && (x1 < 600) && (200 < y1) && (y1 < 250) && 4 < num_of_slots && slots[3]){
				if (slots[3]) {
					load2(board, "4.xml");
				}
				tot = 4;
			}

			/*click on slot5*/
			if ((620 < x1) && (x1 < 730) && (200 < y1) && (y1 < 250) && 5 < num_of_slots && slots[4]){
				if (slots[4]){
					load2(board, "5.xml");
				}
				tot = 4;

			}

			/*click on slot6*/
			if ((100 < x1) && (x1 < 210) && (300 < y1) && (y1 < 350) && 6 < num_of_slots && slots[5]){
				if (slots[5]){
					load2(board, "6.xml");
				}
				tot = 4;
			}

			/*click on slot7*/
			if ((230 < x1) && (x1 < 340) && (300 < y1) && (y1 < 350) && 7 < num_of_slots && slots[6]){
				if (slots[6]){
					load2(board, "7.xml");
				}
				tot = 4;
			}

			/*click on slot8*/
			if ((360 < x1) && (x1 < 470) && (300 < y1) && (y1 < 350) && 8 <= num_of_slots && slots[7]){
				if (slots[7]){
					load2(board, "8.xml");
				}
				tot = 4;

			}

			/*click on slot9*/
			if ((490 < x1) && (x1 < 600) && (300 < y1) && (y1 < 350) && 9 <= num_of_slots && slots[8]){
				if (slots[8]) {
					load2(board, "9.xml");
				}
				tot = 4;
			}

			/*click on slot10*/
			if ((620 < x1) && (x1 < 730) && (300 < y1) && (y1 < 350) && 10 <= num_of_slots && slots[9]){
				if (slots[9]){
					load2(board, "10.xml");
				}
				tot = 4;

			}


			/*click on cancel*/
			if ((640 < x1) && (x1 < 790) && (467 < y1) && (y1 < 522)){
				tot = 3;
				break;
			}
		}
	}


	if (tot == 1){
		start_game(board);
	}
	else if (tot == 2){
		set_setting(board);
	}
	else if (tot == 3){
		set_main_menu(board);
	}
	else if (tot == 4){

		start_game(board);
	}
}

void set_slots(){
	if (file_exist("1.xml") && 1 <= num_of_slots) {
		slots[0] = 1;
		apply_surface(100, 200, slot1g, screen);
	}
	else if (1 <= num_of_slots) {
		slots[0] = 0;
		apply_surface(100, 200, slot1, screen);
	}

	if (file_exist("2.xml") && 2 <= num_of_slots) {
		slots[1] = 1;
		apply_surface(230, 200, slot2g, screen);
	}
	else if (2 <= num_of_slots) {
		slots[1] = 0;
		apply_surface(230, 200, slot2, screen);
	}

	if (file_exist("3.xml") && 3 <= num_of_slots) {
		slots[2] = 1;
		apply_surface(360, 200, slot3g, screen);
	}
	else if (3 <= num_of_slots) {
		slots[2] = 0;
		apply_surface(360, 200, slot3, screen);
	}

	if (file_exist("4.xml") && 4 <= num_of_slots) {
		slots[3] = 1;
		apply_surface(490, 200, slot4g, screen);
	}
	else if (4 <= num_of_slots) {
		slots[3] = 0;
		apply_surface(490, 200, slot4, screen);
	}

	if (file_exist("5.xml") && 5 <= num_of_slots) {
		slots[4] = 1;
		apply_surface(620, 200, slot5g, screen);
	}
	else if (5 <= num_of_slots) {
		slots[4] = 0;
		apply_surface(620, 200, slot5, screen);
	}




	if (file_exist("6.xml") && 6 <= num_of_slots) {
		slots[5] = 1;
		apply_surface(100, 300, slot6g, screen);
	}
	else if (6 <= num_of_slots) {
		slots[0] = 0;
		apply_surface(100, 300, slot6, screen);
	}

	if (file_exist("7.xml") && 7 <= num_of_slots) {
		slots[6] = 1;
		apply_surface(230, 300, slot7g, screen);
	}
	else if (7 <= num_of_slots) {
		slots[6] = 0;
		apply_surface(230, 300, slot7, screen);
	}

	if (file_exist("8.xml") && 8 <= num_of_slots) {
		slots[7] = 1;
		apply_surface(360, 300, slot8g, screen);
	}
	else if (8 <= num_of_slots) {
		slots[7] = 0;
		apply_surface(360, 300, slot8, screen);
	}

	if (file_exist("9.xml") && 9 <= num_of_slots) {
		slots[8] = 1;
		apply_surface(490, 300, slot9g, screen);
	}
	else if (9 <= num_of_slots) {
		slots[8] = 0;
		apply_surface(490, 300, slot9, screen);
	}

	if (file_exist("10.xml") && 10 <= num_of_slots) {
		slots[9] = 1;
		apply_surface(620, 300, slot10g, screen);
	}
	else if (10<=num_of_slots) {
		slots[9] = 0;
		apply_surface(620, 300, slot10, screen);
	}



}

void set_player_selection(char board[BOARD_SIZE][BOARD_SIZE]){
	int x1, y1;

	tot = 0;

	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 195, 195, 195));
	apply_surface(150, 150, player_vs_player, screen);
	apply_surface(150, 300, player_vs_computer, screen);
	apply_surface(640, 467, cancel, screen);


	x1 = 0;
	y1 = 0;

	while (tot == 0){
		if (SDL_PollEvent(&event)){

			if (SDL_Flip(screen) == -1){
				tot = 11;
				break;
			}


			if (event.type == SDL_QUIT){
				tot = 10;
				clean_up();
				exit(0);
			}

			if (event.type == SDL_MOUSEBUTTONDOWN){
				x1 = event.motion.x;
				y1 = event.motion.y;
			}


			/*click on player_vs_player*/
			if ((150 < x1) && (x1 < 650) && (150 < y1) && (y1 < 230)){
				game_mode = 1;
				tot = 1;
				break;

			}

			/*click on player_vs_computer*/
			if ((150 < x1) && (x1 < 650) && (300 < y1) && (y1 < 380)){
				game_mode = 2;
				tot = 2;
				break;
			}

			/*click on cancel*/
			if ((640 < x1) && (x1 < 790) && (467 < y1) && (y1 < 522)){
				tot = 3;
				break;
			}
		}
	}


	if (tot == 1){
		start_game(board);
	}
	else if (tot == 2){
		set_setting(board);
	}
	else if (tot == 3){
		set_main_menu(board);
	}
}

void draw_setting_screen(char board[BOARD_SIZE][BOARD_SIZE]){

	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 195, 195, 195));
	apply_surface(240, 10, setting, screen);
	apply_surface(30, 150, set_user_color1, screen);
	apply_surface(90, 250, white1, screen);
	apply_surface(240, 250, black1, screen);
	apply_surface(30, 340, difficulty, screen);
	apply_surface(40, 450, c1, screen);
	apply_surface(110, 450, c2, screen);
	apply_surface(180, 450, c3, screen);
	apply_surface(250, 450, c4, screen);
	apply_surface(320, 450, best, screen);
	apply_surface(550, 120, your_pick, screen);


	if (strcmp(user_color, "White") == 0)
		apply_surface(600, 200, white1, screen);

	if (strcmp(user_color, "Black") == 0)
		apply_surface(600, 200, black1, screen);

	if (minimax_depth == 1)
		apply_surface(640, 250, c1, screen);

	if (minimax_depth == 2)
		apply_surface(640, 250, c2, screen);

	if (minimax_depth == 3)
		apply_surface(640, 250, c3, screen);

	if (minimax_depth == 4)
		apply_surface(640, 250, c4, screen);

	if (minimax_depth == -1)
		apply_surface(610, 250, best, screen);

	apply_surface(570, 360, start1, screen);
	apply_surface(640, 467, cancel, screen);

}

void set_save(char board[BOARD_SIZE][BOARD_SIZE]){
	int x1, y1;

	tot = 0;

	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 195, 195, 195));
	apply_surface(200, 10, save_game2, screen);


	set_slots();

	apply_surface(640, 467, cancel, screen);


	x1 = 0;
	y1 = 0;

	while (tot == 0){
		if (SDL_PollEvent(&event)){

			if (SDL_Flip(screen) == -1){
				tot = 11;
				break;
			}


			if (event.type == SDL_QUIT){
				tot = 10;
				clean_up();
				exit(0);

			}

			if (event.type == SDL_MOUSEBUTTONDOWN){
				x1 = event.motion.x;
				y1 = event.motion.y;
			}


			/*click on slot1*/
			if ((100 < x1) && (x1 < 210) && (200 < y1) && (y1 < 50) && 1 < num_of_slots && slots[0]){
				slots[0] = 1;
				save_game_gui(board, "1.xml");
				tot = 4;
			}

			/*click on slot2*/
			if ((230 < x1) && (x1 < 340) && (200 < y1) && (y1 < 250) && 2 < num_of_slots && slots[1]){
				slots[1] = 1;
				save_game_gui(board, "2.xml");
				tot = 4;
			}

			/*click on slot3*/
			if ((360 < x1) && (x1 < 470) && (200 < y1) && (y1 < 250) && 3 < num_of_slots && slots[2]){
				slots[2] = 1;
				save_game_gui(board, "3.xml");
				tot = 4;
			}

			/*click on slot4*/
			if ((490 < x1) && (x1 < 600) && (200 < y1) && (y1 < 250) && 4 < num_of_slots && slots[3]){
				slots[3] = 1;
				save_game_gui(board, "4.xml");
				tot = 4;
			}

			/*click on slot5*/
			if ((620 < x1) && (x1 < 730) && (200 < y1) && (y1 < 250) && 5 < num_of_slots && slots[4]){
				slots[4] = 1;
				save_game_gui(board, "5.xml");
				tot = 4;

			}

			/*click on slot6*/
			if ((100 < x1) && (x1 < 210) && (300 < y1) && (y1 < 350) && 6 < num_of_slots){
				slots[5] = 1;
				save_game_gui(board, "6.xml");
				tot = 4;
			}

			/*click on slot7*/
			if ((230 < x1) && (x1 < 340) && (300 < y1) && (y1 < 350) && 7 < num_of_slots){
				slots[6] = 1;
				save_game_gui(board, "7.xml");
				tot = 4;
			}

			/*click on slot8*/
			if ((360 < x1) && (x1 < 470) && (300 < y1) && (y1 < 350) && 8 <= num_of_slots ){
				slots[7] = 1;
				save_game_gui(board, "8.xml");
				tot = 4;

			}

			/*click on slot9*/
			if ((490 < x1) && (x1 < 600) && (300 < y1) && (y1 < 350) && 9 <= num_of_slots){
				slots[8] = 1;
				save_game_gui(board, "9.xml");
				tot = 4;
			}

			/*click on slot10*/
			if ((620 < x1) && (x1 < 730) && (300 < y1) && (y1 < 350) && 10 <= num_of_slots){
				slots[9] = 1;
				save_game_gui(board, "10.xml");
				tot = 4;

			}
			

			/*click on cancel*/
			if ((640 < x1) && (x1 < 790) && (467 < y1) && (y1 < 522)){
				tot = 3;
				break;
			}
		}
	}

	if (tot == 3){
		/*nothing happens and the game continue*/
		draw_board(board);
	}
	else if (tot == 4){
		/*the game is saved and the game continue*/
		draw_board(board);
	}
}

void choose_promotion(char prom[MAX_STR_LN]){
	int x1 = 0;
	int y1 = 0;


	apply_surface(200, 50, queen, screen);
	apply_surface(200, 150, rook, screen);
	apply_surface(200, 250, knight, screen);
	apply_surface(200, 350, bishop, screen);

	if (SDL_Flip(screen) == -1){
		tot = 11;
	}
	while (1){
		if (SDL_PollEvent(&event)){

			if (event.type == SDL_MOUSEBUTTONDOWN){
				x1 = event.motion.x;
				y1 = event.motion.y;
			}


			/*click on queen*/
			if (((200 < x1) && (x1 < 350) && (50 < y1) && (y1 < 105))){
				strcpy(prom, "queen");
				break;
			}

			/*click on rook*/
			else if (((200 < x1) && (x1 < 350) && (150 < y1) && (y1 < 205))){
				strcpy(prom, "rook");
				break;
			}

			/*click on knight*/
			else if (((200 < x1) && (x1 < 350) && (250 < y1) && (y1 < 305))){
				strcpy(prom, "knight");
				break;
			}

			/*click on bishop*/
			else if (((200 < x1) && (x1 < 350) && (350 < y1) && (y1 < 405))){
				strcpy(prom, "bishop");
				break;
			}
		}

	}
}

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination){
	SDL_Rect offset;

	offset.x = x;
	offset.y = y;

	SDL_BlitSurface(source, NULL, destination, &offset);
}

void apply_surface2(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip){
	SDL_Rect offset;

	offset.x = x;
	offset.y = y;

	SDL_BlitSurface(source, clip, destination, &offset);
}

int init(){
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
		return 0;
	}
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
	if (screen == NULL){
		return 0;
	}
	SDL_WM_SetCaption("Chess", NULL);
	return 1;
}

int load_files(){
	chess = load_image("chess.bmp");
	white = load_image("white.bmp");
	black = load_image("black.bmp");
	new_game = load_image("new_game.bmp");
	load_game = load_image("load_game.bmp");
	quit1 = load_image("quit.bmp");
	player_vs_player = load_image("player_vs_player.bmp");
	player_vs_computer = load_image("player_vs_computer.bmp");
	setting = load_image("setting.bmp");
	difficulty = load_image("difficulty.bmp");
	set_user_color1 = load_image("set_user_color1.bmp");
	cancel = load_image("cancel.bmp");

	c1 = load_image("c1.bmp");
	c2 = load_image("c2.bmp");
	c3 = load_image("c3.bmp");
	c4 = load_image("c4.bmp");
	best = load_image("best.bmp");
	white1 = load_image("white1.bmp");
	black1 = load_image("black1.bmp");
	your_pick = load_image("your_pick.bmp");
	cancel2 = load_image("cancel2.bmp");
	start1 = load_image("start1.bmp");

	long_white = load_image("long_white.bmp");
	long_black = load_image("long_black.bmp");
	nums = load_image("nums.bmp");
	letters = load_image("letters.bmp");
	stripe_hight = load_image("stripe_hight.bmp");
	stripe_width = load_image("stripe_width.bmp");
	restart_game = load_image("restart_game.bmp");
	main_menu2 = load_image("main_menu2.bmp");
	save_game1 = load_image("save_game1.bmp");
	quit2 = load_image("quit2.bmp");

	pick_a_piece_black = load_image("pick_a_piece_black.bmp");
	pick_apiece_white = load_image("pick_apiece_white.bmp");
	place_the_piece_black = load_image("place_the_piece_black.bmp");
	place_the_piece_white = load_image("place_the_piece_white.bmp");

	check = load_image("check.bmp");
	mate = load_image("mate.bmp");

	invalid_move = load_image("invalid_move.bmp");
	empty_square = load_image("empty_square.bmp");
	not_your_piece = load_image("not_your_piece.bmp");
	not_in_board = load_image("not_in_board.bmp");

	slot1 = load_image("slot1.bmp");
	slot2 = load_image("slot2.bmp");
	slot3 = load_image("slot3.bmp");
	slot4 = load_image("slot4.bmp");
	slot5 = load_image("slot5.bmp");
	slot6 = load_image("slot6.bmp");
	slot7 = load_image("slot7.bmp");
	slot8 = load_image("slot8.bmp");
	slot9 = load_image("slot9.bmp");
	slot10 = load_image("slot10.bmp");
	slot1g = load_image("slot1g.bmp");
	slot2g = load_image("slot2g.bmp");
	slot3g = load_image("slot3g.bmp");
	slot4g = load_image("slot4g.bmp");
	slot5g = load_image("slot5g.bmp");
	slot6g = load_image("slot6g.bmp");
	slot7g = load_image("slot7g.bmp");
	slot8g = load_image("slot8g.bmp");
	slot9g = load_image("slot9g.bmp");
	slot10g = load_image("slot10g.bmp");

	queen = load_image("queen.bmp");
	rook = load_image("rook.bmp");
	knight = load_image("knight.bmp");
	bishop = load_image("bishop.bmp");

	load_game1 = load_image("load_game1.bmp");

	save_game2 = load_image("save_game2.bmp");

	if (chess == NULL){
		return 0;
	}

	return 1;
}

void clean_up(){

	SDL_FreeSurface(chess);
	SDL_FreeSurface(white);
	SDL_FreeSurface(black);

	SDL_FreeSurface(new_game);
	SDL_FreeSurface(load_game);
	SDL_FreeSurface(quit1);

	SDL_FreeSurface(player_vs_player);
	SDL_FreeSurface(player_vs_computer);
	SDL_FreeSurface(cancel);

	SDL_FreeSurface(setting);
	SDL_FreeSurface(difficulty);
	SDL_FreeSurface(set_user_color1);




	SDL_FreeSurface(c1);
	SDL_FreeSurface(c2);
	SDL_FreeSurface(c3);
	SDL_FreeSurface(c4);
	SDL_FreeSurface(best);
	SDL_FreeSurface(white1);
	SDL_FreeSurface(black1);
	SDL_FreeSurface(your_pick);
	SDL_FreeSurface(cancel2);
	SDL_FreeSurface(start1);

	SDL_FreeSurface(long_white);
	SDL_FreeSurface(long_black);
	SDL_FreeSurface(nums);
	SDL_FreeSurface(letters);
	SDL_FreeSurface(stripe_hight);
	SDL_FreeSurface(stripe_width);
	SDL_FreeSurface(restart_game);
	SDL_FreeSurface(main_menu2);
	SDL_FreeSurface(save_game1);
	SDL_FreeSurface(quit2);

	SDL_FreeSurface(pick_a_piece_black);
	SDL_FreeSurface(pick_apiece_white);
	SDL_FreeSurface(place_the_piece_black);
	SDL_FreeSurface(place_the_piece_white);

	SDL_FreeSurface(check);
	SDL_FreeSurface(mate);

	SDL_FreeSurface(invalid_move);
	SDL_FreeSurface(empty_square);
	SDL_FreeSurface(not_your_piece);
	SDL_FreeSurface(not_in_board);


	SDL_FreeSurface(slot1);
	SDL_FreeSurface(slot2);
	SDL_FreeSurface(slot3);
	SDL_FreeSurface(slot4);
	SDL_FreeSurface(slot5);
	SDL_FreeSurface(slot6);
	SDL_FreeSurface(slot7);
	SDL_FreeSurface(slot8);
	SDL_FreeSurface(slot9);
	SDL_FreeSurface(slot10);
	SDL_FreeSurface(slot1g);
	SDL_FreeSurface(slot2g);
	SDL_FreeSurface(slot3g);
	SDL_FreeSurface(slot4g);
	SDL_FreeSurface(slot5g);
	SDL_FreeSurface(slot6g);
	SDL_FreeSurface(slot7g);
	SDL_FreeSurface(slot8g);
	SDL_FreeSurface(slot9g);
	SDL_FreeSurface(slot10g);

	SDL_FreeSurface(queen);
	SDL_FreeSurface(rook);
	SDL_FreeSurface(knight);
	SDL_FreeSurface(bishop);

	SDL_FreeSurface(load_game1);

	SDL_FreeSurface(save_game2);

	SDL_Quit();
}

void set_clip(){
	int i;


	W_PAWN_W.x = 2 * 64;
	W_PAWN_W.y = 4 * 64;
	W_PAWN_B.x = 0 * 64;
	W_PAWN_B.y = 4 * 64;

	B_PAWN_W.x = 1 * 64;
	B_PAWN_W.y = 4 * 64;
	B_PAWN_B.x = 3 * 64;
	B_PAWN_B.y = 4 * 64;

	W_BISHOP_W.x = 1 * 64;
	W_BISHOP_W.y = 0 * 64;
	W_BISHOP_B.x = 2 * 64;
	W_BISHOP_B.y = 0 * 64;

	B_BISHOP_W.x = 5 * 64;
	B_BISHOP_W.y = 0 * 64;
	B_BISHOP_B.x = 0 * 64;
	B_BISHOP_B.y = 0 * 64;

	W_ROOK_W.x = 4 * 64;
	W_ROOK_W.y = 1 * 64;
	W_ROOK_B.x = 5 * 64;
	W_ROOK_B.y = 1 * 64;

	B_ROOK_W.x = 2 * 64;
	B_ROOK_W.y = 1 * 64;
	B_ROOK_B.x = 3 * 64;
	B_ROOK_B.y = 1 * 64;

	W_KNIGHT_W.x = 2 * 64;
	W_KNIGHT_W.y = 3 * 64;
	W_KNIGHT_B.x = 3 * 64;
	W_KNIGHT_B.y = 3 * 64;

	B_KNIGHT_W.x = 1 * 64;
	B_KNIGHT_W.y = 3 * 64;
	B_KNIGHT_B.x = 0 * 64;
	B_KNIGHT_B.y = 3 * 64;

	W_QUEEN_W.x = 2 * 64;
	W_QUEEN_W.y = 2 * 64;
	W_QUEEN_B.x = 3 * 64;
	W_QUEEN_B.y = 2 * 64;

	B_QUEEN_W.x = 1 * 64;
	B_QUEEN_W.y = 2 * 64;
	B_QUEEN_B.x = 0 * 64;
	B_QUEEN_B.y = 2 * 64;

	W_KING_W.x = 3 * 64;
	W_KING_W.y = 0 * 64;
	W_KING_B.x = 4 * 64;
	W_KING_B.y = 0 * 64;

	B_KING_W.x = 1 * 64;
	B_KING_W.y = 1 * 64;
	B_KING_B.x = 0 * 64;
	B_KING_B.y = 1 * 64;


	for (i = 0; i < 24; i++){
		clip[i].w = 64;
		clip[i].h = 64;
	}


}


void set_setting(char board[BOARD_SIZE][BOARD_SIZE]){
	int x1, y1;

	tot = 0;

	draw_setting_screen(board);

	x1 = 0;
	y1 = 0;

	while (tot == 0){
		if (SDL_PollEvent(&event)){

			if (SDL_Flip(screen) == -1){
				tot = 11;
				break;
			}


			if (event.type == SDL_QUIT){
				tot = 10;
				clean_up();
				exit(0);
			}

			if (event.type == SDL_MOUSEBUTTONDOWN){
				x1 = event.motion.x;
				y1 = event.motion.y;
			}


			/*click on WHITE*/
			if ((90 < x1) && (x1 < 210) && (250 < y1) && (y1 < 290)){
				user_color = "White";
				comp_color = "Black";
				draw_setting_screen(board);
			}

			/*click on BLACK*/
			if ((240 < x1) && (x1 < 360) && (250 < y1) && (y1 < 290)){
				user_color = "Black";
				comp_color = "White";
				draw_setting_screen(board);
			}

			/*click on 1*/
			if ((40 < x1) && (x1 < 80) && (450 < y1) && (y1 < 50)){
				minimax_depth = 1;
				draw_setting_screen(board);
			}

			/*click on 2*/
			if ((110 < x1) && (x1 < 150) && (450 < y1) && (y1 < 500)){
				minimax_depth = 2;
				draw_setting_screen(board);
			}

			/*click on 3*/
			if ((180 < x1) && (x1 < 220) && (450 < y1) && (y1 < 500)){
				minimax_depth = 3;
				draw_setting_screen(board);
			}

			/*click on 4*/
			if ((250 < x1) && (x1 < 290) && (450 < y1) && (y1 < 500)){
				minimax_depth = 4;
				draw_setting_screen(board);
			}

			/*click on BEST*/
			if ((320 < x1) && (x1 < 420) && (450 < y1) && (y1 < 500)){
				minimax_depth = -1;
				draw_setting_screen(board);
			}

			/*click on START!*/
			if ((570 < x1) && (x1 < 750) && (360 < y1) && (y1 < 430)){
				tot = 1;
				break;
			}

			/*click on CANCEL*/
			if ((640 < x1) && (x1 < 790) && (467 < y1) && (y1 < 522)){
				tot = 2;
				break;
			}
		}
	}

	if (tot == 1)
		start_game(board);
	if (tot == 2)
		set_player_selection(board);

}

SDL_Surface *load_image(char* filename){
	SDL_Surface* loadedImage = NULL;


	SDL_Surface* optimizedImage = NULL;

	loadedImage = SDL_LoadBMP(filename);

	if (loadedImage != NULL){
		optimizedImage = SDL_DisplayFormat(loadedImage);

		SDL_FreeSurface(loadedImage);

		if (optimizedImage != NULL)
		{
			SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB(optimizedImage->format, 0, 0xFF, 0xFF));
		}
	}

	return optimizedImage;
}

void draw_mate(char board[BOARD_SIZE][BOARD_SIZE]){
	draw_board(board);
	apply_surface(211, 211, mate, screen);
	if (SDL_Flip(screen) == -1){
		tot = 11;
	}
	SDL_Delay(2000);
	draw_board(board);
	if (SDL_Flip(screen) == -1){
		tot = 11;
	}
}

void draw_check(char board[BOARD_SIZE][BOARD_SIZE]){
	draw_board(board);
	apply_surface(211, 211, check, screen);
	if (SDL_Flip(screen) == -1){
		tot = 11;
	}
	SDL_Delay(2000);
	draw_board(board);
	if (SDL_Flip(screen) == -1){
		tot = 11;
	}
}

void draw_invalid_move(char board[BOARD_SIZE][BOARD_SIZE]){

	draw_board(board);
	apply_surface(211, 211, invalid_move, screen);
	if (SDL_Flip(screen) == -1){
		tot = 11;
	}
	SDL_Delay(1500);
	draw_board(board);
	if (SDL_Flip(screen) == -1){
		tot = 11;
	}

}

void draw_not_your_piece(char board[BOARD_SIZE][BOARD_SIZE]){

	draw_board(board);
	apply_surface(211, 211, not_your_piece, screen);
	if (SDL_Flip(screen) == -1){
		tot = 11;
	}
	SDL_Delay(1500);
	draw_board(board);
	if (SDL_Flip(screen) == -1){
		tot = 11;
	}

}

void draw_empty_square(char board[BOARD_SIZE][BOARD_SIZE]){

	draw_board(board);
	apply_surface(211, 211, empty_square, screen);
	if (SDL_Flip(screen) == -1){
		tot = 11;
	}
	SDL_Delay(1500);
	draw_board(board);
	if (SDL_Flip(screen) == -1){
		tot = 11;
	}

}

void draw_not_in_board(char board[BOARD_SIZE][BOARD_SIZE]){

	draw_board(board);
	apply_surface(211, 211, not_in_board, screen);
	if (SDL_Flip(screen) == -1){
		tot = 11;
	}
	SDL_Delay(1500);
	draw_board(board);
	if (SDL_Flip(screen) == -1){
		tot = 11;
	}

}



void game2(char board[BOARD_SIZE][BOARD_SIZE]) {

	while (game_still_on == 1) {
		if (game_mode == 2) {
			if (strcmp(curr_turn, comp_color) == 0) {
				if (computer_turn2(board, comp_color)) {
					if (strcmp(curr_turn, "White") == 0)
						curr_turn = "Black";
					else curr_turn = "White";
				}
			}
			else {
				user_turn2(board);
				draw_board(board);
			}
		}
		else {
			user_turn2(board);
			draw_board(board);
		}
	}
	set_main_menu(board);
}

void user_turn2(char board[BOARD_SIZE][BOARD_SIZE]){
	char from[MAX_STR_LN] = "";
	char to[MAX_STR_LN] = "";
	char promotion[MAX_STR_LN] = "";

	int x1, x2, y1, y2, sy, fy;
	char sx, fx;

	tot = 0;


	x1 = 0;
	y1 = 0;

	x2 = 0;
	y2 = 0;

	sx = 0;
	fx = 0;

	sy = 0;
	fy = 0;


	while (tot == 0){

		draw_board(board);

		if (SDL_PollEvent(&event)){

			if (event.type == SDL_QUIT){
				tot = 10;
				clean_up();
				exit(0);
			}

			if (event.type == SDL_MOUSEBUTTONDOWN){

				if (second_click == 0){
					x1 = event.motion.x;
					y1 = event.motion.y;
				}
				else if (second_click == 1){
					x2 = event.motion.x;
					y2 = event.motion.y;
				}

				/*click on restart game*/
				if (((600 < x1) && (x1 < 750) && (50 < y1) && (y1 < 130)) || ((600 < x2) && (x2 < 750) && (50 < y2) && (y2 < 130))){
					tot = 1;
					second_click = 0;
					restart2(board);
					break;
				}

				/*click on SAVE GAME*/
				else if (((625 < x1) && (x1 < 725) && (150 < y1) && (y1 < 230)) || ((600 < x2) && (x2 < 700) && (150 < y2) && (y2 < 230))){
					set_save(board);
					second_click = 0;
					tot = 0;
				}

				/*click on MAIN MENU*/
				else if (((625 < x1) && (x1 < 725) && (250 < y1) && (y1 < 330)) || ((600 < x2) && (x2 < 700) && (250 < y2) && (y2 < 330))){
					tot = 3;
					second_click = 0;
					break;
				}

				/*click on QUIT*/
				else if (((625 < x1) && (x1 < 725) && (450 < y1) && (y1 < 490)) || ((600 < x2) && (x2 < 700) && (450 < y2) && (y2 < 490))){
					tot = 4;
					second_click = 0;
					clean_up();
					exit(0);
				}

				else if (second_click == 0){
					strcpy(from, "");

					sx = (x1 - def_x) / 64 + 'a';
					sy = (y1 - def_y) / 64;

					sy = 7 - sy + 1;

					sprintf(from, "<%c,%d>", sx, sy);
					second_click = 1;


					if (x1<10 || x1 >522 || y1<10 || y1>522){
						draw_not_in_board(board);
						second_click = 0;
					}

					else if (board[sx - 'a'][sy - 1] == EMPTY){
						draw_empty_square(board);
						second_click = 0;
					}

					else if (strcmp(curr_turn, "White") == 0){
						if (!check_if_pos_is_white(board[sx - 'a'][sy - 1])){
							draw_not_your_piece(board);
							second_click = 0;
						}

					}
					else if (strcmp(curr_turn, "Black") == 0){
						if (!check_if_pos_is_black(board[sx - 'a'][sy - 1])){
							draw_not_your_piece(board);
							second_click = 0;
						}
					}
				}

				else if (second_click == 1){
					strcpy(to, "");

					fx = (x2 - def_x) / 64 + 'a';
					fy = (y2 - def_y) / 64;

					fy = 7 - fy + 1;
					sprintf(to, "<%c,%d>", fx, fy);

					if (x2<10 || x2 >522 || y2<10 || y2>522){
						draw_not_in_board(board);
						second_click = 0;
					}

					else if (sx == fx && sy == fy) {
						sx = fx;
						sy = fy;
						sprintf(from, "<%c,%d>", sx, sy);
					}

					else if (check_if_pos_is_black(board[fx - 'a'][fy - 1]) && strcmp(curr_turn, "Black") == 0) {
						sx = fx;
						sy = fy;
						sprintf(from, "<%c,%d>", sx, sy);
					}

					else if (check_if_pos_is_white(board[fx - 'a'][fy - 1]) && strcmp(curr_turn, "White") == 0) {
						sx = fx;
						sy = fy;
						sprintf(from, "<%c,%d>", sx, sy);
					}



					else if (check_if_valid_input(from) && check_if_valid_input(to)) {
						if ((board[sx - 'a'][sy - 1] == 'm' && fy - 1 == 7) || (board[sx - 'a'][sy - 1] == 'M' && fy - 1 == 0))
							choose_promotion(promotion);
						if (make_move_user2(board, from, to, promotion)) {
							if (strcmp(curr_turn, "White") == 0) {
								curr_turn = "Black";
							}
							else {
								curr_turn = "White";
							}
							second_click = 0;
							break;
						}
						else{
							draw_invalid_move(board);
							second_click = 0;
						}

					}
				}
			}
		}
	}

	if (tot == 1){

	}
	if (tot == 2){

	}
	if (tot == 3){
		minimax_depth = 1;
		user_color = "White";
		comp_color = "Black";
		curr_turn = "White";
		game_still_on = 1;
		game_mode = 1;

		set_main_menu(board);
	}
	if (tot == 4){
		clean_up();
		exit(0);
	}
}

int computer_turn2(char board[BOARD_SIZE][BOARD_SIZE], char* comp_color){
	node* head = NULL;


	initial_minimax(board);

	draw_board(board);

	if (strcmp(comp_color, "White") == 0) {
		head = get_all_moves_black(board);
		if (head == NULL){
			game_still_on = 0;
			draw_mate(board);
			return 1;
		}
		if (check_if_black_in_check(board))
			draw_check(board);
		free_linked_list(head);
		head = NULL;
	}
	if (strcmp(comp_color, "Black") == 0) {
		head = get_all_moves_white(board);
		if (head == NULL) {
			game_still_on = 0;
			draw_mate(board);
			return 1;
		}
		if (check_if_white_in_check(board))
			draw_check(board);
		free_linked_list(head);
		head = NULL;
	}

	return 1;

}

int make_move_user2(char board[BOARD_SIZE][BOARD_SIZE], char from[MAX_STR_LN], char to[MAX_STR_LN], char promotion[MAX_STR_LN]) {
	node* head = NULL;
	node* curr = NULL;
	int col, row;
	char c;
	int legal = 0;
	char x[MAX_STR_LN] = " ";
	col = from[1] - 'a';
	row = from[3] - '0' - 1;
	if (strcmp(promotion, ""))
		sprintf(x, "%s to %s %s", from, to, promotion);
	else sprintf(x, "%s to %s", from, to);
	if (!(check_if_valid_position(to) && check_if_valid_position(from))){
		printf(WRONG_POSITION);
		return 0;
	}
	else if (((strcmp(curr_turn, "White") == 0) && (check_if_pos_is_black(board[col][row]))) || ((strcmp(curr_turn, "Black") == 0) && (check_if_pos_is_white(board[col][row]))) || (board[col][row] == EMPTY)){
		printf(NO_DICS);
		return 0;
	}
	else{
		c = board[col][row];
		if (c == 'm') head = get_moves_m(board, col, row, curr_turn);
		else if (c == 'M') head = get_moves_M(board, col, row, curr_turn);
		else if (c == 'b' || c == 'B') head = get_moves_b(board, col, row, curr_turn);
		else if (c == 'r' || c == 'R') head = get_moves_r(board, col, row, curr_turn);
		else if (c == 'n' || c == 'N') head = get_moves_n(board, col, row, curr_turn);
		else if (c == 'q' || c == 'Q') head = get_moves_q(board, col, row, curr_turn);
		else if (c == 'k' || c == 'K') head = get_moves_k(board, col, row, curr_turn);
	}

	curr = head;
	while (curr){
		if (strcmp(curr->move, x) == 0) {
			legal = 1;
			break;
		}
		/*temp = curr;*/
		curr = curr->next;
		/*free(temp);*/
	}
	free_linked_list(head);
	head = NULL;

	if (!legal) printf(ILLEGAL_MOVE);
	else {
		update_board_from_string(board, x);
		draw_board(board);
		if (strcmp(curr_turn, "White") == 0) {
			head = get_all_moves_black(board);
			if (head == NULL){
				game_still_on = 0;
				draw_mate(board);
				return 1;
			}
			if (check_if_black_in_check(board))
				draw_check(board);
			free_linked_list(head);
			head = NULL;
		}
		if (strcmp(curr_turn, "Black") == 0) {
			head = get_all_moves_white(board);
			if (head == NULL) {
				game_still_on = 0;
				draw_mate(board);
				return 1;
			}
			if (check_if_white_in_check(board))
				draw_check(board);
			free_linked_list(head);
			head = NULL;
		}
	}
	return legal;
}

void restart2(char board[BOARD_SIZE][BOARD_SIZE]){
	init_board_(board);
	draw_board(board);

	curr_turn = "White";
	game_still_on = 1;


	game2(board);
}

void save_game_gui(char board[BOARD_SIZE][BOARD_SIZE], char slot[MAX_STR_LN]) {
	int i, j;
	char content[9];

	FILE* xml_file = fopen(slot, "w");
	

	fprintf(xml_file, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
	fprintf(xml_file, "<game>\n");
	fprintf(xml_file, "\t<type>%u</type>\n", game_mode);
	if (minimax_depth>0 && minimax_depth<5)
		fprintf(xml_file, "\t<difficulty>%u</difficulty>\n", minimax_depth);
	else fprintf(xml_file, "\t<difficulty>Best</difficulty>\n");
	if (strcmp(user_color, "White") == 0)
		fprintf(xml_file, "\t<user_color>%s</user_color>\n", "White");
	else fprintf(xml_file, "\t<user_color>%s</user_color>\n", "Black");
	if (strcmp(curr_turn, "White") == 0)
		fprintf(xml_file, "\t<next_turn>%s</next_turn>\n", "White");
	else fprintf(xml_file, "\t<next_turn>%s</next_turn>\n", "Black");
	fprintf(xml_file, "\t<board>\n");
	for (i = 7; i >= 0; i--){
		content[8] = '\0';
		for (j = 0; j < 8; j++) {
			if (board[j][i] == EMPTY) content[j] = '_';
			else content[j] = board[j][i];
		}
		fprintf(xml_file, "\t\t<row_%u>%s</row_%u>\n", i + 1, content, i + 1);
	}
	fprintf(xml_file, "\t</board>\n");
	fprintf(xml_file, "</game>");
	fclose(xml_file);

}

int load2(char board[BOARD_SIZE][BOARD_SIZE], char x[200]){
	char c;
	char *line = (char *)calloc(100, sizeof(char));
	int pos, i;

	FILE* ipf = fopen(x, "r");
	if (!ipf) {
		return 0;
	}
	else {
		clear_board(board);
		while (1) {
			pos = 0;
			c = getc(ipf);
			if (c == EOF)
				break;
			while (c != EOF && c != '\n') {
				line[pos++] = (char)c;
				c = getc(ipf);
			}
			line[pos++] = '\0';
			if (c == '\n') pos = 0;
			if (strstr(line, "type") != NULL) {
				game_mode = line[7] - '0';
			}
			else if (strstr(line, "difficulty") != NULL) {
				if (strstr(line, "Best") != NULL)
					minimax_depth = -1;
				else minimax_depth = line[13] - '0';
			}
			else if (strstr(line, "user_color") != NULL) {
				if (strstr(line, "White") != NULL) {
					user_color = "White";
					comp_color = "Black";
				}
				else {
					user_color = "Black";
					comp_color = "White";
				}
			}
			else if (strstr(line, "next_turn") != NULL) {
				if (strstr(line, "White") != NULL)
					curr_turn = "White";
				else curr_turn = "Black";
			}
			else if (strstr(line, "row_8") != NULL) {
				for (i = 0; i < BOARD_SIZE; i++){
					if (line[9 + i] == '_')
						board[i][7] = EMPTY;
					else board[i][7] = line[9 + i];
				}
			}
			else if (strstr(line, "row_7") != NULL) {
				for (i = 0; i < BOARD_SIZE; i++){
					if (line[9 + i] == '_')
						board[i][6] = EMPTY;
					else board[i][6] = line[9 + i];
				}
			}
			else if (strstr(line, "row_6") != NULL) {
				for (i = 0; i < BOARD_SIZE; i++){
					if (line[9 + i] == '_')
						board[i][5] = EMPTY;
					else board[i][5] = line[9 + i];
				}
			}
			else if (strstr(line, "row_5") != NULL) {
				for (i = 0; i < BOARD_SIZE; i++){
					if (line[9 + i] == '_')
						board[i][4] = EMPTY;
					else board[i][4] = line[9 + i];
				}
			}
			else if (strstr(line, "row_4") != NULL) {
				for (i = 0; i < BOARD_SIZE; i++){
					if (line[9 + i] == '_')
						board[i][3] = EMPTY;
					else board[i][3] = line[9 + i];
				}
			}
			else if (strstr(line, "row_3") != NULL) {
				for (i = 0; i < BOARD_SIZE; i++){
					if (line[9 + i] == '_')
						board[i][2] = EMPTY;
					else board[i][2] = line[9 + i];
				}
			}
			else if (strstr(line, "row_2") != NULL) {
				for (i = 0; i < BOARD_SIZE; i++){
					if (line[9 + i] == '_')
						board[i][1] = EMPTY;
					else board[i][1] = line[9 + i];
				}
			}
			else if (strstr(line, "row_1") != NULL) {
				for (i = 0; i < BOARD_SIZE; i++){
					if (line[9 + i] == '_')
						board[i][0] = EMPTY;
					else board[i][0] = line[9 + i];
				}
			}


		}
		fclose(ipf);
	}
	free(line);
	print_board_(board);
	return 1;
}

void start_game(char board[BOARD_SIZE][BOARD_SIZE]){

	draw_board(board);

	game2(board);
}
