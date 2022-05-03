# include <bits/stdc++.h>
#include<limits>
using namespace std;


struct date    //To store date
{
   int dd;
   int mm;
   int yyyy;
};
date today_;
int LoggedInId = -1;  // to store the id of logged in user
class user{                
    public:
    string password, name;
    int id;
    int role;
    public:
    int Login();
    void Logout();
    void setid(int a);
    void setname(string a);
    void setpass(string a);
    void setrole(int a);
};
class book{
    public:
    string title;
    string author;
    string ISBN;
    string publication;
    int is_available;
    date issue_date;
    int borrower_id;
    
    
    bool book_request();
    void show_duedate(string ISBN);
    void setTitle(string a);
    void setAuthor(string b);
    void setISBN(string c);
    void setPublication(string d);
    void setavailability(int x);
    void setissueDate(date x);
    
    
};

class Librarian : public user{
    public:
    void view();   // from where he will choose what to do
    int Login();
    

};
class Professor : public user{
    public:
    int fine_amount;
    vector<book> bookList;
    int calculate_fine();
    void clear_fine_amout();
    void view();
    void see_issued_books();
    void issueBook();
    void returnBook();
    void getData();
    int Login();
    Professor(){
        fine_amount=0;
    }
};
class Student : public user{
    public:
    int fine_amount;
    vector<book> bookList;
    int calculate_fine();
    void getData();
    void clear_fine_amout();
    void view();
    void see_issued_books();
    void issueBook();
    void returnBook();
    int Login();
    Student(){
        fine_amount=0;
    }


};


class user_database{
    public:
     vector<user> userList;
     void addUser(int id);
     void deleteUser();
     void updateUser();
     int searchUser();
     void display();

};
user_database users;

class book_database{
    public:
    vector<book> allBooks;
    void addBook();
    void deleteBook();
    void updatebook();
    int searchBook();
    void display();
};
book_database books;

// all the functions relayed to user class
void user::setid(int a){
    id = a;
}
void user::setname(string a){
    name = a;
}
void user::setpass(string a){
    password = a;
}
void user::setrole(int a){
    role = a;
}
int user::Login(){
    
    int id;
    string password;

    cout<<"ID: \n";
    cin>>id;
    cout<<"password: \n";
    cin>>password;
    
    int i=0;
   
    while(i<users.userList.size()){
        
        if(users.userList[i].id==id){
            if(users.userList[i].password==password){
                LoggedInId = id;
                
                return users.userList[i].role;
            }
            else {
                cout<<"Password Incorrect";
                return -2;
            }
        }
        
        i++;
    }
   
    return -1;
    
    

};
void user:: Logout(){


    cout<<"Logged out succesfully!\n";
    cout<<"#######  Library Management System ####### \n";
    cout<<"Press 1 for Login\n";
    LoggedInId = -1;
    user x;
    int z;
    cin>>z;
    if(z==1)
    role=x.Login();
    else cout<<"Invalid request\n";
    Librarian librarian1;
    Student student1;
    Professor professor1;
    switch (role)
    {
    case 1: 
    
    librarian1.view();
    break;
    case 2:
    student1.getData();
    student1.view();
    break;
    case 3:
    professor1.getData();
    professor1.view();
    break;

    default: 
     cout<<"Select appropriate Role";
        break;
    }

}


// all the functions relayed to book class
void book::setAuthor(string a){
    author = a;
}
void book::setISBN(string a){
    ISBN=a;
}
void book::setTitle(string a){
    title=a;
}
void book::setPublication(string a){
    publication=a;
}
void book::setavailability(int x){
    is_available = x;
}
bool book::book_request(){
    return is_available;


}
void book::setissueDate(date x){
    issue_date=x;
}

// we are making our database in this function
void create_db(){
        user user1;user1.id=1; user1.name="Librarrian";user1.password="Library";user1.role=1;
        
        user user2;user2.id=2;user2.name="User2";user2.password="user2";user2.role=2;
        user user3;user3.id=3;user3.name="User3";user3.password="user3";user3.role=2;
        user user4;user4.id=4;user4.name="user4";user4.password="user4";user4.role=3;
        user user5;user5.id=5;user5.name="user5";user5.password="user5";user5.role=3;
        users.userList.push_back(user1);
        users.userList.push_back(user2);
        users.userList.push_back(user3);
        users.userList.push_back(user4);
        users.userList.push_back(user5);
        book book1;book1.title="Harry Potter";book1.author="Rudyard";book1.ISBN="har123";book1.publication="Hogwarts";book1.issue_date.dd=0;book1.issue_date.mm=0;book1.issue_date.yyyy=0 ;book1.is_available=1;book1.borrower_id=-1;
        book book2;book2.title="Intro to algos";book2.author="Cormen";book2.ISBN="cor123";book2.publication="IITK";book2.issue_date.dd=10;book2.issue_date.mm=03;book2.issue_date.yyyy=2022;book2.is_available=0;book2.borrower_id=2;
        book book3;book3.title="A tale of two cities";book3.author="Charles Dickens";book3.ISBN="atotc123";book3.publication="Disney";book3.issue_date.dd=0;book3.issue_date.mm=0;book3.issue_date.yyyy=0 ;book3.is_available=1;book3.borrower_id=-1;
        books.allBooks.push_back(book1);
        books.allBooks.push_back(book2);
        books.allBooks.push_back(book3);
}

// this is the portalview of librarian
void Librarian:: view(){
    
    cout<<"Welcome Librarian\n";
    cout<<"1 See all Books\n";
    cout<<"2 See all Users\n";
    cout<<"3 Add a Book\n";
    cout<<"4 Delete a book\n";
    cout<<"5 Update a book\n";
    cout<<"6 Add a user\n";
    cout<<"7 Delete a user\n";
    cout<<"8 Update a user\n";
    cout<<"9 See books issued by a user\n";
    cout<<"10 See user to which book is issued to\n";
    cout<<"11 Logout\n";
    cout<<"Choose what you want to do\n";
    int choice;
    cin>>choice;
    user x;
    int id;
    int ind;
    int i;
    char temp;
    switch (choice)
    {
    case 1:
        system("clear");
        books.display();
        cout << "Press x to Continue\n";
        
        while(1){
            cin>>temp;
            if(temp=='x')break;
        }
        system("clear");
        view();
    case 2:
        system("clear");
        users.display();
        cout << "Press x to Continue\n";
        
        while(1){
            cin>>temp;
            if(temp=='x')break;
        }
        system("clear");
        view();
    case 3:
        system("clear");
        books.addBook();
        cout << "Press x to Continue\n";
        
        while(1){
            cin>>temp;
            if(temp=='x')break;
        }
        system("clear");
        view();
    case 4:
        system("clear");
        books.deleteBook();
        cout << "Press x to Continue\n";
        cout<<"Press x to continue\n";
        while(1){
            cin>>temp;
            if(temp=='x')break;
        }
        system("clear");
        view();
    case 5:
       system("clear");
       books.updatebook();
       cout << "Press x to Continue\n";
        cout<<"Press x to continue\n";
        while(1){
            cin>>temp;
            if(temp=='x')break;
        }
        system("clear");
       view();
    case 6:
       system("clear");
       users.addUser(users.userList.size()+2);
       cout<<"Press x to continue\n";
       while(1){
            cin>>temp;
            if(temp=='x')break;
        }
        system("clear");
       view();
    case 7:
       system("clear");
       users.deleteUser();
       cout<<"Press x to continue\n";
       while(1){
            cin>>temp;
            if(temp=='x')break;
        }
        system("clear");
       view();
    case 8:
        system("clear");
       users.updateUser();
       cout<<"Press x to continue\n";
       while(1){
            cin>>temp;
            if(temp=='x')break;
        }
        system("clear");
       view();
    case 9:
       system("clear");
       ind = users.searchUser();
       if(ind==-1){cout<<"No user found\n";}
       else {
           i=0;
           while(i<books.allBooks.size()){
               
               if(books.allBooks[i].borrower_id==users.userList[ind].id)
               cout<<"Title: "<<books.allBooks[i].title<<endl;
               i++;
           }
       }
       cout<<"Press x to continue\n";
       while(1){
            cin>>temp;
            if(temp=='x')break;
        }
        system("clear");
       view();
    case 10:
       system("clear");
       ind=books.searchBook();
       if(ind==-1){cout<<"No such book found\n";}
       else if(books.allBooks[ind].borrower_id!=-1){
           i=0;
           while(i<users.userList.size()){
               if(users.userList[i].id==books.allBooks[ind].borrower_id){ind=i;break;}
               i++;
           }
           
           cout<<"Borrower: "<<users.userList[ind].name<<endl;
       }
       else{
           cout<<"Book available\n";
       }
       cout<<"Press x to continue\n";
       while(1){
            cin>>temp;
            if(temp=='x')break;
        }
        system("clear");
       view();
       
    case 11:
       system("clear");
       this->Logout();
    
       
    

    
    default:
        x.Login();
    }
}

//this is the portalview of prof 
void Professor:: view(){
    cout<<"Welcome "<<name<<endl;
    cout<<"1 See all Books\n";
    cout<<"2 See your books\n";
    cout<<"3 Check book availability\n";
    cout<<"4 Issue a book\n";
    cout<<"5 See Fine\n";
    cout<<"6 Clear Fine\n";
    cout<<"7 Return book\n";
    cout<<"8 Logout\n";
    cout<<"\n Choose what you want to do\n";

    int choice;
    cin>>choice;
    book x;
    int ind;
    int date;
    user y;
    char temp;
    switch (choice)
    {
    case 1:
        system("clear");
        books.display();
        cout << "Press x to Continue\n";
        
        while(1){
            cin>>temp;
            if(temp=='x')break;
        }
        system("clear");
        view();
    case 2:
        system("clear");
        this->see_issued_books();
        cout << "Press x to Continue\n";
        
        while(1){
            cin>>temp;
            if(temp=='x')break;
        }
        system("clear");
        view();
    case 3:
         system("clear");
       ind = books.searchBook();
       if(ind==-1){
           cout<<"No such book found\n";
           
       }
       else{
           x = books.allBooks[ind];
       if(x.book_request()){
           cout<<"Book is available\n";
       }
       else cout<<"Book has been issued\n";

       }
       
       cout << "Press x to Continue\n";
        
        while(1){
            cin>>temp;
            if(temp=='x')break;
        }
        system("clear");
       view();
    case 4:
            system("clear");
            this->issueBook();
            cout << "Press x to Continue\n";
        
        while(1){
            cin>>temp;
            if(temp=='x')break;
        }
            view();
        
        
    case 5:
        system("clear");
        this->calculate_fine();
        cout << "Press x to Continue\n";
        
        while(1){
            cin>>temp;
            if(temp=='x')break;
        }
        system("clear");
        view();
    case 6:
        system("clear");
        this->clear_fine_amout();
        cout << "Press x to Continue\n";
        
        while(1){
            cin>>temp;
            if(temp=='x')break;
        }
        system("clear");
        view();
    case 7:
        system("clear");
        this->returnBook();
        cout << "Press x to Continue\n";
        
        while(1){
            cin>>temp;
            if(temp=='x')break;
        }
        system("clear");
        view();
    case 8:
        system("clear");
        this->Logout(); 
          
    default:
    system("clear");
    y.Login();
        
    }



}

// all the functions related to professor child class
void Professor::issueBook(){
    date issue_date;
    int ind = books.searchBook();
    if(ind==-1){
        cout<<"Book not found\n";
        return;
    }
    
    book* to_issue= &(books.allBooks[ind]);
    if((*(to_issue)).is_available==0){
        cout<<"Book already issued to someone\n";
        return;
    }
    cout<<"Enter issue date dd\n";
    cin>>issue_date.dd;
    cout<<"Enter issue month mm\n";
    cin>>issue_date.mm;
    cout<<"Enter issue year yyyy\n";
    cin>>issue_date.yyyy;
    (*(to_issue)).setissueDate(issue_date);
    (*(to_issue)).borrower_id=LoggedInId;
    (*(to_issue)).setavailability(0);
    
    bookList.push_back(*to_issue);
    cout<<"\nBook issued successfully\n\n";

    
}
void Professor::see_issued_books(){
    int i=0;
    cout<<"You have issued "<< bookList.size()<< " books\n\n";
    while(i<bookList.size()){
        cout<<i+1<< ". Title:   "<<bookList[i].title<<endl;
        cout<<"Date of issue: "<<bookList[i].issue_date.dd<<"/"<<bookList[i].issue_date.mm<<"/"<<bookList[i].issue_date.yyyy<<endl<<endl;
        i++;
    }
}
int Professor::calculate_fine(){
    date today;
    cout<<"Enter today's date dd\n";
    cin>>today_.dd;
    cout<<"Enter today's month mm\n";
    cin>>today_.mm;
    cout<<"enter today's year\n";
    cin>>today_.yyyy;
    int i=0;
    int total_fine=0;
    int no_of_days[bookList.size()] ={0};
    int fine[bookList.size()]={0};
    while(i<bookList.size()){
        no_of_days[i]+=(today_.yyyy-bookList[i].issue_date.yyyy)*365;
        no_of_days[i]+=(today_.mm-bookList[i].issue_date.mm)*30;
        no_of_days[i]+=(today_.dd-bookList[i].issue_date.dd);
        if(no_of_days[i]>30)fine[i]=(no_of_days[i]-30)*2;
        cout<<i+1<< " Title: "<<bookList[i].title<<"    Fine : "<<fine[i]<<endl;
        total_fine+=fine[i];
        i++;

        

    }
    cout<<"Total fine: "<<total_fine<<endl;
    this->fine_amount=total_fine;
    return total_fine;



}
void Professor::clear_fine_amout(){
    int i =0;
    
        int amount=calculate_fine();
        
        goto clear;
        clear:
        cout<<"Please enter "<<amount<<" to clear fine\n";
        int fine;
        cin>>fine;
        if(fine!=fine_amount){
            cout<<"Please enter correct fine amount\n";
            goto clear;
        }
        else{
            while(i<bookList.size()){
            bookList[i].issue_date=today_;
            // cout<<bookList[i].issue_date.dd<<"/"<<bookList[i].issue_date.mm<<"/"<<bookList[i].issue_date.yyyy;
            i++;
        }
        fine_amount=0;
        cout<<"\nAll fine cleared!\n";

        }
        return;
        
    
}
void Professor::returnBook(){
     if (this->calculate_fine()!=0){
           cout<<"\nYou have fine, please clear it before returning the book\n";
    }
    
    else{
        int ind = books.searchBook();
        if(ind==-1){
            cout<<"Please enter valid ISBN\n";
        }
        else{
            int ret_id;
            if(this->id==books.allBooks[ind].borrower_id){
                int i=0;
                while(i<this->bookList.size()){if(this->bookList[i].ISBN==books.allBooks[ind].ISBN)ret_id=i;i++;}
                this->bookList.erase(this->bookList.begin()+ret_id);
                books.allBooks[ind].is_available=1;
                books.allBooks[ind].borrower_id=-1;
                cout<<"Book Returned Successfully!\n";
            }
            else{
                cout<<"This book has not been issued by you\n";
            }
            
        }
    }
    
}
void Professor::getData(){
    int i=0;
    while(i<users.userList.size()){
        if(LoggedInId==users.userList[i].id)break;
        i++;
    }
    user x=users.userList[i];
    id=LoggedInId;
    name=x.name;
    i=0;
    while(i<books.allBooks.size()){
        if(books.allBooks[i].borrower_id==LoggedInId)this->bookList.push_back(books.allBooks[i]);
        i++;
    }
    role=x.role;
    password=x.password;
    
    
}

// all the functions related to student child class
void Student:: view(){
    cout<<"Welcome "<<name<<endl;
    cout<<"1 See all Books\n";
    cout<<"2 See your books\n";
    cout<<"3 Check book availability\n";
    cout<<"4 Issue a book\n";
    cout<<"5 See Fine\n";
    cout<<"6 Clear Fine\n";
    cout<<"7 Return book\n";
    cout<<"8 Logout\n";
    cout<<"\n Choose what you want to do\n";

    int choice;
    cin>>choice;
    book x;
    char temp;
    int ind;
    int date;
    switch (choice)
    {
    case 1:
        system("clear");
        books.display();
        cout << "Press x to Continue\n";
        
        while(1){
            cin>>temp;
            if(temp=='x')break;
        }
        system("clear");
        view();
    case 2:
        system("clear");
        this->see_issued_books();
        cout << "Press x to Continue\n";
        
        while(1){
            cin>>temp;
            if(temp=='x')break;
        }
        system("clear");
        view();
    case 3:
        system("clear");
       ind = books.searchBook();
       if(ind==-1){
           cout<<"No such book found\n";
           
       }
       else{
           x = books.allBooks[ind];
       if(x.book_request()){
           cout<<"Book is available\n";
       }
       else cout<<"Book has been issued\n";

       }
       
       cout << "Press x to Continue\n";
        
        while(1){
            cin>>temp;
            if(temp=='x')break;
        }
        system("clear");
       view();
    case 4:
        system("clear");
        if(bookList.size()>=5){
            cout<<"You cannot issue more than 5 books\n";
            cout << "Press x to Continue\n";
        
        while(1){
            cin>>temp;
            if(temp=='x')break;
        }
            view();
        }
        else{
            this->issueBook();
            cout << "Press x to Continue\n";
        
        while(1){
            cin>>temp;
            if(temp=='x')break;
        }
            view();
        }
        
    case 5:
        system("clear");
        this->calculate_fine();
        cout << "Press x to Continue\n";
        
        while(1){
            cin>>temp;
            if(temp=='x')break;
        }
        system("clear");
        view();
    case 6:
        system("clear");
        this->clear_fine_amout();
        cout << "Press x to Continue\n";
        
        while(1){
            cin>>temp;
            if(temp=='x')break;
        }
        system("clear");
        view();
    case 7:
        system("clear");
        this->returnBook();
        cout << "Press x to Continue\n";
        
        while(1){
            cin>>temp;
            if(temp=='x')break;
        }
        system("clear");
        view();
    case 8:
        system("clear");
        cout << "Press x to Continue\n";
        
       
        this->Logout();
    
    default:
        break;
    }


    
}
void Student::issueBook(){
    date issue_date;
    int ind = books.searchBook();
    if(ind==-1){
        cout<<"Book not found\n";
        return;
    }
    
    book* to_issue= &(books.allBooks[ind]);
    if((*(to_issue)).is_available==0){
        cout<<"Book already issued to someone\n";
        return;
    }
    cout<<"Enter issue date dd\n";
    cin>>issue_date.dd;
    cout<<"Enter issue month mm\n";
    cin>>issue_date.mm;
    cout<<"Enter issue year yyyy\n";
    cin>>issue_date.yyyy;
    (*(to_issue)).setissueDate(issue_date);
    (*(to_issue)).borrower_id=LoggedInId;
    (*(to_issue)).setavailability(0);
    
    bookList.push_back(*to_issue);
    cout<<"\nBook issued successfully\n\n";

    
}
void Student::see_issued_books(){
    int i=0;
    cout<<"You have issued "<< bookList.size()<< " books\n\n";
    while(i<bookList.size()){
        cout<<i+1<< ". Title:   "<<bookList[i].title<<endl;
        cout<<"Date of issue: "<<bookList[i].issue_date.dd<<"/"<<bookList[i].issue_date.mm<<"/"<<bookList[i].issue_date.yyyy<<endl<<endl;
        i++;
    }
}
int Student::calculate_fine(){
    date today;
    cout<<"Enter today's date dd\n";
    cin>>today_.dd;
    cout<<"Enter today's month mm\n";
    cin>>today_.mm;
    cout<<"enter today's year\n";
    cin>>today_.yyyy;
    int i=0;
    int total_fine=0;
    int no_of_days[bookList.size()] ={0};
    int fine[bookList.size()]={0};
    while(i<bookList.size()){
        no_of_days[i]+=(today_.yyyy-bookList[i].issue_date.yyyy)*365;
        no_of_days[i]+=(today_.mm-bookList[i].issue_date.mm)*30;
        no_of_days[i]+=(today_.dd-bookList[i].issue_date.dd);
        if(no_of_days[i]>30)fine[i]=(no_of_days[i]-30)*2;
        cout<<i+1<< " Title: "<<bookList[i].title<<"    Fine : "<<fine[i]<<endl;
        total_fine+=fine[i];
        i++;

        

    }
    cout<<"Total fine: "<<total_fine<<endl;
    this->fine_amount=total_fine;
    return total_fine;


}
void Student::clear_fine_amout(){
    
    int i =0;
    
        int amount=calculate_fine();
        
        
        cout<<"Please enter "<<amount<<" to clear fine\n";
        int fine;
        cin>>fine;
        if(fine!=fine_amount){
            cout<<"Please enter correct fine amount\n";
            
        }
        else{
            while(i<bookList.size()){
            bookList[i].issue_date=today_;
            // cout<<bookList[i].issue_date.dd<<"/"<<bookList[i].issue_date.mm<<"/"<<bookList[i].issue_date.yyyy;
            i++;
        }
        fine_amount=0;
        cout<<"\nAll fine cleared!\n";

        }
        
        
    
    
}
void Student::returnBook(){
   if (this->calculate_fine()!=0){
           cout<<"\nYou have fine, please clear it before returning the book\n";
    }
    
    else{
        int ind = books.searchBook();
        if(ind==-1){
            cout<<"Please enter valid ISBN\n";
        }
        else{
            int ret_id;
            if(this->id==books.allBooks[ind].borrower_id){
                int i=0;
                while(i<this->bookList.size()){if(this->bookList[i].ISBN==books.allBooks[ind].ISBN)ret_id=i;i++;}
                this->bookList.erase(this->bookList.begin()+ret_id);
                books.allBooks[ind].is_available=1;
                books.allBooks[ind].borrower_id=-1;
                cout<<"Book Returned Successfully!\n";
            }
            else{
                cout<<"This book has not been issued by you\n";
            }
            
        }
    }
    
}
void Student::getData(){
    int i=0;
    while(i<users.userList.size()){
        if(LoggedInId==users.userList[i].id)break;
        i++;
    }
    user x=users.userList[i];
    id=LoggedInId;
    name=x.name;
    i=0;
    while(i<books.allBooks.size()){
        if(books.allBooks[i].borrower_id==LoggedInId)this->bookList.push_back(books.allBooks[i]);
        i++;
    }
    role=x.role;
    password=x.password;
    
    
}

// all the functions related to user database class
void user_database::addUser(int id){
    cout<<"Enter your name\n";
    string name;
    getline(cin,name);
    getline(cin,name);
    cout<<"Enter your password\n";
    string password;
    getline(cin,password);
    int role;
    cout<<"Enter your role\n";
    cin>> role;

    cout<<"Your id is "<<id<<endl;
    user myuser;
    myuser.setid(id);
    myuser.setname(name);
    myuser.setpass(password);
    myuser.setrole(role);
    users.userList.push_back(myuser);
    
    
};
void user_database::updateUser(){
    int ind = users.searchUser();
    if(ind==-1){
        cout<<"Given uid is not valid\n";
        return;
    }
    user* to_update;
    to_update= &(users.userList[ind]);
    string name,password;
    int role;
    cout<<"Enter new Name\n";
    getline(cin,name);
    getline(cin,name);
    cout<<"Enter new role\n";
    cin>>role;
    cout<<"Enter new password\n";
    getline(cin,password);
    getline(cin,password);
    (*to_update).setname(name);
    (*to_update).setpass(password);
    (*to_update).setrole(role);
    cout<<"User Updated!\n";
    
    

}
void user_database::deleteUser(){
   int ind= users.searchUser();
   if(ind==-1){
       cout<<"ID is not valid\n";
       return;
   }
   
   users.userList.erase(users.userList.begin()+ind);
   cout<<"User Deleted Successfully!\n";

}
int user_database::searchUser(){
    int id;
    cout<<"Enter ID\n";
    cin>>id;
    int i=0;
    while(i<users.userList.size()){
        if(users.userList[i].id==id)return i;
        i++;
    }
    return -1;
}
void user_database::display(){
    int i =0;
    while(i<users.userList.size()){
        if(userList[i].role==1)cout<<"\nRole:          Librarian\n";
        else if(userList[i].role==2)cout<<"\nRole:          Student\n";
        else cout<<"\nRole:          Professor\n";
        cout<<"ID:            "<<userList[i].id<<endl;
        cout<<"Name:          "<<userList[i].name<<endl;
        i++;
        
    }

}

// all the functions related to book database class
void book_database::addBook(){
    string title,author,ISBN;
    string pub;
    cout<<"Title of Book: \n";
    getline(cin,title);
    getline(cin,title);
    cout<<"Name of Author: \n";
    getline(cin,author);
    cout<<"ISBN: \n";
    getline(cin,ISBN);
    cout<<"Publication: \n";
    getline(cin,pub);
    book newbook;
    newbook.setAuthor(author);
    newbook.setISBN(ISBN);
    newbook.setTitle(title);
    newbook.setPublication(pub);
    books.allBooks.push_back(newbook);
    cout<<"Book added successfuly!\n ";
    

}
void book_database::deleteBook(){
    string isbn;
    cout<<"Enter ISBN\n";
    cin>>isbn;
    int i=0;
    vector<book>::iterator it;
    while(i<books.allBooks.size()){
        
        if(isbn==books.allBooks[i].ISBN){
            
            books.allBooks.erase(it);
            cout<<"Successfully Deleted\n";
            return;
        }
        i++;
        it++;
    }
    cout<<"Book not found!\n";


}
int book_database::searchBook(){
    cout<<"Enter ISBN\n";
   string isbn;
   getline(cin,isbn);
   getline(cin,isbn);
   int i =0;
   while(i<books.allBooks.size()){
       if(isbn==books.allBooks[i].ISBN)return i;
       i++;

   }
   return -1;
}
void book_database::updatebook(){
    int ind = books.searchBook();
    if(ind==-1){
        cout<<"Book not found";
        return;
    }
    book* to_update;
    to_update= &(books.allBooks[ind]);
   
    
    string title,author,ISBN;
    string pub;
    cout<<"Title of Book: \n";
    getline(cin,title);
    cout<<"Name of Author: \n";
    getline(cin,author);
    cout<<"ISBN: \n";
    getline(cin,ISBN);
    cout<<"Publication: \n";
    getline(cin,pub);
    (*to_update).setTitle(title);
    (*to_update).setAuthor(author);
    (*to_update).setISBN(ISBN);
    (*to_update).setPublication(pub);
    cout<<"Book updated";


}
void book_database::display(){
    int i = 0;
    while(i<books.allBooks.size()){
        cout<<"Title:         "<<allBooks[i].title<<endl;
        cout<<"Author:        "<<allBooks[i].author<<endl;
        cout<<"ISBN:          "<<allBooks[i].ISBN<<endl;
        cout<<"Publication:   "<<allBooks[i].publication<<endl;
        cout<<"\n\n";
        i++;
    }
}

// It will decide the Landing page after login
void welcome(int role){
    system("clear");
    Librarian librarian1;
    Student   student1;
    Professor professor1;
    
    user x;int i=0;
    while(i<users.userList.size()){
        if(LoggedInId==users.userList[i].id)
        x=users.userList[i];
        i++;
    }
    switch(role){
    case 1: 
    librarian1.view();
    break;
    case 2:
    student1.getData();
    student1.view();
    break;
    case 3:
    professor1.getData();
    professor1.view();
    break;
    default: 
     
        role=x.Login();
       
        welcome(role);
    }
}


int main(){
    
    // Data
    create_db();
    system("clear");
    cout<<"\t#######  Library Management System ####### \n";
    cout<<"Press 1 for Login\nPress 2 to quit\n";
    int role;
    user x;
    int z;
    cin>>z;
    system("clear");
    if(z==1) {
        role=x.Login();
        welcome(role);

    }
    else if(z==2){
        return 0;
    }
    
    else cout<<"Invalid request\n";

    
    

    return 0;

}