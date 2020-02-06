#include <bits/stdc++.h>
using namespace std;
int N;
int stones[100000];
int costs[100000];

int main(){
    scanf("%d", &N);
    for (int i = 0; i < 2; i++){
        if (i == 0){
            scanf("%d", &stones[i]);
            costs[i] = 0;
        } else if (i = 1){
            scanf("%d", &stones[i]);
            costs[i] = abs(stones[1]-stones[0]);
        }
    }
    for (int i = 2; i < N; i++){
        scanf("%d", &stones[i]);
        int one = abs(stones[i]- stones[i-1])+costs[i-1];
        int two = abs(stones[i]- stones[i-2])+costs[i-2];
        costs[i] =min(one, two);
    }
    printf("%d", costs[N-1]);
}