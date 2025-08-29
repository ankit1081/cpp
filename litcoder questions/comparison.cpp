#include<iostream>
#include<vector>
using namespace std;
vector<int> comparison (vector<int> a , vector<int> b){
    int c = 0;
    int d = 0;

    for(int i = 0; i< 3; i++){
        if( a[i]>b[i]){
            c++;
        }
        else if(a[i]<b[i]){
            d++;
        }
    }
    return {c,d};
}
int main(){
    vector<int> a ;
    vector<int> b;
    int temp;

    for(int i = 0;i<3;i++){
        cin>>temp;
        a.push_back(temp);
    }
    for(int i = 0;i<3;i++){
        cin>>temp;
        b.push_back(temp);
    }
    vector<int> result = comparison (a,b);
    cout<<result[0]<<" "<<result[1];
    return 0;

}
