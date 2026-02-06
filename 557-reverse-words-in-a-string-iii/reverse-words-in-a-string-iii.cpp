class Solution {
public:
     string reverse(string s) {
        int l = 0;
        int r = s.size() - 1;
        while(l <= r)
            swap(s[l++], s[r--]);
        return s;
    }
    string reverseWords(string s) {
        string ans = "";
        string word = "";
        int l = 0;
        int r = 0;
        while(l < s.size()) {
            r = l;
            word = "";
            while(r < s.size() && s[r] != ' ')
                word += s[r++];
            if(word.size() > 0) {
                ans += (ans.size() > 0 ? " " : "") + reverse(word);
            }
            while(s[r] == ' ') r++;
            l = r;
        }
        return ans;
    }
};