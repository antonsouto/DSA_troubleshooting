#include <vector>
using namespace std;



class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        // Comparo un elemento de izq con der, si es mayor sumo todos de izq
        // y ademas descarto esa cifra para la siguiente iteración

       if(arr.size() <= 1){
           return 0;
       }else{
           int count = 0;
           int mid = (arr.size() + 1) / 2;
           
           vector<int> izq(arr.begin(), arr.begin() + mid);
           vector<int> der(arr.begin() + mid, arr.end());
           
           // recursiidad
           count += inversionCount(izq);
           count += inversionCount(der);
           
           vector<int> merged;
           int i = 0, j = 0;
           // Algoritmo para comparativa de arrays ordenados
            /*
                izq [2, 4, 6]
                der [1, 3, 5]
                
                izq [1, 2, 4]
                der [3, 5]
            */
           while(i < izq.size() && j < der.size()){
               if(izq[i] > der[j]){
                    merged.push_back(der[j]);
                    count += (izq.size() - i);
                    j++;
                    //i++;
                    //continue;
               }else{
                   
                   merged.push_back(izq[i]);
                   i++;
               }
               
            }
           
           
           while(i<izq.size())merged.push_back(izq[i++]);
           while(j<der.size())merged.push_back(der[j++]);
           arr = merged;
           //sort(izq.begin(), izq.end());
           //sort(der.begin(), der.end());
           return count;
       }

    }
};