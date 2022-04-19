class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int nA = A.size();
        int nB = B.size();
        // could help to sort the smaller of the two lists
        sort(B.begin(), B.end());
        
        int sumA = 0;
        int sumB = 0;
        
        for (int v : A)
            sumA += v;
        
        for (int v : B)
            sumB += v;
        
        for (int i = 0; i < nA; ++i) {
            int aliceBar = A[i];
            
            int ii = 0;
            int j = nB - 1;
            // find the element that will make the two sums
			// the same
            while (ii <= j) {
                int m = ii + (j-ii)/2;
                int bobBar = B[m];
                
                int resA = sumA - aliceBar + bobBar;
                int resB = sumB - bobBar + aliceBar;
                
                if (resA == resB) // both sums are the same!
                    return { aliceBar, bobBar };
                else if (resA > resB) {
					// if 'swapping' something from B leads to a larger sum for A
					// then we should try to 'swap' something smaller
                    j = m - 1;
                } else {
					// if 'swapping' something from B leads to a smaller sum for A
					// then we should try to swap something bigger
                    ii = m + 1;
                }
            }
            
        }
        
        return {};
    }
};