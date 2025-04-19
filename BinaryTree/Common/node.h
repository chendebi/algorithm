#ifndef __alogrithm_node_h__
#define __alogrithm_node_h__

struct Node
{
	int val = 0;
	Node* left = nullptr;
	Node* right = nullptr;

	Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

#endif // !__alogrithm_node_h__
