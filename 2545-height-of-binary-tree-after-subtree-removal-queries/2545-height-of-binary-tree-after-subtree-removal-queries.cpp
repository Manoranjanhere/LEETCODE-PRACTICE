class Solution {
public:
    vector<int> depth, levelArr, max1, max2;

    int height(TreeNode* root, int level) {
        if (!root) return 0;
        levelArr[root->val] = level;
        depth[root->val] = 1 + max(height(root->left, level + 1), height(root->right, level + 1));

    
        if (max1[level] < depth[root->val]) {
            max2[level] = max1[level];
            max1[level] = depth[root->val];
        } else if (max2[level] < depth[root->val]) {
            max2[level] = depth[root->val];
        }

        return depth[root->val];
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        depth.resize(100001, 0);
        levelArr.resize(100001, 0);
        max1.resize(100001, 0);
        max2.resize(100001, 0);

        // Compute depths and max depths for each level
        height(root, 0);

        // Process each query
        for (int i = 0; i < queries.size(); i++) {
            int q = queries[i];
            int level = levelArr[q];
            queries[i] = (max1[level] == depth[q] ? max2[level] : max1[level]) + level - 1;
        }

        return queries;
    }
};