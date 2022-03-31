#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int> list;
        while( n > 0)
        {
            int x = n % 2;
            n /= 2;
            list.push_back(x);
        }
        for(int i = 0; i < list.size() - 1; i ++)
        {
            if( list[i] == list[i + 1]) return false; 
        }
        return true; 
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
    cout<<x.hasAlternatingBits(7);
    return 0 ;
}
