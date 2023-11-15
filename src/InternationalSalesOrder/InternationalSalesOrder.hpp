#ifndef INTERNATIONALSALESORDER_HPP
#define INTERNATIONALSALESORDER_HPP

#include <string>
#include <vector>
#include <algorithm>
#include "Order.hpp"
using namespace OrderNamespace;

namespace InternationalSalesOrderNamespace {

    class InternationalSalesOrder : public Order {
    private:
        int documentNumber;
        std::string customer;
        std::string date;
        double netValue;
        std::string currency;
        std::vector<std::shared_ptr<Item>> items;
        std::string countryOfOrigin;
        int shippingPrice;

    public:
        InternationalSalesOrder(int documentNumber, const std::string &customer, const std::string &date, const std::string &currency, const std::string &countryOfOrigin, int shippingPrice);
        ~InternationalSalesOrder();

        InternationalSalesOrder(const InternationalSalesOrder &internationalSalesOrder);
        InternationalSalesOrder(InternationalSalesOrder &&internationalSalesOrder);
        InternationalSalesOrder& operator=(const InternationalSalesOrder &internationalSalesOrder);

        int getDocumentNumber() const;
        std::string getCustomer() const;
        std::string getDate() const;
        double getNetValue() const;
        std::string getCurrency() const;
        const std::vector<std::shared_ptr<Item>>& getItems() const;
        std::string getCountryOfOrigin() const;
        int getShippingPrice() const;

        void setDocumentNumber(int documentNumber);
        void setCustomer(const std::string &customer);
        void setDate(const std::string &date);
        void setCurrency(const std::string &currency);
        void setItems(const std::vector<std::shared_ptr<Item>> &items);
        void setCountryOfOrigin(const std::string &countryOfOrigin);
        void setShippingPrice(const int shippingPrice);

        void addItem(const Item &item) override;
        void deleteItem(const Item &item) override;
        void displayOrder() const override;
    };

};
#endif

