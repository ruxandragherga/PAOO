#include "SalesOrder.hpp"
#include <iostream>

int main() {

    SalesOrder order1(1, "CustomerA", "2023-10-30", "USD");

    Item item1{"001", 2, 10.5};
    Item item2{"002", 3, 7.8};

    order1.addItem(item1);
    order1.addItem(item2);

    std::cout << "Order 1:" << std::endl;
    order1.displaySalesOrder();

    SalesOrder order1Copy = order1;
    std::cout << "\nCopied Order:" << std::endl;
    order1Copy.displaySalesOrder();

    SalesOrder order2(2, "CustomerB", "2023-10-31", "EUR");
    order2.displaySalesOrder();
    order2 = order1;
    std::cout << "\nOrder 2:" << std::endl;
    order2.displaySalesOrder();


    order1Copy.deleteItem(item1);
    order2.deleteItem(item2);
    std::cout << "\nOrder 1:" << std::endl;
    order1.displaySalesOrder();
    std::cout << "\nOrder 1 copy:" << std::endl;
    order1Copy.displaySalesOrder();
    std::cout << "\nOrder 2:" << std::endl;
    order2.displaySalesOrder();

    return 0;
}