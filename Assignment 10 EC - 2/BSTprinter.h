#pragma once
#include <math.h>
#include <vector>
#include "ClassFunctions.h"


template< class type > class Tree;

template<class type>
class BTreePrinter {
	friend class Tree<type>;
public:
	BTreePrinter(){}
	~BTreePrinter(){}

	void printNode(node * root) {
        int lvlMax = maxLevel(root);
		std::vector< node * > rootVect;
		rootVect.push_back(root);
        printNodeInternal(rootVect, 1, lvlMax);
    }

private:
	void printNodeInternal( std::vector< node *> nodes, int level, int maxLevel) {
        if (nodes.empty() || isAllElementsNull(nodes))
            return;

        int floor = maxLevel - level;
        int edgeLines = (int) pow((float)2, (std::max(floor - 1, 0)));
        int firstSpaces = (int) pow((float)2, (floor)) - 1;
        int betweenSpaces = (int) pow((float)2, (floor + 1)) - 1;

        printWhitespaces(firstSpaces);

        std::vector< node*> newNodes;
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i] != NULL) {
                std::cout << nodes[i]->key;
                newNodes.push_back(nodes[i]->left);
                newNodes.push_back(nodes[i]->right);
            } else {
                newNodes.push_back(NULL);
                newNodes.push_back(NULL);
                std::cout << " ";
            }

            printWhitespaces(betweenSpaces);
        }
        std::cout << std::endl;

        for (int i = 1; i <= edgeLines; i++) {
            for (int j = 0; j < nodes.size(); j++) {
                printWhitespaces(firstSpaces - i);
                if (nodes[j] == NULL) {
                    printWhitespaces(edgeLines + edgeLines + i + 1);
                    continue;
                }

                if (nodes[j]->left != NULL)
                    std::cout << "/";
                else
                    printWhitespaces(1);

                printWhitespaces(i + i - 1);

                if (nodes[j]->right != NULL)
                    std::cout << "\\";
                else
                    printWhitespaces(1);

                printWhitespaces(edgeLines + edgeLines - i);
            }

            std::cout << std::endl;
        }

        printNodeInternal(newNodes, level + 1, maxLevel);
    }

    void printWhitespaces(int count) {
        for (int i = 0; i < count; i++)
            std::cout << " ";
    }

    int maxLevel(node * node) {
        if (node == NULL)
            return 0;

        return std::max(maxLevel(node->left), maxLevel(node->right)) + 1;
    }

    bool isAllElementsNull(std::vector<node*> list) {
        for (int i = 0; i < list.size(); i++) {
            if (list[i] != NULL)
                return false;
        }

        return true;
    }

};
