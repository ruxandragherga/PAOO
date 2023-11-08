#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>
#include <vector>

namespace OrderNamespace {

    struct Item {
        std::string itemNumber;
        int quantity;
        double netPrice;
    };

    // Pure abstract class 
    class Order {
    public:

        virtual int getDocumentNumber() const = 0;
        virtual std::string getCustomer() const = 0;
        virtual std::string getDate() const = 0;
        virtual double getNetValue() const = 0;
        virtual std::string getCurrency() const = 0;
        virtual const std::vector<Item*>& getItems() const = 0;

        virtual void setDocumentNumber(int documentNumber) = 0;
        virtual void setCustomer(const std::string &customer) = 0;
        virtual void setDate(const std::string &date) = 0;
        virtual void setNetValue(double netValue) = 0;
        virtual void setCurrency(const std::string &currency) = 0;
        virtual void setItems(const std::vector <Item*> &items) = 0;

        virtual void addItem(const Item &item) = 0;
        virtual void deleteItem(const Item &item) = 0;
        virtual void displayOrder() const = 0;
    };

};
#endif

