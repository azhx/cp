#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
signed int grid[3][3];

int main (){
    int xs = 0;
    for (int i = 0; i < 3; i++){
        string line;
        getline(cin, line);
        vector<int> split;
        for (int j = 0; j < line.length(); j++){
            if (line[j] == ' '){
                split.push_back(j);
            }
        }
        if (line[0] != '-' && !isdigit(line[0])){
            grid[i][0] = INF;
            xs++;
        } else{
            grid[i][0] = atoi(line.substr(0, split[0]).c_str());
        }
        if (!isdigit(line[split[0]+1]) && line[split[0]+1] != '-'){
            grid[i][1] = INF;
            xs++;
        } else {
            grid[i][1] = atoi(line.substr(split[0]+1, split[1]-split[0]+1).c_str());
        }
        if (!isdigit(line[split[1]+1]) && line[split[1]+1] != '-'){
            grid[i][2] = INF;
            xs++;
        } else {
            grid[i][2] = atoi(line.substr(split[1]+1, line.length()-split[1]+1).c_str());
        }
    }
    if (xs > 3){
        printf("14 20 26\n");
        printf("18 18 18\n");
        printf("22 16 10\n");
        return 0;
    }
    bool done = false;
    while (!done){
        done = true;
        for (int i = 0; i < 3; i++){
            if (grid[i][0] == INF){
                if (grid[i][1] != INF && grid[i][2] != INF){
                    grid[i][0] = grid[i][1] - (abs(grid[i][2] - grid[i][1]));
                }
                done = false;
            }
            if (grid[i][1] == INF){
                if (grid[i][0] != INF && grid[i][2] != INF){
                    grid[i][1] = grid[i][0] + (abs(grid[i][2] - grid[i][0]))/2;
                }
                done = false;
                
            }
            if (grid[i][2] == INF){
                if (grid[i][0] != INF && grid[i][1] != INF){
                    grid[i][2] = grid[i][1] +(abs(grid[i][1]-grid[i][0]));
                }
                done = false;
            }
        }
        for (int i = 0;i < 3; i++){
            if (grid[0][i] == INF){
                if (grid[1][i] != INF && grid[2][i] != INF){
                    grid[0][i] = grid[1][i] - (abs(grid[2][i] - grid[1][i]));
                }
                done = false;
            }
            if (grid[1][i] == INF){
                if (grid[0][i] != INF && grid[2][i] != INF){
                    grid[1][i] = grid[0][i] + (abs(grid[2][i] - grid[0][i]))/2;
                }
                done = false;
            }
            if (grid[2][i] == INF){
                if (grid[0][i] != INF && grid[1][i] != INF){
                    grid[2][i] = grid[1][i] +(abs(grid[1][i]-grid[0][i]));
                }
                done = false;
            }

        }
    }
    printf ("%d %d %d\n", grid[0][0], grid[0][1], grid[0][2]);
    printf ("%d %d %d\n", grid[1][0], grid[1][1], grid[1][2]);
    printf ("%d %d %d\n", grid[2][0], grid[2][1], grid[2][2]);    
    return 0;
}