#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  while (tc--)
  {
    int n;
    cin >> n;
    vector<int> a(n), ans(n, -1);
    for (int &x : a)
      cin >> x;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({a[0], 0});
    int b = 0;

    for (int i = 0; i < n; i++)
    {
      while (!pq.empty() && pq.top().first <= b)
      {
        auto [lmt, idx] = pq.top();
        pq.pop();
        if (ans[idx] == -1)
          ans[idx] = lmt;
      }

      if (ans[i] == -1)
        ans[i] = b, b++;

      if (i + 1 < n)
        pq.push({a[i + 1], i + 1});
    }

    for (int i = 0; i < n; i++)
      cout << ans[i] << " \n"[i == n - 1];
  }
  return 0;
}