#ifndef __alogrithm_generator_h__
#define __alogrithm_generator_h__

#include <iostream>  
#include <queue>  
#include <random>  
#include <cmath>  

#include "node.h"

// 生成随机整数的辅助函数  
int generateRandomNumber(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

// 生成随机二叉树的函数  
Node* generateRandomBinaryTree(int maxDepth = 5, int targetNodes = -1) {
    if (maxDepth <= 0) return nullptr;

    // 计算满二叉树的节点数作为默认值 (2^depth - 1)  
    if (targetNodes == -1) {
        targetNodes = static_cast<int>(std::pow(2, maxDepth)) - 1;
    }

    // 创建根节点  
    Node* root = new Node(generateRandomNumber(1, 100));
    targetNodes--;

    std::queue<std::pair<Node*, int>> nodeQueue; // 存储节点及其当前深度  
    nodeQueue.push({ root, 1 });

    while (!nodeQueue.empty() && targetNodes > 0) 
    {
        auto current = nodeQueue.front();
        nodeQueue.pop();
        Node* currentNode = current.first;
        int currentDepth = current.second;

        // 随机决定是否创建左子节点  
        if (currentDepth < maxDepth &&
            (targetNodes > 0 && (generateRandomNumber(0, 1) || targetNodes >= 2 * (maxDepth - currentDepth))))
        {
            currentNode->left = new Node(generateRandomNumber(1, 100));
            nodeQueue.push({ currentNode->left, currentDepth + 1 });
            targetNodes--;
        }

        // 随机决定是否创建右子节点  
        if (currentDepth < maxDepth &&
            (targetNodes > 0 && (generateRandomNumber(0, 1) || targetNodes >= 2 * (maxDepth - currentDepth)))) {
            currentNode->right = new Node(generateRandomNumber(1, 100));
            nodeQueue.push({ currentNode->right, currentDepth + 1 });
            targetNodes--;
        }
    }

    return root;
}

// 辅助函数：打印二叉树（层次遍历）  
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
