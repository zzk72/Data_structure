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
	p->NextBrother = NULL;//初始化根 
	TreeNode* root = p;
	int t = i;
	p->ch = pre[i++];
	for (int k = 0; k < cnt[t]; k++) {//链接儿子
		TreeNode* Nchild = Prebuild(pre, cnt, i);//建立儿子 
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