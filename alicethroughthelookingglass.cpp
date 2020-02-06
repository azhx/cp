#include <bits/stdc++.h>
using namespace std;
int T;


bool detect(int mag, long long x, long long y){
    long long bound = pow(5, mag)/5;
    bool rect, box, up1, up2, up3;
    rect = (x >= bound && x < bound*4 && y < bound);
    box = (x >= bound *2 && x < bound*3 && y >= bound && y < bound*2);
    if (mag == 1 && !rect && !box){
        return false;
    }
    up1 = (x >= bound && x < bound*2 && y >= bound && y < bound*2);
    up2 = (x >= bound*2 && x < bound*3 && y >= bound*2 && y < bound*3);
    up3 = (x >= bound*3 && x < bound*4 && y >= bound && y < bound*2);
    if (box || rect){
        return true;
    } else if ( up1 || up2 || up3 ){
        bool ans = detect (mag-1, x%bound, y%bound);
        return ans;
    } else {
        return false;
    }
}

int main (){
    scanf("%d", &T);
    for (int i = 0; i < T; i++){
        int mag;
        long long x, y;
        scanf("%d%lld%lld", &mag, &x, &y);
        bool ans = detect(mag, x, y);
        if (ans){
            printf("crystal\n");
        } else {
            printf("empty\n");
        }   
    }
    return 0;
}