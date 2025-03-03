#include "ProductList.h"

ProductList::~ProductList() {
    while (head) {
        Product* temp = head;
        head = head->next;
        delete temp;
    }
}

void ProductList::addProduct(string name, double price, int quantity) {
    Product* newProduct = new Product(name, price, quantity);
    if (!head) {
        head = newProduct;
    }
    else {
        Product* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newProduct;
    }
}

void ProductList::displayProducts() const {
    Product* temp = head;
    while (temp) {
        cout << "Name: " << temp->name << ", Price: " << temp->price << ", Quantity: " << temp->quantity << endl;
        temp = temp->next;
    }
}

ProductList* ProductList::copyList() const {
    ProductList* newList = new ProductList();
    Product* temp = head;
    while (temp) {
        newList->addProduct(temp->name, temp->price, temp->quantity);
        temp = temp->next;
    }
    return newList;
}

void ProductList::deleteProduct(string name) {
    Product* temp = head, * prev = nullptr;
    while (temp && temp->name != name) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) return;
    if (!prev) head = temp->next;
    else prev->next = temp->next;
    delete temp;
}

Product* ProductList::searchProduct(string name) const {
    Product* temp = head;
    while (temp) {
        if (temp->name == name) return temp;
        temp = temp->next;
    }
    return nullptr;
}

void ProductList::updateQuantity(string name, int newQuantity) {
    Product* product = searchProduct(name);
    if (product) product->quantity = newQuantity;
}

void ProductList::sortByName() {
    if (!head || !head->next) return;
    bool swapped;
    do {
        swapped = false;
        Product* temp = head;
        while (temp->next) {
            if (temp->name > temp->next->name) {
                swap(temp->name, temp->next->name);
                swap(temp->price, temp->next->price);
                swap(temp->quantity, temp->next->quantity);
                swapped = true;
            }
            temp = temp->next;
        }
    } while (swapped);
}

void ProductList::sortByPrice() {
    if (!head || !head->next) return;
    bool swapped;
    do {
        swapped = false;
        Product* temp = head;
        while (temp->next) {
            if (temp->price > temp->next->price) {
                swap(temp->name, temp->next->name);
                swap(temp->price, temp->next->price);
                swap(temp->quantity, temp->next->quantity);
                swapped = true;
            }
            temp = temp->next;
        }
    } while (swapped);
}
