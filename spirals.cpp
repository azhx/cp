#include <bits/stdc++.h>
using namespace std;
int x, y, li = 5, lj = 5;
vector<vector<int>> board (13, vector<int>(13, 0));

int main (){
    scanf ("%d %d", &x, &y);
    int N = y - x;
    board[li][lj] = x;
    for (int i =0; i< N; i++){
        int u = board[li-1][lj];
        int d = board[li+1][lj];
        int l = board[li][lj-1];
        int r = board[li][lj+1];
        if (i == 0){
            board[li+1][lj] = board[li][lj]+1;
            li++;
            continue;
        }
        if (d == 0 && r != 0){
            board[li+1][lj] = board[li][lj]+1;
            li++;
            continue;
        } else if (r == 0 && u != 0){
            board[li][lj+1] = board[li][lj]+1;
            lj++;
            continue;
        } else if (u == 0 && l != 0){
            board[li-1][lj] = board[li][lj]+1;
            li--;
            continue;
        } else if (l == 0 && d != 0){
            board[li][lj-1] = board[li][lj]+1;
            lj--;
            continue;
        }
    }
    vector<vector<int>> horiz;
    vector<vector<int>> out;
    for (int i = 0; i < 11; i++){
        for (int j = 0; j < 11; j ++){
            if (board[i][j] != 0){
                horiz.push_back(board[i]);
                break;
            }
        }
    }
    for (int i = 0; i < 11; i++){
        for (int j = 0; j < horiz.size(); j ++){
            if (horiz[j][i] != 0){
                vector<int> temp;
                for (int k = horiz.size()-1; k > -1; k--){
                    temp.push_back(horiz[k][i]);
                }
                out.push_back(temp);
                break;
            }
        }
    }
    for (int i =out[0].size()-1; i > -1; i--){
        for (int j =0; j < out.size(); j++){
            if (out[j][i] == 0){
                printf("   ");
            }
            else if (out[j][i] < 10){
                printf(" %d ", out[j][i]);
            }
            else{
                printf("%d ", out[j][i]);
            }
        }
        printf("\n");
    }

    return 0;
}