#include <bits/stdc++.h>
using namespace std;
int N, a, b;
int paths [10000];

int main (){
    scanf("%d", &N);
    vector<vector<int>> graph(N+1, vector<int>());
    while (true){
        scanf("%d%d", &a, &b);
        if (a == 0 && b ==0){
            break;
        }
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    paths[N] = 1;
    for (int i = N;i > 0; i--){
        for (int j = 0;j < (int)graph[i].size(); j++){
            if (graph[i][j] < i){
                paths[graph[i][j]] += paths[i];
            }
        }
    }
    printf("%d", paths[1]);
    return 0;
}