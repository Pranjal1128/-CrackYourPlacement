class Solution {
public:
    long gcd(long a, long b) {
        if(a > b) {
            return gcd(b, a);
        }
        if(a == 0) return b;
        return gcd(a, b % a);
    }

    long lcm(long a, long b) {
        return (a*b)/gcd(a, b);
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        long nn = n, aa = a, bb = b, cc = c;
        long low = 1, high = INT_MAX;
        while(low < high) {
            long mid = low + (high - low)/2;
            //Ugly numbers less than mid
            long o = (mid/aa) + (mid/bb) + (mid/cc) - (mid/lcm(aa, bb)) - (mid/lcm(bb, cc)) - (mid/lcm(aa, cc)) + (mid/lcm(aa, lcm(bb, cc)));
            if(o < n) {
                low = mid + 1;
            }
            else high = mid;
        }

        return (int)low;
    }
};