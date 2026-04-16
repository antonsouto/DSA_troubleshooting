#include <vector>
using namespace std;


class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int zerosCount = 0;
        for(auto it = arr.begin(); it != arr.end(); ){
            if(*it == 0){
                it = arr.erase(it);
                zerosCount++;
            }else{
                ++it;
            }
        }
        
        while(zerosCount!=0){
            arr.push_back(0);
            zerosCount--;
        }
        
    }
};