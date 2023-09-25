#include <iostream>
#include <queue>
#include <string>
using std::queue;

class Node {
    
public:
    Node(std::string name, float cost) : name_(name), cost_(cost) {}

    float getCost() const {
        return cost_;
    }
    std::string Name()const {return name_;};

    // Sobrecarga do operador '<' para definir a prioridade
    bool operator<(const Node& other) const {
        // Quanto menor o custo, maior a prioridade
        return cost_ > other.cost_;
    }

private:
    float cost_;
    std::string name_;
};

int main() {
    // Crie uma fila de prioridade de nós
    std::priority_queue<Node> priorityQueue;

    // Exemplo de criação de alguns nós
    Node node1("Q1",2.5);
    Node node2("Q2",1.0);
    Node node3("Q3",3.0);

    // Insira os nós na fila de prioridade
    priorityQueue.push(node1);
    priorityQueue.push(node2);
    priorityQueue.push(node3);
    priorityQueue.push(node3);


    // Acesse o nó de maior prioridade (menor custo)
    while(!priorityQueue.empty()){
        Node topNode = priorityQueue.top();
        std::cout << "Nó de maior prioridade: Custo = " << topNode.getCost() << std::endl;

        // Remova o nó de maior prioridade da fila
        priorityQueue.pop();
    }

    return 0;
}
