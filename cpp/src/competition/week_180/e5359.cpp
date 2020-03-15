

#include "extern.h"

typedef long long LL;

class S5359 {
    // �Ƚ�Ч�����ٶȣ���С�� greater ������
    // Ч�� (efficiency, first) ���ȿ��ǣ��ٶ� (speed, second) �����
    struct PairCompare {
        inline bool operator()(pair<LL, LL>& p1, pair<LL, LL>& p2) {
            if (p1.first == p2.first) return p1.second > p2.second;
            else return p1.first > p2.first;
        }
    };
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        // ���ȶ�Ч�����ٶ�������
        vector<pair<LL, LL>> pr; pr.reserve(n);
        for (int i = 0; i < n; ++i)
            pr.push_back(make_pair((LL)efficiency[i], (LL)speed[i]));
        sort(pr.begin(), pr.end(), PairCompare());
        // Ԥ����
        LL spd_sum = 0;   // ���� (������) k ���ٶȵĺ�
        multiset<LL> st;  // ����ٶȵļ���
        LL result = 0;    // �����صĽ��
        // ������Ч�ʴӸߵ���˳�򣬱�������Ա��
        for (int i = 0; i < n; ++i) {
            // ���Ա����û�е����ֵ k���������Ա�����ٶȶ����ǽ���
            if (i < k) {
                spd_sum += pr[i].second;
                st.insert(pr[i].second);
            }
            // ���Ա�����Ѿ����� k���ҵ�ǰԱ���ٶȱȽϿ죬��ô fire ��������Ա�������۸�Ա��Ч�����
            else if (pr[i].second > * st.begin()) {
                spd_sum += pr[i].second - *st.begin();
                st.erase(st.begin());
                st.insert(pr[i].second);
            }
            // ����һ�½��
            result = max(spd_sum * pr[i].first, result);
        }
        return int(result % (LL)1000000007);
    }
};

TEST(week180, e5359) {
    int n, k; vector<int> speed, efficiency;
    n = 6, k = 2;
    speed = str_to_vec<int>("[2,10,3,1,5,8]");
    efficiency = str_to_vec<int>("[5,4,3,9,7,2]");
    ASSERT_EQ(S5359().maxPerformance(n, speed, efficiency, k), 60);
    k = 3;
    ASSERT_EQ(S5359().maxPerformance(n, speed, efficiency, k), 68);
    k = 4;
    ASSERT_EQ(S5359().maxPerformance(n, speed, efficiency, k), 72);
}
