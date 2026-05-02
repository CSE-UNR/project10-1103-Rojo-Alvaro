//Alvaro Rojo
//05/01/2026
//Project 10

#include <stdio.h>

#define WORDFILE "mystery.txt"

int getWord(FILE* fp, char word[]);
void getGuess(char board[][6], int guessNumber);
int isLetter(char ch);
int stringLength(char str[]);
void displayBoard(char word[], char board[][6], int numGuesses);
int letterInWord(char word[], char letter);
int winCondition(char word[], char guess[]);

int main(){

	char word[6];
	char board[6][6];
	int guessNumber = 0;
	int won = 0;
	
	FILE* readfp;
	
	readfp = fopen(WORDFILE, "r");
	
	if(readfp == NULL){
		printf("Cannot open mystery.txt for reading.\nGoodbye!");
		return 0;
	}
	
	if (getWord(readfp, word) == 0){
		printf("File did not contain a 5 letter word.\n");
		fclose(readfp);
		return 0;
	}
	
	fclose(readfp);
	
//	for (int i = 0; i < 5; i++){
//		board[0][i] = word[i];
//	}
	while (guessNumber < 6 && won == 0){
	
	
		getGuess(board, guessNumber);
	
		printf("================================\n");
		displayBoard(word, board, guessNumber + 1);
		
		if (winCondition(word, board[guessNumber])){
			won = 1;
		}
		else{
			guessNumber++;
		}
	}
	
	if (won){
		printf("\n	You won in %d guesses!  \n", guessNumber +1);
		printf("		Nice!           \n");
	}
	else{
		printf("You lost, better luck next time!");
	}
	
return 0;
}
	
int getWord(FILE* readfp, char word[]){
	
	int i = 0;
	char letter;
	
	while ( i < 5 && fscanf(readfp, "%c", &letter) == 1){
		if (letter != '\n' && letter != ' '){
			word[i] = letter;
			i++;
		}
	}
	
	word[i] = '\0';
	
	if (i == 5){
		return 1;
	}
	else{
		return 0;
	}
}
	
void getGuess(char board[][6], int guessNumber){
	
	char input[100];
	int valid = 0;
	int i;
	
	while (!valid){
		printf("GUESS %d! Enter your guess: ", guessNumber + 1);
		scanf("%s", input);
		
		if (stringLength(input) == 5){
			
			valid = 1;
			
			for(i = 0; i < 5; i++){
				if(!isLetter(input[i])){
					valid = 0;
				}
			}
		}
		if (!valid){
		
			printf("Invalid guess. Please enter a 5 letter word.\n");
		}
	}
			
	for (i = 0; i < 5; i++){
		board[guessNumber][i] = input[i];	
	}
		
		board[guessNumber][5] = '\0';
}

int isLetter(char ch){
	
	if ((ch >= 'A' && ch<= 'Z') || (ch >= 'a' && ch <= 'z')){
		return 1;
	}
	
	else{
		return 0;
	}
}

int stringLength(char str[]){
	
	int length = 0;
	
	while (str[length] != '\0'){
		length ++;
	}
	
	return length;
}

void displayBoard(char word[], char board[][6], int numGuesses){

	int row;
	int col;
	
	for (row = 0; row < numGuesses; row++){
		
		for (col = 0; col < 5; col++){
			if(board[row][col] == word[col]){
				printf("%c", board[row][col] -32);
			}
			else{
			printf("%c", board[row][col]);
			}
		}
		
		printf("\n");
		
		for (col = 0; col < 5; col++){
			if (board[row][col] != word [col] && letterInWord(word, board[row][col])){
				printf("^");
			}
			else{
				printf(" ");
			}
		}
		
		printf("\n");
	}
}

int letterInWord(char word[], char letter){
	int i;
	
	for (i = 0; i < 5; i++){
		if (word[i] == letter){
			return 1;
		}
	}
	return 0;
}
	
int winCondition(char word[], char guess[]){

	int i;
	
	for (i = 0; i < 5; i++){
		if (word[i] != guess[i]){
			return 0;
		}
	}
	return 1;
}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		

