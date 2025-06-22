class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) 
    {
        int n=bulbs.size();

        //the next smaller element to the left
        vector<int> left(n, -1);

        //the next smaller element to the right
        vector<int> right(n, n);

        //times[z] = time at which bulb z blooms
        vector<int> times(n);
        for (int z=0; z<n; z++)
        {
            times[bulbs[z]-1]=z;
        }

        //standard code for finding next smaller element to the left
        {
            stack<pair<int, int>> st;
            st.push({times[0], 0});
            left[0]=-1;
            for (int z=1; z<n; z++)
            {
                while (!st.empty())
                {
                    auto p=st.top();
                    if (p.first<times[z])
                    {
                        left[z]=p.second;
                        break;
                    }
                    else st.pop();
                }
                st.push({times[z], z});
            }
        }

    //standard code for finding next smaller element to the right
        {
            stack<pair<int, int>> st;
            st.push({times[n-1], n-1});
            right[n-1]=n;
            for (int z=n-2; z>=0; z--)
            {
                while (!st.empty())
                {
                    auto p=st.top();
                    if (p.first<times[z])
                    {
                        right[z]=p.second;
                        break;
                    }
                    else st.pop();
                }
                st.push({times[z], z});
            }
        }

        //iterating over all valid z to check if condition is satisfied and if it is, res is updated!
        int res=n+1;
        for (int z=k+1; z<n; z++)
        {
            if (left[z]<z-k && right[z-k-1]>=z)
            {
                res=min(res, max(times[z], times[z-k-1]));
            }
        }        
        return res==n+1 ? -1 : res+1;
    }
};