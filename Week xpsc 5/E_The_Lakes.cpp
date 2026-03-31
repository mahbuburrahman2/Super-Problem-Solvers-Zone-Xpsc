#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int grid[N][N];
int n, m;

int dfs(int r, int c)
{
  if (r < 0 || r >= n || c < 0 || c >= m)
    return 0;
  if (grid[r][c] == 0)
    return 0;

  int sum = grid[r][c];
  grid[r][c] = 0;

  int dr[4] = {1, -1, 0, 0};
  int dc[4] = {0, 0, 1, -1};

  for (int k = 0; k < 4; k++)
    sum += dfs(r + dr[k], c + dc[k]);

  return sum;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--)
  {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> grid[i][j];

    int ans = 0;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (grid[i][j] > 0)
          ans = max(ans, dfs(i, j));

    cout << ans << "\n";
  }

  return 0;
}
