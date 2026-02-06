class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int n = s.length();
  int i = 0, j = 0, maxel = 0;
  map<char, int> mp;
  while (j < n) {
    mp[s[j]]++;
    int k = j - i + 1;
    if (mp.size() == j - i + 1) {
      maxel = max(maxel, j - i + 1);
      j++;
    } else if (mp.size() < j - i + 1) {
      while (mp.size() < j - i + 1 && i < n) {
        mp[s[i]]--;
        if (mp[s[i]] == 0)
          mp.erase(s[i]);
        i++;
      }
      j++;
    }
  }
  return maxel;

    }
};