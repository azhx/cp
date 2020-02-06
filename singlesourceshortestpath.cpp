#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int N, M;
int dist[1001]; 


int main (){
    memset(dist, INF, sizeof(dist)); 
    dist[1] = 0;
    vector<pair<int, int>> grid [1001];
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        grid[u].push_back(make_pair(w, v));
        grid[v].push_back(make_pair(w, u));
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq; 
    pq.push(make_pair(dist[1], 1));
    while (!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for (int i = 0; i < grid[u].size(); i++){
            if (dist[grid[u][i].second] > dist[u] + grid[u][i].first ){
                dist[grid[u][i].second] = dist[u] + grid[u][i].first;
                pq.push(grid[u][i]);
            }
        }
    }
    for (int i = 1; i < N+1; i++){
        if (dist[i] != INF){
            printf("%d\n", dist[i]);
        } else {
            printf("%d\n", -1);
        }
    }
    return 0;
}
