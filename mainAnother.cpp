#include<iostream>
#include<string>

#include "Node.h"
#include "Action.h"
#include "Transition.h"
#include "PriorityQueueSearch.h"
#include "State.h" 
#include <queue>
using std::priority_queue;

int main(){

    State* a1 = new State("Q1"); State* a2 = new State("Q2"); State* a3 = new State("Q3");

    Action* act1 = new Action(1.0f); Action* act2 = new Action(20.0f); Action* act3 = new Action(5.0f);

    Node* n1 = new Node(a1, act1); Node* n2 = new Node(a1, act2); Node* n3 = new Node(a1, act3);
    // Node* n4 = new Node(a2, act1);
    // Node* n5 = new Node(a3, act1);
    std::cout<< &n1 << " " << &n2 << " " << &n3 << "\n";

    //HERE:
    //priority_queue<Node*> q;
    //or
    PriorityQueueSearch q;

    q.Push(n1); q.Push(n2); q.Push(n3);
    // q.Push(n4);
    // q.Push(n5);
    
    //remove & print
    while(!q.IsEmpty()){
        Node* node = q.Pop(); 

        std::cout<< node->GetState()->Name() << " cost: " << node->Cost() << " "  << node << "\n";
    }

    delete a1,a2,a3, n1,n2,n3, act1, act2, act3;
    // delete n4, n5;

    return 0;
}