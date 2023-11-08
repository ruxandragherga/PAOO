#ifndef INTERNATIONALSALESORDER_HPP
#define INTERNATIONALSALESORDER_HPP

#include "SalesOrder.hpp"
using namespace SalesOrderNamespace;

    namespace InternationalSalesOrderNamespace {

    class InternationalSalesOrder : public SalesOrder {
    private:
        std::string countryOfOrigin;

    public:
        InternationalSalesOrder(int documentNumber, const std::string &customer, const std::string &date, const std::string &currency, const std::string &countryOfOrigin);
        ~InternationalSalesOrder();

        InternationalSalesOrder(const InternationalSalesOrder &internationalSalesOrder);
        InternationalSalesOrder(InternationalSalesOrder &&internationalSalesOrder);
        InternationalSalesOrder& operator=(const InternationalSalesOrder &internationalSalesOrder);

        std::string getCountryOfOrigin() const;
        void setCountryOfOrigin(const std::string &countryOfOrigin);

        void displayOrder() const;
    };

};
#endif

