#include<iostream>
#include<string>
using namespace std;
void takingIp(){

}
void locker(){
    string str;
    getline(cin, str);
    if (str == "password"){
        cout<<"\nAcesse granted";
    }
    else{
        cout<<"\nAccess Not Granted";
    }
}

void length(){
    string str1, str2;
    getline(cin,str1);
    getline(cin, str2);
    if(str1> str2){
        cout<< "\n Str 1 is bigger ";
    }
    else {
        cout<<"\n Str 2 is bigger ";
    }
}

int main()
{
    locker();
}
