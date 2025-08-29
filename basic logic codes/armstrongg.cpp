//wap to find the number of armstrong numbers in a given array
#include <iostream>
using namespace std;
#define SIZE 100
void input(int A[],int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<"\nEnter Element: ";
        cin>>A[i];
    }
}
void output(int A[],int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<"\nElement: "<<A[i];
    }
}
bool isPrime(int num)
{
    int temp;
    if (num<0)
    {
        temp=num;
        num=-num;
    }

    if(num==0 || num==1)
        return false;
    bool flag =true;
    for (int i=2;i<=num/2;i++)
        if (num%i==0)
    {
        flag=false;
        break;
    }
    if (flag)
    {
        cout<<endl<<temp;
        return true;
    }

    return false;
}

int prime_counter(int A[], int n)
{
    int count=0;
    for (int i=0;i<n;i++)
        if(isPrime(A[i]))
            count++;

    return count;
}
bool isArmstrong(int num)
{
    int temp=num;
    int sum=0, last_digit=0;
    while(temp)
    {
        last_digit=temp%10;
        temp=temp/10;
        sum=sum+last_digit*last_digit*last_digit;

    }
    if (sum==num)
    {
        cout<<endl<<num;
        return true;
    }

    return false;
}

int armstrong_counter(int A[], int n)
{
    int count=0;
    for (int i=0;i<n;i++)
        if(isArmstrong(A[i]))
            count++;

    return count;
}


int main()
{
    int A[SIZE],n,an,pn;
    cout << "Enter Size MAX 100" << endl;
    cin>>n;
    if (n>SIZE || n<=0)
    {
        cout<<"\nINVALID SIZE, PROGRAM EXIT";
        exit(1);
    }
    input(A,n);
    output(A,n);
    int count = prime_counter(A,n);
    cout<<"\nPrime Count="<<count;
    count = armstrong_counter(A,n);
    cout<<"\nArmstrong Count="<<count;

    cout<<"\nEnter the no of armstrong numbers required : ";
    cin>>an;
    cout<<"\nEnter the no of prime numbers required : ";
    cin>>pn;


    return 0;
}
