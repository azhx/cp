#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int N, res;

int main () {
    scanf("%d",&N);
    vector<vector<int>> good (N, vector<int>(N, 0));
    vector<vector<int>> given (N, vector<int>(N, 0));
    int n = 1;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            good[i][j] =n; 
            n+= 1;
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            scanf("%d", &given[i][j]);
        }
    }
    for (int i =0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (given[i][j] != good[i][j]){
                res+= 1;
            }
        }
        if (res != 0){
            cout << res << endl;
            break;
        }
    }

    return 0;
}