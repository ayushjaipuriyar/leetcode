class Solution {
public:
    int maxArea(vector<int>& height) {
        long long int res = 0;
        int l = 0,r = height.size()-1;
        while(l<r){
            long long int area = (r-l)*min(height[l],height[r]);
            res = max(res,area);
            if(height[l]<height[r])
                l++;
            else
                r--;
        }
        return res;
    }
};