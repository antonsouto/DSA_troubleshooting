#include <string>
#include <vector>
using namespace std;




vector<int> lpsCreator(const string &s);

class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // code here
        string conca = s1 + s1;
        vector<int> lps = lpsCreator(s2);
        // [0 1 0] aab en abaaba
        
        int i = 0;
        int j = 0;
        while(i < conca.size()){
            if(conca.at(i) == s2.at(j)){
                i++;
                j++;
                if(j == s2.size()){
                    return true;
                }
            }else{
                if(j > 0){
                    j = lps[j -1];    
                }else{
                    j = 0;
                    i++;
                }
            }
        }
        return false;
    }
};



vector<int> lpsCreator(const string &s){
    vector<int> LPS(s.size(), 0);
    int len = 0;
    int i = 1;
    while(i < s.size()){
        if(s.at(i) == s.at(len)){
            ++len;
            LPS[i++] = len;
        }else{
            if(len == 0){
                LPS[i] = 0;
                i++;
            }else{
                len = LPS[len - 1];
            }
        }
    }
    return LPS;
}