#include <string>
#include <vector>
using namespace std;



class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // code here
        vector<int> alfabeto(26, 0);
        
        if(s1.size() != s2.size()){
            return false;
        }
        
        for(int i = 0; i < s1.size(); ++i){
            alfabeto[s1[i] - 'a'] += 1;
            alfabeto[s2[i] - 'a'] -= 1;
        }
        
        for(auto val : alfabeto){
            if(val != 0){
                return false;
            }
        }
        
        return true;
    }
};