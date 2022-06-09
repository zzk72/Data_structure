//#pragma once
//#include<iostream>
//using namespace std;
//typedef struct haff {
//	long long weight;
//	struct haff* left, * right;
//
//}Haff;
//
//class Haff_heap {
//public:	
//	int len;
//	Haff** H;
//	void down(int i);
//	void up(int i);
//	void swap(Haff*& x, Haff*& y) { Haff* t; t = x; x = y; y = t; }
//
//	Haff* front(void) { return H[1]; }
//	int size(void) { return len; };
//	void set(long long* a,int n);
//	void buildheap(void);
//	Haff* pop(void);
//	void insert(Haff*);
//	void levelorder(void);
//};
//
//Haff* Haff_heap::pop(void) {
//	if (len < 1)return NULL;
//	Haff* tmp = H[1];
//	swap(H[1], H[len]);
//	len--;
//	down(1);
//	return tmp;
//}
//
//void Haff_heap::insert(Haff* t) {
//	H[++len] = t;
//	up(len);
//}
//
//void Haff_heap::up(int p) {
//	while (p > 1 && H[p]->weight < H[p / 2]->weight) {
//		swap(H[p], H[p / 2]);
//		p /= 2;
//	}
//}
//
//void Haff_heap::down(int p) {//下沉a[p] 
//	while (p <= len / 2) {
//		int y = 2 * p;
//		if (y<len/*判断，只要y<len,就有y+1<=len*/ && H[2 * p]->weight>H[2 * p + 1]->weight) {
//			y++;
//		}
//		if (H[y]->weight < H[p]->weight) {
//			swap(H[y], H[p]);
//			p = y;
//		}
//		else break;
//	}
//}
//void Haff_heap::set(long long* a,int n)
//{
//	len = n;
//	H = new Haff * [n + 1];
//	for (int i = 0; i <= len; i++) {
//		H[i] = new Haff;
//		H[i]->weight = a[i];
//		H[i]->left = NULL;
//		H[i]->right = NULL;
//	}
//	buildheap();
//}
//void Haff_heap::buildheap() {
//	for (int i = len / 2; i >= 1; i--) {
//		down(i);
//	}
//}
//
//Haff* HAFFMANTREE(class Haff_heap& heap) {
//	while (heap.size() > 1) {
//		Haff* t1, * t2, * t = new haff;//切记切记一定要重新申请新的空间，否则会覆盖掉之前的 
//		t1 = heap.pop();
//		t2 = heap.pop();
//		if (!t1 || !t2) { cout << "堆已空" << endl; return NULL; }
//		t->weight = t1->weight + t2->weight;
//		t->left = t1; t->right = t2;
//		heap.insert(t);
//	}
//	return heap.front();
//}
//
//void Haff_heap::levelorder(void) {
//	Haff* root = H[1];
//	Haff** Q=new Haff*[len+5], * tmp = NULL;
//	int f = 0, r = 0, cnt = 0;
//
//	Q[r++] = root;
//     cnt++;
//	 r %= len;
//	while (cnt != 0) {
//		tmp = Q[f++];
//		f %= len;
//		cnt--;
//		if (tmp) {
//			printf("%lld ", tmp->weight);
//			if (tmp->left) {
//				Q[r++] = tmp->left;
//				r %= len;
//				cnt++;
//			}
//			if (tmp->right) {
//				Q[r++] = tmp->right;
//				r %= len;
//				cnt++;
//			}
//		}
//	}
//
//}
//
//int main() {
//	Haff_heap tree;
//	int n;
//	scanf("%d", &n);
//	long long* a = new long long[n + 1]{0};
//	for (int i = 1; i <= n; i++) {
//		scanf("%lld", &a[i]);
//	}
//	tree.set(a, n);
//	HAFFMANTREE(tree);
//	for (int i = 1; i < n; i++) {
//		cout << tree.H[i]->weight << " ";
//	}
//}
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 1e6 + 6;
typedef long long ll;

ll n, t, ans[maxn];
inline ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') { f = -1; }
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = (x << 3) + (x << 1)/* x*10 */ + (ch ^ 48)/*即x-48 */;
		ch = getchar();
	}
	return f * x;
}//快读数字 可以用cin或者scanf
int main() {
	priority_queue<ll, vector<ll>, greater<ll> > q;//优先升序队列
	n = read();
	for (int i = 1; i <= n; i++) {
		t = read();//关于为什么不开一个数组的问题，因为1e6感觉会mle
		q.push(t);
	}

	for (int i = 1; i < n; i++) {
		int m = q.top(); q.pop();
		int n = q.top(); q.pop();//这两段 每次都取最小值
		q.push(m + n);
		ans[i] = m + n;//根 可以参考上面的图 也就是母带的长度
	}

	long long res = 0;
	for (int i = 1; i < n; i++) {
		res += ans[i];
	}

	cout << res << endl;
	for (int i = n - 1; i >= 1; --i) {
		cout << ans[i];
		if (i != 1) {
			cout << " ";
		}
	}
}