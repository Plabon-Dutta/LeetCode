class Solution {
public:
    int fib2(int i, int j, int c, int n) {
        if (c == n) return i + j;
        return fib2(j, i + j, c + 1, n);
    }

    int fib(int n) {
        if (n <= 1) return n;
        
        return fib2(0, 1, 2, n);
    }
};