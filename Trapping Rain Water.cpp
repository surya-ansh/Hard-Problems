class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> maxL(n);
        vector<int> maxR(n);

        int maxiL = -1e9;
        for(int i=0; i<n; i++){
            maxiL = max(maxiL, height[i]);
            maxL[i] = maxiL;
        }

        int maxiR = -1e9;
        for(int i=n-1; i>=0; i--){
            maxiR = max(maxiR, height[i]);
            maxR[i] = maxiR;
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            ans += min(maxR[i], maxL[i]) - height[i];
        }

        return ans;
    }

};


2nd approach

// while using stack in classic stack question always push indexes into stack

class Solution {
public:
    int trap(vector<int>& height) {
     int  n = height.size();
     int water = 0 ;
     int  current = 0 ;
     stack<int>st;
    while(current<n){
        while(!st.empty() && height[current] > height[st.top()]){
            int top = st.top();
            st.pop();
            if(st.empty()) break;
            int distance = current - st.top() - 1;
            int boundary = min (height[current],height[st.top()])-height[top];
            water += distance*boundary;

        }
        st.push(current++);

    }
    return water ;
    
        
    }
};