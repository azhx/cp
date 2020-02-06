#include <bits/stdc++.h>
using namespace std;
int target, N, INF = 1e9;int strokes[5281];
vector<int> clubs;
int main() {
    memset(strokes, 0x3f3f3f3f, sizeof(strokes));
    scanf("%d%d", &target, &N);
    strokes[0] = 0;
    for (int i = 0; i < N; i++){
        int tmp;
        scanf("%d", &tmp);
        clubs.push_back(tmp);
    }
    for (int i = 1; i < target+1; i++){
        for (int j = clubs.size()-1; j > -1; j--){
            if(i-clubs[j]>=0){
                strokes[i] = min(strokes[i],1+strokes[i-clubs[j]]);
            }
        }
    }
    if (strokes[target] == 0x3f3f3f3f ){
        printf("Roberta acknowledges defeat."); 
    } else{
        printf("Roberta wins in %d strokes.", strokes[target]);
    }
    return 0;   
}