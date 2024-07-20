#include <iostream>
using namespace std;

pair<int,int> f(int n){
    int increament=10;
    int x_ans=0;
    int y_ans=0;
    int flag=1;
    int posx=1;
    int posy=1;
    for(int i=1;i<=n;i++){
        if(flag==1){ // in x 
            //in +ve x
            if(posx){
                x_ans+=increament;
                posx=0;
            }else{ //-ve x
                x_ans-=increament;
                posx=1;
            }
            flag=0;
        }else{ //in y
            if(posy){ //in +y 
                y_ans+=increament;
                posy=0;
            }else{ //in -ve y
                y_ans-=increament;
                posy=1;
            }
            flag=1;
        }
        increament+=10;
    }

    return {x_ans,y_ans};


}
int main(){
    int n;
    n=4;
    pair<int,int> ans=f(n);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}