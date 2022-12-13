#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

int get_random_number(void);

void play_guess_game(void);

int get_random_number(void)
{
    return rand() % 100 + 1;
}

void play_guess_game(void)
{
    int number = get_random_number();
    int guess, num_guesses = 0;

    printf("A new number has been chosen.\n");
    do {
        num_guesses++;
        printf("Enter guess: ");
        scanf_s("%d", &guess);
        if (guess > number)
            printf("Too high; try again.\n");
        else if (guess < number)
            printf("Too low; try again.\n");
        else
            printf("You won in %d guesses!\n\n", num_guesses);
    } while (guess != number);
}

int main(void)
{
    char ch;

    srand(time(NULL));
    printf("Guess the secret number between 1 and 100.\n\n");
    do {
        play_guess_game();
        printf("Play again? (Y/N) ");
        scanf_s(" %c", &ch, 1);
        printf("\n");
    } while (toupper(ch) == 'Y');
  
    return 0;
}
