#include "generator.h"

// 示例用法  
int main() {
    // 生成默认的5层满二叉树  
    Node* tree1 = generateRandomBinaryTree();
    std::cout << "Default 5-level full binary tree:" << std::endl;
    printBinaryTree(tree1);

    // 生成深度为3，节点数为5的随机二叉树  
    Node* tree2 = generateRandomBinaryTree(3, 100);
    std::cout << "\nRandom binary tree with depth 3 and 5 nodes:" << std::endl;
    printBinaryTree(tree2);

    // 生成深度为4的满二叉树  
    Node* tree3 = generateRandomBinaryTree(4);
    std::cout << "\n4-level full binary tree:" << std::endl;
    printBinaryTree(tree3);

    return 0;
}