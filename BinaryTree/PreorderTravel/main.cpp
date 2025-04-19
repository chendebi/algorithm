#include "generator.h"

// ʾ���÷�  
int main() {
    // ����Ĭ�ϵ�5����������  
    Node* tree1 = generateRandomBinaryTree();
    std::cout << "Default 5-level full binary tree:" << std::endl;
    printBinaryTree(tree1);

    // �������Ϊ3���ڵ���Ϊ5�����������  
    Node* tree2 = generateRandomBinaryTree(3, 100);
    std::cout << "\nRandom binary tree with depth 3 and 5 nodes:" << std::endl;
    printBinaryTree(tree2);

    // �������Ϊ4����������  
    Node* tree3 = generateRandomBinaryTree(4);
    std::cout << "\n4-level full binary tree:" << std::endl;
    printBinaryTree(tree3);

    return 0;
}