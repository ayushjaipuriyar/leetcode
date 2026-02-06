class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> result;
        int n = num.size();
        int carry = k;
        for (int i = n - 1; i >= 0 || carry > 0; i--) {
            if (i >= 0) {
                carry += num[i];
            }
            result.push_back(carry % 10);
            carry /= 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};