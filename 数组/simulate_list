#include <stdio.h>

/**
上网搜洛克P1160
这是一道数组模拟双向队列的问题，因为要频繁的在链表中第i个位置
的左右两侧插入节点，所以结合链表和数组的特点
*/

#define N 100005

struct node{
	int l;  //存左边同学的编号
	int r; //存右边同学的编号
} list[N];

int main()
{
	//list initial
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		list[i].l = -1;
		list[i].r = -1;
	}
	list[0].l = -1;
	list[0].r = 1;
	list[1].l = 0;
	//list add
	for (int i = 2; i <= n; i++) {
		int k, p;
		scanf("%d,%d", &k, &p);
		if (p == 0) {
			list[i].r = k;
			list[list[k].l].r = i;
			list[i].l = list[k].l;
			list[k].l = i;
		}
		if (p == 1) {
			list[i].l = k;
			list[list[k].r].l = i;
			list[i].r = list[k].r;
			list[k].r = i;
		}
	}
	//list delete
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int d = 0;
		scanf("%d", &d);
		if (list[d].l == -1 && list[d].r == -1) {
			continue;
		}
		list[list[d].l].r = list[d].r;
		list[list[d].r].l = list[d].l;
		list[d].l = -1;
		list[d].r = -1;
	}
	//list print
	int x = list[0].r;
	for (int i = 0; x != -1; i++) {
		printf("%d ", x);
		x = list[x].r;
	}
	return 0;
}
