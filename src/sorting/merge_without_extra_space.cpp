#include <vector>
using namespace std;



class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        // int i = 0, j = a.size() -1;
        // while(a[j] > b[i] && j > 0 && i < b.size()){
        //     swap(a[j--], b[i++]);
        // }
        // sort(a.begin(), a.end());
        // sort(b.begin(), b.end());
        // No da putisimo tiempo joder
        int n = a.size();
        int m = b.size();
        int gap = (m + n + 1) / 2;
        
        do{
            
            int left = 0;
            int right = gap;
            while(right < (m + n)){
                if(left < n && right < n){
                    if(a[left] > a[right]){
                        swap(a[left], a[right]);
                    }
                }
                
                else if(left < n && right >= n){
                    if(a[left] > b[right -n]){
                        swap(a[left], b[right - n]);
                    }
                }
                
                else if(left >= n && right >= n){
                    if(b[left - n] > b[right - n]){
                        swap(b[left - n], b[right - n]);
                    }
                }
                
                left++;
                right++;
            }
            if(gap == 1){
                gap = 0;
            }
            else{gap = (gap + 1)/ 2;}
            
        }while(gap > 0);
        
    }
};