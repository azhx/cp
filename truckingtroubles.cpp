#include <bits/stdc++.h>
#define toDigit(x) (x-'0')
using namespace std;
int c, r, d, x, y, w;
vector<int> destinations;
int maxweight[10001];
bool vis[10001];
stack<int> s;
int highest;

int dfs(vector<vector<pair<int, int>>> graph, int v)
{
    int v = s.top(); s.pop();
    for (int i = 0; i < graph[v].size(); i++)
    {
      pair<int,int> p = graph[v][i];
      if (vis[p.first] == false && v != 1)
      {
        maxweight[p.first] = max(min(maxweight[v], p.second), maxweight[p.first]);
        vis[p.first] = true;
      }
      else
      {
        maxweight[p.first] = p.second;
        vis[p.first] = true;
      }
    }
  }
  return highest;
}

int main ()
{
  scanf("%d %d %d", &c, &r, &d);
  vector<vector<pair<int, int>>> graph ((c+1), vector<pair<int, int>>());
  for (int i = 0 ; i < r; i++)
  {
    scanf("%d %d %d", &x, &y, &w);
    graph[x].push_back(make_pair(y, w));
    graph[y].push_back(make_pair(x, w));
  }
  for (int i = 0; i < d; i++)
  {
    int des;
    scanf("%d", &des);
    destinations.push_back(des);
  }
  s.push(1); vis[1] = true;
  while (!s.empty()){
    out = dfs(graph, 1);
  }
  printf("%d\n", dfs(graph, 1) ;
  return 0;
}
