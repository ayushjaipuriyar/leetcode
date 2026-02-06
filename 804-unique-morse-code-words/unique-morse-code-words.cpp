class Solution {
public:
   int uniqueMorseRepresentations(vector<string>& words) {
        string list[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        map<string,int> hash_map;
        string res_code = "";
        int res = 0;
        for(auto word: words) {
            res_code = "";
            for(char c: word) {
                res_code += list[c - 'a'];
            }
            if(hash_map[res_code] == 0) res++;
            hash_map[res_code]++;
        }
        return res;
    }
};