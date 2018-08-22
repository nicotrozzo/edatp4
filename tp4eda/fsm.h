#ifndef FSM_H
#define FSM_H

#include <iostream>

typedef enum {IDLE,WAIT_NAME,NAME_STR,WAIT_COLON,WAIT_VALUE,VAL_STRING,BOOL,OBJECT,ARRAY,NUMBER,VAL_NULL,WAIT_OTHER_MEMBER,ERROR,END}stateType;
typedef enum {WHITE_SPACE}eventType;

typedef struct
{
	stateType nextState;
	void(*act_routine)(void*);
}cellType;

#define NUM_OF_EVENTS 
#define NUM_OF_STATES 14

class fsm
{
public:
	fsm(void* data = NULL);
	void cycle(const eventType &ev);
	stateType getCurrState();

private:
	stateType currentState;
	void* userData;
	//const cellType FSMtable[NUM_OF_STATES][NUM_OF_EVENTS];
};

#endif