#ifndef SALESORDER_HPP
#define SALESORDER_HPP
#include <string>
#include <vector>
#include <algorithm>

struct Item {
    std::string itemNumber;
    int quantity;
    double netPrice;
};

class SalesOrder {
private:
    int documentNumber;
    std::string customer;
    std::string date;
    double netValue;
    std::string currency;
    std::vector<Item*> items;

public:
    // Constructor 
    SalesOrder(int docNum, const std::string& customer, const std::string& date, const std::string& currency);

    // Destructor
    ~SalesOrder();

    // Copy constructor
    SalesOrder(const SalesOrder &salesOrder);

    // Assignment operator 
    SalesOrder &operator=(const SalesOrder &salesOrder);


    int getDocumentNumber() const;
    std::string getCustomer() const;
    std::string getDate() const;
    double getNetValue() const;
    std::string getCurrency() const;
    const std::vector<Item*>& getItems() const;

    void setDocumentNumber(int documentNumber);
    void setCustomer(const std::string &customer);
    void setDate(const std::string &date);
    void setNetValue(double netValue);
    void setCurrency(const std::string &currency);
    
    void addItem(const Item &item);
    void deleteItem(const Item &item);
    void displaySalesOrder() const;
};

#endif 
