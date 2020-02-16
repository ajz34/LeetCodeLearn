// https://leetcode-cn.com/problems/product-of-the-last-k-numbers/

#include "extern.h"

class ProductOfNumbers {
    vector<int> prod{};
public:
    ProductOfNumbers() {

    }

    void add(int num) {
        if (num != 1) for (int& val : prod) val *= num;
        prod.push_back(num);
    }

    int getProduct(int k) {
        return prod[prod.size() - k];
    }
};

TEST(week176, e5341) {
    ProductOfNumbers productOfNumbers = ProductOfNumbers();
    productOfNumbers.add(3);        // [3]
    productOfNumbers.add(0);        // [3,0]
    productOfNumbers.add(2);        // [3,0,2]
    productOfNumbers.add(5);        // [3,0,2,5]
    productOfNumbers.add(4);        // [3,0,2,5,4]
    ASSERT_EQ(productOfNumbers.getProduct(2), 20); // return 20. The product of the last 2 numbers is 5 * 4 = 20
    ASSERT_EQ(productOfNumbers.getProduct(3), 40); // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
    ASSERT_EQ(productOfNumbers.getProduct(4), 0);  // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
    productOfNumbers.add(8);        // [3,0,2,5,4,8]
    ASSERT_EQ(productOfNumbers.getProduct(2), 32); // return 32. The product of the last 2 numbers
}