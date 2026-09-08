#include <iostream>
#include <string>
using namespace std;

class Employee 
{
    public:
        string name;
    
        Employee(string name) {
            this->name = name;
        }
    
        void work() {
            cout << name << " is working..." << endl;
        }
};

class Salary
{
   public:
    void calculateSalary() {
        cout << "Calculating salary..." << endl;
    }
};

class Database
{
   public:
    void saveToDatabase() {
        cout << "Saving employee to database..." << endl;
    }
};

class Email
{
   public:
    void sendEmail(string name) {
        cout << "Sending email to " << name << endl;
    }
};

class Generate
{
   public:
    void generateReport() {
        cout << "Generating employee report..." << endl;
    }
};

int main() {
    Employee employee("Lilit");
    Salary salary;
    Database database;
    Email email;
    Generate generate;

    employee.work();
    salary.calculateSalary();
    database.saveToDatabase();
    email.sendEmail(employee.name);
    generate.generateReport();

    return 0;
}
