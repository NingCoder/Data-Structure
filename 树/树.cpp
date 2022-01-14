#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//树结构 直接copy力扣的数据结构 不浪费时间
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//进行建树 二叉搜索数
TreeNode*buildTree(const vector<int>&arr,int left,int right){
    if(!arr.size()||left>right){
        return nullptr;
    }

    int mid=(left+right+1)>>1;//中间这个数的index 应该是向上取整
    TreeNode *root=new TreeNode(arr[mid]);
    root->left=buildTree(arr,left,mid-1);
    root->right=buildTree(arr,mid+1,right);
    return root;
}
//中序遍历
void inorder(vector<int>&res,TreeNode*root){
    if(root){
        res.push_back(root->val);
        inorder(res,root->left);
        inorder(res,root->right);
    }
}
//层次遍历
vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root) return res;

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            vector<int>temp;
            while(sz>0)
            {
                TreeNode*node=q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                --sz;
            }
            res.push_back(temp);
        }
        return res;
}
//获取层次遍历后 树的具体细节
void getDetailInfo(const vector<vector<int>>&levelOrderRes){
    
    if(levelOrderRes.empty())return ;
    for(int i=0;i<levelOrderRes.size();++i){
        for(int j=0;j<levelOrderRes[i].size();++j){
            cout<<levelOrderRes[i][j]<<" ";
        }
        cout<<endl;
    }
}
//二叉树的最大深度-->使用迭代
int maxDepth(TreeNode* root) {
        if(!root)return 0;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size)
            {
                --size;
                auto node=q.front();q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            ++level;
        }
        return level;
}
//二叉树的最小深度-->使用递归
 int minDepth(TreeNode* root) {
        if(!root) return 0;
        int leftdepth=minDepth(root->left);
        int rightdepth=minDepth(root->right);
        return (root->left&&root->right)?min(leftdepth,rightdepth)+1:leftdepth+rightdepth+1;
}
int main(){
    vector<int>arr={1,2,3,4,5,6,8,9};//{-10,-3,0,5,9};//
    TreeNode *root=buildTree(arr,0,arr.size()-1);
    vector<int>res;
    inorder(res,root);
    for(int i=0;i<res.size();++i){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    vector<vector<int>>levelOrderRes;

    levelOrderRes=levelOrder(root);
    getDetailInfo(levelOrderRes);
    int maxdepth=maxDepth(root);
    int mindepth=minDepth(root);
    cout<<maxdepth<<" "<<mindepth<<endl;
    return 0;
}