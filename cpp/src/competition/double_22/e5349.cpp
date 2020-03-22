// https://leetcode-cn.com/problems/cinema-seat-allocation/

#include "extern.h"

class S5349 {
    struct ComparePair {
        inline bool operator()(vector<int>& v1, vector<int>& v2) {
            if (v1[0] != v2[0]) return v1[0] < v2[0];
            else return v1[1] < v2[1];
        }
    };
    int line_seat_occupied(vector<vector<int>>& reservedSeats, int pl, int pr) {
        vector<bool> s(10, true);
        for (int p = pl; p < pr; ++p)
            s[reservedSeats[p][1] - 1] = false;
        int result = 0;
        if (s[1] && s[2] && s[3] && s[4]) ++result;
        if (s[5] && s[6] && s[7] && s[8]) ++result;
        if (result > 0) return 2 - result;
        if (s[3] && s[4] && s[5] && s[6]) return 1;
        else return 2;
    }
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        if (reservedSeats.empty()) return n * 2;
        sort(reservedSeats.begin(), reservedSeats.end(), ComparePair());
        int pl = 0, n_prev = 0, result = n * 2;
        for (int p = 0; p < reservedSeats.size(); ++p) {
            if (reservedSeats[p][0] != reservedSeats[pl][0]) {
                result -= line_seat_occupied(reservedSeats, pl, p);
                pl = p;
            }
        }
        result -= line_seat_occupied(reservedSeats, pl, reservedSeats.size());
        return result;
    }
};

TEST(double22, e5349) {
    vector<vector<int>> reservedSeats;
    reservedSeats = str_to_mat<int>("[[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]");
    ASSERT_EQ(S5349().maxNumberOfFamilies(3, reservedSeats), 4);
    reservedSeats = str_to_mat<int>("[[2,1],[1,8],[2,6]]");
    ASSERT_EQ(S5349().maxNumberOfFamilies(2, reservedSeats), 2);
    reservedSeats = str_to_mat<int>("[[4,3],[1,4],[4,6],[1,7]]");
    ASSERT_EQ(S5349().maxNumberOfFamilies(4, reservedSeats), 4);
}
