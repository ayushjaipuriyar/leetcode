class Solution
{
public:
  int countMaxOrSubsets(vector<int> &nums)
  {
    int max_or = 0, n = nums.size();
    for (int num : nums)
      max_or |= num;
    int count = 0;
    dfs(nums, 0, 0, max_or, count);
    return count;
  }

private:
  void dfs(const vector<int> &nums, int i, int curr_or, int max_or, int &count)
  {
    if (i == nums.size())
    {
      if (curr_or == max_or && curr_or != 0)
        count++;
      return;
    }
    dfs(nums, i + 1, curr_or | nums[i], max_or, count);
    dfs(nums, i + 1, curr_or, max_or, count);
  }
};
