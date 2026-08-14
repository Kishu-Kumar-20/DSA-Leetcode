// int fibo(int n){
//     if(n == 0 || n == 1) return n;
//     int first = fibo(n-1);
//     int last = fibo(n-2);
//     return first + last;
// }

class Solution {
public:
    int fib(int n) {
        if(n == 0 || n==1) return n;
        int prevsec = 0;
        int prev = 1;

        for(int i = 2; i<=n; i++){
            int curr = prevsec+prev;
            prevsec = prev;
            prev = curr;
        }
        return prev;        
        // return fibo(n);
        
    }
};