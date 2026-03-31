#include <bits/stdc++.h>
using namespace std;

#define f(n) for (int i = 0; i < n; i++)
#define ll long long

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin >> t;
  while (t--)
  {
    ll n;
    cin >> n;

    vector<ll> a(n);
    f(n) cin >> a[i];

    map<ll, ll> mp;
    ll ans = 0;

    mp[a[n - 1]]++;

    for (int i = n - 2; i >= 0; i--)
    {
      if (mp[a[i]] == 1)
      {
        ans += 2;
        mp.clear();
      }
      else
      {
        mp[a[i]]++;
      }
    }

    cout << ans << "\n";
  }
}