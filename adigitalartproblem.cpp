#include <bits/stdc++.h>
using namespace std;
char mode[10];

int main (){
    scanf("%s", mode);
    string operation = mode;
    double a[3], b[3];
    scanf("%lf%lf%lf", &a[0], &a[1], &a[2]);
    scanf("%lf%lf%lf", &b[0], &b[1], &b[2]);
    if (operation == "Multiply"){
        for (int i = 0; i < 3; i++){
            printf("%lf ", a[i]*b[i]);
        }
    } else if (operation == "Screen"){
        for (int i = 0; i < 3; i++){
            printf("%lf ", (1-(1-a[i])*(1-b[i])));
        }
    } else if (operation == "Overlay"){
        for (int i = 0; i < 3; i++){
            if (a[i] < 0.5){
                printf("%lf ", 2*a[i]*b[i]);
            } else {
                printf("%lf ", 1-(2*(1-a[i])*(1-b[i])));
            }
        } 
    }
    return 0;
}