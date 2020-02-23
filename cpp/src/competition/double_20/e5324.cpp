// https://leetcode-cn.com/problems/apply-discount-every-n-orders/

#include "extern.h"

class Cashier {
    int n;
    int cur_n;
    int discount;
    unordered_map<int, int> price_map;

public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n = n;
        this->cur_n = 0;
        this->discount = discount;
        for (size_t s = 0; s < products.size(); ++s) {
            price_map[products[s]] = prices[s];
        }
    }

    double getBill(vector<int> product, vector<int> amount) {
        ++cur_n;
        double result = 0;
        for (size_t s = 0; s < product.size(); ++s) {
            result += price_map[product[s]] * amount[s];
        }
        if (cur_n % n == 0) {
            cur_n = 0;
            result = result - (discount * result) / 100;
        }
        return result;
    }
};

TEST(double20, e5324) {
    Cashier cashier(3, 50, vector<int>{ 1, 2, 3, 4, 5, 6, 7 }, vector<int>{ 100, 200, 300, 400, 300, 200, 100 });
    ASSERT_EQ(cashier.getBill({ 1, 2 }, { 1, 2 })                                  , 500 );
    ASSERT_EQ(cashier.getBill({ 3, 7 }, { 10, 10 })                                , 4000);
    ASSERT_EQ(cashier.getBill({ 1, 2, 3, 4, 5, 6, 7 }, { 1, 1, 1, 1, 1, 1, 1 })    , 800 );
    ASSERT_EQ(cashier.getBill({ 4 }, { 10 })                                       , 4000);
    ASSERT_EQ(cashier.getBill({ 7, 3 }, { 10, 10 })                                , 4000);
    ASSERT_EQ(cashier.getBill({ 7, 5, 3, 1, 6, 4, 2 }, { 10, 10, 10, 9, 9, 9, 7 }) , 7350);
    ASSERT_EQ(cashier.getBill({ 2, 3, 5 }, { 5, 3, 2 })                            , 2500);
}
