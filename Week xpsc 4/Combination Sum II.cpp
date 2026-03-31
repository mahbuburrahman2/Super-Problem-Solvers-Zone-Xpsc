class Solution
{
public:
  void dfs(int idx, vector<int> &c, int t,
           vector<int> &path,
           vector<vector<int>> &ans)
  {
    if (t == 0)
    {
      ans.push_back(path);
      return;
    }

    for (int i = idx; i < c.size(); i++)
    {

      if (i > idx && c[i] == c[i - 1])
        continue;

      if (c[i] > t)
        break;

      path.push_back(c[i]);

      dfs(i + 1, c, t - c[i], path, ans);

      path.pop_back();
    }
  }

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
  {

    sort(candidates.begin(), candidates.end());

    vector<vector<int>> ans;
    vector<int> path;

    dfs(0, candidates, target, path, ans);

    return ans;
  }
};
