//
// Created by 宁一远 on 2022/1/25.
//
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

//对于树的定义
struct  TreeNode{
    int val;
    TreeNode*left,*right;
};
//递归建立二叉树
TreeNode* creatTree(vector<int>arr,int position){
    TreeNode*root;
    if(position>=arr.size()){
        return nullptr;
    }
    root=new TreeNode;
    root->val=arr[position];
    root->left= creatTree(arr,2*position+1);
    root->right= creatTree(arr,2*position+2);
    return root;
}
//先序遍历
void preorderTraversal(TreeNode*root,vector<int>&preorderTraversalRes){
    if(root){
        preorderTraversalRes.push_back(root->val);
        preorderTraversal(root->left,preorderTraversalRes);
        preorderTraversal(root->right,preorderTraversalRes);
    }
}
//后序遍历
void postorderTraversal(TreeNode*root,vector<int>&postorderTraversalRes){
    if(root){
        postorderTraversalRes.push_back(root->val);
        postorderTraversal(root->left,postorderTraversalRes);
        postorderTraversal(root->right,postorderTraversalRes);
    }
}
//中序遍历 迭代 借助stack即可 方便期间直接使用stl
vector<int>inorderTraversal(TreeNode*root){
    vector<int>res;
    stack<TreeNode*>stk;
    while(root!= nullptr||!stk.empty()){
        while(root!= nullptr){
            stk.push(root);
            root=root->left;
        }
        root=stk.top();
        stk.pop();
        res.push_back(root->val);
        root=root->right;
    }
    return res;
}
//获得层数 -->使用迭代实现
int getLevel(TreeNode*root){
    queue<TreeNode*>Q;
    Q.push(root);
    int level=0;
    while(!Q.empty()){
        int sz=Q.size();
        while(sz>0){
            TreeNode*node=Q.front();
            Q.pop();
            if(node->left){
                Q.push(node->left);
            }
            if(node->right){
                Q.push(node->right);
            }
            //层次遍历的话 只需要在这里 记录一下 每层的元素即可
            --sz;
        }
        ++level;
    }
    return level;
}
int minDepth(TreeNode*root){
    if(root== nullptr){
        return 0;
    }
    int leftDepth= minDepth(root->left);
    int rightDepth= minDepth(root->right);
    return (root->left&&root->right)?min(leftDepth,rightDepth)+1:leftDepth+rightDepth+1;
}
//对比树
bool compareTree(TreeNode*root1,TreeNode*root2){
    if(root1== nullptr &&root2== nullptr){
        return true;
    }else if(root1== nullptr||root2== nullptr){
        return false;
    }else if(root1->val!=root2->val){
        return false;
    }else{
        return compareTree(root1->left,root2->left)&& compareTree(root1->right,root2->right);
    }
}
//生成镜像树
TreeNode*mirrorTree(TreeNode*root){
    TreeNode*mirror;
    if(root== nullptr){
        return nullptr;
    }else{
        mirror=new TreeNode;
        mirror->val=root->val;
        mirror->left= mirrorTree(root->right);
        mirror->right= mirrorTree(root->left);
    }
    return mirror;
}

//复原前序和中序遍历后的树-->具体函数的实现 采用分治的思想
TreeNode*MybuildTree(vector<int>& preorder, vector<int>& inorder,int preLeft,int preRight,int inLeft,int inRight,unordered_map<int,int>map)
{
    if(preLeft>preRight||inLeft>inRight)return nullptr;
    //前序遍历  preleft prelft+1 未知数t preright
    //中序遍历  inleft Pindex-1 根Pindex Pindex+1 inright
    //所以前序遍历左边是 Pindex-1-inleft=t-preleft-1==>t=Pindex-inleft+preleft
    int rootVal=preorder[preLeft];
    TreeNode*root=new TreeNode();
    root->val=rootVal;
    root->left= nullptr;root->right= nullptr;
    int pIndex=map[rootVal];

    root->left=MybuildTree(preorder,inorder,preLeft+1,pIndex-inLeft+preLeft,inLeft,pIndex-1,map);
    root->right=MybuildTree(preorder,inorder,pIndex-inLeft+preLeft+1,preRight,pIndex+1,inRight,map);
    return root;
}
//复原前序和中序遍历后的树
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int,int>map;//没有重复的节点 避免重复 出现 保证唯一的二叉树
    int n=preorder.size();
    if(preorder.size()!=inorder.size())return nullptr;
    for(int i=0;i<n;++i)
    {
        map[inorder[i]]=i;
    }
    return MybuildTree(preorder,inorder,0,n-1,0,n-1,map);
}
void compareRes(){
    vector<int>arr={0,1,2,3,4,5,6,8};
    TreeNode*root= nullptr;
    for(int i=0;i<arr.size();++i){
        root= creatTree(arr,0);
    }
    vector<int>inorderTraversalRes= inorderTraversal(root);
    vector<int>preorderTraversalRes;
    preorderTraversal(root,preorderTraversalRes);
    TreeNode*root01= buildTree(preorderTraversalRes,inorderTraversalRes);
    bool res=compareTree(root,root01);
    cout<<res<<endl;
    //生成镜像树
    TreeNode*root02= mirrorTree(root);
    res= compareTree(root,root02);
    cout<<res<<endl;
}
void testTree(){
    vector<int>arr={0,1,2,3,4,5,9,23,6};
    TreeNode*root= nullptr;
    for(int i=0;i<arr.size();++i){
        root= creatTree(arr,0);
    }
    vector<int>inorderTraversalRes= inorderTraversal(root);
    cout<<inorderTraversalRes.size()<<endl;
    for(auto&x:inorderTraversalRes){
        cout<<x<<" ";
    }cout<<endl;
    int level= getLevel(root);
    int minLevel= minDepth(root);
    cout<<level<<" "<<minLevel<<endl;
    cout<<"Hello World!"<<endl;
}
int main(){
    testTree();
    compareRes();
    return 0;

}