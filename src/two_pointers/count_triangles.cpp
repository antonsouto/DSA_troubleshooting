#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



class Solution {
  public:
    bool isTriangle(const int& a,const int& b,const int& c);
    int countTriangles(vector<int>& arr) {
        // code here
        int n = arr.size(); // Num of elements in the array
        int count = 0;
        
        sort(arr.begin(), arr.end(), [](const int& a,const int& b){
                                                return a > b;
                                        });
        
        int i = 0, j, k;
        while(arr[n - 1] == 0){
            n--;
        }
        if(n < 3) return 0;

        while(i != (n - 2)){
            j = i + 1;
            k = n - 1;
            while(j < k){
                if(arr[j] + arr[k] > arr[i]){
                    int m = k - j;
                    count += m;
                    j++;
                }else if(arr[j] + arr[k] <= arr[i]){
                    k--;
                }
            }
            i++;
        }
        return count;
    }
};

bool isTriangle(const int& a,const int& b,const int& c){
        int A = b + c;
        int B = a + c;
        int C = a + b;
        if(A < a || B < b || C < c){
            return false;
        }
        return true;
    }