//C++
//————————————————————单向链表
#include<iostream>
struct ListNode
{
	int data;
	ListNode* next;
	ListNode(int a) { data = a;next = NULL;}
};
//插入
void Insert(ListNode* head, ListNode* p, int K)//要在p的右侧插入新的结点
{
	if (p == NULL)return;//判空机制,若满足条件自动弹出，无需else语句
	ListNode* s = new ListNode(K);//新建结点，new语句，清除时用delete
	s->next = p->next;
	p->next = s;
}
//创建（头插法）
ListNode* BuildList(int n)/*这里的n指的是有效结点数*/ {
	//先创建哨位结点
	ListNode* head = new ListNode(n);//哨位节点data为有效节点数
	int K;
	while (n--)//总共执行n次
	{
		scanf("%d", &K);
		Insert(head, head, K);
	}
	return head;//从无到有创建，故不能返回空
}
//第一查找法：按序查找
ListNode* FindKth(ListNode* head, int k) {
	if (k < 0)return NULL;//数值判空，返回空指针
	ListNode* p = head;
	int i = 0;
	while (p != NULL && i < k)//有效判别与范围判别
	{
		p = p->next;
		i++;
	}
	return p;
}
//第二查找法：按值查找
ListNode* Search(ListNode* head, int k) {
	ListNode* p = head->next;//直接指向第一有效结点即可
	while ( p != NULL&& p->data != k)
	{
		p = p->next;
	}
	return p;
}
//第三查找法：溯源查找（找前驱）
ListNode* FindPrev(ListNode* head, ListNode* p)
{
	if (p == NULL)return NULL;//指针判空
	ListNode* temp= head;
	while (temp!=NULL&&temp->next != p)//注意条件判别顺序防止短路，指针判空是最优先的
	{
		temp=temp->next;
	}
	return temp;
}
//删除
void Delete(ListNode* head, ListNode* p)//删除p的后继结点
{
	if (p == NULL || p->next == NULL)return;
	ListNode* temp = p->next;
	p->next = temp->next;
	delete(temp);
}//若就想删除p，先用FindPrev找到前驱结点。
//变通做法，若p非表尾，将p后继结点的数据赋给p，然后删除后继。
//————————————————————循环链表
//————————————————————双向链表
struct Listnode {
	int data;
	Listnode* prev;
	Listnode* next;
	Listnode(int d) { data = d;prev = next = NULL; }
};
//删除
void Delete(Listnode* head, Listnode* p)//不要忘记head，判断是否为哨位结点，如果是，删去无意义
{
	if (p == NULL || p == head)return;
	Listnode* prev = p->prev;
	Listnode* next = p->next;
	prev->next = next;
	next->prev = prev;
	delete  p;
}
//插入
void Insert(Listnode* head,Listnode* p, int k)//最好也去判断尾结点，否则无法使用next；
{
	if (p == NULL)return;
	Listnode* temp = new Listnode(k);
	Listnode* next = p->next;
	temp->next = next;
	next->prev = temp;
	temp->prev = p;
	p->next = temp;
}
