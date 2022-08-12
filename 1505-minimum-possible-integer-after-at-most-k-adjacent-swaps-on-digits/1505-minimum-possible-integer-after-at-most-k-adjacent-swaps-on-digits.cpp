class Solution {
public:
    string minInteger(string num, int k) {
        const int n = num.size();
        string res;
        res.reserve(n);
        vector<int> q(10, n);
        for (int i = 0; i < n; ++i) {
            const int d = num[i] - '0';
            if (q[d] == n)
                q[d] = i;
        }
        vector<bool> used(n);
        vector<int> q_used(10);
        for (int i = 0; i < n; ++i) {
            for (int d = 0; d < 10; ++d) {
                if (q[d] == n)
                    continue;
                const int c = q[d] - q_used[d];
                
                if (c <= k) {
                    k -= c;
                    res.push_back('0' + d);
                    used[q[d]] = true;
                    for (int d1 = 0; d1 < 10; ++d1) {
                        if (q[d1] > q[d])
                            q_used[d1]++;
                    }
                    while (q[d] < n) {
                        if (used[q[d]])
                            ++q_used[d];
                        if (num[++q[d]] == '0' + d)
                            break;
                    }
                    break;
                }
            }
        }
        return res;
    }
};