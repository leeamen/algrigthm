
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector <TreeNode *> treelist;
    vector <TreeNode *> ::iterator it;
    TreeNode* convertBST(TreeNode* root) {
        for(it=treelist.end()-2;it!=treelist.begin();it--)   //反向迭代器++是访问前一个元素
        {
            (*it)->val += (*(it+1))->val;
        }
        return root;

    }
    void gothrough(TreeNode *root)  //这步操作把所有树节点中序遍历的顺序加入到treelist里
    {
        if(!root)
            return ;
        gothrough(root->left);
        treelist.push_back(root);
        gothrough(root->right);
    }
};

int main()
{
  return 0;
}
