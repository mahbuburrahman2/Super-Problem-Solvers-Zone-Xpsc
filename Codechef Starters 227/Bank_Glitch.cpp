#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int tc;
  cin >> tc;

  while (tc--)
  {
    ll a, b, x, y;
    cin >> a >> b >> x >> y;

    ll t = a / x;            
    ll p = t * (y - x);

    cout << a + b + p << endl;
  }

  return 0;
}