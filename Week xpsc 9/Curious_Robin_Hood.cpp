#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
long long a[MAXN], t[4 * MAXN];

void build(int node, int b, int e)
{
  if (b == e)
  {
    t[node] = a[b];
    return;
  }
  int mid = (b + e) / 2;
  build(2 * node, b, mid);
  build(2 * node + 1, mid + 1, e);
  t[node] = t[2 * node] + t[2 * node + 1];
}

void update(int node, int b, int e, int idx, long long val)
{
  if (b == e)
  {
    t[node] = val;
    return;
  }
  int mid = (b + e) / 2;
  if (idx <= mid)
    update(2 * node, b, mid, idx, val);
  else
    update(2 * node + 1, mid + 1, e, idx, val);

  t[node] = t[2 * node] + t[2 * node + 1];
}

long long query(int node, int b, int e, int l, int r)
{
  if (r < b || e < l)
    return 0;
  if (b >= l && e <= r)
    return t[node];

  int mid = (b + e) / 2;
  return query(2 * node, b, mid, l, r) +
         query(2 * node + 1, mid + 1, e, l, r);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  for (int tc = 1; tc <= T; tc++)
  {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
    }

    build(1, 1, n);

    cout << "Case " << tc << ":\n";

    while (q--)
    {
      int type;
      cin >> type;

      if (type == 1)
      {
        int i;
        cin >> i;
        i++; // 0-based → 1-based

        cout << a[i] << '\n';
        a[i] = 0;
        update(1, 1, n, i, 0);
      }
      else if (type == 2)
      {
        int i, v;
        cin >> i >> v;
        i++;

        a[i] += v;
        update(1, 1, n, i, a[i]);
      }
      else
      {
        int l, r;
        cin >> l >> r;
        l++;
        r++;

        cout << query(1, 1, n, l, r) << '\n';
      }
    }
  }
  return 0;
}