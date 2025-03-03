#include "ProductList.h"

int main() {
    ProductList productList;
    productList.addProduct("Laptop", 1200.50, 5);
    productList.addProduct("Phone", 699.99, 10);
    productList.addProduct("Tablet", 300.00, 7);

    cout << "Product List:\n";
    productList.displayProducts();

    cout << "\nSorting by Price:\n";
    productList.sortByPrice();
    productList.displayProducts();

    cout << "\nUpdating quantity of Phone:\n";
    productList.updateQuantity("Phone", 15);
    productList.displayProducts();

    cout << "\nDeleting Laptop:\n";
    productList.deleteProduct("Laptop");
    productList.displayProducts();

    return 0;
}
