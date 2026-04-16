#include <vector>
using namespace std;


class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        
        int tail = arr.size() - 1;
        int start = 0;
        
        while(start < tail){
            swap(arr[start], arr[tail]);
            start++;
            tail--;
        }
        
    }
};