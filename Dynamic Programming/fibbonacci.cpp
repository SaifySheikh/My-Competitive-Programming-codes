#include<iostream>
#include <vector>
using namespace std;

int getfibbo(int n,vector<int>& dp){
    if(n<=1) return n;

    if(dp[n]!=-1) return dp[n];
    return dp[n]=getfibbo(n-1,dp)+getfibbo(n-2,dp);
}

int main(){
    int n=3;
    vector<int> dp(n+1,-1);
    int ans=getfibbo(n,dp);
    cout<<ans<<endl;
    return 0;
}