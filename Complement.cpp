//1009. Complement of Base 10 Integer
# include <iostream>
using namespace std;
class Complement {
public:
    int bitwiseComplement(int n) {
        int m = n;
        int ans = 0;
        int mask = 0 ;
        if(n==0){
            return 1;
        }
        while(m!= 0 ){
            mask = (mask << 1) | 1;
            m = m >> 1;
        }
        ans = (~n) & mask;
        return ans;
    }

};
int main(){
    Complement C;
    int n ;
    cout<<"Enter the value :";
    cin>>n;
    int value = C.bitwiseComplement(n);
    cout<<value;
    return 0;
}
