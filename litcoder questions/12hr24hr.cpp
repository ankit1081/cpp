#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

void militaryTime(string str){
//taking only time into integer we have to change it
//taking unit digit into h2 and tens into h1
int h1 = (int)str[0]-'0';
int h2 = (int)str[1]-'0';
int h = 10*h1+h2;

//making conditions to check if the time was in AM or PM

if(str[8] == 'A'){
    //checking if the time is 12 am, we have to convert it into 00
    if(h == 12){
        //simply print 00 instead of 12
        cout<<"00";
        //print remaining time values leaving AM
        for(int i = 2; i<=7;i++){
            cout<<str[i];
        }
    }
}
//making same for PM
else{
    //checking if the time was 12 PM
    if(h == 12){
        //simply print the time leaving PM
        for(int i = 0; i<=7 ; i++){
            cout<<str[i];
        }
    }
    //checking if time was above 12PM
    else{
        //add the extra time with 12 to make it 24 hour format and display
        h += 12;
        cout<<h;
        for(int i = 2; i<=7; i++){
            cout<<str[i];
        }
    }
}

}

int main(){
    string str;
    cin>>str;
    militaryTime(str);
    return 0 ;
}

