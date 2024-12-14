#include <iostream>
#include <string>
using namespace std;

class Student {
    string name, className, division, dob, bloodGroup, address, license;
    long long phone;
    int rollNo;

public:
    static int count;

    Student() : name(""), className(""), division(""), dob(""), bloodGroup(""), address(""), license(""), phone(0), rollNo(0) {
        count++;
    }

    Student(const string &n, int roll, const string &cls, const string &div, const string &d, const string &bg, const string &addr, long long ph, const string &lic)
        : name(n), rollNo(roll), className(cls), division(div), dob(d), bloodGroup(bg), address(addr), phone(ph), license(lic) {
        count++;
    }

    Student(const Student &s) {
        name = s.name;
        rollNo = s.rollNo;
        className = s.className;
        division = s.division;
        dob = s.dob;
        bloodGroup = s.bloodGroup;
        address = s.address;
        phone = s.phone;
        license = s.license;
        count++;
    }

    ~Student() {
        count--;
    }

    void input() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Class: ";
        cin >> className;
        cout << "Enter Division: ";
        cin >> division;
        cout << "Enter DOB (dd/mm/yyyy): ";
        cin >> dob;
        cout << "Enter Blood Group: ";
        cin >> bloodGroup;
        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, address);
        cout << "Enter Phone: ";
        cin >> phone;
        cout << "Enter License No: ";
        cin >> license;
    }

    void display() const {
        cout << "Name: " << name << "\nRoll No: " << rollNo << "\nClass: " << className << "\nDivision: " << division
             << "\nDOB: " << dob << "\nBlood Group: " << bloodGroup << "\nAddress: " << address << "\nPhone: " << phone
             << "\nLicense No: " << license << endl;
    }

    static void showCount() {
        cout << "Total Students: " << count << endl;
    }

    friend class Admin;
};

int Student::count = 0;

class Admin {
public:
    void updatePhone(Student &s, long long newPhone) {
        s.phone = newPhone;
    }
};

int main() {
    try {
        Student *s1 = new Student;
        s1->input();

        Student s2("John", 2, "10th", "A", "01/01/2005", "O+", "123 Main St", 9876543210, "DL12345");
        Student s3(s2);

        cout << "\n--- Student 1 ---\n";
        s1->display();
        cout << "\n--- Student 2 ---\n";
        s2.display();
        cout << "\n--- Student 3 (Copied from Student 2) ---\n";
        s3.display();

        Student::showCount();

        Admin admin;
        admin.updatePhone(s2, 1234567890);
        cout << "\n--- Updated Student 2 Phone ---\n";
        s2.display();

        delete s1;

        if (Student::count <= 0) {
            throw runtime_error("No students remaining!");
        }

        Student::showCount();

    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}


