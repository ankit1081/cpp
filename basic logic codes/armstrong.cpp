// wap  program to check weather a number is armstrong or not
#include <iostream>

using namespace std;

bool isArmstrong(int n){
    int org = n;
    int sum = 0;

    while (n>0){
        int rem = n % 10;
        sum = sum + rem*rem*rem;
        n/=10;
    }
    return sum == org;

}
int main()
{
  int n;
  cout<<"Enter a number: ";
  cin>>n;
  if (isArmstrong(n)){
    cout<<n<<" is Armstrong";
  }
  else {
    cout<<n<<" is not Armstrong";
  }
  return 0;
}
