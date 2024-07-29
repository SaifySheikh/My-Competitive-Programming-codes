#include <iostream>
#include <vector>
using namespace std;

void f(int idx,int sum,vector<int>& arr,int target,int k,vector<int>& path,vector<vector<int>>& ans,int steps){
    if(sum==target && steps==k){
        ans.push_back(path);
        return;
    }
    
    if(idx>=arr.size()) return;
    // if(sum>target) return;
    if(steps>k) return;
    
    //npick
    path.push_back(arr[idx]);
    f(idx+1,sum+arr[idx],arr,target,k,path,ans,steps+1);
    //pick
    path.pop_back();
    f(idx+1,sum,arr,target,k,path,ans,steps);
}

int main(){
    vector<int> arr={1,0,-1};
    int target=0;
    int k=3;

    vector<int> path;
    vector<vector<int>> ans;
    int sum=0;

    f(0,sum,arr,target,k,path,ans,0);
    for(vector<int> x : ans){
        for(int ele : x){
            cout<<ele<<" ";
        }
        cout<<" "<<endl;
    }

    cout<<"khtm"<<endl;

    return 0;
}