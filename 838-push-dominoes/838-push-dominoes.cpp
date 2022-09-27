class Solution {
public:
    string pushDominoes(string dom) {
        int n = dom.size();
        string ans = "";
        for(int k = 0; k<n; k++){
            if(dom[k]=='.'){
                int i = k;
                int j = k;
                while(dom[i]=='.' and i>=0){
                    if(i==0){
                        break;
                    }
                    i--;
                }
                while(dom[j]=='.' and j<n){
                    if(j==n-1){
                        break;
                    }
                    j++;
                }
                if(dom[i]=='.' or dom[j]=='.'){
                    if(i==0 and j!=n-1 and dom[j]=='L'){
                    ans.push_back('L');
                    continue;
                    }
                    if(i==0 and j!=n-1 and dom[j]=='R'){
                        ans.push_back('.');
                        continue;
                    }
                    if(j==n-1 and i!=0 and dom[i]=='L'){
                        ans.push_back('.');
                        continue;
                    }
                    if(j==n-1 and i!=0 and dom[i]=='R'){
                        ans.push_back('R');
                        continue;
                    }
                    if(i==0 and j==n-1){
                        if(dom[i]=='R'){
                            ans.push_back('R');
                        }
                        else if(dom[j]=='L'){
                            ans.push_back('L');
                        }
                        else{
                            ans.push_back('.');
                        }
                        
                        continue;
                    }
                }
                if(abs(k-i)==abs(j-k)){
                    if(dom[i]!=dom[j]){
                        ans.push_back('.');
                    }
                    else{
                        ans.push_back(dom[i]);
                    }
                }
                else if(abs(k-i)<abs(j-k)){
                    if(dom[i]=='R'){
                        ans.push_back('R');
                    }
                    else if(dom[j]=='L'){
                        ans.push_back('L');
                    }
                    else{
                        ans.push_back('.');
                    }
                }
                else{
                    if(dom[j]=='L'){
                        ans.push_back('L');
                    }
                    else if(dom[i]=='R'){
                        ans.push_back('R');
                    }
                    else{
                        ans.push_back('.');
                    }
                }
            }
            else{
                ans.push_back(dom[k]);
            }
        }
        return ans;
    }
};