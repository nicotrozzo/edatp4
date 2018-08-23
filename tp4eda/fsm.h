#ifndef FSM_H
#define FSM_H

#include <iostream>

typedef enum {IDLE,WAIT_NAME,NAME_STR,WAIT_COLON,WAIT_VALUE,VAL_STRING,BOOL,OBJECT,ARRAY,NUMBER,VAL_NULL,WAIT_OTHER_MEMBER,FIN,END}stateType;
typedef enum {WHITE_SPACE}eventType;

typedef struct
{
	stateType nextState;
	void(*act_routine)(void*);
}cellType;

#define NUM_OF_EVENTS 5 
#define NUM_OF_STATES 5

typedef enum { IDLE, SEARCH_NAME, GET_VALUE, FIN }stateType;
typedef enum { WS, LLAVE_A, LLAVE_B, DOS_PUNTOS, COMA }eventType;


class fsm
{
public:
	fsm(void* data = NULL);
	void cycle(stateType *currState, const eventType currEv, void *userData);
	stateType getCurrState();

private:
	stateType currentState;
	void* userData;
	//const cellType FSMtable[NUM_OF_STATES][NUM_OF_EVENTS];
};

#endif