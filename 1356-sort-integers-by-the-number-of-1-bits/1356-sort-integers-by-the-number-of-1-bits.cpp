class Solution {
public:
    // O(no of bits in a + no of bits in b)
    
    // static bool cmp(int a, int b){
    //     int A = a;
    //     int B = b;
    //     int cntA = 0;
    //     while(a>0){
    //         cntA += (a&1);
    //         a = a>>1;
    //     }
    //     int cntB = 0;
    //     while(b>0){
    //         cntB += (b&1);
    //         b = b>>1;
    //     }
    //     if(cntA==cntB) return A<B;
    //     return cntA<cntB;
    // }
    
    //faster one 
    // O(no of set bits in a + no of set bits in b)
    static bool cmp(int a, int b){
        int A = a;
        int B = b;
        int cntA = 0;
        while(a>0){
            a = a&(a-1);
            cntA++;
        }
        int cntB = 0;
        while(b>0){
            b = b&(b-1);
            cntB++;
        }
        if(cntA==cntB) return A<B;
        return cntA<cntB;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};

// int cnt = __builtin_popcount(a) gives the no of set bits in a