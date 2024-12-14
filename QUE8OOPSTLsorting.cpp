#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Define the Item structure
struct Item {
    int itemCode;
    string name;
    float cost;
    int quantity;

    // Constructor for easy initialization
    Item(int code, string n, float c, int q) : itemCode(code), name(n), cost(c), quantity(q) {}
};

// Function to print the item record
void printItem(const Item &item) {
    cout << "Item Code: " << item.itemCode << ", Name: " << item.name
         << ", Cost: " << item.cost << ", Quantity: " << item.quantity << endl;
}

// Function to search an item by its code
Item* searchItem(vector<Item>& items, int itemCode) {
    auto it = find_if(items.begin(), items.end(), [itemCode](const Item& item) {
        return item.itemCode == itemCode;
    });

    if (it != items.end()) {
        return &(*it); // Item found
    } else {
        return nullptr; // Item not found
    }
}

int main() {
    // Create a vector of Item objects
    vector<Item> items;
    items.push_back(Item(101, "Laptop", 800.50, 10));
    items.push_back(Item(102, "Mouse", 20.75, 50));
    items.push_back(Item(103, "Keyboard", 50.99, 30));
    items.push_back(Item(104, "Monitor", 250.30, 15));

    // Sort items by itemCode
    sort(items.begin(), items.end(), [](const Item &a, const Item &b) {
        return a.itemCode < b.itemCode;
    });

    cout << "Sorted Item Records by Item Code:" << endl;
    for (const auto &item : items) {
        printItem(item);
    }

    // Searching for an item
    int searchCode = 103; // For example, we search for the item with code 103
    Item* foundItem = searchItem(items, searchCode);

    if (foundItem) {
        cout << "\nFound Item:" << endl;
        printItem(*foundItem);
    } else {
        cout << "\nItem not found!" << endl;
    }

    return 0;
}

