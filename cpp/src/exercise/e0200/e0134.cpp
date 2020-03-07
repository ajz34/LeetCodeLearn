// https://leetcode-cn.com/problems/gas-station/

#include "extern.h"

class S0134 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.empty()) return -1;
        for (int i = 0; i < gas.size(); ++i) {
            gas[i] -= cost[i];
        }
        int total = 0;
        int cnt = 0, result = 0, start_idx = -1;
        bool in_cnt = false;
        for (int i = 0; i < gas.size() * 2; ++i) {
            int v = gas[i % gas.size()];
            if (!in_cnt && v >= 0) {
                in_cnt = true;
                total = v;
                cnt = 1;
                start_idx = i % gas.size();
            }
            else if (in_cnt) {
                if (total + v < 0) {
                    in_cnt = false;
                    result = max(result, cnt);
                    if (result >= gas.size())
                        return start_idx;
                }
                else {
                    ++cnt;
                    total += v;
                }
            }
        }
        result = max(result, cnt);
        if (result >= gas.size())
            return start_idx;
        else return -1;
    }
};

TEST(e0200, e0134) {
    vector<int> gas, cost;
    gas = str_to_vec<int>("[1,2,3,4,5]");
    cost = str_to_vec<int>("[3,4,5,1,2]");
    ASSERT_EQ(S0134().canCompleteCircuit(gas, cost), 3);
    gas = str_to_vec<int>("[2,3,4]");
    cost = str_to_vec<int>("[3,4,3]");
    ASSERT_EQ(S0134().canCompleteCircuit(gas, cost), -1);
}
