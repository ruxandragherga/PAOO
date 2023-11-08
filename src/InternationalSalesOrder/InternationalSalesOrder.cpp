#include <iostream>
#include "InternationalSalesOrder.hpp"
using namespace InternationalSalesOrderNamespace;

InternationalSalesOrder::InternationalSalesOrder(int documentNumber, const std::string &customer, const std::string &date, const std::string &currency, const std::string &countryOfOrigin)
    : SalesOrder(documentNumber, customer, date, currency), countryOfOrigin(countryOfOrigin) {
    std::cout << "\nInternationalSalesOrder Constructor called." << std::endl;
}

InternationalSalesOrder::~InternationalSalesOrder() {
    std::cout << "\nInternationalSalesOrder Destructor called." << std::endl;
}

InternationalSalesOrder::InternationalSalesOrder(const InternationalSalesOrder &internationalSalesOrder)
    : SalesOrder(internationalSalesOrder), countryOfOrigin(internationalSalesOrder.countryOfOrigin) {
    std::cout << "\nInternationalSalesOrder Copy Constructor called." << std::endl;
}

InternationalSalesOrder::InternationalSalesOrder(InternationalSalesOrder &&internationalSalesOrder)
    : SalesOrder(std::move(internationalSalesOrder)), countryOfOrigin(std::move(internationalSalesOrder.countryOfOrigin)) {
    std::cout << "\nInternationalSalesOrder Move Constructor called." << std::endl;
}

InternationalSalesOrder& InternationalSalesOrder::operator=(const InternationalSalesOrder &internationalSalesOrder) {
    std::cout << "\nInternationalSalesOrder Assignment Operator called." << std::endl;

    if (this != &internationalSalesOrder) {
        SalesOrder::operator=(internationalSalesOrder);
        this->countryOfOrigin = internationalSalesOrder.countryOfOrigin;
    }

    return *this;
}

std::string InternationalSalesOrder::getCountryOfOrigin() const {
    return countryOfOrigin;
}

void InternationalSalesOrder::setCountryOfOrigin(const std::string &countryOfOrigin) {
    this->countryOfOrigin = countryOfOrigin;
}

void InternationalSalesOrder::displayOrder() const {
    SalesOrder::displayOrder();
    std::cout << "Country of Origin:    " << countryOfOrigin << std::endl;
}

