class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int prevSum = nums[0]+nums[1]+nums[2];
        for(int i = 0;i<n;i++){
            int start = i+1;
            int end = n-1;
            while(start<end){
                int curSum = nums[i]+nums[start]+nums[end];
                if(curSum == target)
                    return curSum;
                else if(curSum<target)
                    start++;
                else
                    end--;
                if(abs(curSum-target)<abs(prevSum-target))
                   prevSum = curSum;
                  
            }
        }
        ans = prevSum;
        return ans;
    }
};