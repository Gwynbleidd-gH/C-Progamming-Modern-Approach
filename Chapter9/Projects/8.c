#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int roll_dice(void);

bool play_game(void);

int roll_dice(void)
{
    return rand() % 6 + 1 + rand() % 6 + 1;
}

bool play_game(void)
{
    int roll, point;

    roll = roll_dice();
    printf("You rolled: %d\n", roll);

    if (roll == 7 || roll == 11) {
        printf("You win!\n");
        return true;
    }
    else if (roll == 2 || roll == 3 || roll == 12) {
        printf("You lose!\n");
        return false;
    }

    point = roll;
    printf("Your point is %d\n", point);

    while (true) {
        roll = roll_dice();
        printf("You rolled: %d\n", roll);

        if (roll == point) {
            printf("You win!\n");
            return true;
        }
        else if (roll == 7) {
            printf("You lose!\n");
            return false;
        }
    }
}

int main(void)
{
    int wins = 0, losses = 0;
    char ch;

    srand(time(NULL));
    
    do {
        play_game() ? wins++ : losses++;

        printf("\nPlay again? ");
        scanf_s(" %c", &ch, 1);
        printf("\n");
    } while (toupper(ch) == 'Y');

    printf("Wins: %d  Losses: %d\n", wins, losses);
  
    return 0;
}
