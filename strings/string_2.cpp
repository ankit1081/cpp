#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main(){
	string str;
	getline(cin, str);
	int size = 0;
	for(const auto ch : str){
		cout <<  ch;
		size++;
	}

	cout << endl << size << endl;

	int i;
	for(i=0; str[i]!='\0'; i++);

	cout << i << endl;

	cout<<str.size()<<endl;

	int pos = str.find('k');
	cout<<endl<<pos;
	pos = str.find("nk");
	cout<<endl<<pos;
	str.append("Singh");
	cout<<endl<<str;
	str = str+"akki";
	cout<<endl<<str;
}
//rfind() to find all the occurance of the sring
//find() to find the first occurance of the string
