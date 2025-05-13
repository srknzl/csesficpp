#include <bits/stdc++.h>

#define ll long long

using namespace std;
constexpr ll MOD = 1000000007;

int getMoveId(char c) {
  switch (c) {
  case '?':
    return 0;
    break;
  case 'L':
    return 1;
    break;
  case 'R':
    return 2;
    break;
  case 'D':
    return 3;
    break;
  case 'U':
    return 4;
    break;
  default:
    break;
  }
  return -1;
}

constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int search(int x, int y, int moveCount, vector<int> &moveOrder, bool visited[][9]) {
  if (x == 7 && y == 1) {
    if (moveCount == int(moveOrder.size())) {
      return 1;
    } else {
      return 0;
    }
  }

  if (visited[x - 1][y] && visited[x + 1][y] && !visited[x][y - 1] && !visited[x][y + 1]) return 0;
  if (visited[x][y - 1] && visited[x][y + 1] && !visited[x - 1][y] && !visited[x + 1][y]) return 0;
  int ans = 0;
  int newX, newY;
  switch (moveOrder[moveCount]) {
  case 0:
    for (auto dir : dirs) {
      newX = dir[0] + x;
      newY = dir[1] + y;
      if (!visited[newX][newY]) {
        visited[newX][newY] = true;
        ans += search(newX, newY, moveCount + 1, moveOrder, visited);
        visited[newX][newY] = false;
      }
    }
    break;
  case 1:
    newX = dirs[1][0] + x;
    newY = dirs[1][1] + y;
    if (!visited[newX][newY]) {
      visited[newX][newY] = true;
      ans += search(newX, newY, moveCount + 1, moveOrder, visited);
      visited[newX][newY] = false;
    }
    break;
  case 2:
    newX = dirs[0][0] + x;
    newY = dirs[0][1] + y;
    if (!visited[newX][newY]) {
      visited[newX][newY] = true;
      ans += search(newX, newY, moveCount + 1, moveOrder, visited);
      visited[newX][newY] = false;
    }
    break;
  case 3:
    newX = dirs[2][0] + x;
    newY = dirs[2][1] + y;
    if (!visited[newX][newY]) {
      visited[newX][newY] = true;
      ans += search(newX, newY, moveCount + 1, moveOrder, visited);
      visited[newX][newY] = false;
    }
    break;
  case 4:
    newX = dirs[3][0] + x;
    newY = dirs[3][1] + y;
    if (!visited[newX][newY]) {
      visited[newX][newY] = true;
      ans += search(newX, newY, moveCount + 1, moveOrder, visited);
      visited[newX][newY] = false;
    }
    break;
  default:
    break;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  string moves;
  cin >> moves;
  vector<int> moveOrder(moves.length());
  for (size_t i = 0; i < moves.length(); i++) {
    moveOrder[i] = getMoveId(moves[i]);
  }
  bool visited[9][9];
  
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      visited[i][j] = (i == 0 || j == 0 || i == 8 || j == 8);
    }
  }
  visited[1][1] = true;
  cout << search(1, 1, 0, moveOrder, visited) << endl;
}