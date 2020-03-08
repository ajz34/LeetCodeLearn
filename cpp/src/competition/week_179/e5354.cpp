// https://leetcode-cn.com/problems/time-needed-to-inform-all-employees/

#include "extern.h"

class S5354 {
    int numOfMinutesInner(int n, int headID, vector<int>& manager, vector<int>& informTime,
        vector<bool>& leaf_node, vector<int>& res_time, int idx) {
        if (idx == -1) return 0;
        if (res_time[idx] != -1) {
            leaf_node[idx] = false;
            return res_time[idx];
        }
        res_time[idx] = numOfMinutesInner(n, headID, manager, informTime, leaf_node, res_time, manager[idx]) + informTime[idx];
        return res_time[idx];
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<bool> leaf_node(n, true);
        vector<int> res_time(n, -1);
        for (int i = 0; i < n; ++i) {
            numOfMinutesInner(n, headID, manager, informTime, leaf_node, res_time, i);
        }
        int result = 0;
        for (int i = 0; i < n; ++i)
            if (!leaf_node[i])
                result = max(res_time[i], result);
        return result;
    }
};

TEST(week179, e5354) {
    int n, headID; vector<int> manager, informTime;
    n = 1, headID = 0, manager = { -1 }, informTime = { 0 };
    ASSERT_EQ(S5354().numOfMinutes(n, headID, manager, informTime), 0);
    n = 6, headID = 2, manager = { 2, 2, -1, 2, 2, 2 }, informTime = { 0, 0, 1, 0, 0, 0 };
    ASSERT_EQ(S5354().numOfMinutes(n, headID, manager, informTime), 1);
    n = 7, headID = 6, manager = { 1, 2, 3, 4, 5, 6, -1 }, informTime = { 0, 6, 5, 4, 3, 2, 1 };
    ASSERT_EQ(S5354().numOfMinutes(n, headID, manager, informTime), 21);
    n = 15, headID = 0, manager = { -1, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 }, informTime = { 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 };
    ASSERT_EQ(S5354().numOfMinutes(n, headID, manager, informTime), 3);
    n = 4, headID = 2, manager = { 3, 3, -1, 2 }, informTime = { 0, 0, 162, 914 };
    ASSERT_EQ(S5354().numOfMinutes(n, headID, manager, informTime), 1076);
}
