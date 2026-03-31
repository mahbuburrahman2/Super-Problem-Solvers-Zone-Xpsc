#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[400001], ans = 0, mod = 1e9 + 7;
int main()
{
  f[0] = 1;
  for (int i = 1; i <= 4e4; i++)
  {
    string a = to_string(i);
    if (string(a.rbegin(), a.rend()) == a)
    {
      for (int j = i; j <= 4e4; j++)
        f[j] = (f[j] + f[j - i]) % mod;
    }
  }
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    cout << f[n] << endl;
  }
}