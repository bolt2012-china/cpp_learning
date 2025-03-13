#include "game.h"
#include <iostream>
#include <vector>
using namespace std;

const int p[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
char board[11] = {'-', '-', '-', '\n', '-', '-', '-', '\n', '-', '-', '-'};

vector<int> devide(long long n) {
  vector<int> power(9, 0);
  for (int i = 0; i < 9; i++) {
    while (n % p[i] == 0) {
      power[i]++;
      n /= p[i];
    }
  }
  return power;
}

long long play(long long code, int player, int x, int y) {
  int rank = (x-1)*3+(y-1);
  return code + (p[rank] ^ player);
}

void print(long long code) {
  vector<int> power = devide(code);
  for (int i = 0; i < 9; i++) {
    if (power[i] == 1)
      board[i] = 'x';
    else if (power[i] == 2)
      board[i] = 'o';
    else
      board[i] = '-';
  }
  for (int i = 0; i < 11; i++)
  {
    if (i % 4 != 3)
      cout << board[i] << " ";
    else
      cout << board[i];
  }
}

int check_winner(long long code) {
  for (int i = 0; i < 3; i++) {
    if (board[i] != '0' && board[i] == board[i + 3] && board[i] == board[i + 6]) {
      return (board[i] == 'x') ? 1 : 2;
    }
  }
  for (int i = 0; i < 9; i += 3) {
    if (board[i] != '-' && board[i] == board[i + 1] && board[i] == board[i + 2]) {
      return (board[i] == 'x') ? 1 : 2;
    }
  }
  if (board[0] != '-' && board[0] == board[4] && board[0] == board[8]) {
    return (board[0] == 'x') ? 1 : 2;
  } else if (board[2] != '-' && board[2] == board[4] && board[2] == board[6]) {
    return (board[2] == 'x') ? 1 : 2;
  }
  return 0;
}

