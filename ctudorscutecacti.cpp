#include <bits/stdc++.h>
using namespace std;
int N, Q;

int main (){
    scanf("%d%d", &N, &Q);
    vector<vector<int>> columns (N+1, vector<int>());
    vector<vector<int>> rows (N+1, vector<int>()); 
    for (int i = 0; i < Q; i++){
        int event;
        scanf("%d", &event);
        if (event == 1){
            int a, b;
            scanf("%d%d", &a, &b);
            columns[a].push_back(b);
            rows[b].push_back(a);
        }
        if (event ==2){
            int a, b;
            scanf("%d%d", &a, &b);
            int repeat = 0;
            for (int j = 0; j < (int)columns[a].size(); j++){
                if (columns[a][j] == b){
                    repeat++;
                }
            }
            int res = (columns[a].size() + rows[b].size() - repeat)%2;
            if (res == 1){
                printf("%d\n", 1);
            } else if (res == 0){
                printf("%d\n", 0);
            }
        }
    }
    return 0;
}