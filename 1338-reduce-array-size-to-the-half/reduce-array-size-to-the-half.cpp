class Solution {
public:
    int minSetSize(vector<int>& v) {
        
        int res = 0;
        int n = v.size();
        priority_queue<pair<int,int>> pq;
        unordered_map<int, int> ump;
        
        for(auto &x : v)
            ump[x]++;
        
        for(auto &x : ump) {
            pq.push({x.second, x.first});
        }
        
        int removedCount = 0;
        
        while(pq.empty() == false) {    
            if(removedCount >= n/2)
                break;
            int freq = pq.top().first;
            pq.pop();
            removedCount += freq;
            res++;
        }
        return res;
    }
};