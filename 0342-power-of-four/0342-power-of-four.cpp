class Solution {
public:
    bool isPowerOfFour(int n) {
        // If 'n' is 1, it is a power of four
        if (n == 1)
            return true;
        
        // If 'n' is non-positive, it cannot be a power of four
        if (n <= 0)
            return false; 
        
        // Calculate the square root of 'n'
        double sqrtN = sqrt(n);

        // Take the logarithm base 2 of the square root
        double log2SqrtN = log2(sqrtN);
        
        // Check if the result of the logarithmic operation is an integer
        return (log2SqrtN == (int)log2SqrtN);
    }
};