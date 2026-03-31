class Solution
{
public:
  vector<vector<int>> ans;

  void backtrack(int idx, vector<int> &candidates,
                 int target, vector<int> &temp)
  {
    if (target == 0)
    {
      ans.push_back(temp);
      return;
    }

    for (int i = idx; i < candidates.size(); i++)
    {

      if (candidates[i] > target)
        break;

      temp.push_back(candidates[i]);

      backtrack(i, candidates, target - candidates[i], temp);

      temp.pop_back();
    }
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target)
  {

    sort(candidates.begin(), candidates.end());

    vector<int> temp;

    backtrack(0, candidates, target, temp);

    return ans;
  }
};
