
#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    void input() {
        cout << "Enter Title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter Price: ";
        cin >> price;
    }

    void display() const {
        cout << "Title: " << title << "\nPrice: " << price << endl;
    }
};

class Book : public Publication {
    int pageCount;

public:
    void input() {
        Publication::input();
        cout << "Enter Page Count: ";
        cin >> pageCount;
    }

    void display() const {
        Publication::display();
        cout << "Page Count: " << pageCount << endl;
    }
};

class Tape : public Publication {
    float playTime;

public:
    void input() {
        Publication::input();
        cout << "Enter Playing Time (in minutes): ";
        cin >> playTime;
    }

    void display() const {
        Publication::display();
        cout << "Playing Time: " << playTime << " minutes" << endl;
    }
};

int main() {
    Book b;
    Tape t;

    cout << "Enter details for Book:\n";
    b.input();
    cout << "\nEnter details for Tape:\n";
    t.input();

    cout << "\n--- Book Details ---\n";
    b.display();
    cout << "\n--- Tape Details ---\n";
    t.display();

    return 0;
}
