#include <iostream>
#include "SalesOrder.hpp"
using namespace SalesOrderNamespace;
using namespace OrderNamespace;

// SalesOrder constructor
SalesOrder::SalesOrder(int documentNumber, const std::string &customer, const std::string &date, const std::string &currency) {
    std::cout << "\nSalesOrder Constructor called." << std::endl;

    this->documentNumber = documentNumber;
    this->customer = customer;
    this->date = date;
    this->netValue = 0;
    this->currency = currency;
    this->items = std::vector<std::shared_ptr<Item>>();
}

// SalesOrder destructor
SalesOrder::~SalesOrder() {
    std::cout << "\nSalesOrder Destructor called." << std::endl;
}

// SalesOrder copy constructor
SalesOrder::SalesOrder(const SalesOrder &salesOrder) {
    std::cout << "\nSalesOrder Copy Constructor called." << std::endl;

    this->documentNumber = salesOrder.documentNumber;
    this->customer = salesOrder.customer;
    this->date = salesOrder.date;
    this->netValue = salesOrder.netValue;
    this->currency = salesOrder.currency;
     
    for (const auto& item : salesOrder.items) {
        items.push_back(std::make_shared<Item>(*item));
    }
}

// SalesOrder move constructor
SalesOrder::SalesOrder(SalesOrder &&salesOrder) {
    std::cout << "\nSalesOrder Move Constructor called." << std::endl;

    this->documentNumber = salesOrder.documentNumber;
    this->customer = std::move(salesOrder.customer);
    this->date = std::move(salesOrder.date);
    this->netValue = salesOrder.netValue;
    this->currency = std::move(salesOrder.currency);
    this->items = std::move(salesOrder.items);

    salesOrder.documentNumber = 0;
    salesOrder.customer.clear();
    salesOrder.date.clear();
    salesOrder.netValue = 0;
    salesOrder.currency.clear();
    salesOrder.items.clear();
}

// SalesOrder assignment operator
SalesOrder& SalesOrder::operator=(const SalesOrder &salesOrder) {
    std::cout << "\nSalesOrder Assignment Operator called." << std::endl;

    if (this != &salesOrder) {
        this->documentNumber = salesOrder.documentNumber;
        this->customer = salesOrder.customer;
        this->date = salesOrder.date;
        this->netValue = salesOrder.netValue;
        this->currency = salesOrder.currency;

        for (const auto& item : salesOrder.items) {
            items.push_back(std::make_shared<Item>(*item)); 
        }
    }

    return *this;
}

// Getters
int SalesOrder::getDocumentNumber() const { return documentNumber; }
std::string SalesOrder::getCustomer() const { return customer; }
std::string SalesOrder::getDate() const { return date; }
double SalesOrder::getNetValue() const { return netValue; }
std::string SalesOrder::getCurrency() const { return currency; }
const std::vector<std::shared_ptr<Item>>& SalesOrder::getItems() const { return items; }

// Setters
void SalesOrder::setDocumentNumber(int documentNumber) { this->documentNumber = documentNumber; }
void SalesOrder::setCustomer(const std::string &customer) { this->customer = customer; }
void SalesOrder::setDate(const std::string &date) { this->date = date; }
void SalesOrder::setCurrency(const std::string &currency) { this->currency = currency; }
void SalesOrder::setItems(const std::vector<std::shared_ptr<Item>> &items){ this->items = items; }


void SalesOrder::addItem(const Item& item) {
    std::shared_ptr<Item> newItem = std::make_shared<Item>(item);
    items.push_back(newItem);
    netValue += item.quantity * item.netPrice;
}

void SalesOrder::deleteItem(const Item& item) {
    auto it = std::remove_if(items.begin(), items.end(),
        [&item](const std::shared_ptr<Item>& currentItem) {
            return currentItem->itemNumber == item.itemNumber;
        });

    if (it != items.end()) {
        netValue -= (*it)->quantity * (*it)->netPrice;
        items.erase(it);
    }
}

void SalesOrder::displayOrder() const {
    
    std::cout << "Document Number:      " << documentNumber << std::endl;
    std::cout << "Customer:             " << customer << std::endl;
    std::cout << "Date:                 " << date << std::endl;
    std::cout << "Net Value:            " << netValue << std::endl;
    std::cout << "Currency:             " << currency << std::endl;

    std::cout << "Items:" << std::endl;
    for (const auto& item : items) {
        std::cout << "  Item Number: " << item->itemNumber << std::endl;
        std::cout << "  Quantity:    " << item->quantity << std::endl;
        std::cout << "  Net Price:   " << item->netPrice << std::endl;
    }
}

