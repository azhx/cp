#include <bits/stdc++.h>
using namespace std;
#define toDigit(x) (x-'0')

string subtract(string num){
    int subtract = toDigit(num[num.length()-1]);
    num = num.substr(0, num.length()-1);
    for (int i = num.length()-1; i >-1; i--){
        int raw = toDigit(num[i]) - subtract;
        if (raw < 0){
            raw = 10+ raw;
            subtract = 1;
        } else {
            subtract = 0;
        }
        char achar = raw + '0';
        num[i] = achar;
    }
    if (num[0] == '0'){
        num = num.substr(1, num.length()-1);
    }
    return num;
}

int main(){
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        char number[50];
        scanf("%s", number);
        string num = number;
        printf("%s\n", num.c_str());
        while (num.length() > 2){
            num = subtract(num);
            printf("%s\n", num.c_str());        
        }
        string out = number;
        if (stoi(num)%11 == 0){
            printf("The number %s is divisible by 11.\n", out.c_str());
        } else{
            printf("The number %s is not divisible by 11.\n", out.c_str());
        }
    }
    return 0;
}