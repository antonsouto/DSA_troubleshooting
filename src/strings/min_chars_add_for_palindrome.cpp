#include <string>
#include <vector>
#include <algorithm>
using namespace std;



vector<int> lpsBuild(const string &pat);


class Solution {
  public:
    int minChar(string &s) {
        // code here
        string cadenaRev = s;
        reverse(cadenaRev.begin(), cadenaRev.end());
        string pat = s + "#" + cadenaRev;
        vector<int> lps = lpsBuild(pat);
        
        return(s.size() - lps.back()); 
        
    }
};

vector<int> lpsBuild(const string &pat){
    vector<int> lps(pat.size(), 0);
    int len = 0;
    int i = 1;
    
    while(i < pat.size()){
        if(pat[i] == pat[len]){
            lps[i] = ++len;
            i++;
        }else{
            if(len == 0){
                lps[i] = 0;
                i++;
            }else if(len > 0){
                len = lps[len - 1];
            }
        }
    }
    return lps;
}