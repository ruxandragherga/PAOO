#include <iostream>
#include "SalesOrder.hpp"
#include "InternationalSalesOrder.hpp"
using namespace SalesOrderNamespace;
using namespace InternationalSalesOrderNamespace;

int main() {
    
    SalesOrder order1(1, "CustomerA", "2023-10-30", "USD");
    Item item1{"001", 2, 10.5};
    Item item2{"002", 3, 7.8};
    order1.addItem(item1);
    order1.addItem(item2);
    std::cout << "Order 1:" << std::endl;
    order1.displayOrder();


    SalesOrder order1Copy = order1;
    std::cout << "\nCopied Order:" << std::endl;
    order1Copy.displayOrder();


    SalesOrder order2(2, "CustomerB", "2023-10-31", "EUR");
    order2.displayOrder();
    order2 = order1;
    std::cout << "\nOrder 2:" << std::endl;
    order2.displayOrder();


    order1Copy.deleteItem(item1);
    order2.deleteItem(item2);
    std::cout << "\nOrder 1:" << std::endl;
    order1.displayOrder();
    std::cout << "\nOrder 1 copy:" << std::endl;
    order1Copy.displayOrder();
    std::cout << "\nOrder 2:" << std::endl;
    order2.displayOrder();


    SalesOrder movedOrder = std::move(order2);
    std::cout << "\nMoved Order:" << std::endl;
    movedOrder.displayOrder();
    std::cout << "\nOriginal Order after Move:" << std::endl;
    order2.displayOrder();


    InternationalSalesOrder internationalSalesOrder(3, "CustomerC", "2023-11-05", "EUR", "Italy");
    internationalSalesOrder.displayOrder();

    Order *order4 = &order1;
    Order *order5 = &internationalSalesOrder;
    order5->addItem(item2);
    order4->displayOrder();
    order5->displayOrder();

    
    return 0;
}