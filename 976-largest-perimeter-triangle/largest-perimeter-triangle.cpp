class Solution {
public:
    int largestPerimeter(vector<int>& arr) {
    int n = arr.size();
    int maxi = 0;
    sort(arr.begin(), arr.end(), greater<int>());
     for (int i = 0; i < n-2; i++){
        if (arr[i] < arr[i+1] + arr[i+2]){
            maxi = max(maxi, arr[i] + arr[i+1] + arr[i+2]);
            break;
        }
    }
    if(maxi)
        return maxi;
    else
        return 0;
    }
    
};