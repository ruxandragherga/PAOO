#include <iostream>
#include "Order.hpp"
#include "SalesOrder.hpp"
#include "InternationalSalesOrder.hpp"
#include "Category.hpp"

int main() {
    Item item1{"001", 20, 10.5};
    Item item2{"002", 30, 7.8};
    Item item3{"003", 60, 15.8};
    SalesOrderNamespace::SalesOrder salesOrder1(10001, "CustomerA", "2023-10-30", "USD");
    salesOrder1.addItem(item1);
    salesOrder1.addItem(item2);
    SalesOrderNamespace::SalesOrder salesOrder2(10002, "CustomerB", "2023-11-15", "USD");
    salesOrder2.addItem(item1);
    InternationalSalesOrderNamespace::InternationalSalesOrder intSalesOrder1(20001, "CustomerC", "2023-03-01", "GBP", "UK", 30);
    intSalesOrder1.addItem(item1);
    intSalesOrder1.addItem(item2);
    intSalesOrder1.addItem(item3);
    InternationalSalesOrderNamespace::InternationalSalesOrder intSalesOrder2(20002, "CustomerD", "2023-04-01", "JPY", "Japan", 40);
    intSalesOrder2.addItem(item2);
    intSalesOrder2.addItem(item3);

    salesOrder1.displayOrder();
     std::cout << "------------------------------------\n";
    salesOrder2.displayOrder();
     std::cout << "------------------------------------\n";
    intSalesOrder1.displayOrder();
     std::cout << "------------------------------------\n";
    intSalesOrder2.displayOrder();
    std::cout << "------------------------------------\n";

    CategoryNamespace::Category<SalesOrderNamespace::SalesOrder> salesOrders("Sales Order");
    salesOrders.addOrder(salesOrder1);
    salesOrders.addOrder(salesOrder2);
    CategoryNamespace::Category<InternationalSalesOrderNamespace::InternationalSalesOrder> intSalesOrders("International Order");
    intSalesOrders.addOrder(intSalesOrder1);
    intSalesOrders.addOrder(intSalesOrder2);

    salesOrders.displayCategory();
    intSalesOrders.displayCategory();

    return 0;
}
