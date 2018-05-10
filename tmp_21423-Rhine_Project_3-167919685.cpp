#include <iostream>
#include <fstream>
using namespace std;

struct book{
    char title[50];
    char author_name[50];
    string subject;
    int year;

};

//Number of Books in Library
//Because of being sick, I missed the classes relevant to basically this entire code. lol I have no real idea of how to compose a binary search.
void library(char title[50], char author_name[50], int& no_of_books)
{
    ifstream fin;
    fin.open("/Users/kattrhine/Desktop/library.txt");
    if (fin.fail())
        cout<<"Error: There is no library data. Please add books to library database."<<endl;
    book books[100];
    for (int i=0; i<100; i++)
    {
        fin>>books[i].title;
        fin>>books[i].author_name;
        binary_search(books[i].title, books[i].author_name, NULL, true);
        no_of_books=i;
    }
}

//Add Books to Library
void add_books(char title[50], char author_name[50], int& subject_number, string& subject, int& year, int& no_of_books)
{
    ifstream fin ("/Users/kattrhine/Desktop/library.txt");
    ofstream fout ("/Users/kattrhine/Desktop/library.txt");
    book books[100];
    while (1)
    {
        char title[50];
        char author_name[50];
        int subject_number;
        string subject;
        int year;
        int no_of_books;
        library(title,author_name,no_of_books);
        for (int i=no_of_books+1; i<100; i++)
        {
            cout<<"Please enter the information for the book:"<<endl;
            cout<<"Title: ";
            cin>>books[i].title;
            cout<<"Author (Last, First): ";
            cin>>books[i].author_name;
            cout<<"Subject (Select Number): "<<endl;
            cout<<"1: Life Sciences"<<endl;
            cout<<"2: Fiction"<<endl;
            cout<<"3: Physical Sciences"<<endl;
            cout<<"4: Journal"<<endl;
            cout<<"5: Magazine"<<endl;
            cout<<"6: Children's Book"<<endl;
            cin>>subject_number;
            if (subject_number==1)
                books[i].subject="Life Sciences";
            if (subject_number==2)
                books[i].subject="Fiction";
            if (subject_number==3)
                books[i].subject="Physical Sciences";
            if (subject_number==4)
                books[i].subject="Journal";
            if (subject_number==5)
                books[i].subject="Magazine";
            if (subject_number==6)
                books[i].subject="Children's Book";
            while (subject_number>6 || subject_number<1)
            {
                cout<<"Invalid input. Please select the subject number associated with your subject."<<endl;
                cout<<"1: Life Sciences"<<endl;
                cout<<"2: Fiction"<<endl;
                cout<<"3: Physical Sciences"<<endl;
                cout<<"4: Journal"<<endl;
                cout<<"5: Magazine"<<endl;
                cout<<"6: Children's Book"<<endl;
                cin>>subject_number;
            }
            cout<<"Year of publication: ";
            cin>>year;
            cout<<endl<<endl;
            cout<<"Would you like to add another book? Y/N"<<endl;
            char choice;
            cin>>choice;
            while (choice !='N' && choice!='n' && choice!='Y' && choice!='y')
            {
                cout<<"Invalid input. Would you like to add another book? Y/N"<<endl;
                cin>>choice;
            }
            if (choice=='N' || choice=='n')
                library(title,author_name,no_of_books);
                break;
        }
    }
}

//Search for Book in Library
void book_search(char title[50], char author_name[50], string& subject)
{
    book books[100];
    int matching_book[100];
    char available='Y';
    char check_choice;
    ifstream fin;
    fin.open ("/User/kattrhine/Desktop/library.txt");
    for (int i=0; i<101; i++)
    {
        fin.getline(books[i].author_name,50);
        fin.getline(books[i].title,50);
        fin>>books[i].subject;
    }
    int choice;
    char search[50];
    cout<<"Please select a criteria by which to search for books: "<<endl;
    cout<<"1: Book Title"<<endl;
    cout<<"2: Author Name"<<endl;
    cout<<"3: Subject"<<endl;
    cin>>choice;
    if (choice==1)
    {
        cout<<"Enter book title: ";
        cin.getline(search,50);
        cout<<"The following book(s) match your search:"<<endl;
        for (int i=0; i<100; i++)
        {
            binary_search(books[i].title, books[i].title, search, true);
            cout<<books[i].title<<" by "<<books[i].author_name<<endl;
            if (available=='Y')
                cout<<"This book is currently available."<<endl;
            if (available=='N')
                cout<<"This book is currently unavailable."<<endl;
            cout<<"Would you like to check this book out/in? Y/N"<<endl;
            cin>>check_choice;
            while (check_choice!='Y' && check_choice!='y' && check_choice!='N' && check_choice!='n')
            {
                cout<<"Invalid input. Would you like to check this book out/in? Y/N"<<endl;
                cin>>check_choice;
            }
            if (check_choice=='Y' || check_choice=='y')
            {
                if (available='Y')
                {
                    available=='N';
                }
                if (available='N')
                {
                    available=='Y';
                }
            }
        }
    }
    if (choice==2)
    {
        cout<<"Enter author name: ";
        cin.getline(search,50);
        cout<<"The following book(s) match your search:"<<endl;
        for (int i=0; i<100; i++)
        {
            binary_search(books[i].author_name, books[i].author_name, search, true);
            cout<<books[i].title<<" by "<<books[i].author_name<<endl;
            if (available=='Y')
                cout<<"This book is currently available."<<endl;
            if (available=='N')
                cout<<"This book is currently unavailable."<<endl;
            cout<<"Would you like to check this book out/in? Y/N"<<endl;
            cin>>check_choice;
            while (check_choice!='Y' && check_choice!='y' && check_choice!='N' && check_choice!='n')
            {
                cout<<"Invalid input. Would you like to check this book out/in? Y/N"<<endl;
                cin>>check_choice;
            }
            if (check_choice=='Y' || check_choice=='y')
            {
                if (available='Y')
                {
                    available=='N';
                }
                if (available='N')
                {
                    available=='Y';
                }
            }
        }
    }
    if (choice==3)
    {
        cout<<"Enter subject: ";
        cin.getline(search,50);
        cout<<"The following book(s) match your search:"<<endl;
        for (int i=0; i<100; i++)
        {
            binary_search(books[i].subject, books[i].subject,search,true);
            cout<<books[i].title<<" by "<<books[i].author_name<<endl;
            if (available=='Y')
                cout<<"This book is currently available."<<endl;
            if (available=='N')
                cout<<"This book is currently unavailable."<<endl;
            cout<<"Would you like to check this book out/in? Y/N"<<endl;
            cin>>check_choice;
            while (check_choice!='Y' && check_choice!='y' && check_choice!='N' && check_choice!='n')
            {
                cout<<"Invalid input. Would you like to check this book out/in? Y/N"<<endl;
                cin>>check_choice;
            }
            if (check_choice=='Y' || check_choice=='y')
            {
                if (available='Y')
                {
                    available=='N';
                }
                if (available='N')
                {
                    available=='Y';
                }
            }
        }
    }
}

//Delete Books
//I also missed the bit about removing parts of an array. I'm deleting books from the library and tallying a count after the deletion.
void delete_books(char title[50], char author_name[50], string& subject)
{
    book books[100];
    int matching_book[100];
    ifstream fin;
    fin.open ("/User/kattrhine/Desktop/library.txt");
    for (int i=0; i<101; i++)
    {
        fin.getline(books[i].author_name,50);
        fin.getline(books[i].title,50);
        fin>>books[i].subject;
    }
    int choice;
    char search[50];
    cout<<"Please select a criteria by which to search for the book(s) to delete: "<<endl;
    cout<<"1: Book Title"<<endl;
    cout<<"2: Author Name"<<endl;
    cout<<"3: Subject"<<endl;
    cin>>choice;
    if (choice==1)
    {
        cout<<"Enter book title: ";
        cin.getline(search,50);
        cout<<"The following book(s) match your search:"<<endl;
        for (int i=0; i<100; i++)
        {
            char delete_choice;
            binary_search(books[i].title, books[i].title, search, true);
            cout<<books[i].title<<" by "<<books[i].author_name<<endl;
            cout<<"Delete this book? Y/N"<<endl;
            cin>>delete_choice;
            while (delete_choice !='N' && delete_choice!='n' && delete_choice!='Y' && delete_choice!='y')
            {
                cout<<"Invalid input. Would you like to delete this book? Y/N"<<endl;
                cin>>choice;
            }
            if (delete_choice=='Y' || delete_choice=='y')
            {
                for (int j=0; j<50; j++)
                    {
                        remove(books[i].title, books[i].title, 50);
                        remove(books[i].author_name, books[i].author_name, 50);
                        remove(books[i].subject, books[i].subject, 50);
                        remove(books[i].year, books[i].year, 50);
                    }
            }
        }
    }
    if (choice==2)
    {
        char delete_choice;
        cout<<"Enter author name: ";
        cin.getline(search,50);
        cout<<"The following book(s) match your search:"<<endl;
        for (int i=0; i<100; i++)
        {
            binary_search(books[i].author_name, books[i].author_name, search, true);
            cout<<books[i].title<<" by "<<books[i].author_name<<endl;
            cout<<"Delete this book? Y/N"<<endl;
            cin>>delete_choice;
            while (delete_choice !='N' && delete_choice!='n' && delete_choice!='Y' && delete_choice!='y')
            {
                cout<<"Invalid input. Would you like to delete this book? Y/N"<<endl;
                cin>>choice;
            }
            if (delete_choice=='Y' || delete_choice=='y')
            {
                for (int j=0; j<50; j++)
                {
                    remove(books[i].title, books[i].title, 50);
                    remove(books[i].author_name, books[i].author_name, 50);
                    remove(books[i].subject, books[i].subject, 50);
                    remove(books[i].year, books[i].year, 50);
                }
            }
        }
    }
    if (choice==3)
    {
        char delete_choice;
        cout<<"Enter subject: ";
        cin.getline(search,50);
        cout<<"The following book(s) match your search:"<<endl;
        for (int i=0; i<100; i++)
        {
            binary_search(books[i].subject, books[i].subject,search,true);
            cout<<books[i].title<<" by "<<books[i].author_name<<endl;
            cout<<"Delete this book? Y/N"<<endl;
            cin>>delete_choice;
            while (delete_choice !='N' && delete_choice!='n' && delete_choice!='Y' && delete_choice!='y')
            {
                cout<<"Invalid input. Would you like to delete this book? Y/N"<<endl;
                cin>>choice;
            }
            if (delete_choice=='Y' || delete_choice=='y')
            {
                for (int j=0; j<50; j++)
                {
                    remove(books[i].title, books[i].title, 50);
                    remove(books[i].author_name, books[i].author_name, 50);
                    remove(books[i].subject, books[i].subject, 50);
                    remove(books[i].year, books[i].year, 50);
                }
            }
        }
    }
}

//Modify Books
void modify_books(char title[50], char author_name[50], string& subject)
{
    int no_of_books;
    book books[100];
    ifstream fin;
    ofstream fout;
    fin.open ("/User/kattrhine/Desktop/library.txt");
    for (int i=0; i<101; i++)
    {
        fin.getline(books[i].author_name,50);
        fin.getline(books[i].title,50);
        fin>>books[i].subject;
    }
    int choice;
    char search[50];
    cout<<"Please select a criteria by which to search for the book(s) to modify: "<<endl;
    cout<<"1: Book Title"<<endl;
    cout<<"2: Author Name"<<endl;
    cout<<"3: Subject"<<endl;
    cin>>choice;
    if (choice==1)
    {
        cout<<"Enter book title: ";
        cin.getline(search,50);
        cout<<"The following book(s) match your search:"<<endl;
        for (int i=0; i<100; i++)
        {
            char modify_choice;
            binary_search(books[i].title, books[i].title, search, true);
            cout<<books[i].title<<" by "<<books[i].author_name<<endl;
            cout<<"Modify this book? Y/N"<<endl;
            cin>>modify_choice;
            while (modify_choice !='N' && modify_choice!='n' && modify_choice!='Y' && modify_choice!='y')
            {
                cout<<"Invalid input. Would you like to delete this book? Y/N"<<endl;
                cin>>choice;
            }
            if (modify_choice=='Y' || modify_choice=='y')
            {
                fout.write(books[i].title, 50);
                fout.write(books[i].author_name, 50);
                fout<<books[i].subject;
                fout<<books[i].year;
                
            }
        }
    }
    if (choice==2)
    {
        char modify_choice;
        cout<<"Enter author name: ";
        cin.getline(search,50);
        cout<<"The following book(s) match your search:"<<endl;
        for (int i=0; i<100; i++)
        {
            binary_search(books[i].author_name, books[i].author_name, search, true);
            cout<<books[i].title<<" by "<<books[i].author_name<<endl;
            cout<<"Modify this book? Y/N"<<endl;
            cin>>modify_choice;
            while (modify_choice !='N' && modify_choice!='n' && modify_choice!='Y' && modify_choice!='y')
            {
                cout<<"Invalid input. Would you like to delete this book? Y/N"<<endl;
                cin>>choice;
            }
            if (modify_choice=='Y' || modify_choice=='y')
            {

            }
        }
    }
    if (choice==3)
    {
        char modify_choice;
        cout<<"Enter subject: ";
        cin.getline(search,50);
        cout<<"The following book(s) match your search:"<<endl;
        for (int i=0; i<100; i++)
        {
            binary_search(books[i].subject, books[i].subject,search,true);
            cout<<books[i].title<<" by "<<books[i].author_name<<endl;
            cout<<"Modify this book? Y/N"<<endl;
            cin>>modify_choice;
            while (modify_choice !='N' && modify_choice!='n' && modify_choice!='Y' && modify_choice!='y')
            {
                cout<<"Invalid input. Would you like to delete this book? Y/N"<<endl;
                cin>>choice;
            }
            if (modify_choice=='Y' || modify_choice=='y')
            {

            }
        }
    }
    library(title,author_name,no_of_books);
}

int main ()
{
    ifstream fin ("/Users/kattrhine/Desktop/library.txt");
    ofstream fout ("/Users/kattrhine/Desktop/library.txt");
    while (1)
    {
        book books[100];
        char title[50];
        char author_name[50];
        int subject_number;
        string subject;
        int year;
        int no_of_books;
        int task;
        cout<<"Which task would you like to perform?"<<endl;
        cout<<"1: Add a book or books."<<endl;
        cout<<"2: Search for a book."<<endl;
        cout<<"3: Modify book information."<<endl;
        cout<<"4: Delete a book from library database."<<endl;
        cout<<"5: Save changes and close."<<endl;
        if (task==1)
            add_books(title,author_name,subject_number,subject,year,no_of_books);
        if (task==2)
            book_search(title, author_name, subject);
        if (task==3)
        if (task==4)
            delete_books(title, author_name, subject);
        if (task==5)
            cout<<"Thank you. Goodbye."<<endl;
            fout.close();
        return 0;
    }
}
