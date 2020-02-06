#include <bits/stdc++.h>
using namespace std;
int N, first, second, maxi;
int readings [1001]; 

int main (){
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        int reading; 
        scanf("%d", &reading);
        readings[reading]++;
        if (readings[first] < readings[reading]){
            first = reading;
        }
    }
    vector<int> firsts;
    vector<int> seconds;
    for (int i = 0; i < 1001; i++){
        if (readings[first] == readings[i]){
            firsts.push_back(i);
        } else if (readings[second] < readings[i]){
            second = i;
        }
    }
    for (int i = 0; i < 1001; i++){
        if (readings[second] == readings[i]){
            seconds.push_back(i);
        }
    }
    if (firsts.size() > 1){
        for (int i = 0; i < firsts.size(); i++){
            for (int j = 0; j < firsts.size(); j++){
                if (i!=j){
                    if (maxi < abs(firsts[i] - firsts[j])){
                        maxi = abs(firsts[i] - firsts[j]);
                    }
                }
            }
        }
    } else if(firsts.size() == 1 && seconds.size() > 1){
        for (int i = 0; i < seconds.size(); i++){
            if (maxi < abs(firsts[0] - seconds[i])){
                maxi = abs(firsts[0] - seconds[i]);
            }
        }
    } else if (firsts.size() == 1 && seconds.size() ==1){
        maxi = abs(firsts[0]-seconds[0]);
    }

    printf("%d\n", maxi);
    return 0;
}