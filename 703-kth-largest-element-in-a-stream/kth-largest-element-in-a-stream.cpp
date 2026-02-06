class KthLargest {
    int n;
    priority_queue<int,vector<int>,greater<int>>pq;
public:
    KthLargest(int k, vector<int>& nums) {
        this->n = k;
        for(auto x:nums){
            if(pq.size()<n){
                pq.push(x);
                continue;
            }
            if(x>pq.top()){
                pq.pop();
                pq.push(x);
            }
        }
    }
    
    int add(int val) {
        if(pq.size()<n){
                pq.push(val);
                return pq.top();
            }
            if(val>pq.top()){
                pq.pop();
                pq.push(val);
            }
            return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */