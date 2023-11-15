#ifndef SALESORDER_HPP
#define SALESORDER_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <functional>

#include "Order.hpp"
using namespace OrderNamespace;


namespace SalesOrderNamespace {

    class SalesOrder : public Order {
    private:
        int documentNumber;
        std::string customer;
        std::string date;
        double netValue;
        std::string currency;
        std::vector<std::shared_ptr<Item>> items;

    public:
        // Constructor 
        SalesOrder(int docNum, const std::string& customer, const std::string& date, const std::string& currency);
        // Destructor
        ~SalesOrder();
        // Copy constructor
        SalesOrder(const SalesOrder &salesOrder);
        // Move constructor
        SalesOrder(SalesOrder &&salesOrder);
        // Assignment operator 
        SalesOrder &operator=(const SalesOrder &salesOrder);
        // Getters
        int getDocumentNumber() const;
        std::string getCustomer() const;
        std::string getDate() const;
        double getNetValue() const;
        std::string getCurrency() const;
        const std::vector<std::shared_ptr<Item>>& getItems() const;
        // Setters
        void setDocumentNumber(int documentNumber);
        void setCustomer(const std::string &customer);
        void setDate(const std::string &date);
        void setCurrency(const std::string &currency);
        void setItems(const std::vector<std::shared_ptr<Item>> &items);
        
        void addItem(const Item &item) override;
        void deleteItem(const Item &item) override;
        void displayOrder() const override;
    };

};
#endif 

