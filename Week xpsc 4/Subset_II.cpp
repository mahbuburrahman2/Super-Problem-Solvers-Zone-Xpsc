#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void f(int idx, vector<int> &nums,
         vector<vector<int>> &ans,
         vector<int> &cur)
  {

    // Store current subset
    ans.push_back(cur);

    for (int i = idx; i < nums.size(); i++)
    {

      // Skip duplicates
      if (i > idx && nums[i] == nums[i - 1])
        continue;

      // Choose
      cur.push_back(nums[i]);

      // Recurse
      f(i + 1, nums, ans, cur);

      // Backtrack
      cur.pop_back();
    }
  }

  vector<vector<int>> subsetsWithDup(vector<int> &nums)
  {

    sort(nums.begin(), nums.end()); // Important

    vector<vector<int>> ans;
    vector<int> cur;

    f(0, nums, ans, cur);

    return ans;
  }
};

int main()
{

  Solution sol;

  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  vector<int> nums(n);

  cout << "Enter elements: ";
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  vector<vector<int>> result = sol.subsetsWithDup(nums);

  cout << "\nAll unique subsets:\n";

  for (auto &v : result)
  {
    cout << "[ ";
    for (int x : v)
    {
      cout << x << " ";
    }
    cout << "]\n";
  }

  return 0;
}
