bool sort_comparator(const vector<int>&a, const vector<int>&b)
{
    return a[0]==b[0] ? a[1]<b[1] : a[0]>b[0];    
}

class Solution {
public:    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        int n = people.size();
        
        // result vector
        vector<vector<int>>ans;

        // sort based on custom comparator
        sort(people.begin(),people.end(),sort_comparator);

        // insert each people in to Kth position and as we already sorted
        // people array in descending order of H and so greater H people will
        // be insrted first and then the lower height people and when lower
        // height people are inserted in Kth position there will be K people
        // before him with greater or equal height and also it does not affect 
        // people after Kth position cause their height is already higher
        for(int i=0;i<n;i++)
            ans.insert(ans.begin()+people[i][1],people[i]);

        return ans;
    }
};