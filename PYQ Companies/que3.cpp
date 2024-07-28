#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int f(vector<int>& arr){
    int n=arr.size();
    vector<int> prefix(n);
    int len=0;
    int cnt=0;

    for(int i=0;i<n;i++){
        if(arr[i]==0){
            cnt--;
        }else{
            cnt++;
        }
        prefix[i]=cnt;
    }

    unordered_map<int, int> map;
    map[0]=-1;

    for(int i=0;i<n;i++){
        if(prefix[i] == 0) {
            len = i + 1;
        }

        if(map.find(prefix[i])!=map.end()){ //mil gya
            len=max(len,i-map[prefix[i]]);
        }else{
            map[prefix[i]]=i;
        }
    }

    return len;
}

int main(){
    vector<int> arr={0,1,1,0,0};
    int ans=f(arr);
    cout<<ans<<endl;

    return 0;
}