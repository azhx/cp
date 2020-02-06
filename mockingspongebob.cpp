#include <bits/stdc++.h>
using namespace std;
int N;

int main(){
    scanf("%d\n", &N);
    for (int i = 0; i < N+1; i++){
        string line;
        getline(cin, line);
        bool capital = false;
        for (int j =0; j < line.length(); j++){
            if (line[j] >='A' && line[j] <= 'Z'){
                if (capital == false){
                    line[j] = line[j]- 'A' + 'a';
                    capital = true;
                } else{
                    capital = false;
                }
            } else if (line[j] >='a' && line[j] <= 'z'){
                if (capital == true){
                    line[j] = line[j] -'a'+'A';
                    capital = false;
                } else{
                    capital = true;
                }
            }
        }
        printf("%s\n", line.c_str());
    }
    return 0;
}