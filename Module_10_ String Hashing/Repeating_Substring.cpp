#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll p1 = 131, mod1 = 1e9 + 7;
const ll p2 = 137, mod2 = 1e9 + 9;
const int N = 1e5 + 9;
ll pw1[N], pw2[N];
ll h1[N], h2[N];

void build(string &s, int n)
{
  pw1[0] = pw2[0] = 1;
  for (int i = 1; i < N; i++)
    pw1[i] = pw1[i - 1] * p1 % mod1,
    pw2[i] = pw2[i - 1] * p2 % mod2;

  for (int i = 0; i < n; i++)
    h1[i + 1] = (h1[i] + (ll)s[i] * pw1[i]) % mod1,
           h2[i + 1] = (h2[i] + (ll)s[i] * pw2[i]) % mod2;
}

int check(int len, int n)
{
  map<pair<ll, ll>, int> seen;
  for (int i = 0; i + len <= n; i++)
  {
    ll a1 = (h1[i + len] - h1[i] + mod1) % mod1 * pw1[N - 1 - i] % mod1;
    ll a2 = (h2[i + len] - h2[i] + mod2) % mod2 * pw2[N - 1 - i] % mod2;
    auto key = make_pair(a1, a2);
    if (seen.count(key))
      return seen[key];
    seen[key] = i;
  }
  return -1;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();
  build(s, n);

  int lo = 1, hi = n - 1, ans_pos = -1, ans_len = 0;
  while (lo <= hi)
  {
    int mid = (lo + hi) / 2;
    int pos = check(mid, n);
    if (pos != -1)
    {
      ans_pos = pos;
      ans_len = mid;
      lo = mid + 1;
    }
    else
    {
      hi = mid - 1;
    }
  }

  if (ans_pos == -1)
    cout << -1;
  else
    cout << s.substr(ans_pos, ans_len);
}
