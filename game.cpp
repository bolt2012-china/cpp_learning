#include "game.h"

#include <iostream>
using namespace std;
int p[9] = {2,3,5,7,11,13,17,19,23};
char board[11] = {'\0','\0','\0','\n','\0','\0','\0','\n','\0','\0','\0'};

int *devide(long long n){
  int power[9]={};
  for(int i=0;i<9;i++){
    while (n%p[i]==0){
      power[i]+=1;
    }
   }
  return power;
}

long long play(long long code, int player, int x, int y) {
  long long result = code;
  int rank = (x-1)*3+y-1;
  result += p[rank]^player;
  return result;
}

void print(long long code) {
  //int p[9] = {2,3,5,7,11,13,17,19,23};
  //char board[11] = {'\0','\0','\0','\n','\0','\0','\0','\n','\0','\0','\0'};
  int *power = devide(code);
  for (int i = 0; i < 9; i++) {
    if (power[i] == 1)
      board[i] ='x';
    if (power[i] == 2)
      board[i] = 'o';
    if (power[i] == 0)
      board[i] = '-';
  }
  for (int i = 0; i < 9; i++) {
    cout << board[i];
  }
  cout << endl;
}

int check_winner(long long code) {
  for (int i = 0; i < 3; i++) {
    if (board[i] == board[i+3] == board[i+6]) {
      if (board[i] == 'x')
        return 1;
      if (board[i] == 'o')
        return 2;
        }
       }
  int j=0;
  while (j<9) {
    if (board[j] == board[j+1] == board[j+2]){
      if (board[j] == 'x')
        return 1;
      if (board[j] == 'o')
        return 2;
      }
    j += 3;
   }
  if ((board[0] == board[4] == board[8] == 'x') || (board[2] == board[4] == board[6] == 'x'))
    return 1;
  if ((board[0] == board[4] == board[8] == 'o') || (board[2] == board[4] == board[6] == 'o'))
    return 2;
}