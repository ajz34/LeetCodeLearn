// https://leetcode-cn.com/problems/max-points-on-a-line/

#include "extern.h"

typedef pair<int, int> pii;

class S0149 {
    void gcd(pii& p) {
        int l = abs(p.first), r = abs(p.second);
        if (r == 0) p = make_pair(1, 0);
        else if (l == 0) p = make_pair(0, 1);
        else {
            if (l < r) swap(l, r);
            while (r != 0) {
                l -= (l / r) * r;
                swap(l, r);
            }
            if (p.first < 0) l *= -1;
            p.first /= l, p.second /= l;
        }
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int ps = points.size();
        if (ps == 0) return 0;
        int result = 1;
        map<pii, int> s;
        for (int i = 0; i < ps; ++i) {
            int rep_point = 1;
            s.clear();
            for (int j = i + 1; j < ps; ++j) {
                pii k = make_pair(points[j][0] - points[i][0], points[j][1] - points[i][1]);
                if (k.first == 0 && k.second == 0) rep_point += 1;
                else { gcd(k); s[k] += 1; }
            }
            result = max(rep_point, result);
            for (auto& p : s)
                result = max(p.second + rep_point, result);
        }
        return result;
    }
};

TEST(e0200, e0149) {
    vector<vector<int>> points;
    points = str_to_mat<int>("[[1,1],[2,2],[3,3]]");
    ASSERT_EQ(S0149().maxPoints(points), 3);
    points = str_to_mat<int>("[[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]");
    ASSERT_EQ(S0149().maxPoints(points), 4);
}
