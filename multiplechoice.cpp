#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    scanf("%d\n", &N);
    vector<char> student;
    vector<char> teacher;
    int correct = 0;
    for (int i =0; i< N; i++){
        char tmp;
        scanf(" %c", &tmp);
        student.push_back(tmp);
    }
    for (int i =0; i < N; i++){
        char tmp;
        scanf(" %c", &tmp);
        teacher.push_back(tmp);
    }
    for (int i= 0; i < student.size();i++){
        if (student[i] == teacher[i]){
            correct ++;
        }
    }
    printf("%d", correct);
    return 0;
}