#include "stdafx.h"

#include "game_console.h"




int console(char board[BOARD_SIZE][BOARD_SIZE])
{

	char c = '\0';
	char x[50] = "";

	clear_board(board);
	init_board_(board);
	print_board_(board);
	printf("Enter game setting:\n");
	if (1 != scanf("%s", x)){
		printf("%s","Error: standard function scanf has failed\n");
		exit(0);
	}

	while (1){

		if (strcmp(x, "game_mode") == 0) set_game_mode();

		else if (strcmp(x, "difficulty") == 0) {
			if (game_mode == 2) set_minimax_depth();
			else {
				c = getchar();
				while (c != '\n') {
					c = getchar();
				}
				printf(ILLEGAL_COMMAND);
			}
		}

		else if (strcmp(x, "user_color") == 0) {
			if (game_mode == 2) set_user_color();
			else {
				c = getchar();
				while (c != '\n') {
					c = getchar();
				}
				printf("%s", "Only allowed in player vs.computer mode\n");
			}
		}

		else if (strcmp(x, "game_mode") == 0) set_game_mode();

		else if (strcmp(x, "load") == 0) load(board);

		else if (strcmp(x, "print") == 0) print_board_(board);

		else if (strcmp(x, "start") == 0) start(board);

		else if (strcmp(x, "quit") == 0) exit(0);

		else {
			c = getchar();
			while (c != '\n') {
				c = getchar();
			}
			printf(ILLEGAL_COMMAND);
		}
		if (game_still_on) {
			if (1 != scanf("%s", x)){
				printf("%s","Error: standard function scanf has failed\n");
				exit(0);
			}
		}
		else break;

	}
	return 0;
}

void set_minimax_depth() {
	unsigned int depth;
	char x[50] = "";

	if (1 != scanf("%s", x)){
		printf("Error: standard function scanf has failed\n");
		exit(0);
	}

	if (strcmp(x, "best") == 0)
		minimax_depth = -1;
	else if (strcmp(x, "depth") == 0) {
		if (1 != scanf("%u", &depth)){
			printf("Error: standard function scanf has failed\n");
			exit(0);
		}
		if ((depth > 0) && (depth < 5))
			minimax_depth = depth;
		else printf(WRONG_MINIMAX_DEPTH);
	}
	else printf(WRONG_MINIMAX_FORMAT);

}

void set_game_mode() {
	unsigned int x;
	if (1 != scanf("%u", &x)){
		printf("Error: standard function scanf has failed\n");
		exit(0);
	}
	if (x == 1){
		game_mode = x;
		printf("Running game in 2 players mode\n");
	}
	else if (x == 2) {
		game_mode = x;
		printf("Running game in player vs. AI mode\n");

	}
	else printf(WRONG_GAME_MODE);
}

void set_user_color() {
	char x[20];

	if (1 != scanf("%s", x)){
		printf("Error: standard function scanf has failed\n");
		exit(0);
	}

	if (strcmp(x, "black") == 0) {
		user_color = "Black";
		comp_color = "White";
	}
	else if (strcmp(x, "white") == 0) {
		user_color = "White";
		comp_color = "Black";
	}
}

int load(char board[BOARD_SIZE][BOARD_SIZE]){
	char c, x[200] = "";
	FILE* ipf;
	char *line = (char *)calloc(100, sizeof(char));
	int pos, i;

	if (1 != scanf("%s", x)){
		printf("Error: standard function scanf has failed\n");
		exit(0);
	}
	ipf = fopen(x, "r");
	if (!ipf) {
		printf("%s", "Wrong file name\n");
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

void save_game(char board[BOARD_SIZE][BOARD_SIZE]) {
	int i, j;
	char file[200];
	char content[9];
	FILE* xml_file;

	if (1 != scanf("%s", file)){
		printf("Error: standard function scanf has failed\n");
		exit(0);
	}

	xml_file = fopen(file, "w");
	

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

int restart(char board[BOARD_SIZE][BOARD_SIZE]){

	char c;
	char x[50] = "";
	init_board_(board);
	print_board_(board);

	minimax_depth = 1;
	user_color = "White";
	comp_color = "Black";
	curr_turn = "White";
	game_still_on = 1;
	game_mode = 1;

	printf("Enter game setting:\n");
	if (1 != scanf("%s", x)){
		printf("Error: standard function scanf has failed\n");
		exit(0);
	}

	while (1){

		if (strcmp(x, "game_mode") == 0) set_game_mode();

		else if (strcmp(x, "difficulty") == 0) {
			if (game_mode == 2) set_minimax_depth();
			else {
				c = getchar();
				while (c != '\n') {
					c = getchar();
				}
				printf(ILLEGAL_COMMAND);
			}
		}

		else if (strcmp(x, "user_color") == 0) {
			if (game_mode == 2) set_user_color();
			else {
				c = getchar();
				while (c != '\n') {
					c = getchar();
				}
				printf("%s", "Only allowed in player vs.computer mode\n");
			}
		}

		else if (strcmp(x, "game_mode") == 0) set_game_mode();

		else if (strcmp(x, "load") == 0) load(board);

		else if (strcmp(x, "print") == 0) print_board_(board);

		else if (strcmp(x, "start") == 0) start(board);

		else if (strcmp(x, "quit") == 0) exit(0);

		else {
			c = getchar();
			while (c != '\n') {
				c = getchar();
			}
			printf(ILLEGAL_COMMAND);
		}

		if (1 != scanf("%s", x)){
			printf("Error: standard function scanf has failed\n");
			exit(0);
		}


	}



	return 0;
}

void set_place(char board[BOARD_SIZE][BOARD_SIZE]) {
	char x[20] = "";
	char c[20] = "";

	if (1 != scanf("%s", x)){
		printf("Error: standard function scanf has failed\n");
		exit(0);
	}

	if (1 != scanf("%s", c)){
		printf("Error: standard function scanf has failed\n");
		exit(0);
	}
	board[x[1] - 'a'][x[3] - '0' - 1] = c[0];
}

void start(char board[BOARD_SIZE][BOARD_SIZE]) {
	unsigned int i, j, mone_white, mone_black;

	mone_black = mone_white = 0;

	for (i = 0; i < BOARD_SIZE; i++)
	for (j = 0; j < BOARD_SIZE; j++) {
		if (board[i][j] == WHITE_PAWN || board[i][j] == WHITE_ROOK || board[i][j] == WHITE_KNIGHT || board[i][j] == WHITE_BISHOP || board[i][j] == WHITE_QUEEN || board[i][j] == WHITE_KING) mone_white++;
		if (board[i][j] == BLACK_PAWN || board[i][j] == BLACK_ROOK || board[i][j] == BLACK_KNIGHT || board[i][j] == BLACK_BISHOP || board[i][j] == BLACK_QUEEN || board[i][j] == BLACK_KING) mone_black++;
	}
	if (mone_black + mone_white == 0 || mone_black == 0 || mone_white == 0 || mone_black>16 || mone_white>16)
		printf(WROND_BOARD_INITIALIZATION);
	else game(board);

}

void game(char board[BOARD_SIZE][BOARD_SIZE]) {
	while (game_still_on == 1) {
		if (game_mode == 2) {
			if (strcmp(curr_turn, comp_color) == 0) {
				if (computer_turn(board, comp_color)) {
					if (strcmp(curr_turn, "White") == 0)
						curr_turn = "Black";
					else curr_turn = "White";

				}
			}
			else {
				user_turn(board);
			}
		}
		else {
			user_turn(board);
		}
	}



}

int computer_turn(char board[BOARD_SIZE][BOARD_SIZE], char* comp_color){
	node* head = NULL;


	initial_minimax(board);

	print_board_(board);

	if (strcmp(comp_color, "White") == 0) {
		head = get_all_moves_black(board);
		if (head == NULL){
			game_still_on = 0;
			printf("Mate! %s player wins the game\n", curr_turn);
			return 1;
		}
		if (check_if_black_in_check(board)) printf("Check!\n");
		free_linked_list(head);
		head = NULL;
	}
	if (strcmp(comp_color, "Black") == 0) {
		head = get_all_moves_white(board);
		if (head == NULL) {
			game_still_on = 0;
			printf("Mate! %s player wins the game\n", curr_turn);
			return 1;
		}
		if (check_if_white_in_check(board)) printf("Check!\n");
		free_linked_list(head);
		head = NULL;
	}

	return 1;

}

void user_turn(char board[BOARD_SIZE][BOARD_SIZE]){
	char c;
	node *head = NULL;
	char trash[5] = " ";
	char x[50] = " ";
	char from[MAX_STR_LN] = " ";
	char to[MAX_STR_LN] = " ";
	const char delimeter[2] = " ";
	char promotion[MAX_STR_LN] = "";
	char *token;


	printf("%s player - enter your move:\n", curr_turn);
	if (1 != scanf("%s", x)){
		printf("Error: standard function scanf has failed\n");
		exit(0);
	}

	while (1){

		if (strcmp(x, "quit") == 0) exit(0);

		else if (strcmp(x, "print") == 0) print_board_(board);

		else if (strcmp(x, "save") == 0) save_game(board);

		else if (strcmp(x, "restart") == 0) {
			restart(board);
			break;
		}

		else if (strcmp(x, "get_moves") == 0) check_get_moves(board);

		else if (strcmp(x, "get_all_moves") == 0) {
			if (strcmp(curr_turn, "White") == 0) head = get_all_moves_white(board);
			else head = get_all_moves_black(board);
			print_moves(head);
			free_linked_list(head);
			head = NULL;
		}

		else if (strcmp(x, "move") == 0) {

			
			if (1 != scanf("%[^\n]%*c", x)){
				printf("Error: standard function scanf has failed\n");
				exit(0);
			}
			token = strtok(x, delimeter);

			if (token != NULL) {
				strcpy(from, token);
				token = strtok(NULL, delimeter);
			}


			if (token != NULL) {
				strcpy(trash, token);
				token = strtok(NULL, delimeter);
			}

			if (token != NULL) {
				strcpy(to, token);
				token = strtok(NULL, delimeter);
			}

			if (token != NULL) {
				strcpy(promotion, token);
				token = strtok(NULL, delimeter);
			}

			if (check_if_valid_input(from) && check_if_valid_input(to) && strcmp(trash, "to") == 0) {
				if (make_move_user(board, from, to, promotion)) {
					if (strcmp(curr_turn, "White") == 0) {
						curr_turn = "Black";
					}
					else {
						curr_turn = "White";
					}
					break;
				}

			}

			else printf(ILLEGAL_COMMAND);


		}

		else {
			c = getchar();
			while (c != '\n') {
				c = getchar();
			}
			printf(ILLEGAL_COMMAND);
		}
		if (game_still_on) {
			printf("%s player - enter your move:\n", curr_turn);
			if (1 != scanf("%s", x)){
				printf("Error: standard function scanf has failed\n");
				exit(0);
			}
		}
		else break;

	}



}

int make_move_user(char board[BOARD_SIZE][BOARD_SIZE], char from[MAX_STR_LN], char to[MAX_STR_LN], char promotion[MAX_STR_LN]) {
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
		print_board_(board);
		if (strcmp(curr_turn, "White") == 0) {
			head = get_all_moves_black(board);
			if (head == NULL){
				game_still_on = 0;
				printf("Mate! %s player wins the game\n", curr_turn);
				return 1;
			}
			if (check_if_black_in_check(board)) printf("Check!\n");
			free_linked_list(head);
			head = NULL;
		}
		if (strcmp(curr_turn, "Black") == 0) {
			head = get_all_moves_white(board);
			if (head == NULL) {
				game_still_on = 0;
				printf("Mate! %s player wins the game\n", curr_turn);
				return 1;
			}
			if (check_if_white_in_check(board)) printf("Check!\n");
			free_linked_list(head);
			head = NULL;
		}
	}
	return legal;
}

int check_if_valid_position(char x[50]) {
	if (x[1] - 'a' < 0 || x[1] - 'a' > 7){
		return 0;
	}

	if (x[3] - '0' - 1 < 0 || x[3] - '0' - 1 > 7) {
		return 0;
	}

	return 1;
}

int check_if_valid_input(char x[50]) {
	if (x[0] != '<') {
		return 0;
	}

	if (x[2] != ',') {
		return 0;
	}

	if (x[4] != '>') {
		return 0;
	}
	return 1;
}


