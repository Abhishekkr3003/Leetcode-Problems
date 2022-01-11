class Solution {
public:
    int mctFromLeafValues(vector<int> &arr) {
        stack<int> st;
        st.push(arr[0]);
        int res = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < st.top())
                st.push(arr[i]);
            else {
                while (!st.empty() && st.top() < arr[i]) {
                    int top = st.top();
                    st.pop();
                    // cout << "here";
                    if (st.empty()) {
                        res += arr[i] * top;
                    } else {
                        if (st.top() < arr[i]) {
                            res += st.top() * top;
                        } else {
                            res += arr[i] * top;
                        }
                    }
                }
                st.push(arr[i]);
            }
        }
        // cout << res << endl;
        while (st.size() > 1) {
            int top = st.top();
            st.pop();
            res += top * st.top();
        }
        return res;
    }
};