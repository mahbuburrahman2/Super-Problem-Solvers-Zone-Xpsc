class Solution
{
public:
  vector<string> result;

  void backtrack(string &digits, vector<string> &maps, int idx, string &cur)
  {
    if (idx == digits.size())
    {
      result.push_back(cur);
      return;
    }

    int digit = digits[idx] - '0';

    for (char c : maps[digit])
    {

      cur.push_back(c);

      backtrack(digits, maps, idx + 1, cur);

      cur.pop_back();
    }
  }

  vector<string> letterCombinations(string digits)
  {

    if (digits.empty())
      return result;

    vector<string> maps{
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"};

    string cur = "";

    backtrack(digits, maps, 0, cur);

    return result;
  }
};