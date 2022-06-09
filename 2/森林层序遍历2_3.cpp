/*
7-2 森林的层次遍历
分数 100
作者 谷方明
单位 吉林大学
给定一个森林F，求F的层次遍历序列。森林由其先根序列及序列中每个结点的度给出。

输入格式:
第1行，1个整数n，表示森林的结点个数， 1≤n≤100000.

第2行，n个字符，用空格分隔，表示森林F的先根序列。字符为大小写字母及数字。

第3行，n个整数，用空格分隔，表示森林F的先根序列中每个结点对应的度。

输出格式:
1行，n个字符，用空格分隔，表示森林F的层次遍历序列。

输入样例:
在这里给出一组输入。例如：

14
A B C D E F G H I J K L M N
4 0 3 0 0 0 0 2 2 0 0 0 1 0
输出样例:
在这里给出相应的输出。例如：

A M B C G H N D E F I L J K
代码长度限制
16 KB
时间限制
100 ms
内存限制
5 MB
*/
#include<iostream>
#include<vector>

using namespace std;
typedef struct tree {
	char ch;
	struct tree* Firstchild, * NextBrother;
}TreeNode;

int p = 0,tp=0;
char* ch;
int* cnt;
int num = 0;
TreeNode** root;
TreeNode* Prebuild(char* pre, int* cnt, int& i) {
	TreeNode* p = new TreeNode;
	p->Firstchild = NULL;
	p->NextBrother = NULL;//³õÊ¼»¯¸ù 
	TreeNode* root = p;
	int t = i;
	p->ch = pre[i++];
	for (int k = 0; k < cnt[t]; k++) {//Á´½Ó¶ù×Ó
		TreeNode* Nchild = Prebuild(pre, cnt, i);//½¨Á¢¶ù×Ó 
		if (k == 0)p->Firstchild = Nchild;
		else p->NextBrother = Nchild;
		p = Nchild;
	}
	return root;
}

void levelorder(TreeNode* root) {
	TreeNode** Q=new TreeNode*[p], * tmp = NULL;
	int f = 0, r = 0, cnt = 0;
	Q[r++] = root;
	cnt++;
	while (cnt != 0) {
		tmp = Q[f++];
		cnt--;
		while (tmp) {
			cout << tmp->ch; tp++;
			if (tp < p)cout << " ";
			else cout << endl;
			if (tmp->Firstchild) {
				Q[r++] = tmp->Firstchild;
				cnt++;
			}
			tmp = tmp->NextBrother;
		}
	}
}
int main() {
	scanf("%d",&p);
	ch = new char[p];
	cnt = new int[p];
	root = new TreeNode * [p];
	for (int i = 0; i < p; i++) {
		cin >> ch[i];
	}
	fflush(stdin);
	for (int i = 0; i < p; i++) {
		cin >> cnt[i];
	}
	int mp = 0;

	TreeNode* root=Prebuild(ch, cnt, mp),*tp;
	tp = root;
	while (mp < p) {
		tp ->NextBrother= Prebuild(ch, cnt, mp);
		tp = tp->NextBrother;
	}
	
	//	cout << "mp=" << mp<<endl;
	levelorder(root);
	
}
/* 
7
A B C D E F G
2 0 0 0 2 0 0
*/
/*
14
A B C D E F G H I J K L M N
4 0 3 0 0 0 0 2 2 0 0 0 1 0

*/
