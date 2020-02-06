#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int N, res;
int days[100000][3];

int main (){
    scanf("%d\n", &N);
    scanf("%d%d%d", &days[0][0], &days[0][1], &days[0][2]); 
    for (int i = 1; i < N; i++){
        scanf("%d%d%d", &days[i][0], &days[i][1], &days[i][2]); 
        days[i][0] = days[i][0] + max(days[i-1][1], days[i-1][2]);
        days[i][1] = days[i][1] + max(days[i-1][0], days[i-1][2]);
        days[i][2] = days[i][2] + max(days[i-1][0], days[i-1][1]);       
    }
    res = max({days[N-1][0], days[N-1][1], days[N-1][2]});
    printf("%d", res);
    return 0;
}