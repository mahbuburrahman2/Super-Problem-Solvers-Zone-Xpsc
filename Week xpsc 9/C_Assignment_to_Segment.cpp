#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 5;

long long tree[4 * N];
long long lazy[4 * N];
bool marked[4 * N];

int n, m;

void push(int node, int start, int end)
{
  if (marked[node])
  {
    tree[node] = lazy[node];

    if (start != end)
    {
      marked[node * 2] = true;
      marked[node * 2 + 1] = true;

      lazy[node * 2] = lazy[node];
      lazy[node * 2 + 1] = lazy[node];
    }

    marked[node] = false;
  }
}

void update(int node, int start, int end, int l, int r, long long val)
{
  push(node, start, end);

  if (start > r || end < l)
    return;

  if (l <= start && end <= r)
  {
    marked[node] = true;
    lazy[node] = val;
    push(node, start, end);
    return;
  }

  int mid = (start + end) / 2;
  update(node * 2, start, mid, l, r, val);
  update(node * 2 + 1, mid + 1, end, l, r, val);
}

long long query(int node, int start, int end, int idx)
{
  push(node, start, end);

  if (start == end)
    return tree[node];

  int mid = (start + end) / 2;

  if (idx <= mid)
    return query(node * 2, start, mid, idx);
  else
    return query(node * 2 + 1, mid + 1, end, idx);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  while (m--)
  {
    int type;
    cin >> type;

    if (type == 1)
    {
      int l, r;
      long long v;
      cin >> l >> r >> v;
      update(1, 0, n - 1, l, r - 1, v);
    }
    else
    {
      int i;
      cin >> i;
      cout << query(1, 0, n - 1, i) << "\n";
    }
  }

  return 0;
}