#include <bits/stdc++.h>
using namespace std;
int N, M, min;
string candidates[20];
int candidatevotes[20];
int voters [10000][20];

int main (){
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++){
        char tmp[20];
        scanf("%s", tmp);
        candidates[i] = tmp;
    }
    for (int i = 0; i < M; i++){
        int tmp;
        scanf("%d", &tmp);
        for (int j = 0; j < tmp; j++){
            char tmp [20];
            scanf("%s", tmp);
            string name = tmp;
            for (int k = 0; k < 20; k ++){
                if (candidates[k] == name){
                    voters[i][j] = k;
                }
            }
        }
    }
    return 0;
}