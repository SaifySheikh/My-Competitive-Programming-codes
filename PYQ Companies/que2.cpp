#include <iostream>
using namespace std;

int f(int n){
    int ans=1;
    while(n!=0){
        int ele=n%10;
        ans*=ele;
        n/=10;
    }
    return ans;
}

int main(){
    int n=5244;
    int ans=f(n);
    cout<<ans<<endl;
    return 0;
}