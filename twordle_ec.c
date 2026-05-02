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
void displayOneGuess(char word[], char guess[]);
char toLowercase(char letter);
char toUppercase(char letter);
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
			word[i] = toLowercase(letter);
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
		board[guessNumber][i] = toLowercase(input[i]);	
	}
		
		board[guessNumber][5] = '\0';
}

char toLowercase(char letter){

	if (letter >= 'A' && letter <= 'Z'){
		return letter + 32;
	}
	else{
		return letter;
	}
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
	
	for (row = 0; row < numGuesses; row++){
		displayOneGuess(word, board[row]);
	}
}

void displayOneGuess(char word[], char guess[]){
	
	int result[5] = {0,0,0,0,0};
	int used[5] = {0,0,0,0,0};
	int i;
	int j;
	
	for (i = 0; i < 5; i++){
		if(guess[i] == word[i]){
		
			result[i] = 2;
			used[i] = 1;
		}
	}
	for (i = 0; i < 5; i++){
		if (result[i] == 0){
			for (j = 0; j < 5; j++){
				if (used[j] == 0 && guess[i] == word[j]){
					result[i] = 1;
					used[j] = 1;
					j = 5;
				}
			}
		}
	}
	for (i = 0; i < 5; i++){
		if (result[i] == 2){
			printf("%c", toUppercase(guess[i]));
		}
		else{
			printf("%c", guess[i]);
		}
	}
	
	printf("\n");
	
	for (i = 0; i < 5; i++){
		if (result[i] == 1){
			printf("^");
		}
		else{
			printf(" ");
		}
	}
	printf("\n");
}

char toUppercase(char letter){

	if (letter >= 'a' && letter <= 'z'){
		return letter -32;
	}
	else{
		return letter;
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

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		

