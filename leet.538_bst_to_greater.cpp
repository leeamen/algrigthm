#include<iostream>
#include<vector>

#define LEE_538_LIB 1
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {

      convert(root);
      return root;
    }

    void convert(TreeNode* node)
    {
      if(node == NULL)
      {
        return ;
      }
      /*
      右
      */
      convert(node->right);
      node->val += sum;
      /*
      保存当前节点的结果到sum中
      */
      sum = node->val;
      /*
      左
      */
      convert(node->left);
    }
};


class Solution2 {
public:
    vector<TreeNode*>treenode_vector;
    TreeNode* convertBST(TreeNode* root)
    {
      //保存到数组中
      Save2Vector(root);
      //处理数组，后边值加到前边值上
      for(int i = treenode_vector.size() - 2; i >= 0; i--)
      {
        treenode_vector[i]->val += treenode_vector[i+1]->val;
      }
      return root;
    }

    void Save2Vector(TreeNode* node)
    {
      if(node == NULL)
      {
        return;
      }
      //左中右，从小到大
      Save2Vector(node->left);
      treenode_vector.push_back(node);
      Save2Vector(node->right);
    }


};

#if LEE_538_LIB != 1
int main()
{
  return 0;
}
#endif
