#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
long long N, M;

int main (){
    scanf("%lld%lld", &N, &M);
    vector<long long> arr;
    for (long i =0; i < N; i++){
        long long tmp;
        scanf("%lld", &tmp);
        arr.push_back(tmp);
    }
    long long maxi = 0;
    long long a = 0, b = 0;
    long long sum = 0;
    for (long i = 0; i <N; i++){
        sum += arr[i];
        b ++;
        while (sum >= M){
            sum -= arr[a]; 
            a++;    
        }
        maxi = max(b-a, maxi);
    }
    printf("%lld\n", maxi);
    return 0;
}