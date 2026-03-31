#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--)
  {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    ll sum = 0;
    for (auto &row : a)
      for (auto &x : row)
        cin >> x, sum += x;

    ll k = sum / 2;
    cout << k * (sum - k) << "\n";

    vector<int> down(m);
    ll c = 0;
    for (int j = m - 1; j >= 0 && c < k; j--)
      for (int i = 0; i < n && c < k; i++)
        c += a[i][j], down[j]++;

    int r = 0;
    for (int j = 0; j < m; j++)
    {
      while (r < down[j])
        cout << 'D', r++;
      cout << 'R';
    }
    while (r < n)
      cout << 'D', r++;
    cout << "\n";
  }
  return 0;
}