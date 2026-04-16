#include <vector>
using namespace std;




class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int aux = d%arr.size(); //saco el resto que el resto son vueltas completas
        // A + B = arr ; B + A = rot arr / d = size(A)
        vector<int> A;
        vector<int> B;
        
        for(auto it = arr.begin(); it != arr.end(); ++it){
            if(aux != 0){
                A.push_back(*it);
                --aux;
            }else{
                B.push_back(*it);
            }
            
        }
        for(auto it = A.begin(); it != A.end(); ++it){
            B.push_back(*it);
        }
        
        arr = B;
    }
};