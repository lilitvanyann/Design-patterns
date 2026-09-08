#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    string name;

    Employee(string name) {
        this->name = name;
    }

    void work() {
        cout << name << " is working..." << endl;
    }

    void calculateSalary() {
        cout << "Calculating salary..." << endl;
    }

    void saveToDatabase() {
        cout << "Saving employee to database..." << endl;
    }

    void sendEmail() {
        cout << "Sending email to " << name << endl;
    }

    void generateReport() {
        cout << "Generating employee report..." << endl;
    }
};

int main() {
    Employee employee("Lilit");

    employee.work();
    employee.calculateSalary();
    employee.saveToDatabase();
    employee.sendEmail();
    employee.generateReport();

    return 0;
}
