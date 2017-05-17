#include <iostream>
#include <string.h>
using namespace std;
int main()
{
  int n,s[10050],a[10050],x,max = 0,i;
  cin >> n;
  memset(s,0,sizeof(s));
  memset(a,0,sizeof(a));
  cin >> x;
  s[0] = x;
  a[0] = x;
  int j = x;
  max = x;
  int rj = 0;
  for (int k = 0;k < n-1;++k)
  {
    cin >> x;
    a[k+1] = x;
    if (s[k] < 0 )
    {
      s[k+1] = x;
    }
    else s[k+1] = s[k] + x;
    if (max < s[k+1])
    {
      max = s[k+1];
      j = a[k+1];
      rj = k+1;
    }
    //cout << s[k+1] <<endl;
  }
  for (int k = rj;k >= 0;--k)
  {
    if (s[k] >= 0)
      i = a[k];
    else break;
  }
  if (max < 0)
    cout << 0 << " " << a[0] << " " << a[n-1];
  else
    cout << max << " " << i << " " << j;
}

