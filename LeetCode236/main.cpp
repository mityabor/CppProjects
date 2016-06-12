#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};




class Solution {
public:
    const int static INF = 2000000;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {

        std::vector<int> valuesOfVisiting;
        std::vector<TreeNode*> nodesOfVisiting;
        std::vector<int> heights;
        std::map<TreeNode*, int> visitMap;

        int cnt = 0;
        performEulerTour(root, valuesOfVisiting, nodesOfVisiting, heights, visitMap, -1, cnt);

        int i = visitMap[p];
        int j = visitMap[q];

        SegmentNode* root1 = buildSparseTree(heights);
        std::pair< int, int > result = runQuery(root1, i, j);
        return  nodesOfVisiting[result.second];





    }
    void performEulerTour(TreeNode* root, std::vector<int>& valuesOfVisiting, std::vector<TreeNode*>& nodesVisited, std::vector<int>& heights, std::map<TreeNode*, int>& visitDictionary,
                           int prevHeight, int& cnt)
    {
        if (!root)
        {
            return;
        }
        prevHeight++;
        visitDictionary[root] = cnt;
        cnt++;
        valuesOfVisiting.push_back(root->val);
        nodesVisited.push_back(root);
        heights.push_back(prevHeight);
        performEulerTour(root->left, valuesOfVisiting, nodesVisited, heights, visitDictionary, prevHeight, cnt);
        valuesOfVisiting.push_back(root->val);
        nodesVisited.push_back(root);
        heights.push_back(prevHeight);
        cnt++;
        performEulerTour(root->right, valuesOfVisiting, nodesVisited, heights, visitDictionary,   prevHeight, cnt);
    }
    struct SegmentNode
    {
        int val;
        int argmin;
        int rightPos;
        int leftPos;
        SegmentNode* right;
        SegmentNode* left;
        SegmentNode(int _val, int _argmin, int _leftPos, int _rightPos): val(_val), argmin(_argmin), leftPos(_leftPos), rightPos(_rightPos), left(NULL), right(NULL){}

    };
private:
    static SegmentNode* buildSparseTree(const std::vector<int>& heights, int leftIndex, int rightIndex)
    {

        if(leftIndex == rightIndex)
        {
            SegmentNode* node = new SegmentNode(heights[leftIndex], leftIndex, leftIndex, rightIndex);
            return node;
        }

        int m = (leftIndex + rightIndex) / 2;
        SegmentNode* left = buildSparseTree(heights, leftIndex, m);
        SegmentNode* right = buildSparseTree(heights, m+1, rightIndex);

        int argmin;
        int val;
        if (left->val < right->val)
        {
            argmin = left->argmin;
            val = left->val;


        }
        else
        {
            argmin = right->argmin;
            val = right->val;
        }
        SegmentNode* node = new SegmentNode(val, argmin, leftIndex, rightIndex);

        node->left = left;
        node->right = right;
        return node;
    }

    static SegmentNode* buildSparseTree(const std::vector<int>& heights)
    {

        return buildSparseTree(heights, 0, heights.size() - 1);
    }

    static std::pair<int, int> runQuery(SegmentNode* segmentNode, int i, int j)
    {

        if(i < segmentNode->leftPos)
        {
            i = segmentNode->leftPos;
        }
        if(j > segmentNode->rightPos)
        {
            j = segmentNode->rightPos;
        }
        if (i > j)
        {
            return std::pair<int, int>(600000, -1);
        }
        if (i == segmentNode->leftPos && j == segmentNode->rightPos)
        {
            return std::pair<int, int>(segmentNode->val, segmentNode->argmin);
        }


        std::pair<int, int>  leftResult = runQuery(segmentNode->left, i, j);
        std::pair<int, int>  rightResult = runQuery(segmentNode->right, i, j);

        if (leftResult.first < rightResult.first)
        {

            return leftResult;
        } else
        {
            return rightResult;
        }

    }

};


int main(int argc, char *argv[])
{
    TreeNode* node0 = new TreeNode(3);
    TreeNode* node1 = new TreeNode(5);
    TreeNode* node2 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(6);
    TreeNode* node4 = new TreeNode(2);
    TreeNode* node5 = new TreeNode(0);
    TreeNode* node6 = new TreeNode(8);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node8 = new TreeNode(4);
    node0->left = node1;
    node0->right = node2;
    node1->left = node3;
    node1->right = node4;
    node4->left = node7;
    node4->right = node8;
    node2->left = node5;
    node2->right = node6;

    Solution sol;
    TreeNode* node = sol.lowestCommonAncestor(node0, node3, node8);
    std::cout <<  node->val<< std::endl;
    return 0;
}
