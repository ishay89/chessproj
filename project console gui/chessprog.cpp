#include "stdafx.h"


#include "chessprog.h"

extern "C" { FILE __iob_func[3] = { *stdin,*stdout,*stderr }; }

int minimax_depth = 1;
char* user_color = "White";
char* comp_color = "Black";
char* curr_turn = "White";
unsigned int game_still_on = 1;
unsigned int game_mode = 1;




int main(int argc, char* args[])
{
	char board[BOARD_SIZE][BOARD_SIZE];

	clear_board(board);
	
	if (argc == 1) console(board);
	else if (strcmp(args[1], "gui") == 0) gui(board);
	else if (strcmp(args[1], "console") == 0) console(board);
	else printf("%s", "wrong arguments!");
	return 0;
}


int file_exist(char* str) {
	FILE* ipf = NULL;
	ipf = fopen(str, "r");
	if (ipf == NULL)
		return 0;
	else {
		fclose(ipf);
		return 1;
	}
}

void clear_board(char board[BOARD_SIZE][BOARD_SIZE]) {
	int i, j;
	for (i = 0; i < BOARD_SIZE; i++){
		for (j = 0; j < BOARD_SIZE; j++){
			board[i][j] = EMPTY;
		}
	}


}

void print_line(){
	int i;

	printf(" |");
	for (i = 1; i < BOARD_SIZE * 4; i++){
		printf("-");
	}
	printf("|\n");
}

void print_board_(char board[BOARD_SIZE][BOARD_SIZE])
{
	int i, j;
	print_line();
	for (j = BOARD_SIZE - 1; j >= 0; j--)
	{
		printf("%d", j + 1);
		for (i = 0; i < BOARD_SIZE; i++){
			printf("| %c ", board[i][j]);
		}
		printf("|\n");
		print_line();
	}
	printf("  ");
	for (j = 0; j < BOARD_SIZE; j++){
		printf(" %c  ", (char)('a' + j));
	}
	printf("\n");
}

void init_board_(char board[BOARD_SIZE][BOARD_SIZE]){
	int i, j;

	for (i = 0; i < BOARD_SIZE; i++){
		for (j = 0; j < BOARD_SIZE; j++){
			board[j][i] = EMPTY;
		}
	}

	for (i = 0; i < BOARD_SIZE; i++){
		for (j = 0; j < BOARD_SIZE; j++){
			if (i == 1) board[j][i] = WHITE_PAWN;
			else if (i == 6) board[j][i] = BLACK_PAWN;
			else board[j][i] = EMPTY;
		}
	}

	board[0][0] = WHITE_ROOK;
	board[7][0] = WHITE_ROOK;
	board[1][0] = WHITE_KNIGHT;
	board[6][0] = WHITE_KNIGHT;
	board[2][0] = WHITE_BISHOP;
	board[5][0] = WHITE_BISHOP;
	board[3][0] = WHITE_QUEEN;
	board[4][0] = WHITE_KING;
	board[0][7] = BLACK_ROOK;
	board[7][7] = BLACK_ROOK;
	board[1][7] = BLACK_KNIGHT;
	board[6][7] = BLACK_KNIGHT;
	board[2][7] = BLACK_BISHOP;
	board[5][7] = BLACK_BISHOP;
	board[3][7] = BLACK_QUEEN;
	board[4][7] = BLACK_KING;
}

void rm(char new_board[BOARD_SIZE][BOARD_SIZE], int col, int row) {
	new_board[col][row] = EMPTY;
}

void make_new_board(char old_board[BOARD_SIZE][BOARD_SIZE], char new_board[BOARD_SIZE][BOARD_SIZE]){
	int i, j;

	for (i = 0; i < BOARD_SIZE; i++)
	for (j = 0; j < BOARD_SIZE; j++)
		new_board[i][j] = old_board[i][j];


}

int check_if_pos_is_black(char c) {

	if (c == 'M' || c == 'B' || c == 'R' || c == 'N' || c == 'Q' || c == 'K')
		return 1;

	return 0;
}

int check_if_pos_is_white(char c) {

	if (c == 'm' || c == 'b' || c == 'r' || c == 'n' || c == 'q' || c == 'k')
		return 1;

	return 0;
}

node* make_new_node(){
	node* ret = (node*)calloc(1, sizeof(node));
	alloc_check(ret);
	strcpy(ret->move, " ");
	return ret;
}

void alloc_check(const void *pointer) {
	if (pointer == NULL) {
		printf("Failed to allocate memory\n");
		exit(0);
	}
}


void free_linked_list(node* head){
	node* temp;
	node* curr = head;
	while (curr != NULL) {
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	head = NULL;
}










