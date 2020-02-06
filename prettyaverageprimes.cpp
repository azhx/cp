#include <bits/stdc++.h>
using namespace std;
int T;
int main (){
    scanf("%d", &T);
    for (int i = 0; i < T; i++){
        int avg, sum, a, b;
        scanf("%d", &avg);
        sum = avg*2;
        for (int j = 2; j < avg+1; j++){
            a = j;
            b = sum-j;
            bool prime = true;
            int num = 3;
            while (num <= sqrt(a)){
                if (((a/num)*num) == a){
                    prime = false;
                }
                num +=2;
            }
            if (((a/2)*2) == a){
                prime = false;
            }
            num = 3;
            while (num <= sqrt(b)){
                if (((b/num)*num) == b){
                    prime = false;
                }
                num += 2;
            }
            if (((b/2)*2) == b){
                prime = false;
            }
            if (prime){
                printf("%d %d\n", a, b);
                break;
            }
        }
    }
    return 0;
}