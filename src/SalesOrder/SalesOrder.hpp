#ifndef SALESORDER_HPP
#define SALESORDER_HPP

#include <string>
#include <vector>
#include <algorithm>

#include "Order.hpp"
using namespace OrderNamespace;


namespace SalesOrderNamespace {

    class SalesOrder : public Order {
    protected:
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

        // Move constructor
        SalesOrder(SalesOrder &&salesOrder);

        // Assignment operator 
        SalesOrder &operator=(const SalesOrder &salesOrder);


        int getDocumentNumber() const override;
        std::string getCustomer() const override;
        std::string getDate() const override;
        double getNetValue() const override;
        std::string getCurrency() const override;
        const std::vector<Item*>& getItems() const override;

        void setDocumentNumber(int documentNumber) override;
        void setCustomer(const std::string &customer) override;
        void setDate(const std::string &date) override;
        void setNetValue(double netValue) override;
        void setCurrency(const std::string &currency) override;
        void setItems(const std::vector<Item*> &items) override;
        
        void addItem(const Item &item) override;
        void deleteItem(const Item &item) override;
        void displayOrder() const override;
    };

};
#endif 

