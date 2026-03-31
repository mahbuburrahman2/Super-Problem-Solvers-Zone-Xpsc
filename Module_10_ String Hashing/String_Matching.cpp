#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll p1 = 137, mod1 = 1e9 + 7;
const ll p2 = 149, mod2 = 1e9 + 9;
const int N = 1e6 + 9;
ll pw1[N], pw2[N];

void prec()
{
  pw1[0] = pw2[0] = 1;
  for (int i = 1; i < N; i++)
  {
    pw1[i] = pw1[i - 1] * p1 % mod1;
    pw2[i] = pw2[i - 1] * p2 % mod2;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  prec();

  string t, pat;
  cin >> t >> pat;

  int n = t.size(), m = pat.size();

  if (m > n)
  {
    cout << 0;
    return 0;
  }

  // Build prefix hashes for text
  vector<ll> h1(n + 1, 0), h2(n + 1, 0);
  for (int i = 0; i < n; i++)
  {
    h1[i + 1] = (h1[i] + (ll)t[i] * pw1[i]) % mod1;
    h2[i + 1] = (h2[i] + (ll)t[i] * pw2[i]) % mod2;
  }

  // Hash of pattern
  ll pat_h1 = 0, pat_h2 = 0;
  for (int i = 0; i < m; i++)
  {
    pat_h1 = (pat_h1 + (ll)pat[i] * pw1[i]) % mod1;
    pat_h2 = (pat_h2 + (ll)pat[i] * pw2[i]) % mod2;
  }

  // Slide window of size m over text
  int cnt = 0;
  for (int i = 0; i <= n - m; i++)
  {
    ll win1 = (h1[i + m] - h1[i] + mod1) % mod1;
    ll win2 = (h2[i + m] - h2[i] + mod2) % mod2;

    if (win1 == pat_h1 * pw1[i] % mod1 &&
        win2 == pat_h2 * pw2[i] % mod2)
      cnt++;
  }

  cout << cnt;
  return 0;
}