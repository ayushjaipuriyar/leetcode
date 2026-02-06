class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        long long temp=0;
        for(int i =0;i<nums.size();i++){
            temp +=nums[i];
            nums[i] = temp;
        }
        return nums;
    }
};