#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int X, Y, N, xs, ys, xe, ye, dy, dx, yt, xt, sum, i, j= 1;

int main (){
    scanf("%d %d %d", &X, &Y, &N);
    scanf("%d %d", &xs, &ys);
    scanf("%d %d", &xe, &ye);
    dy = abs(ye-ys);
    dx = abs(xe-xs);
    for (int k = 0; k <N; k++){
        i++;
        if (i%2 == 0){
            j++;
        }
        j/i
    }
    yt = (ye == ys) ? i:i+1;
    i = 0;
    while (dx > 0){
        i++;
        dx = dx-(2*1);
    }
    xt = (xe == xs) ? i:i+1;
    cout << xt+yt << endl;
    return 0;
}
