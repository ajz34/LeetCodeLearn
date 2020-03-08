// https://leetcode-cn.com/problems/frog-position-after-t-seconds/

#include "extern.h"

class S5355 {
    /// �ڵ���Ϣ
    struct Status {
        int pos = 0;           // �ڵ���
        set<int> traversed{};  // ����ȥ���Ľڵ���
        double prob = 0.;      // �Լ���ǰ�ĸ���
    };
    /// ���ڽӱ� neighbours �У�Ѱ�Ҳ����ص�ǰ�ڵ� stat ��һ�����Ա����Ľڵ��� result
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
        // ������ʼ���� 1 �Žڵ�
        int INIT_POS = 1;
        // �����ڽӱ�
        unordered_map<int, vector<int>> neighbours;
        for (auto v : edges) {
            neighbours[v[0]].push_back(v[1]);
            neighbours[v[1]].push_back(v[0]);
        }
        // �����������״̬
        Status stat_init;
        stat_init.pos = INIT_POS;
        stat_init.traversed.insert(INIT_POS);
        stat_init.prob = 1.;
        // Ϊ BFS ��׼����������ʵ��
        vector<Status> all_prev{ stat_init };
        vector<Status> all_next;
        double result = 0.;
        // BFS
        for (int time = 0; time < t; ++time) {
            all_next.clear();
            if (all_prev.empty()) break;
            // ����һ���Ľڵ�������
            for (auto& stat : all_prev) {
                // �����������һ�� stat ���ԣ���һ�����ܵĽڵ���
                set<int> nextpos = possible_nextpos(stat, neighbours);
                // �����һ���ڵ���Ϊ�գ���ô����ֻ��ԭ�ش�ת�����ⲿ�ָ��ʼӵ�����С�
                if (nextpos.empty()) {
                    if (stat.pos == target)
                        result += stat.prob;
                }
                // �����һ����Ų�Ϊ�գ���ô�����µĽڵ㣬��ӵ���һ��ѭ����Ҫ�����Ľڵ��С�
                // �������һ�������Ŀ��������ô������Զ�����ܻص�Ŀ�ꡣ�������Ҫ������
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
        // �����β����ʱ��Ļ����������ǡ����Ŀ����ϣ��ͽ����ʼ���ȥ��
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
