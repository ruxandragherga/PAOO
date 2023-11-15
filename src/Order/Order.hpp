#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>
#include <vector>
#include <memory>

namespace OrderNamespace {

    struct Item {
        std::string itemNumber;
        int quantity;
        double netPrice;
    };

    // Pure abstract class 
    class Order {
    public:
        virtual ~Order() = default;

        virtual void addItem(const Item &item) = 0;

        virtual void deleteItem(const Item &item) = 0;

        virtual void displayOrder() const = 0;
    };

};
#endif

