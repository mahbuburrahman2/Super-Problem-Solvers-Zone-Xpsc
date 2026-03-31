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
    int n, k;
    cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>> pq;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    string s;
    cin >> s;

    for (int i = 0; i < n; i++)
      if (s[i] == '0')
        pq.push(a[i]);

    if (pq.size() < k)
      cout << -1 << endl;
    else
    {
      ll ans = 0;
      while (k--)
      {
        ans += pq.top();
        pq.pop();
      }
      cout << ans << endl;
    }
  }
  return 0;
}