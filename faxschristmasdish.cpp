#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int N, M, D;
stack<int> s; 
vector<int> graph[300001];
int earliest[300001];

int DFS(int item){ 
    if (graph[item].size() == 0){
        return earliest[item];
    } else{
        int maxi = 0;
        for (int i = 0; i < (int)graph[item].size(); i++){
            int ans = DFS(graph[item][i]);
            maxi = max(maxi, ans);
        }
        return min(maxi, earliest[item]);
    }
}

int main (){
    memset(earliest, INF, sizeof(earliest)); 
    scanf("%d%d%d", &N, &M, &D);
    for (int i = 0; i < M; i++){
        int n, nadj; 
        scanf("%d%d", &n, &nadj);
        for (int j = 0; j < nadj; j++){
            int tmp;
            scanf("%d", &tmp);
            graph[n].push_back(tmp);
        }
    }
    for (int i = 0; i < D; i++){
        int tmp;
        scanf("%d", &tmp);
        earliest[tmp] = min(i+1, earliest[tmp]);
    }
    int res = DFS(1);
    if (res == INF){
        printf("%d", -1);
    } else{
        printf("%d", res);
    }
    return 0;
}