#include <bits/stdc++.h>
using namespace std;

int main ()
{
  int h1, w1, h2, w2;
  scanf("%d %d\n%d %d", &h1, &w1, &h2, &w2);
  if ((h1-1)*w2 < (h2-1)*w1)
  {
    printf("2");
  }
  else if ((h1-1)*w2 > (h2-1)*w1)
  {
    printf("1");
  }
  else
  {
    printf("-1");
  }
}
