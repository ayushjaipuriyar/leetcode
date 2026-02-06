class Solution {
public:

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i<m ;i++){
        if ( target <= matrix[i][n-1] && target >= matrix[i][0]){
            int low=0;
            int high = n-1;
            
            while(low<=high)
            {
                int mid = (low + (high-low) /2 );
                if(matrix[i][mid]==target)
                    return true;
                if(matrix[i][mid]<target)
                    low = mid+1;
                else
                    high =high-1;
            }
            return false;
        }   
        else
            continue;
    }
    return false;
}
};
