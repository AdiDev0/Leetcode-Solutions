class Solution {
public:
    int countCollisions(string dir) {
        int n = dir.size();
        stack<char> s;
        int count = 0;
        for(int i = 0; i<n; i++){
            if(s.empty() and dir[i]=='L'){
                continue;
            }
            if(s.empty()){
                s.push(dir[i]);
            }
            else if(s.top()=='R' and dir[i]=='L'){
                count+=s.size()+1;
                while(!s.empty()){
                    s.pop();
                }
                s.push('S');
            }
            else if(s.top()=='R' and dir[i]=='S'){
                count+=s.size();
                while(!s.empty()){
                    s.pop();
                }
                s.push('S');
            }
            else if(s.top()=='R' and dir[i]=='R'){
                s.push('R');
            }
            else if(s.top()=='S' and dir[i]=='R'){
                s.pop();
                s.push('R');
            }
            else if(s.top()=='S' and dir[i]=='L'){
                count+=1;
            }
        }
        return count;
    }
};

//"SSRSSRLLRSLLRSRSSRLRRRRLLRRLSSRR" 20