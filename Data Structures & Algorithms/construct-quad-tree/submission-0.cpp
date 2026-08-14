/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }
private:
    Node* build(vector<vector<int>>& grid, int r, int c, int len) {
        bool isLeaf = true;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (grid[r + i][c + j] != grid[r][c]) {
                    isLeaf = false;
                    break;
                }
            }
        }
        if (isLeaf) return new Node(grid[r][c] == 1, true);
        
        len /= 2;
        return new Node(false, false, 
            build(grid, r, c, len), 
            build(grid, r, c + len, len), 
            build(grid, r + len, c, len), 
            build(grid, r + len, c + len, len));
    }
};