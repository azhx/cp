#include <bits/stdc++.h>
using namespace std;
int N;
char tmp[200000];

int main (){
    string target, current;
    scanf("%d\n", &N);
    scanf("%s", tmp);
    current = tmp;
    scanf("%s", tmp);
    target = tmp;
    for (int i = 0; i < N-1; i++){
        if (target[i] != current[i]){
            bool yes = false;
            if (current[i] == current[i+1]){
                yes == true;
            };
            if (current[i] == 'F'){
                current[i] = 'A';
            } else {
                current[i] = 'F';
            } 
            if (i != N-1 && yes == true){
                if (current[i+1] == 'F'){
                    current[i+1] = 'A';
                } else {
                    current[i+1] = 'F';
                } 
            }
        } if (i == N-2){
            if (current[i] != target[i]){
                printf("NO");
                return 0;
            } else {
                printf("YES");
                return 0;
            }
        }
    }
}