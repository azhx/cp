#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> graph [10000];
int main () {
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
    }
    int a, b;
    while (true){
        scanf("%d%d", &a, &b);
        if (a == 0 && b == 0){
            break;
        }
        bool vis[10000];
        int level[10000];
        bool circle = false;
        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));
        queue<int> q; q.push(a); vis[a] = true;
        while (!q.empty()){
            int v = q.front(); q.pop();
            for (int i = 0; i < graph[v].size(); i++){
                if (vis[graph[v][i]] == false){
                    vis[graph[v][i]] = true;
                    level[graph[v][i]] = level[v] + 1;
                    q.push(graph[v][i]);
                } else if (graph[v][i] == a){
                    level[graph[v][i]] = level[v] + 1;
                    circle = true;
                    break;
                }
            }
        }
        if (level[b] == -1 || circle == false){
            printf("No\n");
        } else if (circle == true){
            printf("Yes %d\n", level[b]);
        }
    }
    return 0;
}