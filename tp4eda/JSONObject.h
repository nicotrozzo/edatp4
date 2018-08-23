#ifndef JSON_OBJECT_H
#define JSON_OBJECT_H

#include <iostream>

using namespace std;

typedef enum {}JSONError;

typedef struct
{
	string name;
	string value;
	string type;
}JSONMember;

class JSONObject
{
private:
	JSONMember * members;
	unsigned int fieldCount;
	JSONError err;
public:
	JSONObject();
	JSONObject(string& s);
	JSONObject(const char* s);
	unsigned int getFieldCount();
	const char *getFieldType(const char *f);
	const char *getArrayType(const char *f);
	unsigned int getFieldSize(const char *f);
	bool isFieldPresent(const char *f);
	void *copyField(const char *f);
	void *copyArrayValue(const char *f, unsigned int pos);
	void print();
	JSONError getError();
	bool parseString(const char *s);
	bool parseString(string& s);
};

#endif