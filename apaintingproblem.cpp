#include <bits/stdc++.h>
using namespace std;
int N, M, K;

int main (){
    scanf("%d%d%d", &N, &M, &K);
    /*vector<int> Nexp;
    vector<int> Mexp;
    while (N != 0){
        int modn = N%2;
        Nexp.push_back(modn);        
        N = N/2;
    }
    while (M != 0){
        int modm = M%2;
        Mexp.push_back(modm);        
        M = M/2;
    }*/
    int blue = 0, purple = 0;
    for (int i = 0; i < K; i++){
        if (((M>>i)&1)+ ((N>>i)&1) == 1){
            blue++;
        } else{
            purple++;
        }
    }
    printf("%d %d", blue, purple);
    return 0;
}

/*
        for (int i = 0; i < k; i++)
            if (((m >> i) & 1) + ((n >> i) & 1) == 1)
                b++;
            else
*/