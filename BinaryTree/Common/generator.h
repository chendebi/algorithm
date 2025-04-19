#ifndef __alogrithm_generator_h__
#define __alogrithm_generator_h__

#include <iostream>  
#include <queue>  
#include <random>  
#include <cmath>  

#include "node.h"

// ������������ĸ�������  
int generateRandomNumber(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

// ��������������ĺ���  
Node* generateRandomBinaryTree(int maxDepth = 5, int targetNodes = -1) {
    if (maxDepth <= 0) return nullptr;

    // �������������Ľڵ�����ΪĬ��ֵ (2^depth - 1)  
    if (targetNodes == -1) {
        targetNodes = static_cast<int>(std::pow(2, maxDepth)) - 1;
    }

    // �������ڵ�  
    Node* root = new Node(generateRandomNumber(1, 100));
    targetNodes--;

    std::queue<std::pair<Node*, int>> nodeQueue; // �洢�ڵ㼰�䵱ǰ���  
    nodeQueue.push({ root, 1 });

    while (!nodeQueue.empty() && targetNodes > 0) 
    {
        auto current = nodeQueue.front();
        nodeQueue.pop();
        Node* currentNode = current.first;
        int currentDepth = current.second;

        // ��������Ƿ񴴽����ӽڵ�  
        if (currentDepth < maxDepth &&
            (targetNodes > 0 && (generateRandomNumber(0, 1) || targetNodes >= 2 * (maxDepth - currentDepth))))
        {
            currentNode->left = new Node(generateRandomNumber(1, 100));
            nodeQueue.push({ currentNode->left, currentDepth + 1 });
            targetNodes--;
        }

        // ��������Ƿ񴴽����ӽڵ�  
        if (currentDepth < maxDepth &&
            (targetNodes > 0 && (generateRandomNumber(0, 1) || targetNodes >= 2 * (maxDepth - currentDepth)))) {
            currentNode->right = new Node(generateRandomNumber(1, 100));
            nodeQueue.push({ currentNode->right, currentDepth + 1 });
            targetNodes--;
        }
    }

    return root;
}

// ������������ӡ����������α�����  
void printBinaryTree(Node* root) {
    if (!root) return;

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            Node* node = q.front();
            q.pop();
            std::cout << node->val << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        std::cout << std::endl;
    }
}

#endif // !__alogrithm_generator_h__
