#include <vector>
using namespace std;



class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        int n = citations.size();
        vector<int> freq(n + 1, 0);
        
        
        auto it = citations.begin();
        do{
            if(*it > n){
                freq[n]++;
            }else{
                freq[*it]++;
            }
            it++;
        }while(it != citations.end());
        
        int acum = 0;
        for(int i = n; i >= 0; --i){
            acum += freq[i];
            if(acum >= i){
                return i;
            }
        }
        
        
    }
};