#include <bits/stdc++.h>
using namespace std;
int l, w;
vector<vector<char>> canvas;


int main (){
    scanf("%d %d\n", &l, &w);
    for (int i = 0; i < l; i++){
        string line;
        getline(cin, line);
        vector<char> ln;
        for (int j = 0; j < line.length(); j++){
            ln.push_back(line[j]);
        }
        canvas.push_back(ln);
    }
    int res = 0;
    for (int i = 0; i < w; i++){
        int bcount= 0;
        for (int j = 0; j < l; j++){
            if (canvas[j][i] == 'R'){
                break;
            }
            else if (canvas[j][i] == 'B'){
                bcount = 0;
            }
            else if (canvas[j][i] == '.'){
                if (i != 0 && (canvas[j][i-1] == 'B' || canvas[j][i-1] == '.')){
                    bcount++;
                }
                canvas[j][i] ='B';
                bcount++;
            }
        }
        res = res * bcount;
    }
    printf("%d", res);
    return 0;
}








/*
bool nevergood = false;

int main(){
    scanf("%d %d\n", &l, &w);
    vector<vector<char>> canvas;
    for (int i = 0; i < l; i++){
        string line;
        getline(cin, line);
        vector<char> ln;
        for (int j = 0; j < line.length(); j++){
            ln.push_back(line[j]);
        }
        canvas.push_back(ln);
        for (int j = 0; j < canvas.size(); j++){
            for (int k = 0; k < canvas[0].size(); k++){
                if (canvas[j][k] == 'B'){
                    for (int m = 0; m < j+1; m++){
                        for (int n = 0; n < k+1; n++){
                            if (canvas[m][n] == 'R'){
                                nevergood = true;
                            }
                            canvas[m][n] = 'B';
                        }
                    }
                } else if (canvas[j][k] == 'R'){
                    for (int m = canvas.size()-1; m > j-1; m--){
                        for (int n = canvas[0].size()-1; n > k-1; n--){
                            if (canvas[m][n] == 'B'){
                                nevergood = true;
                            }
                            canvas[m][n] = 'R';
                        }
                    }
                }
            }
        }
    }
    int colorings= 1, doublings= 0, dots =0;
    for (int i = 0; i < l; i++){
        for (int j = 0; j < w; j++){
            if (canvas[i][j] == '.'){
                dots++;
                int dotsfound = 0;
                for (int k = 0; k < i + 1; k ++){
                    for (int m = 0; m < j + 1; m++){
                        if (canvas[k][m] == '.'){
                            dotsfound ++; 
                        }
                    }
                }
                if (dotsfound-1 == 0){
                    colorings = colorings *2;
                    doublings ++;
                } else if (dotsfound == dots) {
                    colorings = colorings + doublings;
                } else if (dotsfound < dots){
                    colorings = colorings + (doublings * (dots-dotsfound+1));
                }
            }
        }
    }
    if (nevergood == true){
        printf("0");
    } else{
        printf("%d", colorings);
    }
    return 0;
}
*/