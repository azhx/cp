#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

string XOR (vector<string> state, int j, int L) {
    string newstate;
    for (int k = 0; k < L; k ++){
        char newchar = ((state[j-1][k] - '0') ^ (state[j][k] -'0')) + '0';
        newstate += newchar;
    }
    return newstate;
}

int main ()
{
    int R, L;
    scanf("%d%d", &R, &L);
    vector<string> lights(R, "0");
    for (int i = 0; i < R; i++){
        string s;
        for (int j = 0; j < L; j++){
            char ch;
            scanf(" %c", &ch);
            s += ch;
        }
        lights[i] = s;
    }

    unordered_set<string> possibilities;
    vector<string> state;
    for (int i = 1; i < R; i++){
        state = lights;
        for (int j = i - 1; j > -1 ; j --){
            state[R-j-1] = XOR(state, R-j-1, L);
        }
        possibilities.insert(state[R-1]);
    }
    possibilities.insert(lights[R-1]);
/* queue<pair<int, vector<string>>> q;
    for (int i = 1; i< R; i++){
        int level [31] = {0};
        int currlevel = 0;
        q.push(make_pair(i, XOR(lights, i, L)));
        while (!q.empty()){
            currlevel++;
            int v;
            vector<string> state;
            tie(v, state) = q.front();
            q.pop();
            for (int j = 1; j < R; j++){
                if (level[j] == currlevel){
                    state = XOR(state, j, L);
                    if (j == R){
                        possibilities.insert(state[j]);
                    }
                    else {
                        q.push(make_pair(j, state));
                        
                    }
                }
            }
        }
    }
*/
    printf("%ld\n", possibilities.size());
    return 0;
 }