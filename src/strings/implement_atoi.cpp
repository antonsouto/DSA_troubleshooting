#include <string>
#include <vector>
#include <climits>
using namespace std;




class Solution {
  public:
    int myAtoi(string& s) {
        // code here
        vector<int> numeros;
        bool negative = false;
        bool leadingZeros = true;
        bool leadingSpaces = true;
        bool stopParsing = false;
        for(auto val : s){
            switch(val){
                case ' ':
                    if(leadingSpaces){
                        continue;
                    }else{
                        stopParsing = true;
                    }
                    break;
                case '-':
                    if(leadingSpaces){
                    negative = true;}
                    break;
                case '+':
                    negative = false;
                    leadingZeros = leadingSpaces = false;
                    break;
                case '0':
                    if(leadingZeros){
                        continue;
                    }else{
                        numeros.push_back(0);
                        leadingZeros = leadingSpaces = false;
                    }
                    break;
                case '1':
                    numeros.push_back(1);
                    leadingZeros = leadingSpaces = false;
                    break;
                case '2':
                    numeros.push_back(2);
                    leadingZeros = leadingSpaces = false;
                    break;
                case '3':
                    numeros.push_back(3);
                    leadingZeros = leadingSpaces = false;
                    break;
                case '4':
                    numeros.push_back(4);
                    leadingZeros = leadingSpaces = false;
                    break;
                case '5':
                    numeros.push_back(5);
                    leadingZeros = leadingSpaces = false;
                    break;
                case '6':
                    numeros.push_back(6);
                    leadingZeros = leadingSpaces = false;
                    break;
                case '7':
                    numeros.push_back(7);
                    leadingZeros = leadingSpaces = false;
                    break;
                case '8':
                    numeros.push_back(8);
                    leadingZeros = leadingSpaces = false;
                    break;
                case '9':
                    numeros.push_back(9);
                    leadingZeros = leadingSpaces = false;
                    break;
                default:
                    stopParsing = true;
                    break;
                
            }
            if(stopParsing){
                break;
            }
        }
        
        long num = 0;
        int base = 1;
        
        for(int i = numeros.size() -1; i >= 0; i--){
            if(num > (INT_MAX - numeros[i]) / 10){
                return negative ? INT_MIN : INT_MAX;
            }
            num += numeros[i] * base;
            base *= 10;
        }
        return negative ? -(int)num : (int)num;
    }
};