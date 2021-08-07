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
int index;
int buyed_book_pos;
double current_cost;
void separate(string s)
{
    stringstream ss;
    ss<<s;
    string title;
    string author;
    string publisher;
    double price;
    int quantity;

    ss>>title;
    ss>>author;
    ss>>publisher;
    ss>>price;
    ss>>quantity;
    storedbook[index].title=title;
    storedbook[index].author=author;
    storedbook[index].publisher=publisher;
    storedbook[index].price=price;
    storedbook[index].quantity=quantity;
    storedbook[index].del=0;
    index++;
}
void load_stored_books()
{
    index=1;
    ifstream myreadfile;
    myreadfile.open("data.txt");
    string s;
    while(getline(myreadfile,s))
    {
        separate(s);
    }
    myreadfile.close();
}
void updating_store_books()
{
    ofstream myinput;
    string title;
    string author;
    string publisher;
    double price;
    int quantity;
    myinput.open("data.txt",ofstream::out);
    for(int i=1; i<index; i++)
    {
        if(storedbook[i].quantity==0 || storedbook[i].del==1)
            continue;
        title=storedbook[i].title;
        author=storedbook[i].author;
        publisher=storedbook[i].publisher;
        price=storedbook[i].price;
        quantity=storedbook[i].quantity;
        myinput<<title<<" ";
        myinput<<author<<" ";
        myinput<<publisher<<" ";
        myinput<<price<<" ";
        myinput<<quantity<<" "<<endl;
    }
    myinput.close();
}
void cash_out()
{
    getchar();
    system("cls");
    cout<<"you cost is:"<<current_cost<<endl;
    cout<<"thank you come again"<<endl;
    cout<<"press enter to go back to main menu"<<endl;
    getchar();
}
void add_new_book()
{
    system("cls");
    ofstream myinput;
    string title;
    string author;
    string publisher;
    double price;
    int quantity;
    cout<<"Enter title name"<<endl;
    cin>>title;
    cout<<"Enter author name"<<endl;
    cin>>author;
    cout<<"Enter publisher name"<<endl;
    cin>>publisher;
    cout<<"Enter price"<<endl;
    cin>>price;
    cout<<"Enter Quantity"<<endl;
    cin>>quantity;
    getchar();
    storedbook[index].title=title;
    storedbook[index].author=author;
    storedbook[index].publisher=publisher;
    storedbook[index].price=price;
    storedbook[index].quantity=quantity;
    storedbook[index].del=0;
    index++;
    cout<<"Book Added Successfully"<<endl;
    cout<<"press enter to go back to customer menu"<<endl;
    getchar();

}

void show_all_books()
{

    for(int i=1; i<index; i++)
    {
        if(storedbook[i].del==1)
            continue;
        cout<<"Serial NO:"<<i<<" "<<endl;
        cout<<"Title:"<<storedbook[i].title<<" "<<endl;
        cout<<"Author:"<<storedbook[i].author<<" "<<endl;
        cout<<"Publisher:"<<storedbook[i].publisher<<" "<<endl;
        cout<<"Price:"<<storedbook[i].price<<" "<<endl;
        cout<<"Quantity:"<<storedbook[i].quantity<<" "<<endl;
        cout<<endl<<endl;
    }
}

int search_book(string s)
{

    for(int i=1; i<index; i++)
    {
        if(storedbook[i].title==s)
        {
            return i;
        }
    }
    return -1;
}
void show_all_purchased_books()
{
    if(buyed_book_pos==1)
        cout<<"No book added to list yet"<<endl;
    for(int i=1; i<buyed_book_pos; i++)
    {
        cout<<"Serial NO:"<<i<<" "<<endl;
        cout<<"Title:"<<buyed_books[i].title<<" "<<endl;
        cout<<"Author:"<<buyed_books[i].author<<" "<<endl;
        cout<<"Publisher:"<<buyed_books[i].publisher<<" "<<endl;
        cout<<"Price:"<<buyed_books[i].price<<" "<<endl;
        cout<<"Quantity:"<<buyed_books[i].quantity<<" "<<endl;
        cout<<endl<<endl;
    }
    getchar();
    cout<<"press enter to go back to customer menu"<<endl;
    getchar();


}
void adding_books_to_purchased_list(int a,int quantity)
{
    buyed_books[buyed_book_pos].title=storedbook[a].title;
    buyed_books[buyed_book_pos].author=storedbook[a].author;
    buyed_books[buyed_book_pos].quantity=quantity;
    buyed_books[buyed_book_pos].price=storedbook[a].price;
    buyed_books[buyed_book_pos].publisher=storedbook[a].publisher;
    buyed_book_pos++;
    current_cost+=(storedbook[a].price*(double)quantity);
}
void buy_book(int a)
{
    cout<<"Book Details"<<endl;
    cout<<"Title:"<<storedbook[a].title<<" "<<endl;
    cout<<"Author:"<<storedbook[a].author<<" "<<endl;
    cout<<"Publisher:"<<storedbook[a].publisher<<" "<<endl;
    cout<<"Price per book:"<<storedbook[a].price<<" "<<endl;
    cout<<"Available quantity:"<<storedbook[a].quantity<<" "<<endl;
    cout<<endl<<endl;

    cout<<"How many would you like to buy:"<<endl;
    int quantity;
    cin>>quantity;
    while(quantity>storedbook[a].quantity)
    {
        cout<<"Sorry we don't have that many available,please enter a new value or 0 to exit"<<endl;
        cin>>quantity;
    }
    if(quantity<=0)
        return;
    storedbook[a].quantity-=quantity;
    getchar();
    cout<<"Added to list successfully"<<endl;
    cout<<"press enter to go back to customer menu"<<endl;
    getchar();
    adding_books_to_purchased_list(a,quantity);
}
void customer()
{
    system("cls");
    cout<<"\n\n\n";
    cout<<"How can i help u:"<<endl;
    cout<<"1.Show books"<<endl;
    cout<<"2.Search for books"<<endl;
    cout<<"3.Show balance"<<endl;
    cout<<"4.Show buyed books"<<endl;
    cout<<"5.Cash out"<<endl;
    cout<<"6.Exit"<<endl;
    int a;
    cin>>a;

    if(a==1)
    {
        system("cls");
        show_all_books();
        cout<<"enter the index you want to buy the book of:"<<endl;
        cout<<"enter 0 to go back:"<<endl;
        cin>>a;
        if(a>0)
        {
            buy_book(a);
        }
        system("cls");
        customer();

    }
    else if(a==2)
    {
        system("cls");
        cout<<"Enter book name"<<endl;
        string s;
        getchar();
        cin>>s;
        int flg=search_book(s);
        if(flg>=0)
        {
            cout<<"Book is available"<<endl;
            cout<<"Press 1.Buy the book"<<endl;
            cout<<"Press 2.Back to customer menu"<<endl;
            cin>>a;
            if(a==1)
            {
                buy_book(a);
            }
            system("cls");
            customer();
        }
        else
        {
            cout<<"no book found by this name"<<endl;
            cout<<"press enter to go back to customer menu"<<endl;
            getchar();
            customer();
        }
    }
    else if(a==3)
    {
        system("cls");
        getchar();
        cout<<"your current balance is:"<<current_cost<<endl;
        cout<<"press enter to go back to customer menu"<<endl;
        getchar();
        customer();
    }
    else if(a==4)
    {
        system("cls");
        show_all_purchased_books();
        customer();
    }
    else if(a==5)
    {
        cash_out();
    }
}
void delete_book()
{
    system("cls");
    int a;
    cout<<"Enter 1 to show all books"<<endl;
    cout<<"Enter 2 to go back"<<endl;
    cin>>a;
    if(a==1)
    {
        show_all_books();
        cout<<endl<<endl;
        cout<<"Enter the No. of the book you want to delete otherwise 0 to back to delete menu"<<endl;
        cin>>a;
        getchar();
        if(a>0)
        {
            storedbook[a].del=1;
            cout<<"Book Deleted Successfully....press enter to continue"<<endl;
            getchar();
        }

        delete_book();
    }
    else
        return;

}
void manager()
{
    system("cls");
    cout<<"Manager counter:"<<endl;
    cout<<"1.Add a new book"<<endl;
    cout<<"2.Delete a book"<<endl;
    cout<<"3.To go back"<<endl;
    int a;
    cin>>a;
    if(a==1)
    {
        add_new_book();
        manager();
    }
    else if(a==2)
    {
        delete_book();
        manager();
    }
    else
        return;
}
void menu()
{
    load_stored_books();
    cout<<"\n\n\n";
    cout<<"1.Customer"<<endl;
    cout<<"2.Manager"<<endl;
    cout<<"Choose any option please:";
    buyed_book_pos=1;
    int a;
    cin>>a;
    if(a==1)
        customer();
    else
        manager();

    updating_store_books();
}
void title()
{
    cout<<"-------------------------------------\n";
    cout<<"|\n";
    cout<<"|Welcome to General bookshop "<<endl;
    cout<<"|\n";
    cout<<"--------------------------------------\n";
}
int main()
{
    system("cls");
    title();
    menu();
    return main();
}
