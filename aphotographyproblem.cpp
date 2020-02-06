#include <bits/stdc++.h>
using namespace std;
int N, M;
double image[1000][1000];

int main (){
    scanf("%d%d", &N, &M);
    double total = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            double tmp;
            scanf("%lf", &tmp);
            total += tmp;
            image[i][j] = tmp;
        }
    }
    double avg = (double) total/(M*N);
    if ((avg-0.48) < -0.00001){
        printf("underexposed\n");
    } else if (abs(avg-0.48) < 0.00001){
        printf("correctly exposed\n");
        return 0;
    } else if ((avg-0.48) > 0.00001){
        printf("overexposed\n");
    }
    double c = (0.48/avg);
    double actualc = c;
    while (abs(avg - 0.48) > 0.00001){
        total = 0;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                image[i][j]*=c;
                if (image[i][j] > 1){
                    image[i][j] = 1;
                }
                total += image[i][j];
            }
        }
        avg = (double)total/(M*N);
        c = (0.48/avg);
        actualc *=c;
    }
    printf("%lf", actualc);
    return 0;
}