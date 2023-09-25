// PriorityQueueSearch.cpp
#include "PriorityQueueSearch.h"
#include<vector>
#include <iostream>
using std::vector;

void PriorityQueueSearch::Push(Node*& element) {
    priority_queue<Node*> tempData = data;
    while (!tempData.empty()) {
        Node* node = tempData.top();
        std::cout << " cost: " << node->Cost() << " "<< node << ", ";
        tempData.pop();
    }
     std::cout << "\n";
    data.push(element);
}

Node* PriorityQueueSearch::Pop() {
    Node* element = data.top();
    data.pop();
    return element;
}

bool PriorityQueueSearch::IsEmpty() const {
    return data.empty();
}

bool PriorityQueueSearch::Exist(const Node* element) const {
    priority_queue<Node*> tempData = data;
    while (!tempData.empty()) {
        if (tempData.top() == element) {
            return true;
        }
        tempData.pop();
    }
    return false;
}

bool PriorityQueueSearch::ExistLargeThan(Node* element) const {
    priority_queue<Node*> tempData = data;
    while (!tempData.empty()) {
        Node* top = tempData.top();
        if (top->GetState() == element->GetState() && top->Cost() > element->Cost()) {
            return true;
        }
        tempData.pop();
    }
    return false;
}


void  PriorityQueueSearch::RemoveLargeThanBy(Node* element) {
    vector<Node*> newNodes;
    while (!data.empty()) {
        Node* node = data.top();
        data.pop();

        if (node->GetState() == element->GetState() && node->Cost() < element->Cost()) {
            //node->DeletePath();
            //delete node;
            break; 
        }
        newNodes.push_back(node);
    }

    for (Node* node : newNodes) {
        data.push(node);
    }
}
