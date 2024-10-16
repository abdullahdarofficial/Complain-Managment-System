#pragma once
// pure virtual class

class Person
{
public:
	virtual int getId() const = 0;
	virtual void command() = 0;
};

