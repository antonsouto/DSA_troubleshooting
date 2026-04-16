#include <vector>
#include <algorithm>
#include <climits>
using namespace std;



class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n = a.size();
        
        int m = b.size();
        
        
        // Siempre hacemos la busqueda binaria en el array mas corto
        if(n > m){
            return kthElement(b, a, k);
        }
        
        // Limites de cuantos elementos podemos tomar de a
        int low = max(0, k - m);
        int high = min(k, n);
        
        // Busqueda binaria sobre el numero de elementos que nomamos de a
        
        while(low <= high){
            int i = (low + high)/2; //Elementos tomados de a
            int j = k - i;          //Elementos tomados de b
            
            int leftB = (j == 0)? INT_MIN : b[j - 1];
            int rightB = (j == m)? INT_MAX : b[j];
            
            int leftA = (i == 0)? INT_MIN : a[i - 1];
            int rightA = (i == n)? INT_MAX : a[i];
            
            // Comprobamos si la particion es correcta
            
            if(leftA <= rightB && leftB <= rightA){
                // El mayor de la izquierda es el k/esimo elemento
                return max(leftA, leftB);
            }else if(leftA > rightB){
                //Tomamos demasiados elementos de a
                high = i - 1;
            }
            else{ 
                low = i + 1;
            }
        }
        // si no se encuentra (no deber'ia de pasar)
        return -1;
    }
};