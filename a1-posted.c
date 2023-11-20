// skills needed - parallel array
// Your code must show the simulation as it progresses, including the changing positions of each hero and bird.
// It must print out the outcome of the simulation at the end, specifically whether the heroes escaped the Hollow
// or died in the attempt.

// Timmy - t, harold - H, bird - v



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_ROW       15
#define MAX_COL       60
#define MAX_BIRDS    128
#define BIRD_FREQ     90

#define Timmy  'T'
#define Harold 'H'
#define bird   'v'

#define C_TRUE         1
#define C_FALSE        0

void initHollow(char[MAX_ROW][MAX_COL]);
void printHollow(char[MAX_ROW][MAX_COL]);
char escapeOver(char, char, int, int);
char isDone(char, int);
int  moveHero(char, int, char[MAX_ROW][MAX_COL]);
void moveBird(int, int[MAX_BIRDS], int[MAX_BIRDS], char[MAX_ROW][MAX_COL]);
void moveInHollow(char, int, int, int, int, char[MAX_ROW][MAX_COL]);
void printResult(char, char, int, int);
int  randomInt(int);

int main()
{
  srand(time(NULL));
  char hollow[MAX_ROW][MAX_COL];
  initHollow(hollow);
  int tCol,hCol;
  int rows[MAX_ROW],cols[MAX_COL],curr_bird_index=0;
  while(! escapeOver(Timmy,Harold,tCol,hCol)){
    moveHero(Timmy,tCol,hollow);
    moveHero(Harold,hCol,hollow);
    if(0.9*randomInt(10)>0.1*randomInt(10)){

    }
  }
  return 0;
}

void initHollow(char hollow[MAX_ROW][MAX_COL]){
  for (int i=0;i<MAX_ROW;i++){
    for (int j=0;j<MAX_COL;j++){
      hollow[i][j]='.';
    }
  }
}
void printHollow(char hollow[MAX_ROW][MAX_COL]){
  for (int i=0;i<MAX_ROW;i++){
    for (int j=0;j<MAX_COL;j++){
      printf("%c  ",hollow[i][j]);
    }
    printf("\n");
  }
}

void moveInHollow(char avatar, int oldRow, int oldCol, int newRow, int newCol,char hollow[MAX_ROW][MAX_COL]){
  hollow[oldRow][oldCol]='.';
  hollow[newRow][newCol]=avatar;
}

char isDone(char avatar, int col){
  if (avatar=='+' || col>MAX_COL)
  return C_TRUE;
  return C_FALSE;
}


char escapeOver(char tAvatar, char hAvatar, int tCol, int hCol){
  if (isDone(tAvatar,tCol) && isDone(hAvatar,hCol))
  return C_TRUE;
  return C_FALSE;
}

void printResult(char tAvatar, char hAvatar, int tCol, int hCol){
  if (tAvatar=='+' && hAvatar=='+')
  printf("Both are dead : H at %d , T at %d \n",hCol,tCol);
  else if (tAvatar=='+')
  printf("T died at &d, H escaped hollow",tCol);
  else if (hAvatar=='+')
  printf("H died at &d, T escaped hollow",hCol);
  else
  printf("Both of them escaped the Hollow");

}

int moveHero(char avatar, int oldPos, char hollow[MAX_ROW][MAX_COL]){
  int newPos;
  if (avatar=='H'){
     int possibility[5]={0.2,0.1,0.1,0.4,0.2},max=0,step=0;
     for (int i=0;i<5;i++){
      int rand=randomInt(10);
      if(possibility[i]*rand>max){
        max=possibility[i]*rand;
        step=i;
      }
     }
     switch (step){
      case 0:
      newPos=oldPos;
      case 1:
      newPos=oldPos+6;
      case 2:
      newPos=oldPos-4>=0?oldPos-4:0;
      case 3:
      newPos=oldPos+4;
      case 4:
      newPos=oldPos-2>=0?oldPos-2:0;
     }
  }
  
  else{
    int possibility[3]={0.5,0.2,0.3},max=0,step=0;
    for (int i=0;i<3;i++){
      int rand=randomInt(10);
      if(possibility[i]*rand>max){
        max=possibility[i]*rand;
        step=i;
      }
    }
    switch (step){
    case 0:
    newPos=oldPos+3;
    case 1:
    newPos=oldPos-2>=0?oldPos-2:0;
    case 2:
    newPos=oldPos+1;
  }
  }
  moveInHollow(avatar,MAX_ROW-1,oldPos,MAX_ROW-1,newPos,hollow);
  return newPos;
}

void moveBird(int index, int rows[MAX_BIRDS], int cols[MAX_BIRDS], char hollow[MAX_ROW][MAX_COL]){
  if (randomInt(2)==1)
    rows[index]+=1;
  else
    rows[index]+=2;
  int rand=randomInt(3);
  if (rand==0)
  cols[index]-=1;
  else if (rand==2)
  cols[index]+=1;
}



/*
  Function:  randomInt
  Purpose:   returns a random number in the range [0,max)
  Parameters:
    in:      maximum of range
    return:  randomly generated number
*/

int randomInt(int max)
{
  return(rand() % max);
}

