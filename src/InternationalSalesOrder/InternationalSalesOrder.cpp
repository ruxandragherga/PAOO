#include <iostream>
#include "InternationalSalesOrder.hpp"
using namespace InternationalSalesOrderNamespace;
using namespace OrderNamespace;

// Constructor
InternationalSalesOrder::InternationalSalesOrder(int documentNumber, const std::string& customer, const std::string& date, const std::string& currency, const std::string& countryOfOrigin, int shippingPrice)
    : documentNumber(documentNumber), customer(customer), date(date), currency(currency), countryOfOrigin(countryOfOrigin), shippingPrice(shippingPrice) {
    std::cout << "\nInternationalSalesOrder Constructor called." << std::endl;
}

// Destructor
InternationalSalesOrder::~InternationalSalesOrder() {
    std::cout << "\nInternationalSalesOrder Destructor called." << std::endl;
}

// Copy constructor
InternationalSalesOrder::InternationalSalesOrder(const InternationalSalesOrder& internationalSalesOrder)
    : documentNumber(internationalSalesOrder.documentNumber),
      customer(internationalSalesOrder.customer),
      date(internationalSalesOrder.date),
      netValue(internationalSalesOrder.netValue),
      currency(internationalSalesOrder.currency),
      countryOfOrigin(internationalSalesOrder.countryOfOrigin),
      shippingPrice(internationalSalesOrder.shippingPrice) {
    std::cout << "\nInternationalSalesOrder Copy Constructor called." << std::endl;
    
    for (const auto& item : internationalSalesOrder.items) {
        items.push_back(std::make_shared<Item>(*item));
    }
}


// Copy assignment operator
InternationalSalesOrder& InternationalSalesOrder::operator=(const InternationalSalesOrder& internationalSalesOrder) {
    std::cout << "\nInternationalSalesOrder Assignment Operator called." << std::endl;

    if (this != &internationalSalesOrder) {
        this->documentNumber = internationalSalesOrder.documentNumber;
        this->customer = internationalSalesOrder.customer;
        this->date = internationalSalesOrder.date;
        this->netValue = internationalSalesOrder.netValue;
        this->currency = internationalSalesOrder.currency;
        this->countryOfOrigin = internationalSalesOrder.countryOfOrigin;
        this->shippingPrice = internationalSalesOrder.shippingPrice;

        for (const auto& item : internationalSalesOrder.items) {
            items.push_back(std::make_shared<Item>(*item)); 
        }
    }

    return *this;
}

// Getter methods
int InternationalSalesOrder::getDocumentNumber() const { return documentNumber; }
std::string InternationalSalesOrder::getCustomer() const { return customer; }
std::string InternationalSalesOrder::getDate() const { return date; }
double InternationalSalesOrder::getNetValue() const { return netValue; }
std::string InternationalSalesOrder::getCurrency() const { return currency; }
const std::vector<std::shared_ptr<Item>>& InternationalSalesOrder::getItems() const { return items; }
std::string InternationalSalesOrder::getCountryOfOrigin() const { return countryOfOrigin; }
int InternationalSalesOrder::getShippingPrice() const { return shippingPrice; }

// Setter methods
void InternationalSalesOrder::setDocumentNumber(int newDocumentNumber) { documentNumber = newDocumentNumber; }
void InternationalSalesOrder::setCustomer(const std::string& newCustomer) { customer = newCustomer; }
void InternationalSalesOrder::setDate(const std::string& newDate) { date = newDate; }
void InternationalSalesOrder::setCurrency(const std::string& newCurrency) { currency = newCurrency; }
void InternationalSalesOrder::setItems(const std::vector<std::shared_ptr<Item>>& newItems) { items = newItems; }
void InternationalSalesOrder::setCountryOfOrigin(const std::string& newCountryOfOrigin) { countryOfOrigin = newCountryOfOrigin; }
void InternationalSalesOrder::setShippingPrice(int newShippingPrice) { shippingPrice = newShippingPrice; }


void InternationalSalesOrder::addItem(const Item& item) {
    if (this->items.empty()) netValue = shippingPrice;
    std::shared_ptr<Item> newItem = std::make_shared<Item>(item);
    items.push_back(newItem);
    netValue += item.quantity * item.netPrice;
}

void InternationalSalesOrder::deleteItem(const Item& item) {
    auto it = std::remove_if(items.begin(), items.end(),
        [&item](const std::shared_ptr<Item>& currentItem) {
            return currentItem->itemNumber == item.itemNumber;
        });

    if (it != items.end()) {
        netValue -= (*it)->quantity * (*it)->netPrice;
        items.erase(it);
    }
    if (this->items.empty()) netValue = 0;
}

void InternationalSalesOrder::displayOrder() const {
    std::cout << "Document Number:      " << documentNumber << std::endl;
    std::cout << "Customer:             " << customer << std::endl;
    std::cout << "Date:                 " << date << std::endl;
    std::cout << "Net Value:            " << netValue << std::endl;
    std::cout << "Currency:             " << currency << std::endl;
    std::cout << "Country of Origin: " << countryOfOrigin << std::endl;
    std::cout << "Shipping Price: " << shippingPrice << std::endl;
    std::cout << "Items:" << std::endl;
    for (const auto& item : items) {
        std::cout << "  Item Number: " << item->itemNumber << std::endl;
        std::cout << "  Quantity:    " << item->quantity << std::endl;
        std::cout << "  Net Price:   " << item->netPrice << std::endl;
    }
}
