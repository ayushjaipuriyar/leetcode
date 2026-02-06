class Solution {
public:
    int pivotIndex(vector<int>& nums) {
     int lsum = 0,sum=0;
  for (int i = 0; i < nums.size(); i++)
    sum+=nums[i];
    for (int j = 0; j < nums.size(); j++){
        if (lsum ==sum- lsum-nums[j])
            return j;
        lsum += nums[j];
  }
  return -1;
    }
};