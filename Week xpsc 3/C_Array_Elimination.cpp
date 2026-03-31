#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tc;
  cin >> tc;
  while (tc--)
  {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
      cin >> x;

    int g = 0;
    for (int i = 0; i < 31; i++)
    {
      int cnt = 0;
      for (int x : a)
        if (x & (1 << i))
          cnt++;
      g = __gcd(g, cnt);
    }

    for (int k = 1; k <= n; k++)
      if (g % k == 0)
        cout << k << " ";
    cout << "\n";
  }
}
