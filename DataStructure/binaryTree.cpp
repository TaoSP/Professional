/******************************************************************************
 * binaryTre.cpp
 * Author : Huangtao
 * Version: V1.0.0  2020-01-26 Create
 * Description: 二叉排序树, 非模板实现, 非平衡
******************************************************************************/
#include <iostream>
#include <queue>
using namespace std;

typedef struct Node
{
    int val;
    Node *leftChild; 
    Node *rightChild;
    Node *parent;
    Node(int t) : val(t), leftChild(nullptr), rightChild(nullptr), parent(nullptr)
    {}
    //Node() = default;
}Node;

// BinaryTree
class BinaryTree
{
private:
    Node *root;
    void recursivePreOrder(Node *p);
    void recursiveInOrder(Node *p);
    void recursivePostOrder(Node *p);
    void recursiveDestory(Node *p);

public:
    BinaryTree();
    ~BinaryTree();
    int insert(int val);
    int remove(int val);
    Node* find(int val);
    Node* predecessor(Node *p); // 返回 p 的前驱
    Node* successor(Node *p);   // 返回 p 的后继
    int preOrder();
    int inOrder();
    int postOrder();
    int layerOrder();
    int minimum();
    int maximum();
};

void BinaryTree::recursivePreOrder(Node *p)
{
    if(p != nullptr)
    {
        std::cout << p->val << " ";
        recursivePreOrder(p->leftChild);
        recursivePreOrder(p->rightChild);
    }
}

void BinaryTree::recursiveInOrder(Node *p)
{
    if(p != nullptr)
    {
        recursiveInOrder(p->leftChild);
        std::cout << p->val << " ";
        recursiveInOrder(p->rightChild);
    }
}

void BinaryTree::recursivePostOrder(Node *p)
{
    if(p != nullptr)
    {
        recursivePostOrder(p->leftChild);
        recursivePostOrder(p->rightChild);
        std::cout << p->val << " ";
    }
}

void BinaryTree::recursiveDestory(Node *p)
{
    if(p)
    {
        if(p->leftChild)
            recursiveDestory(p->leftChild);
        if(p->rightChild)
            recursiveDestory(p->rightChild);
        delete p;
    }
}

BinaryTree::BinaryTree() :root(0)
{
}

BinaryTree::~BinaryTree()
{
    recursiveDestory(root); // 递归删除
}

int BinaryTree::insert(int val)
{
    Node *pParent = nullptr;
    Node *pNode = root;

    while(pNode != nullptr)
    {
        pParent = pNode;
        if(val < pNode->val)
            pNode = pNode->leftChild;
        else if(val > pNode->val)
            pNode = pNode->rightChild;
        else
            break;
    }
    
    pNode = new Node(val);
    if(pParent == nullptr)
    {
        root = pNode;
    }
    else
    {
        if(val < pParent->val)
            pParent->leftChild = pNode;
        else
            pParent->rightChild = pNode;
    }
    pNode->parent = pParent;
    
    return true;
}

// case 1. 被删除节点是叶子节点，直接删除
// case 2. 被删除节点只有左子树或只有右子树，将整个子树移到被删除节点位置
// case 3. 被删除节点同时有左子树和右子树, 用前驱或后继节点值替代被删除节点
int BinaryTree::remove(int val)
{
    Node *pNode = this->find(val);
    if(!pNode)
        return false;

    Node *pDel = nullptr;
    if(pNode->leftChild && pNode->rightChild) // case 3
    {
        pDel = pNode->leftChild; // 寻找前驱
        while (pDel->rightChild)
        {
            pDel = pDel->rightChild;
        }
        pNode->val = pDel->val;
        
    }
    else // case 1, 2
    {
        pDel = pNode;
        pNode = (pNode->leftChild) ? pNode->leftChild : pNode->rightChild;
        if(pNode)
        {
            pNode->parent = pDel->parent;
        }
        
        if(pDel->parent == nullptr) // 被删除节点是头节点
        {
            root = pNode;
        }
        else
        {
            if(pDel == pDel->parent->leftChild)
                pDel->parent->leftChild = pNode; // 用子树替换被删除节点
            else
                pDel->parent->rightChild = pNode;
        }
    }

    delete pDel;
    pDel = nullptr;

    return true;
}

Node* BinaryTree::find(int val)
{
    Node *pNode = root;
    while (pNode) // 非递归
    {
        if(val == pNode->val)
            return pNode;
        else if(val > pNode->val)
            pNode = pNode->rightChild;
        else
            pNode = pNode->leftChild;
    }
    return nullptr;
}

Node* BinaryTree::predecessor(Node *p)
{
    Node *pNode = p;

    if(pNode->leftChild) // 1. p有左子树，则前驱为其左子树中最大值
    {
        pNode = pNode->leftChild;
        while (pNode->rightChild)
        {
            pNode = pNode->rightChild;
        }
        return pNode;
    }

    Node *pParent = pNode->parent;
    if(pParent && (pNode == pParent->rightChild)) // 2. p无左子树，且p为其父节点的右子树
    {
        return pParent;
    }
    else // 3. p无左子树，且p为其父节点的左子树，寻找第一个拥有右子树的父节点
    {
        while (pParent)
        {
            pNode = pParent;
            pParent = pParent->parent;
            if(pNode == pParent->rightChild)
                return pParent;
        }
    }

    return nullptr;
}

Node* BinaryTree::successor(Node *p)
{
    Node *pNode = p;
    if(pNode->rightChild) // 1. p有右子树
    {
        pNode = pNode->rightChild;
        while(pNode->leftChild)
        {
            pNode = pNode->leftChild;
        }
        return pNode;
    }

    Node *pParent = pNode->parent;
    if(pParent && (pNode == pParent->leftChild)) // 2. p为其父节点的左子树
    {
        return pParent;
    }
    else // 3. p为其父节点的右子树，寻找第一个拥有左子树的父节点
    {
        while(pParent)
        {
            pNode = pParent;
            pParent = pParent->parent;
            if(pNode == pParent->leftChild)
                return pParent;
        }
    }

    return nullptr;
}

int BinaryTree::preOrder()
{
    recursivePreOrder(root);
    return true;
}

int BinaryTree::inOrder()
{
    recursiveInOrder(root);
    return true;
}

int BinaryTree::postOrder()
{
    recursivePostOrder(root);
    return true;
}

int BinaryTree::layerOrder()
{
    Node *pNode = root;
    if(!pNode)
        return false;

    queue<Node *> que;
    que.push(pNode);
    while(!que.empty())
    {
        pNode = que.front();
        std::cout << pNode->val << " ";
        que.pop();

        if(pNode->leftChild)
            que.push(pNode->leftChild);
        if(pNode->rightChild)
            que.push(pNode->rightChild);
    }

    return true;
}

int BinaryTree::minimum()
{
    Node *pNode = root;
    while(pNode->leftChild)
        pNode = pNode->leftChild;

    return pNode->val;
}

int BinaryTree::maximum()
{
    Node *pNode = root;
    while(pNode->rightChild)
        pNode = pNode->rightChild;

    return pNode->val;
}

/* {10, 2, 9, 3, 1, 33, 2020, 2019, 8, 6, 2021, 2022};
            10
        2       33
    1     9       2020
        3       2019  2021
          8             2022
        6
*/
int main()
{
    int val[12] = {10, 2, 9, 3, 1, 33, 2020, 2019, 8, 6, 2021, 2022};
    BinaryTree tree;
    for(int i = 0; i< 12; i++)
        tree.insert(val[i]);

    tree.remove(2);

    //tree.preOrder();
    //cout << endl;
    tree.inOrder();
    cout << endl;
    //tree.postOrder();
    //cout << endl;
    tree.layerOrder();
    cout << endl;

    //Node *pNode = tree.predecessor(tree.find(2022));
    cout << tree.successor(tree.find(8))->val << endl;
    cout << tree.minimum() << endl;
    cout << tree.maximum() << endl;

    return 0;
}
