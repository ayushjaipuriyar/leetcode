class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> hp;
        for(int i =0;i<n;i++)
            hp.push_back(make_pair(nums2[i],nums1[i]));
        sort(hp.begin(), hp.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;  // Compare in descending order based on the first value
});
        long long res = 0,sum=0;
        priority_queue<int,vector<int>, greater<int>> pq;
        for(auto pair:hp){
            pq.push(pair.second);
            sum+=pair.second;
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size() == k){
                res = max(res,sum*pair.first);
            }

        }
        return res;
    }
};