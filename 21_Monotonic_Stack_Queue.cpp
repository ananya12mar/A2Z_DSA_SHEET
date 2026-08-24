#include <bits/stdc++.h>
using namespace std;

vector<int> nextLargerElement(vector<int> arr)
{
    stack<int> st;
    vector<int> ans;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            ans.push_back(-1);
            st.push(arr[i]);
        }
        else
        {
            if (st.top() < arr[i])
            {
                while (!st.empty() && st.top() < arr[i])
                    st.pop();

                if (st.empty())
                    ans.push_back(-1);
                else
                    ans.push_back(st.top());

                st.push(arr[i]);
            }
            else
            {
                ans.push_back(st.top());
                st.push(arr[i]);
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
}