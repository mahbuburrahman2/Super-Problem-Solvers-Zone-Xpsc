#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 5;

string s;
int lazy[4 * N];

void update(int node, int b, int e, int l, int r)
{
  if (e < l || b > r)
    return;

  if (l <= b && e <= r)
  {
    lazy[node] ^= 1;
    return;
  }

  int m = (b + e) >> 1;
  update(node << 1, b, m, l, r);
  update(node << 1 | 1, m + 1, e, l, r);
}

int query(int node, int b, int e, int idx)
{
  if (b == e)
  {
    int bit = s[b] - '0';
    return bit ^ lazy[node];
  }

  int m = (b + e) >> 1;

  if (idx <= m)
    return lazy[node] ^ query(node << 1, b, m, idx);
  else
    return lazy[node] ^ query(node << 1 | 1, m + 1, e, idx);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  for (int tc = 1; tc <= t; tc++)
  {
    cin >> s;
    int n = s.size();

    memset(lazy, 0, sizeof lazy);

    int q;
    cin >> q;

    cout << "Case " << tc << ":\n";

    while (q--)
    {
      char type;
      cin >> type;

      if (type == 'I')
      {
        int l, r;
        cin >> l >> r;
        l--, r--;
        update(1, 0, n - 1, l, r);
      }
      else
      {
        int i;
        cin >> i;
        i--;
        cout << query(1, 0, n - 1, i) << '\n';
      }
    }
  }
  return 0;
}