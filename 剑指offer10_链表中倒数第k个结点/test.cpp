#include<iostream>
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
		if (count < k&&cur==nullptr){
			return nullptr;
		}
		while (cur != nullptr){
			cur = cur->next;
			pre = pre->next;
		}
		return pre;
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

int main(){
	Solution s1;
	//�ȴ�������
	s1.PushFront(1);
	s1.PushFront(2);
	s1.PushFront(3);
	s1.PushFront(4);
	s1.PushFront(5);

	system("pause");
	return 0;
}