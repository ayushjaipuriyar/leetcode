class Solution
{
public:
  int binarySearch(vector<int> &arr, int x, int low, int high)
  {
    if (low > high)
      return high + 1;

    else
    {
      int mid = (low + high) / 2;
      if (x == arr[mid])
        return mid;
      else if (x > arr[mid]) // x is on the right side
        return binarySearch(arr, x, mid + 1, high);
      else // x is on the right side
        return binarySearch(arr, x, low, mid - 1);
    }
  }
  int searchInsert(vector<int> &nums, int target)
  {
    return this->binarySearch(nums, target, 0, nums.size() - 1);
  }
};
