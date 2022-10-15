#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h>

int main(void)
{
#define N 10
	char board[N][N];
	char letter = 'A';
	int random_num;
	int i, j;
	int row = 0;
	int col = 0;
	bool up_blocked = false;
	bool down_blocked = false;
	bool left_blocked = false;
	bool right_blocked = false;
	bool moved = false;

	srand((unsigned int)time(NULL));

	/* fills the board with dots . */
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			board[i][j] = '.';
	board[0][0] = letter++;
	while (letter <= 'Z') {
		random_num = rand() % 4;
		switch (random_num) {
		case 0:
			if (row - 1 >= 0 && board[row - 1][col] == '.') {
				board[--row][col] = letter++;
				moved = true;
			}
			else
				up_blocked = true;
			break;
		case 1:
			if (row + 1 < N && board[row + 1][col] == '.') {
				board[++row][col] = letter++;
				moved = true;
			}
			else
				down_blocked = true;
			break;
		case 2:
			if (col - 1 >= 0 && board[row][col - 1] == '.') {
				board[row][--col] = letter++;
				moved = true;
			}
			else
				left_blocked = true;
			break;
		case 3:
			if (col + 1 < N && board[row][col + 1] == '.') {
				board[row][++col] = letter++;
				moved = true;
			}
			else
				right_blocked = true;
			break;
		}
		if (moved) {
			up_blocked = down_blocked = left_blocked = right_blocked = false;
			moved = false;
		}
		if (up_blocked && down_blocked && left_blocked && right_blocked)
			break;
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; ++j) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
    return 0;
}
