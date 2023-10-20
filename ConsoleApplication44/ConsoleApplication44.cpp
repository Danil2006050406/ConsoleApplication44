#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>
using namespace std;

class Product {
public:
    string name;
    double price;

    Product(const string& n, double p) : name(n), price(p) {}
};

class ProductsCollection {
private:
    vector<Product> products;

public:
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    void exportToCsv(const string& filename) {
        ofstream file(filename);
        file << "Product Name,Price" << endl;
        for (const Product& product : products) {
            file << product.name << "," << product.price << endl;
        }
        file.close();
    }
};

class CsvExporterAdapter {
private:
    ProductsCollection& productsCollection;

public:
    CsvExporterAdapter(ProductsCollection& pc) : productsCollection(pc) {}

    void exportToCsv(const string& filename) {
        productsCollection.exportToCsv(filename);
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ProductsCollection productCollection;

    Product product1("Продукт 1", 10.0);
    Product product2("Продукт 2", 15.0);

    productCollection.addProduct(product1);
    productCollection.addProduct(product2);

    CsvExporterAdapter csvExporter(productCollection);
    csvExporter.exportToCsv("products.csv");

    return 0;
}
