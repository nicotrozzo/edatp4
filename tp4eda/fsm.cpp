#include "fsm.h"

fsm::fsm()
{

}

void fsm::cycle(stateType *currState, const eventType currEv, void *userData)
{
	const cellType FSMtable[NUM_OF_STATES][NUM_OF_EVENTS] =
	//	  WHITE_SPACE		  ||	LLAVE
	{	{{non_act_routine,IDLE},{non_act_routine,WAIT_NAME},{}},	//IDLE
		{{},{},{}},		//WAIT_NAME
		{{},{},{}},		//NAME_STR
		{{},{},{}},		//WAIT_COLON
		{ {},{},{}},	//WAIT_VALUE
		{ {},{},{} },	//VAL_STRING
		{ {},{},{} },	//BOOL
		{ {},{},{}},	//OBJECT
		{ {},{},{} },	//ARRAY
		{ {},{},{} },	//NUMBER
		{ {},{},{}},	//VAL_NULL
		{ {},{},{} },	//WAIT_OTHER_MEMBER
		{ {},{},{} },	//ERROR
		{ {},{},{} }	//END
	}
//	typedef enum { IDLE, WAIT_NAME, NAME_STR, WAIT_COLON, WAIT_VALUE, VAL_STRING, BOOL, OBJECT, ARRAY, NUMBER, VAL_NULL, WAIT_OTHER_MEMBER, ERROR, END }stateType;

}