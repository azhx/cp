#include <bits/stdc++.h>
using namespace std;
int R;
int main(){
    while (true){
        int pennies = 0;
        scanf("%d", &R);
        if (R==0){
            break;
        }
        for (int i= 0-R; i < R+1; i++){
            pennies = pennies + (2*floor(sqrt(R*R-i*i))+1);
        }
        printf("\n%d", pennies);
    } 
    return 0;
}