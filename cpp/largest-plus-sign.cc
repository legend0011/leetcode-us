// https://leetcode.com/problems/largest-plus-sign/description/
// chi zhang, 2018.2.7

class Node {
public:
    Node() : up(1), left(1), right(1), down(1), val(1) {}
    void setZero() {
        up = 0;
        left = 0;
        right = 0;
        down = 0;
        val = 0;
    }

public:
    int up;
    int left;
    int right;
    int down;
    int val;
    
};

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        // Init matrix
        vector<vector<Node>> A;
        for (int i = 0; i < N; ++i) {
            Node node;
            vector<Node> tmp(N, node);
            A.push_back(tmp);
        }
        
        for (int i = 0; i < mines.size(); ++i) {
            int x = mines[i][0];
            int y = mines[i][1];
            A[x][y].setZero();
        }
            
        // cal up
        for (int j = 0; j < N; ++j) {
            for (int i = 1; i < N; ++i) {
                if (A[i][j].val == 1) {
                    A[i][j].up = A[i - 1][j].up + 1;
                }
            }
        }
        // cal left
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j < N; ++j) {
                if (A[i][j].val == 1) {
                    A[i][j].left = A[i][j - 1].left + 1;
                }
            }
        }
        // cal right
        for (int i = 0; i < N; ++i) {
            for (int j = N - 2; j >= 0; --j) {
                if (A[i][j].val == 1) {
                    A[i][j].right = A[i][j + 1].right + 1;
                }
            }
        }
        // cal down
        for (int j = 0; j < N; ++j) {
            for (int i = N - 2; i >= 0; --i) {
                if (A[i][j].val == 1) {
                    A[i][j].down = A[i + 1][j].down + 1;
                }
            }
        }
        
        // sizeof plus_sign is min(up, left, right, down)
        int rs = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int size = min(A[i][j].up, A[i][j].left, A[i][j].right, A[i][j].down);
                rs = std::max(size, rs);
            }
        }
        return rs;
    }
private:
    int min(int a, int b, int c, int d) {
        int rs = a;
        rs = std::min(rs, b);
        rs = std::min(rs, c);
        return std::min(rs, d);
    }
};
