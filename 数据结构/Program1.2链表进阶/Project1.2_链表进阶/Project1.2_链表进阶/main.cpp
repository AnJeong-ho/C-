//————————————————————查找倒数第K个结点的数值
#include<iostream>
struct ListNode
{
	int data;
	ListNode* next;
};
int FindBack_K(ListNode* head, int k)
{
	if (head == NULL || k <= 0)return 0;
	ListNode* slow = head;
	ListNode* fast = head;
	for(int i = 1;i < k&&fast!=NULL;i++)
		fast = fast->next;//注意，这是移动结点指针的常用语法，在限制步数的同时判断是否为空
	if (fast == NULL)return 0;//若为空，返回弹出
	while (fast->next!= NULL)//同时移动
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow->data;
}//复杂度O(n)
//其余两种解法，一个是：用遍历得到总长，对最末尾进行k-1次取前驱，复杂度O(n²)
//另一个是，遍历得到总长，通过数学运算得到正数是第几个，正着遍历，复杂度是O(n)


//————————————————————找单链表的中间结点
ListNode* FindMiddle(ListNode* head)
{
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast != NULL && fast->next != NULL)//偶数情况返回的是右侧的，要想是左侧，fast!=NULL改为fast->next->next!=NULL
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}


//————————————————————反转链表
//看似困难，其实逐步拆解即可，再用循环遍历
ListNode* Reverse(ListNode* head)
{
	if (head == NULL)return NULL;
	ListNode* p = head;
	ListNode* q = head->next;
	while (p->next != NULL)
	{
		p->next = q->next;
		q->next = head;
		head = q;
		q = p->next;
	}
	return head;
}
//进阶：成组反转
ListNode* kth(ListNode* head, ListNode* p,int k)//找寻p之后第k个结点
{
	if (p==NULL||k < 0)return NULL;
	ListNode* q = p;
	for (int i = 0;i < k&&q!=NULL;i++)
	{
		q = q->next;
	}
	if (q == NULL)return NULL;
	return q;
}
ListNode* Prev(ListNode* head, ListNode* p) //找前驱
{
	if (p == NULL || p == head) return NULL;  // 添加p==head判断
	ListNode* q = head;
	while (q != NULL && q->next != p) {
		q = q->next;
	}
	return q;  // 直接返回q
}
ListNode* Rev(ListNode* head, ListNode* p, int k)//p到p之后k个结点范围内
{
	if (kth(head, p, k - 1) == NULL)return head;
	ListNode* temp = kth(head, p, k);
	kth(head, p, k - 1)->next = NULL;
	p= Reverse(p);
	kth(head, p, k - 1) -> next = temp;
	return head;
}
ListNode* reverse(ListNode* head, int k)
{
	if (head == NULL||k<=1)return head;
	ListNode* p = head->next;
	if (kth(head, head->next, k - 1) == NULL)return head;
	while (kth(head,p,k-1)!=NULL)
	{
		Rev(head, p, k);
		p = kth(head, p, k);
	}
	return head;
}


//————————————————————链表相交问题
//重点是了解模型的性质，两链表必汇于一点，之后是重合的，那么让短链表先移动，使两链表并驾齐驱，若相等，找到交点；
ListNode* cross(ListNode* head1, ListNode* head2)
{
	if (head1 == NULL || head2 == NULL)return NULL;
	ListNode* p1=head1,*p2=head2;
	int L1=1, L2=1;//长度
	while (p1->next!= NULL)
	{
		L1++;
		p1 = p1->next;
	}//得到长度
	while (p2->next != NULL)
	{
		L2++;
		p2 = p2->next;
	}//得到长度
	if (p1 != p2)return NULL;//不相交
	int Difference = (L1 > L2 ? L1 - L2 : L2 - L1);
	if (L1 > L2)
	{
		p1 = head1;
		for (int i = 0;i < Difference;i++)
		{
			p1 = p1->next;
		}
		p2 = head2;
	}
	else
	{
		p2 = head2;
		for (int i = 0;i < Difference;i++)
		{
			p2 = p2->next;
		}
		p1 = head1;
	}
	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}


//————————————————————单链表判环问题
//使p=head;p=p->next;循环下去
//若无环，则必有p=NULL；
//若有环，也要判断结束标志，否则死循环
//怎么判断结束标志呢，运用双指针，一个slow，一个fast，若有环，必须在某一时刻重合
//——————————返回布尔型
bool detcetCycle(ListNode* head)
{
	if (head == NULL)return 0;
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast!=NULL&&fast->next != NULL)
	{
		
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return 1;
	}
	return 0;
}
//——————————返回环的入口
//根据数学关系，p1=head到入口的距离L1和p2=相遇点到入口的距离L2满足关系L1=L2+(n-1)L。L为环长，当且仅当fast指针进入环一圈便相遇，则L1=L2;
//综上，无论如何，p1与p2都是同时到达入口，故无需对齐；
ListNode* detectCycleEntrence(ListNode* head)
{
	if (head == NULL)return NULL;
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast != NULL && fast->next != NULL)
	{

		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			ListNode* p1 = fast;
			ListNode* p2 = head;
			while (p1 != p2)
			{
				p1 = p1->next;
				p2 = p2->next;
			}
			return p1;
		}
	}
	return NULL;
}


//————————————————————判断一个单链表是否回文
//找到中间节点，使后半部分链表翻转
bool FindHw(ListNode* head)
{
	if (head == NULL)return 1;//判断head为空，更加严谨
	if (head->next == NULL)return 1;//单结点自动为回文；
	ListNode* p = FindMiddle(head);
	ListNode* q = p->next;
	p->next = NULL;
	q = Reverse(q);
	p = head;
	while (p != NULL && q != NULL)
	{
		if (p->data != q->data)
		{
			return 0;
		}
		p = p->next;
		q = q->next;
	}
	return 1;
}



//————————————————————重排链表结点
ListNode* reorderList(ListNode* head)
{
	if (head == NULL)return head;//判空
	if (head->next == NULL)return head;//判单个
	ListNode* t = FindMiddle(head);
	ListNode* q = t->next;
	t->next = NULL;
	q = Reverse(q);//将后半部分链表翻转，进而从an开始依次加入
	ListNode*p = head;
	while (p!=NULL&&q!=NULL)//加入的过程
	{
		ListNode* temp1 = p->next;
		ListNode* temp2 = q->next;
		p->next = q;
		q->next = temp1;
		q = temp2;
		p = temp1;
	}
	return head;
}




//——————————————————一元多项式及其操作
//每个结点包含两个数据域和一个链接域
//数据域包括系数和指数
//——————————两多项式相加
struct MultiList
{
	int coef;
	int exp;
	MultiList* next;
};
MultiList* Add(MultiList* head1, MultiList* head2)//有哨位结点，无需判别head非空
{
	MultiList* p = head1;
	MultiList* p1 = head1->next;
	MultiList* p2 = head2->next;
	while (1)
	{
		if (p1 == NULL && p2 == NULL)
		{
			return head1;
		}
		if (p2==NULL||p1->exp < p2->exp)
		{
			p->next = p1;
			p = p->next;
			p1 = p1->next;
		}
		else if (p1==NULL||p1->exp > p2->exp)
		{
			p->next = p2;
			p = p->next;
			p2 = p2->next;
		}
		else
		{
			int sum = p1->coef + p2->coef;
			if (sum != 0)
			{
				p1->coef = sum;
				p->next=p1;
				p = p->next;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
	}
}








