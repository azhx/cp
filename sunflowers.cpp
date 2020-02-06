#include <bits/stdc++.h>
using namespace std;
#define toDigit(x) (x-'0')
int N, tl, tr, bl;

int main (){
    scanf("%d", &N);
    vector<vector<long long>> matrix;
    for (int i = 0; i < N; i++){
        vector<long long> row;
        for (int j = 0; j < N; j++){
            long long tmp;
            scanf("%lld", &tmp);
            row.push_back(tmp);
        }
        matrix.push_back(row);
    }
    tl = matrix[0][0]; // tl < tr, tl < bl
    tr = matrix[0][N-1]; //tr > tl, tr < br
    bl = matrix[N-1][0]; // bl > tl, bl < br

    if (tl < tr && tl < bl){
        for (int i = 0; i < N; i ++){
            for (int j = 0; j < N; j++){
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    } else if (tl > tr && tl < bl){
        for (int i = N-1; i > -1; i--){
            for (int j = 0; j < N; j++){
                cout << matrix[j][i] << " ";
            }
            cout << "\n";
        }
    } else if (tl < tr && tl > bl){
        for (int i = 0; i < N; i++){
            for (int j = N-1; j > -1; j--){
                cout << matrix[j][i] << " ";
            }
            cout << "\n";
        }        
    } else if (tl > tr && tl > bl){
        for (int i = N-1; i > -1; i --){
            for (int j = N-1; j > -1; j--){
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    } 
    return 0;
}