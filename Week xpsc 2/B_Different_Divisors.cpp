#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> prime;
bool visprime[300005];

void Prime(ll NN)
{
  prime.push_back(2);
  for (ll i = 4; i <= NN; i += 2)
    visprime[i] = true;

  for (ll i = 3; i <= NN; i += 2)
  {
    if (visprime[i])
      continue;
    prime.push_back(i);
    for (ll j = i * i; j <= NN; j += 2 * i)
      visprime[j] = true;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  Prime(200000);

  while (t--)
  {
    int d;
    cin >> d;

    ll p = 0, q = 0;

    for (ll x : prime)
    {
      if (x >= d + 1)
      {
        p = x;
        break;
      }
    }

    for (ll x : prime)
    {
      if (x >= p + d)
      {
        q = x;
        break;
      }
    }

    cout << p * q << "\n";
  }

  return 0;
}
