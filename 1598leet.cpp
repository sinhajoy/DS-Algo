class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<int> stk;
        for(string s : logs){
            if(s=="./")
                continue;
            else if(s=="../" && !stk.empty())
                stk.pop();
            else if(s=="../" && stk.empty())
                continue;
            else
                stk.push(0);
        }
        int a = stk.size();
        return a;
    }
};