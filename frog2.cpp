#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int N, K, mini;
int stones[100000];
int costs[100000];

int main(){
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i ++){
        scanf("%d", &stones[i]);
    }
    for (int i = 0; i < K; i++){
        costs[i] = (i == 0)? 0: abs(stones[0]-stones[i]);
    }
    for (int i = K; i < N; i++){
        mini = INF;
        for (int j = 1; j < K+1; j++){
            mini = min(mini, abs(stones[i]- stones[i-j])+costs[i-j]);
        }
        costs[i] = (mini == INF) ? 0: mini;
    }
    printf("%d", costs[N-1]);
}