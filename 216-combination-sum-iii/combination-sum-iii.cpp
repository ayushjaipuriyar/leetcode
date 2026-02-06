class Solution {
public:
    void solve(vector<int> temp,int k,int n,vector<vector<int>> &ans,int &sum,int s){
        if(temp.size()==k && sum==n){
            ans.push_back(temp);
            return;
        }
        else if(temp.size()==k){
            return;
        }
        for(int i=s;i<=9;i++){
            temp.push_back(i);
            sum=sum+i;
            solve(temp,k,n,ans,sum,i+1);
            temp.pop_back();
            sum=sum-i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>>anss;
        int sum=0;
        solve(temp,k,n,anss,sum,1);
        return anss;
    }
};