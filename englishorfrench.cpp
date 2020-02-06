#include <bits/stdc++.h>
using namespace std;

int main ()
{
  int s = 0, t = 0;
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N+1; i++)
  {
    //char in [100];
    string line;
    //scanf("%[^\n]s", in);
    getline(cin, line);
    for (int j = 0; j < line.length(); j++){
      if (line[j] == 'S' || line[j] == 's')
      {
        s+=1;
      }
      else if (line[j] == 'T' || line[j] == 't')
      {
        t+=1;
      }
    }
    printf("%d", i);
  }
  if (s > t)
  {
    printf("French");
  }
  else if (t > s)
  {
    printf("English");
  }
  else
  {
    printf("French");
  }
  return 0;
}
