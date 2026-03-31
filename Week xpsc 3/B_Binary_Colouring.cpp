#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  while (tc--)
  {
    ll x;
    cin >> x;
    vector<int> a;
    while (x > 0)
    {
      if (x % 2 == 0)
      {
        a.push_back(0);
        x /= 2;
      }
      else
      {
        int v;
        if (x % 4 == 1)
          v = 1;
        else
          v = -1;
        a.push_back(v);
        x = (x - v) / 2;
      }
    }
    cout << a.size() << "\n";

    for (int v : a)
      cout << v << " ";
    cout << "\n";
  }

  return 0;
}
