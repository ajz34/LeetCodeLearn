// https://leetcode-cn.com/problems/number-of-days-between-two-dates/

#include "extern.h"

class Solution {
    int days_to_1970(string date) {
        int y = stoi(date.substr(0, 4));
        int m = stoi(date.substr(5, 2));
        int d = stoi(date.substr(8, 2));
        vector<int> month_list{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        assert(y >= 1970);
        int result = (y - 1970) * 365;
        result += (y - 1968) / 4;
        result -= (y - 2000) / 100;
        if (y % 4 == 0 && y % 100 != 0 && m <= 2) result -= 1;
        result = accumulate(month_list.begin(), month_list.begin() + m - 1, result);
        result += d;
        return result;
    }
public:
    int daysBetweenDates(string date1, string date2) {
        return abs(days_to_1970(date1) - days_to_1970(date2));
    }
};

TEST(week177, e5169) {
    ASSERT_EQ(Solution().daysBetweenDates("2019-06-29", "2019-06-30"), 1);
    ASSERT_EQ(Solution().daysBetweenDates("2020-01-15", "2019-12-31"), 15);
}
