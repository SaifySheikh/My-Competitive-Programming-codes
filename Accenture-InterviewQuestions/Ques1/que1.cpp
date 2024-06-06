#include <iostream>
using namespace std;

int sum2(int n,int m){
    int s2=0;
    for(int i=1;i<=n;i++){
        if(i%m==0) s2+=i;
    }
    return s2;
}

int sum(int n,int m){
    int sum=0;
    for(int i=1;i<=n;i++){
        if(i%m!=0) sum+=i;
    }
    return sum;
}
int diff(int n,int m){
    int diff=0;

}
int main(){
    int n=30;
    int m=6;
    int s1=sum(n,m);
    int s2=sum2(n,m);

    cout<<abs(s1-s2)<<endl;

    return 0;
}