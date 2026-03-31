#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    ll p, q;
    cin >> p >> q;
    bool k = (3 * p < 2 * q) || (q <= p);
    if (k)
    {
      cout << "Alice" << endl;
    }
    else
    {
      cout << "Bob" << endl;
    }
  }
  return 0;
}
