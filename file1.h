#ifndef CARTSYSTEM_H
#define CARTSYSTEM_H

#include <string>
#include <vector>
using namespace std;

// Forward declarations
class Product;
class User;
class CartItem;
class Cart;
class Payment;
class Order;

// =========================
// Class: Product
// =========================
class Product {
private:
    int productId;
    string name;
    double price;
    int stock;

public:
    Product(int id, const string& name, double price, int stock);
    int getProductId() const;
    string getName() const;
    double getPrice() const;
    int getStock() const;
    void setStock(int newStock);
};

// =========================
// Class: User
// =========================
class User {
private:
    int userId;
    string username;
    string email;

public:
    User(int id, const string& username, const string& email);
    int getUserId() const;
    string getUsername() const;
    string getEmail() const;
};

// =========================
// Class: CartItem
// =========================
class CartItem {
private:
    Product* product;
    int quantity;

public:
    CartItem(Product* product, int quantity);
    Product* getProduct() const;
    int getQuantity() const;
    void setQuantity(int quantity);
};

// =========================
// Class: Cart
// =========================
class Cart {
private:
    User* user;
    vector<CartItem> items;

public:
    Cart(User* user);
    void addItem(Product* product, int quantity);
    void removeItem(int productId);
    double calculateTotal() const;
    vector<CartItem> getItems() const;
};

// =========================
// Class: Payment
// =========================
class Payment {
private:
    int paymentId;
    double amount;
    string method;

public:
    Payment(int id, double amount, const string& method);
    int getPaymentId() const;
    double getAmount() const;
    string getMethod() const;
    bool processPayment();
};

// =========================
// Class: Order
// =========================
class Order {
private:
    int orderId;
    User* user;
    vector<CartItem> items;
    double totalAmount;
    Payment* payment;

public:
    Order(int id, User* user, const vector<CartItem>& items, Payment* payment);
    int getOrderId() const;
    double getTotalAmount() const;
    void printOrderSummary() const;
};

#endif // CARTSYSTEM_H
