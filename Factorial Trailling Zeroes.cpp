class Solution {
public:
    int trailingZeroes(int n) {
        long long n5 = 0;
        long long m5 = 5;
        while(n / m5 > 0){
            n5 += n / m5;
            m5 *= 5;
        }
        return n5;
    }
};