#include <bits/stdc++.h>
using namespace std;
int n, d;
int main(){
    scanf("%d %d", &n, &d);
    int whole = n/d;
    if (whole != 0){
        printf("%d ", whole);
    }
    int mod = n % d;
    int common;
    if (mod != 0){
        for (int i = 1; i < mod+1; i ++){
            if (mod % i == 0 && d % i == 0){
                common = i;
            }
        }
        printf("%d/%d", mod/common, d/common);
    }
    return 0;
}