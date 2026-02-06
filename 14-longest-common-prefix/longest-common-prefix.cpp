class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       string prefix = "";
       int n = strs.size();
       int mini = INT_MAX;

       for (auto &x:strs){
           int t = x.length();
            mini = min(mini,t);
       }
        
        int ind = 0;
        
        while(mini--) {
            
            bool flag = true;
            
            for(int i=1; i<n; i++) {
                if(strs[i][ind] != strs[0][ind]) {
                    flag = false;
                    break;
                }
            }    
            
            if(flag == true)            
                prefix += strs[0][ind];
            else
                break; 
            
            ind++;
        }
        
        return prefix;
    }
};