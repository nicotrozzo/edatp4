#include "fsm.h"

fsm::fsm(void* data = NULL)
{

}

/*void fsm::cycle(stateType *currState, const eventType currEv, void *userData)
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

}*/



void fsm::cycle(stateType *currState, const eventType currEv, void *userData)
{
	const cellType FSMtable[NUM_OF_STATES][NUM_OF_EVENTS] =
	//			WS	 ||  	 LLAVE_A        ||		 LLAVE_B   ||		DOS_PUNTOS	  ||		 COMA  
	{ 
	{ { NULL,IDLE },	{ NULL,SEARCH_NAME },	{error_action,FIN},{ error_action,FIN },{ error_action,FIN } },	//IDLE
	{ { NULL,SEARCH_NAME},{error_action,FIN},{empty_object,FIN},{ save_name,GET_VALUE},{error_action,FIN} },		//SEARCH_NAME
	{ { NULL, GET_VALUE},{error_action,FIN},{save_value, FIN }, {error_action,FIN} , {save_value,SEARCH_NAME } },		//GET_VALUE
	{ {NULL,FIN}	,	{ NULL,FIN }	,		{ NULL,FIN }		,		{ NULL,FIN }	, {NULL,FIN} }	//FIN
	}
}

void error_action(void *pointer)
{
	jsonDataAux *data = (jsonDataAux*)pointer;
	data->err.isErrorPresent = true;
	data->err.type = UNEXPECTED_CHAR;
}

void save_value(void *pointer)
{
	jsonDataAux *data = (jsonDataAux*)pointer;
	data->value = data->object.substr(data->stringInit, data->stringLength);
}

void save_name(void *pointer)
{
	jsonDataAux *data = (jsonDataAux*)pointer;
	data->name = data->object.substr(data->stringInit, data->stringLength);
}
void empty_object(void *pointer)
{

}