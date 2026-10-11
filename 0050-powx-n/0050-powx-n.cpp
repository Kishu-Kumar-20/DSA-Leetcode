class Solution {
public:
    double power(double x, long long n, double ans){
        if(n == 0) return ans;
        if(n%2 == 0){
            return power(x*x,n/2,ans);
        }else{
            return power(x,n-1,ans*x);
        }
    }
    double myPow(double x, int n) {
        if(n < 0) return (1.0)/power(x,n*-1LL,1.0);
        return power(x,n,1.0);
    }
};