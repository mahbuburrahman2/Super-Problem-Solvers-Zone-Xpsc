class Solution
{
public:
  vector<vector<string>> ans;
  vector<string> board;

  vector<int> row, d1, d2;

  void dfs(int col, int n)
  {

    if (col == n)
    {
      ans.push_back(board);
      return;
    }

    for (int r = 0; r < n; r++)
    {

      if (row[r] || d1[r - col + n] || d2[r + col])
        continue;

      board[r][col] = 'Q';
      row[r] = d1[r - col + n] = d2[r + col] = 1;

      dfs(col + 1, n);

      board[r][col] = '.';
      row[r] = d1[r - col + n] = d2[r + col] = 0;
    }
  }

  vector<vector<string>> solveNQueens(int n)
  {

    board.assign(n, string(n, '.'));

    row.assign(n, 0);
    d1.assign(2 * n, 0);
    d2.assign(2 * n, 0);

    dfs(0, n);

    return ans;
  }
};
