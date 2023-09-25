#ifndef DXUT_AI_ISTATE_H
#define DXUT_AI_ISTATE_H
//------------------------------------------
#include<vector>
#include <string>
using std::vector;
//------------------------------------------
class Transition;
//------------------------------------------

class State {
private:
	std::string name;
	vector<Transition*>* edges;
	void DeleteEdges();
public:
	State();
	State(std::string name);
	~State();


	vector<Transition*>* Edges() const;
	std::string Name() const;
	void AddTransition(Transition* transition);

	//------------------------------------------
//	virtual bool IsTriggered() const = 0;		// M�todo para verificar se a transi��o deve ocorrer
//	virtual State* GetTargetState() const = 0; // M�todo para obter o estado de destino da transi��o
};

inline std::string State::Name() const { return name; }


#endif