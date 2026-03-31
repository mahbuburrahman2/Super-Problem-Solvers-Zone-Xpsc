#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[300];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
  {
    string s;
    int m;
    cin >> s >> m;

    memset(a, 0, sizeof a);

    for (char &c : s)
    {
      a[c]++;
      m -= (c - 'a' + 1);
    }

    for (int i = 'z'; i >= 'a'; i--)
    {
      while (a[i] && m < 0)
      {
        m += i - 'a' + 1;
        a[i]--;
      }
    }

    for (char c : s)
    {
      if (a[c] > 0)
      {
        cout << c;
        a[c]--;
      }
    }
    cout << endl;
  }
  return 0;
}