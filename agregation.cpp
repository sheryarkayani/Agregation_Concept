#include<iostream>
#include <cstring> // Include <cstring> for strlen and strcpy
using namespace std;


class Employee {
public:
char* name;

Employee (const char* name) {  //constructor

this->name = new char[strlen(name) + 1];

strcpy(this->name, name);

}

//member function
char* displayName() {
    return this->name;
}


~Employee() { 

cout<< "employee class is destroyed"<<endl;
}


};


class Company {

public:
char* name;
Employee* emp; //creaing employee object in company class

//here we create object outside the constructor

//and pass the obj refrence to the constructor

Company (const char* compyName , Employee* emp)
{

    name = new char[strlen(compyName) + 1];
    strcpy(name, compyName);

//we creating relationship here by passing refrence to pointer here
    this->emp = emp;

}

~Company ()
{

    cout<<"Company class is destroyed"<<endl;
}
};


int main()
{
        //we are using scopes here
    {

         cout<<"Suppose employee ahmed works at google"<<endl;
        Employee emp ("Ahmed");

        {
            Company compy ("Google" , &emp); //here we are passing emp reference

        } //here company is deleted but emp is still there


cout<<"at this point company gets deleted but employee" <<emp.displayName()<<"is still there"<<endl;


    } //here employee obj will be deleted
   





 return 0;
}