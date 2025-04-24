#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_ROUNDS 5
#define MAX_WORD_LENGTH 19

void upperWord(char* word)
{
  for (int i = 0; word[i] != '\0'; i++) 
  {
    word[i] = toupper(word[i]);
  }
}


int checkLetter(char* word, char* find_word, char letter, int* attempts, char* wrong_letters) 
{
  int found = 0;
  int counter = 0;

  for (int i = 0; i < MAX_WORD_LENGTH; i++) 
  {
    if (wrong_letters[i] == letter) 
    {
      printf("Letter %c was used already!\n", letter);
      return -1;
    }
  }
    
  for (int i = 0; word[i] != '\0'; i++) 
  {
    if (find_word[i] == letter) 
      {
        printf("Letter %c was used already!\n", letter);
        return -1;
      }
    if (word[i] == letter) 
    {
      find_word[i] = word[i];
      found = 1;
    }
    else 
    {
      wrong_letters[counter++] = letter;
    }
  }
    
  if (found != 1) {
    (*attempts)--;
  }
    
  return 0;
}

void displayWord(char word[], char* find_word) 
{
  for (int i = 0; word[i] != '\0'; i++) 
  {
    if (find_word[i] != '\0') 
    {
      printf("%c ", find_word[i]);
    }
    else 
    {
      printf("_ ");
    }
  }
  printf("\n");
}



int gameGoing(char* word, char* find_word, int attempts) 
{
  if (strcmp(word, find_word) == 0 || attempts == 0) 
  {
    return 0;
  }
  return 1;
}

void game(char* word, char* find_word, int rounds, char* wrong_letters) 
{
  char letter;
  while (gameGoing(word, find_word, rounds) != 0) 
  {
    printf("Attempts left: %d\n", rounds);
    printf("Enter a letter:\n > ");
    scanf(" %c", &letter);
        
    while(getchar() != '\n');
        
    if (checkLetter(word, find_word, toupper(letter), &rounds, wrong_letters) != -1) 
    {
      displayWord(word, find_word);
    }
        
        
  }
}

void displayMessage(char* word, char* find_word) 
{
  if (strcmp(word, find_word) == 0) 
  {
    printf("Congratulations, you won!\n");
  }
  else 
  {
    printf("LOST! The Word was %s\n", word);
  }
}


int main()
{
  int rounds = MAX_ROUNDS;
  char word[MAX_WORD_LENGTH];
  char find_word[MAX_WORD_LENGTH];
    
  for (int i = 0; i<19; i++) 
  {
    find_word[i] = '\0';
  }

  char wrong_letters[MAX_WORD_LENGTH];
    
  printf("Word to look for:\n > ");
  scanf("%s", word);
  system("clear");


  upperWord(word);
    
  game(word, find_word, rounds, wrong_letters);
   
  displayMessage(word, find_word);

  return 0;
}

