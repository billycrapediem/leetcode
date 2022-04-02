#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
#include<queue>
#include<set> 
using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> server;
        for(int i = 0; i < k ; i ++)
        {
            server.insert(i);
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> busy;
        vector<int> times(k, 0), ans; 
        for(int i = 0; i < arrival.size(); i ++)
        {
            while(!busy.empty() && busy.top().first <= arrival[i])
            {
                server.insert(busy.top().second);
                busy.pop();
            }
            if( server.empty())
            {
                continue;
            }
            auto flag = server.lower_bound(i%k);
            if( flag == server.end())
            {
                flag = server.begin();          
            }
            busy.emplace(arrival[i] + load[i], *flag);
            server.erase(flag);
            times[*flag] ++;
        }
        int maxr = *max_element(times.begin(), times.end());
        for(int i = 0; i < k; i ++)
        {
            if( times[i] == maxr) ans.push_back(i);
        }
        return ans; 
    }
};
        
void display(vector<int> x)
{
    for(int i = 0; i < x.size(); i++)
    {
        cout<<x[i]<<" ";
    }
    return ; 
}

int main(){
    Solution x;
    int k = 3;
    vector<int> arrival = {1,2,3,4,5};
    vector<int> load = {5,2,3,3,3};
    display(x.busiestServers(k,arrival,load));

    return 0 ;
}
