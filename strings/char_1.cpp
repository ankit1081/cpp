#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;


class Solution {
public:

    //function to reverse a string
    //will use same logic to as reversing an integer array
    void reverse(char name[], int n ){
        int s = 0 ;
        int e = n-1;
        while (s<e){
            swap(name[s++],name[e--]);
        }
    }

    //funtion to print the length of a charecter
    //this also shows that char string behaves like an array and array fuctions can also be performed here
    int getLength(char name[]){
        int count  = 0;
        for(int i = 0; name[i] != '\0'; i++){  // comparing with \0 because at wide space , it is stored as null
            // and cin stops execution here giving exact length
            count++;
        }
        return count;
    }

    //palindrome function for character array
    bool charPalindrome(char a[],int n) {
        int s = 0;
        int e = n-1;
        while(s<e){
            if(toLowercase(a[s]) != toLowercase(a[e])){
                return 0;
            }
            s++;
            e--;
        }
        return 1;
    }

    //function to convert uppercase to lowercase
    char toLowercase(char ch){
        if((ch>= 'a' && ch<= 'z')){//(ch >= '0' && ch <= '9') this is added to just help with palindrome fun 
            return ch ;
        }
        else{
            char temp  = ch - 'A'+'a';//ascii value are used here -> lets char = 'B' 
            //then -> 65-65+1 = 2 which is equal to 'b'
            return temp;
        }
    }

    //helper function for string palindrome checker which checks if string char are alpha numeric or not 
    bool isvalid(char ch ){
        if((ch>= 'a' && ch<= 'z') || (ch >= 'A' && ch<= 'Z') || (ch >= '0' && ch <= '9')){
            return true ;
        }
        return false;
    }

    //finding a maximum occuring char in a string
    //this will also teach how to map char with integer 
    char maxOccuringChar(string s){
        //create an array to store the frequency of alphabets in string 
        int arr[26] ={0};

        //now count the uppercase as well as lowercase in string and store their frequency
        for(int i= 0 ; i<s.size(); i++){
            char ch = s[i];
            int no = 0;
            //uppercase
            //here mapping is done , for A the index will be 0 , for B it will be 1 , it will store frequency as value
            if(ch >= 'A' && ch <= 'Z'){
                no = ch - 'A';
            }
            //lowecase
            //for a the index will be 0 , for B it will be 1
            else{
                no = ch - 'a';
            }
            arr[no]++;
        }
        //finding the max occuring char
        int ans = 0 , maxi = -1;
        for( int i =0  ; i<26 ; i++){
            if(maxi <arr[i] ){
                ans = i;//we are taking the index as ans 
                maxi = arr[i]; //update the value of maxi for the next loop till 25
            }
        }
        return 'a'+ans;//this will return the index value in form of char , 
        //ASIIC value of a is 0 , then any index like for 6 it will return g
    }
    
};
int main() {
    Solution S;
    char name[20];

    cout<<"Enter your name : ";
    cin>>name;

    cout<<"Your name is :";
    cout<<name<<endl;
    //cin will stop processing when a wide space occurs 
    //eg - ip - ankit , op - ankit 
    //eg - ip - ankit singh , op - ankit 

    int n = S.getLength(name);
    cout<<"Length:"<<n<<endl;
    //another way to get size directly is 
    cout<<"length:"<<strlen(name)<<endl;


    S.reverse(name , n);
    cout<<"Name after reverse :";
    cout<<"Your name is :";
    cout<<name<<endl;

    string a = "Too hot to hoot";
    cout<<"Char is Palindrome or not ? :"<<S.charPalindrome(name,n)<<endl;

    string m = "gg boys";
    cout<<"Max occuring char : "<<S.maxOccuringChar(m)<<endl;

    return 0;
}