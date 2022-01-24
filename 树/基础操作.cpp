//
// Created by 宁一远 on 2022/1/24.
//
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

//对于树的定义
struct  TreeNode{
    int val;
    TreeNode*left,*right;
};

//插入节点 算是一颗二叉树吧
TreeNode*insertNode(TreeNode*root,int val){
    TreeNode*newNode,*parentNode,*currentNode;
    //存储新节点 数值设置 以为left和right设置 作为一颗叶子节点
    //    newNode=(TreeNode*
    newNode=new TreeNode;
    newNode->val=val;
    newNode->left= nullptr;newNode->right= nullptr;
    //如果根节点不存在
    if(root== nullptr){
        return newNode;
    }else{
        //存储节点 寻找可以插入的节点
        currentNode=root;
        while(currentNode!= nullptr){
            //存储父节点
            parentNode=currentNode;
            //进行左右树的查找
            if(currentNode->val>val){
                currentNode=currentNode->left;
            }else{
                currentNode=currentNode->right;
            }
        }
        //对于节点的插入
        if(parentNode->val>val){
            parentNode->left=newNode;
        }else{
            parentNode->right=newNode;
        }
    }
    //操作完成 返回根节点
    return root;
}
//计算深度 使用递归的方式 -->迭代方式借助队列
// -->借助队列的话有一点脱裤子放屁 多此一举的感觉
int getBtreeDepth(TreeNode*root){
    if(root== nullptr){
        return 0;
    }
    else{
        int leftDepth= getBtreeDepth(root->left);
        int rightDepth= getBtreeDepth(root->right);
        return 1+(leftDepth>rightDepth?leftDepth:rightDepth);
    }
}
//前序遍历 -->中序遍历和后序遍历 递归方式的话没有什么大的变化 基本都是一样的
void preOrder(TreeNode*root,vector<int>&res){
    if(root){
        res.push_back(root->val);
        preOrder(root->left,res);
        preOrder(root->right,res);
    }
}
vector<int> inorder(TreeNode*root){
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
//层序遍历 -->树的层序遍历
vector<vector<int>> levelOrder(TreeNode*root){
    queue<TreeNode*>Q;
    Q.push(root);
    vector<vector<int>>res;
    while(!Q.empty()){
        int sz=Q.size();
        vector<int>temp;
        while(sz>0){
            TreeNode*node=Q.front();
            Q.pop();
            temp.push_back(node->val);
            if(node->left){
                Q.push(node->left);
            }
            if(node->right){
                Q.push(node->right);
            }
            --sz;
        }
        res.push_back(temp);
    }
    return res;
}
void testBtree(){
    TreeNode*root= nullptr;
    const int sz01=7;
    int node01[sz01]={3,1,2,6,4,5,7};
    for(int i : node01){
        root=insertNode(root,i);
    }
    int depth= getBtreeDepth(root);
    printf("%d\n",depth);
    vector<int>res;
    preOrder(root,res);
    for(int i=0;i<res.size();++i){
        cout<<res[i]<<",";
    }
    cout<<endl;
    vector<vector<int>>levelRes=levelOrder(root);
    for(auto & levelRe : levelRes){
        for(int j : levelRe){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    vector<int>orderRes= inorder(root);
    for(int i=0;i<orderRes.size();++i){
        cout<<orderRes[i]<<",";
    }cout<<endl;
}
int main(){
    testBtree();
    return 0;
}