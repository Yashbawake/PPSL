/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<iostream>
#include<fstream>
using namespace std;

struct Employee{
    char name[50];
    int id;
    float salary;
};

//Function to write employee data
void writeToFile(const Employee& employee){
    ofstream outFile("employee.dat",ios::binary);
    
    if(!outFile){
        cerr<<"Error!Could not open the file for writing"<<endl;
        return;
    }
    
    //Write the structure to binary file
    outFile.write(reinterpret_cast<const char*>(&employee),sizeof(employee));
    
    outFile.close();
    
    cout<<"Employee data written to file successfully"<<endl;
}

//Function to read employee data from the file
void readFromFile(){
    Employee employee;
    
    ifstream inFile("employee.dat", ios::binary);
    if(!inFile){
        cerr<<"Error! could not open file for reading!"<<endl;
        return ;
    }
    
    //Read structure from the file
    inFile.read(reinterpret_cast<char*>(&employee),sizeof(employee));
    
    if(inFile){
        cout<<"\nEmployee data read from binary file:"<<endl;
        cout<<"Name:"<<employee.name<<endl;
        cout<<"Id:"<<employee.id<<endl;
        cout<<"Salary:"<<employee.salary<<endl;
    }else{
        cerr<<"Error!could not read data from the binary file"<<endl;
    }
    
    inFile.close();
}

int main(){
    Employee employee;
    
    //Input employee details
    cout<<"Enter Employee details"<<endl;
    cout<<"Name:";
    cin.ignore();
    cin.getline(employee.name,50);
    cout<<"ID:";
    cin>>employee.id;
    cout<<"Salary:";
    cin>>employee.salary;
    
    //Write employee data to binary file;
    writeToFile(employee);
    
    //Read employee data from binary file
    readFromFile();
    
    return 0;
}