#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
  {
    ll p, q;
    cin >> p >> q;

    if (3 * p == 2 * q)
    {
      cout << "Bob\n";
      continue;
    }

    ll r = 3 * p - 2 * q;
    if (r < 0)
    {
      cout << "Alice\n";
      continue;
    }

    // Solve 3i - 2j = r with i>=0, j>=0
    // minimal j = 0 → i = r/3
    if (r % 3 == 0)
    {
      ll i = r / 3;
      ll j = 0;
      if (i <= p && j <= q - 1)
        cout << "Bob\n";
      else
        cout << "Alice\n";
    }
    else
    {
      cout << "Alice\n";
    }
  }

  return 0;
}
