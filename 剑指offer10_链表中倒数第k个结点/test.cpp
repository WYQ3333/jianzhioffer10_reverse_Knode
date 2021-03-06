#include<iostream>
#include<stack>

#include<assert.h>
#include<list>

using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

typedef int DataType;

class Solution {
public:
	Solution()
		:_phead(nullptr)
	{}

	ListNode* BuyNewNode(DataType val){
		ListNode * NewNode = (ListNode*)new ListNode(val);
		return NewNode;
	}
	void PushFront(DataType data){
		ListNode* NewNode = BuyNewNode(data);
		if (NewNode == nullptr){
			assert(NewNode);
			return;
		}
		NewNode->next = _phead;
		_phead = NewNode;
	}
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* cur = pListHead;
		ListNode* pre = pListHead;
		int count = 0;
		while (cur != nullptr&&count < k){
			cur = cur->next;
			++count;
		}
		if (count < k&&cur == nullptr){
			return nullptr;
		}
		while (cur != nullptr){
			cur = cur->next;
			pre = pre->next;
		}
		return pre;
	}

	ListNode* ReverseList1(ListNode* pHead){
		//定义三个指针
		ListNode* pre = pHead;
		ListNode* cur = pHead;
		ListNode* nPhead = nullptr;
		while (nullptr != cur){
			pre = cur;
			cur = cur->next;
			//头插放入新的链表中
			pre->next = nPhead;
			nPhead = pre;
		}
		return nPhead;
	}

	ListNode* ReverseList2(ListNode* pHead) {

		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		ListNode* p = pHead;
		stack<ListNode* > s;
		while (p->next)
		{
			s.push(p);
			p = p->next;
		}
		ListNode* head = p;
		while (!s.empty())
		{
			p->next = s.top();
			p = p->next;
			s.pop();
		}
		p->next = NULL;
		return head;
	}

	//第三种方法：只使用两个指针
	ListNode* ReverseList3(ListNode* pHead){
		if (nullptr == pHead || nullptr == pHead->next){
			return pHead;
			//没有节点或者只有一个节点的情况
		}
		ListNode* p = pHead->next;
		ListNode* q = nullptr;
		while (p->next){
			q = p->next;
			p->next = q->next;
			q->next = pHead->next;
			pHead->next = q;
		}
		//出了循环之后p指向链表的最后一个节点，此时链表顺序为51234
		//所以要将phead的结点接到p之后
		ListNode* cur = pHead;
		pHead = cur->next;
		cur->next = nullptr;
		p->next = cur;
		return pHead;
	}

	~Solution(){
		ListNode* cur = _phead;
		while (cur){
			cur = cur->next;
			delete _phead;
			_phead = cur;
		}
	}
public:
	ListNode* _phead;
};


void TestFunc3(){
	Solution s3;
	//先创建链表
	s3.PushFront(1);
	s3.PushFront(2);
	s3.PushFront(3);
	s3.PushFront(4);
	s3.PushFront(5);
	ListNode* cur = nullptr;
	cout << "逆转前的单链表为：";
	cur = s3._phead;
	while (cur){
		cout << cur->val << "-->";
		cur = cur->next;
	}
	cout << endl;
	cur = s3.ReverseList3(s3._phead);
	cout << "逆转后的单链表为：";
	while (cur){
		cout << cur->val << "-->";
		cur = cur->next;
	}
	cout << endl;
	
}


void TestFunc(){
	Solution s1;
	//先创建链表
	s1.PushFront(1);
	s1.PushFront(2);
	s1.PushFront(3);
	s1.PushFront(4);
	s1.PushFront(5);

	//找倒数第k个结点
	ListNode* cur = s1.FindKthToTail(s1._phead, 3);
	//找倒数第三个，应该是3；
	cout << "倒数第k个结点为:";
	cout << cur->val << " " << endl;
}

void TestFunc2(){
	Solution s1;
	ListNode* cur = nullptr;
	//先创建链表
	s1.PushFront(1);
	s1.PushFront(2);
	s1.PushFront(3);
	s1.PushFront(4);
	s1.PushFront(5);
	cur = s1._phead;
	cout << "逆转前的链表为：" << endl;
	while (cur){
		cout << cur->val << "-->";
		cur = cur->next;
	}
	cout << endl;
	cout <<"逆转后的链表为："<< endl;
	cur = s1.ReverseList2(s1._phead);
	while (cur){
		cout << cur->val << "-->";
		cur = cur->next;
	}
}

int main(){

	TestFunc3();
	//Solution s1;
	////先创建链表
	//s1.PushFront(1);
	//s1.PushFront(2);
	//s1.PushFront(3);
	//s1.PushFront(4);
	//s1.PushFront(5);

	////找倒数第k个结点
	//ListNode* cur = s1.FindKthToTail(s1._phead, 3);
	////找倒数第三个，应该是3；
	//cout << "倒数第k个结点为:";
	//cout << cur->val << " " << endl;

	system("pause");
	return 0;
}