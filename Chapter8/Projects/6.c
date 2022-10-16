#include <stdio.h>

int main()
{
#define MESSAGE_MAX_LEN 100
	char message[MESSAGE_MAX_LEN];
	int i;
	
	fgets(message, MESSAGE_MAX_LEN, stdin);
	message[strlen(message) - 1] = '\0';
	for (i = 0; message[i] != '\0'; i++) {
		switch (message[i]) {
		case 'a': case 'A':
			printf("4");
			break;
		case 'b': case 'B':
			printf("8");
			break;
		case 'e': case 'E':
			printf("3");
			break;
		case 'i': case 'I':
			printf("1");
			break;
		case 'o': case 'O':
			printf("0");
			break;
		case 's': case 'S':
			printf("5");
			break;
		default:
			if (message[i] >= 'a' && message[i] <= 'z')
				printf("%c", message[i] - ('a' - 'A'));
			else
				printf("%c", message[i]);
		}
	}
	printf("!!!!!!!!!!\n");
	return 0;
}
