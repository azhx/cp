#include <bits/stdc++.h>
using namespace std;

int main ()
{
  char ta[100], tb[100];
  scanf("%s%s", ta, tb);
  string a = ta, b = tb;
  string tempa = a;
  for (int i = 0; i < tempa.length(); i++)
  {
    bool found = false;
    for (int j = 0; j < b.length(); j++)
    {
      if (a[0] == b[j])
      {
        found = true;
        a.erase(a.begin());
        b.erase(b.begin()+j);
        break;
      }
    }
    if (found == false)
    {
      found = false;
      a.append(a, 0, 1);
      a.erase(a.begin());
    }
  }
  if ((a.length() == 0 && b.length() > 0) || (b.length() == 0 && a.length() > 0))
  {
    printf("N");
  }
  else if (a.length() > 0 && b.length() > 0)
  {
    for (int i = 0; i < b.length(); i++)
    {
      if (b[i] != '*')
      {
        printf("N");
        return 0;
      }
    }
    printf("A");
  }
  else
  {
    printf("A");
  }
}
