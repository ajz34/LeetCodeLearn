// https://leetcode-cn.com/problems/bulb-switcher-iii/

#include "extern.h"

class S5353 {
public:
    int numTimesAllBlue(vector<int>& light) {
        int lsize = light.size();
        vector<bool> stat(lsize + 1, false);
        stat[0] = true;
        int blue_id = 0, result = 0;
        for (int c = 0; c < lsize; ++c) {
            int l = light[c];
            stat[l] = true;
            while (blue_id < lsize && stat[blue_id + 1])
                blue_id += 1;
            if (blue_id == c + 1)
                result += 1;
        }
        return result;
    }
};

TEST(week179, e5353) {
    vector<int> light;
    light = str_to_vec<int>("[2,1,3,5,4]");
    ASSERT_EQ(S5353().numTimesAllBlue(light), 3);
    light = str_to_vec<int>("[3,2,4,1,5]");
    ASSERT_EQ(S5353().numTimesAllBlue(light), 2);
    light = str_to_vec<int>("[4,1,2,3]");
    ASSERT_EQ(S5353().numTimesAllBlue(light), 1);
    light = str_to_vec<int>("[2,1,4,3,6,5]");
    ASSERT_EQ(S5353().numTimesAllBlue(light), 3);
    light = str_to_vec<int>("[1,2,3,4,5,6]");
    ASSERT_EQ(S5353().numTimesAllBlue(light), 6);
}
