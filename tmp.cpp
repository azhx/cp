#include <bits/stdc++.h>
using namespace std;
int N, Q, i, j;
bool grid [100000][100000];

int main (){
    scanf("%d%d", &N, &Q);
    for (int i =0; i < Q; i++){
        int event;
        scanf("%d", &event);
        if (event == 1){
            scanf("%d%d", &i, &j);
            bool target;
            if (grid[i][j] == true){
                target = false;
            } else{
                target = true;
            }
            for (int k = 0; k < N; k++){
                grid[j][k] = target;
                grid[k][i] = target;
            }
        } else if (event == 2){
            scanf("%d%d", &i, &j);
            if (grid[i][j] == true){
                printf("%d\n", 1);
            } else {
                printf("%d\n", 0);
            }
        }
    }
    return 0;
}