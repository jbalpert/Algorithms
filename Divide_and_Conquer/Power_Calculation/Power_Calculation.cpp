#include <iostream>

using namespace std;

// Top Down Recursion O(log(n))
// int power(int x, unsigned int n){
//     if(n == 0){
//         return 1;
//     }
//     if(n == 1){
//         return x;
//     }
//     return power(x, n / 2 + n % 2) * power(x, n/2);    
// }

// Tail Recursive O(log(n))
int power(int x, unsigned int n, int result = 1){
    if(n == 0)
        return result;
    else if(n % 2 == 0)
        return power(x * x, n / 2, result);
    else{
        return power(x * x, n / 2, result * x);
    }
}

// Bottom Up Recursion O(log(n))
// int power(int x, unsigned int n){
//     int answer = 1;
//     while(n){
//         if(n % 2 == 1)
//             answer *= x;
//         n /= 2;
//         x *= x;
//     }
//     return answer;
// }

int main(){
    for(unsigned int i = 0; i < 31; i++){
        cout << power(2, i) << endl;
    }
}