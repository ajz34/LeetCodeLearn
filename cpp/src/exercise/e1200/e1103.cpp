#include "extern.h"

class S1103 {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int t_min = max(candies * 2 / num_people - num_people - 2, -1);
        vector<int> result(num_people, 0);
        int total_count = 0;
        t_min = -1;
        if (t_min >= 0) {
            for (int n = 0; n < num_people; ++n) {
                result[n] = (t_min + 1) * (n + 1) + t_min * (t_min + 1) / 2;
            }
        }
        total_count = (t_min + 1) * num_people * (num_people - 1) / 2 + t_min * (t_min + 1) / 2 * num_people;
        int t = t_min + 1;
        while (candies != total_count) {
            for (int n = 0; n < num_people; ++n) {
                int add_val = min(candies - total_count, n + 1 + t * num_people);
                result[n] += add_val;
                total_count += add_val;
                if (candies == total_count) break;
            }
            t += 1;
        }
        return result;
    }
};

TEST(e1200, e1103) {
    vector<int> ans;
    ans = str_to_vec<int>("[1,2,3,1]");
    ASSERT_THAT(S1103().distributeCandies(7, 4), ans);
    ans = str_to_vec<int>("[5,2,3]");
    ASSERT_THAT(S1103().distributeCandies(10, 3), ans);
}
