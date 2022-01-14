//����������ĵݹ����յĺܲ��ã�������Ҫ�������濴�ݹ�һ��




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

void prevorder(BTnode* root) {//�������   �� ������ ������
	if (root == NULL) {
		printf("NULL ");
		return;
	}
		
		printf("%c ", root->data);
	prevorder(root->left);
	prevorder(root->right);
}



void inorder(BTnode*root) {//�������                ������ ��  ������
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	inorder(root->left);
	printf("%c ", root->data);
	inorder(root->right);

}


void postorder(BTnode*root) {//�������		������ ������ ��
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	postorder(root->left);
	postorder(root->left);
	printf("%c ", root->data);


}

int BTsize1(BTnode*root) {//�������еĽ�����
	if (root == NULL) {
		
		return;
	}
	static int cout = 0;//��һ�ַ����þ�̬�������м���
	cout++;
	BTsize1(root->left);
	BTsize1(root->right);
	return cout;

}

void BTsize2(BTnode*root,int *ps) {//�ڶ��ַ�����psָ���������մ������Ĳ��������м���
	if (root == NULL) {
		return;
	}
	(*ps)++;
	BTsize2(root->left,ps);
	BTsize2(root->right,ps);
	
}


int BTsize3(BTnode*root) {//�����ַ������÷��εķ������еݹ鷵�ؼ���
	return root == NULL ? 0 : BTsize3(root->left) + BTsize3(root->right) + 1;
}


int BinaryTreeLeafSize(BTnode* root)//����Ҷ�ӽ��ĸ���
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



int BinaryTreeLevelKSize(BTnode* root,int k) {//�����k����ĸ���
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