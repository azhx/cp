#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int N, sum;

int main () {
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        int val;
        scanf("%d", &val);
        sum += val;
    }
    float avg = (float)sum/(float)N;
    printf("%.1f\n", (float)((int)(avg*10))/10);
    return 0;
}