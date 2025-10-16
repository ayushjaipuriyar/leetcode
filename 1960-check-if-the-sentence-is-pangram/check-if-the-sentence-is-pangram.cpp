class Solution {
public:
    bool checkIfPangram(string str) {
        int count = 1;
         sort(str.begin(), str.end());
        for(int i = 1;i<str.length();i++)
            if(str[i-1]!=str[i])
                count++;
        if(count == 26)
            return true;
        return false;
    }
};