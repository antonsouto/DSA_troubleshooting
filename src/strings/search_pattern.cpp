#include <string>
#include <vector>
using namespace std;




class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        // code here
        vector<int> resultado;
        int i = 0;
        int j = 0;
        
        vector<int> LPS(pat.size(), 0);
        generateLPS(LPS, pat);
        
        for(; i < txt.size(); ){
            if(txt[i] == pat[j]){
                ++j, ++i;
                if(j == pat.size()){
                    resultado.push_back(i - j);;
                    j = LPS[j - 1];
                }
            }else{
                if(j > 0){
                    j = LPS[j - 1];
                }else{
                    i++;
                }
            }
        }
        
        return resultado;
        
    }
    
    
    void generateLPS(vector<int> &LPS, string &pat){
    
    int len = 0;
    LPS[0] = 0;
    
    for(int i = 1; i < pat.size(); ){
        if(pat[i] == pat[len]){
            len++;
            LPS[i++] = len;
        }else{
            if(len == 0){
                LPS[i++] = 0;
            }else{
                len = LPS[len -1];
            }
        }
    }
}
};