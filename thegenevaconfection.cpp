#include <bits/stdc++.h>
using namespace std;
int T;

int main (){
    scanf("%d", &T);
    for (int i= 0; i< T; i++){
        int N, j = 1;
        scanf("%d", &N);
        stack<int> r, b;
        bool done = false;
        for (int j = 0; j < N; j++){
            int tmp;
            scanf("%d", &tmp);
            r.push(tmp);
        }
        while (!done){
            if (!r.empty() && r.top() == j){
                r.pop(); j++;
            } else if (!b.empty() && b.top() ==j){
                b.pop(); j++;
            } else if (!r.empty()){
                b.push(r.top());
                r.pop();
            } else{
                done = true;
            }
            if (j == N+1){
                done = true;
            }
        }
        if (b.empty()){
            printf("Y\n");
        } else {
            printf("N\n");
        }
    }
    return 0;
}