#include<iostream>
using namespace std;

void simplePyramid(int n ){
    for( int i = 1 ; i<= n ; i++){
        cout<<"\n";
        for ( int j = 1 ; j<= i ; j++){
            cout<<"*"<<" ";
        }
    }
}
 void invertedPyramid(int n){
    for(int i = n ; i>=1; i--){
        cout<<"\n";
        for(int j = 1 ; j <=i ; j++){
            cout<<"* ";
        }
    }
 }
 void flippedSimplePyramid(int n){
    for ( int i = 1;i<=n;i++){
        cout<<"\n";
        for(int k = 1; k<= n-i;k++){
            cout<<" "<<" ";
        }
        for(int j = 1 ; j<=i ; j++){
            cout<<"*"<<" ";
        }
    }
}
void flippedInvertedPyramid(int n){
    for ( int i = n;i>=1;i--){
        cout<<"\n";
        for(int k = 1; k<= n-i;k++){
            cout<<" "<<" ";
        }
        for(int j = 1 ; j<=i ; j++){
            cout<<"*"<<" ";
        }
    }
}
void traingle(int n){
    for ( int i = 1;i<=n;i++){
        cout<<"\n";
        for(int k = 1; k<= n-i;k++){
            cout<<" ";
        }
        for(int j = 1 ; j<=i ; j++){
            cout<<"*"<<" ";
        }
    }
}
void invertedTraingle(int n){
    for ( int i = n;i >=1;i--){
        cout<<"\n";
        for(int k = 1; k<= n-i;k++){
            cout<<" ";
        }
        for(int j = 1 ; j<=i ; j++){
            cout<<"*"<<" ";
        }
    }
}
void halfDiamondPattern(int n){
    for(int i = 1; i<=n;i++){
        cout<<"\n";
        for(int j=1;j<=i;j++ ){
            cout<<"*"<<" ";
        }
    }
    for(int i = n-1; i>=1;i--){
        cout<<"\n";
        for(int j=1;j<=i;j++ ){
            cout<<"*"<<" ";
        }
    }

}
void flippedHalfDiamondPattern(int n){
    for ( int i = 1;i<=n;i++){
        cout<<"\n";
        for(int k = 1; k<= n-i;k++){
            cout<<" "<<" ";
        }
        for(int j = 1 ; j<=i ; j++){
            cout<<"*"<<" ";
        }
    }
    for ( int i = n-1;i>=1;i--){
        cout<<"\n";
        for(int k = 1; k<= n-i;k++){
            cout<<" "<<" ";
        }
        for(int j = 1 ; j<=i ; j++){
            cout<<"*"<<" ";
        }
    }
}
void diamond(int n ){
    for ( int i = 1;i<=n;i++){
        cout<<"\n";
        for(int k = 1; k<= n-i;k++){
            cout<<" ";
        }
        for(int j = 1 ; j<=i ; j++){
            cout<<"*"<<" ";
        }
    }
    for ( int i = n-1;i >=1;i--){
        cout<<"\n";
        for(int k = 1; k<= n-i;k++){
            cout<<" ";
        }
        for(int j = 1 ; j<=i ; j++){
            cout<<"*"<<" ";
        }
    }
}
void hourglass(int n){
    for ( int i = n;i >=1;i--){
        cout<<"\n";
        for(int k = 1; k<= n-i;k++){
            cout<<" ";
        }
        for(int j = 1 ; j<=i ; j++){
            cout<<"*"<<" ";
        }
    }
    for ( int i = 2;i<=n;i++){
        cout<<"\n";
        for(int k = 1; k<= n-i;k++){
            cout<<" ";
        }
        for(int j = 1 ; j<=i ; j++){
            cout<<"*"<<" ";
        }
    }
}
void numberPyramid(int n){
    int a = 1;
    for(int i = 1 ; i<= n; i++){
        cout<<"\n";

        for(int j = 1 ; j<=i;j++){
            cout<<a<<" ";
        }
        a++;
    }
}
void alphabetPyramid(int n){
    int num = 65;
    for(int i = 1;i<=n;i++){
        cout<<"\n";

        for(int j = 1 ; j<=i;j++){
            char ch = int(num);
            cout<<ch<<" ";

        }
        num++;
    }
}
void continousAlphabetPyramid(int n){
    int num = 65;
    for(int i = 1;i<=n;i++){
        cout<<"\n";

        for(int j = 1 ; j<=i;j++){
            char ch = int(num);
            cout<<ch<<" ";
            num++;

        }

    }
}

void hollowSimplePyramid(int n ){
    for( int i = 1 ; i<= n ; i++){
        cout<<"\n";
        for ( int j = 1 ; j<= i ; j++){
            if(j==1 || i == n || j==i){
                cout<<"*"<<" ";
            }
            else{
                cout<<" "<<" ";
            }
        }

    }
}

int main()
{
    int n ;
    cin>>n;
    cout<<"\nsimple pyramid"<<endl;
    simplePyramid(n);
    cout<<"\ninverted pyramid"<<endl;
    invertedPyramid(n);
    cout<<"\nflipped simple pyramid"<<endl;
    flippedSimplePyramid(n);
    cout<<"\nflipped Inverted pyramid"<<endl;
    flippedInvertedPyramid(n);
    cout<<"\ntraingle"<<endl;
    traingle(n);
    cout<<"\ninverted traingle"<<endl;
    invertedTraingle(n);
    cout<<"\nhalf diamond pattern"<<endl;
    halfDiamondPattern(n);
    cout<<"\nflipped half diamond pattern"<<endl;
    flippedHalfDiamondPattern(n);
    cout<<"\ndiamond "<<endl;
    diamond(n);
    cout<<"\nhourglass"<<endl;
    hourglass(n);
    cout<<"\nnumber pyramid"<<endl;
    numberPyramid(n);
    cout<<"\nalphabet pyramid"<<endl;
    alphabetPyramid(n);
    cout<<"\ncontinuous alphabet pyramid"<<endl;
    continousAlphabetPyramid(n);
    cout<<"\nHollow Simple Pyramid"<<endl;
    hollowSimplePyramid(n );

    return 0;
}
