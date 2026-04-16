#include <string>
#include <vector>
using namespace std;




class Solution {
  public:
    char nonRepeatingChar(string &s) {
        //  code here
        // vector<vector<int>> solution(s.size(), vector<int>(0));
        
        vector<int> alfabeto(26, 0);
        
        for(int iter = 0; iter < s.size(); ++iter){
            alfabeto[s[iter] - 'a'] += 1;
        }
        
        for(int iter = 0; iter < s.size(); ++iter){
            if(alfabeto[s[iter]  - 'a'] == 1){
                return s[iter];
            }
        }
        return '$';
            
    }
};