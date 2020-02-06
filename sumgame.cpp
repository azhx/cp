#include <bits/stdc++.h>
using namespace std;
int N;

int main (){
    scanf("%d", &N);
    vector<int> a;
    vector<int> b;
    for (int i =0; i < N; i++){
        int tmp;
        scanf("%d", &tmp);
        a.push_back(tmp);
    }
    for (int i = 0; i < N; i++){
        int tmp;
        scanf("%d", &tmp);
        b.push_back(tmp);
    }
    int maxi = 0, suma = 0, sumb = 0;
    for (int i = 0; i < N; i++){
        suma += a[i];
        sumb += b[i];
        if (suma == sumb){
            maxi = i+1;
        }
    }
    printf("%d\n", maxi);
    return 0;
}