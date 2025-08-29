#include<iostream>
#include<cstring>
#include<string>
#include<limits>
using namespace std;

int main()
{
    int num;
    char str[] = "NB2_ADSA";
    char str1[] = {'A','B','C','\0','A'};
    cout<<str<<endl<<str1<<endl;
    cout<<strlen(str)<<endl<<strlen(str1)<<endl;

    //char str2[100], str3[100],str4[100];
    //cin cannot handle widespace, it will not take data after space and move to next array
    //cin.ignore(numeric_limits<streamsize>::max(),'\n');//ignore() will only ignore 1 space , but max ignore will ignore whole buffer
    //cin>>num;
    string str2;
    getline(cin,str2);

    //cin>>str2;
    //cin>>str3;
    //cin>>str4;
    cout<<str2<<endl;
    //cout<<str3<<endl;
    //cout<<str4<<endl;

}
