#include <bits/stdc++.h>
using namespace std;
char tmp [1000000];
int grid[2][2] = {{1, 2}, {3, 4}};

int main (){
    scanf("%s", tmp);
    string operations = tmp; 
    for (int i = 0; i < operations.length(); i++){
        if (operations[i] == 'V'){
            int tmp[2]; 
            tmp[0] = grid[0][0];
            tmp[1] = grid[1][0];
            grid[0][0] = grid[0][1];
            grid[1][0] = grid[1][1];
            grid[0][1] = tmp[0];
            grid[1][1] = tmp[1];
        } else if (operations[i] == 'H'){
            int tmp[2];
            tmp[0] = grid[0][0];
            tmp[1] = grid[0][1];
            grid[0][0] = grid[1][0];
            grid[0][1] = grid[1][1];
            grid[1][0] = tmp[0];
            grid[1][1] = tmp[1];
        }
    }
    printf("%d %d\n%d %d\n", grid[0][0], grid[0][1], grid[1][0], grid[1][1]);
    return 0;

}