#include<bits/stdc++.h>
using namespace std;
struct Book
{
    string title;
    string author;
    double price;
    string publisher;
    int quantity;
    int del;
} storedbook[200000],buyed_books[200000];
int myindex;
void title()
{
    cout<<"-------------------------------------\n";
    cout<<"|\n";
    cout<<"|Welcome to General bookshop "<<endl;
    cout<<"|\n";
    cout<<"--------------------------------------\n";
    cout<<"\n\n\n";
    cout<<"1.Customer"<<endl;
    cout<<"2.Manager"<<endl;
    cout<<"Choose any option please:";
}

int main()
{
  system("cls"); 
 title(); 
 return main();
}
