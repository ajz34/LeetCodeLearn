// https://leetcode-cn.com/problems/frog-position-after-t-seconds/

#include "extern.h"

class S5355 {
    /// 节点信息
    struct Status {
        int pos = 0;           // 节点编号
        set<int> traversed{};  // 曾经去过的节点编号
        double prob = 0.;      // 自己当前的概率
    };
    /// 从邻接表 neighbours 中，寻找并返回当前节点 stat 下一步可以遍历的节点编号 result
    set<int> possible_nextpos(Status& stat, unordered_map<int, vector<int>>& neighbours) {
        set<int> result;
        for (int i : neighbours[stat.pos]) {
            if (stat.traversed.find(i) == stat.traversed.end())
                result.insert(i);
        }
        return result;
    }
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        // 出发点始终是 1 号节点
        int INIT_POS = 1;
        // 构建邻接表
        unordered_map<int, vector<int>> neighbours;
        for (auto v : edges) {
            neighbours[v[0]].push_back(v[1]);
            neighbours[v[1]].push_back(v[0]);
        }
        // 构建出发点的状态
        Status stat_init;
        stat_init.pos = INIT_POS;
        stat_init.traversed.insert(INIT_POS);
        stat_init.prob = 1.;
        // 为 BFS 作准备，用向量实现
        vector<Status> all_prev{ stat_init };
        vector<Status> all_next;
        double result = 0.;
        // BFS
        for (int time = 0; time < t; ++time) {
            all_next.clear();
            if (all_prev.empty()) break;
            // 对上一步的节点作遍历
            for (auto& stat : all_prev) {
                // 先求出对于上一步 stat 而言，下一步可能的节点编号
                set<int> nextpos = possible_nextpos(stat, neighbours);
                // 如果下一步节点编号为空，那么青蛙只能原地打转。将这部分概率加到结果中。
                if (nextpos.empty()) {
                    if (stat.pos == target)
                        result += stat.prob;
                }
                // 如果下一步编号不为空，那么创建新的节点，添加到下一次循环需要遍历的节点中。
                // 但如果这一步编号是目标结果，那么我们永远不可能回到目标。这种情况要跳过。
                else {
                    if (stat.pos != target) {
                        for (int p : nextpos) {
                            all_next.push_back(stat);
                            auto& s = all_next.back();
                            s.pos = p;
                            s.traversed.insert(p);
                            s.prob /= nextpos.size();
                        }
                    }
                }
            }
            swap(all_prev, all_next);
        }
        // 最后收尾：到时间的话，如果青蛙恰好在目标点上，就将概率加上去。
        for (auto& stat : all_prev) {
            if (stat.pos == target)
                result += stat.prob;
        }
        return result;
    }
};

TEST(week179, e5355) {
    int n, t, target; vector<vector<int>> edges;
    n = 7, t = 2, target = 4, edges = str_to_mat<int>("[[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]]");
    ASSERT_EQ(S5355().frogPosition(n, edges, t, target), double(1.) / double(6.));
    n = 7, t = 1, target = 7, edges = str_to_mat<int>("[[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]]");
    ASSERT_EQ(S5355().frogPosition(n, edges, t, target), double(1.) / double(3.));
    n = 7, t = 20, target = 6, edges = str_to_mat<int>("[[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]]");
    ASSERT_EQ(S5355().frogPosition(n, edges, t, target), double(1.) / double(6.));
}
