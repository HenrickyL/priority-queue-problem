#ifndef DXUT_AI_TRANSITION_H
#define DXUT_AI_TRANSITION_H
//------------------------------------------
class State;
class Action;

//------------------------------------------

class Transition {
private:
	State* target;
	Action* action;
public:
	Transition(State*& state, Action* act);


	State* GetState() const;
	Action* GetAction() const;

	//virtual void Enter() = 0;	// M�todo de entrada no estado
	//virtual void Execute() = 0; // M�todo para a l�gica do estado
	//virtual void Exit() = 0;	// M�todo de sa�da do estado
};




#endif