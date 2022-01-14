//二叉树这里的递归掌握的很不好，寒假需要再来认真看递归一次




#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef char BTdatatype;


typedef struct Binarytree {
	struct  BTnode *left;
	struct  BTnode *right;
	BTdatatype data;
}BTnode;



BTnode* buynode(BTdatatype x) {
	BTnode *newnode = (BTnode*)malloc(sizeof(BTnode));
	assert(newnode != NULL);
	newnode->data = x;
	newnode->left = newnode->right = NULL;
	return newnode;
}


BTnode*  Creatnode() {
	BTnode *nodeA = buynode('A');
	BTnode *nodeB = buynode('B');
	BTnode *nodeC = buynode('C');
	BTnode *nodeD = buynode('D');
	BTnode *nodeE = buynode('E');
	BTnode *nodeF = buynode('F');

	nodeA->left = nodeB;
	nodeA->right = nodeC;
	nodeB->left = nodeD;
	nodeC->left = nodeE;
	nodeC->right = nodeF;
	return nodeA;
}

void prevorder(BTnode* root) {//先序遍历   根 左子树 右子树
	if (root == NULL) {
		printf("NULL ");
		return;
	}
		
		printf("%c ", root->data);
	prevorder(root->left);
	prevorder(root->right);
}



void inorder(BTnode*root) {//中序遍历                左子树 根  右子树
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	inorder(root->left);
	printf("%c ", root->data);
	inorder(root->right);

}


void postorder(BTnode*root) {//后序遍历		左子树 右子树 根
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	postorder(root->left);
	postorder(root->left);
	printf("%c ", root->data);


}

int BTsize1(BTnode*root) {//计算树中的结点个数
	if (root == NULL) {
		
		return;
	}
	static int cout = 0;//第一种方法用静态变量进行计数
	cout++;
	BTsize1(root->left);
	BTsize1(root->right);
	return cout;

}

void BTsize2(BTnode*root,int *ps) {//第二种方法：ps指针用来接收传进来的参数，进行计数
	if (root == NULL) {
		return;
	}
	(*ps)++;
	BTsize2(root->left,ps);
	BTsize2(root->right,ps);
	
}


int BTsize3(BTnode*root) {//第三种方法：用分治的方法进行递归返回计数
	return root == NULL ? 0 : BTsize3(root->left) + BTsize3(root->right) + 1;
}


int BinaryTreeLeafSize(BTnode* root)//计算叶子结点的个数
{
	if (root == NULL)
	{
		return 0;
	}

	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}

	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}



int BinaryTreeLevelKSize(BTnode* root,int k) {//计算第k层结点的个数
	if (root == NULL) {
		return 0;
	}
	if (k == 1) {
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

int main() {
	BTnode* root = Creatnode();
	/*prevorder(root);
	int cout = 0;
	BTsize2(root, &cout);
	printf("%d", cout);*/
	/*printf("%d", BinaryTreeLevelKSize( root,3));*/
	BinaryTreeFind(root, 'Z');
	
	
	
}