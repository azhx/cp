#include <bits/stdc++.h>
#define toDigit(x) (x-'0')
using namespace std;
int graph [51][51] = {0};

void i (int x, int y)
{
  graph[x][y] = 1;
  graph[y][x] = 1;
}

void d (int x, int y)
{
  graph[x][y] = 0;
  graph[y][x] = 0;
}

vector<int> n (int x)
{
  vector<int> friends;
  for (int i = 0; i < 51 ; i++)
  {
    if (graph[x][i] != 0)
    {
      friends.push_back(i);
    }
  }
  return friends;
}

int f (int x)
{
  vector<int> checked;
  vector<int> friends = n(x);
  checked.push_back(x);
  for (auto i: friends)
  {
    if (find(checked.begin(), checked.end(), i) == checked.end())
    {
      checked.push_back(i);
    }
    for (int j= 0; j < 51; j++)
    {
      if (graph[i][j] == 1)
      {
        if (find(checked.begin(), checked.end(), j) == checked.end())
        {
          checked.push_back(j);
        }
      }
    }
  }
  return checked.size()-friends.size()-1;
}

int s (int x, int y)
{
  int level[51] = {0};
  bool vis[51] = {false};
  queue<int> q;
  q.push(x); vis[x] = true;
  while ((!q.empty()) && (vis[y] == false))
  {
    int v = q.front();
    q.pop();
    for (int i = 1; i < 51; i++)
    {
      if ((graph[v][i] == 1) && (vis[i] == false))
      {
        level[i] = level[v] + 1;
        q.push(i); vis[i] = true;
        //cout << "hit" << graph[vert-1][i] << endl;
      }
    }
  }
  if (level[y] == 0)
  {
    return -1;
  }
  else
  {
    return level[y];
  }
}

int main () {
  vector<int> adjlist []= {
    {0},
    {6},
    {6},
    {4, 5, 6, 15},
    {3, 5, 6},
    {3, 4, 6},
    {1, 2, 3, 4, 5, 7}, //6
    {6, 8},
    {7, 9},
    {8, 10, 12}, //9
    {9, 11}, //10
    {10, 12},
    {9, 11, 13}, //12
    {12, 14, 15},
    {13}, //14
    {3, 13},
    {17, 18},
    {16, 18},
    {16, 17}
  };

  for (int i = 1; i < (sizeof(adjlist)/sizeof(*adjlist)); i++){
    for (int j = 0; j < adjlist[i].size(); j++){
        graph[i][adjlist[i][j]] = 1;
    }
  }
  char command;
  int x, y;
  while (command != 'q'){
    scanf("%s", &command);
    if (command == 'i'){
      scanf("%d %d", &x, &y);
      i(x, y);
    } else if (command == 'd'){
      scanf("%d %d", &x, &y);
      d(x, y);
    } else if (command == 'n'){
      scanf("%d", &x);
      printf("%lu\n", n(x).size());
    } else if (command == 'f'){
      scanf("%d", &x);
      printf("%d\n", f(x));
    } else if (command == 's'){
      scanf("%d %d", &x, &y);
      int out = s(x, y);
      if (out == -1)
      {
        printf("%s\n", "Not connected");
      }
      else
      {
        printf("%d\n", out);
      }
    }
  }
  return 0;
}
