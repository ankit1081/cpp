//1281. Subtract the Product and Sum of Digits of an Integer
#include<iostream>
using namespace std ;
class ProductandSum {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;

        while(n!=0){
            int digit = n%10;
            product = digit * product;
            sum = sum+digit;

            n = n/10;

        }
        int result = product - sum;
        return result;

    }
};
int main(){
    ProductandSum P;
    int n ;
    cout<<"Enter the number :";
    cin>>n;
    int Ans = P.subtractProductAndSum(n);
    cout<< "Ans is:"<<Ans;
    return 0 ;
}
