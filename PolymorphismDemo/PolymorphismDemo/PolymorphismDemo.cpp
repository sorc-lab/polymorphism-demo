// PolymorphismDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

/** Ad-hoc (AKA overloading) ================================================== */
int GetSize(int x)
{
	return x;
}

int GetSize(std::string x)
{
	return x.length();
}
/** =========================================================================== */

/** Sub-type ================================================================== */
class Animal
{
public:
	virtual void MakeNoise() // virtual method, allows override
	{
		std::cout << "Animal noise." << std::endl;
	}
};

class Dog : public Animal // sub-class
{
public:
	void MakeNoise() override
	{
		std::cout << "Woof!" << std::endl;
	}
};

class Cat : public Animal // sub-class
{
public:
	void MakeNoise() override
	{
		std::cout << "Meow." << std::endl;
	}
};

void Stroke(Animal* animal) // must use pointer or reference
{
	animal->MakeNoise();
}
/** =========================================================================== */

int main()
{
	std::cout << GetSize(5) << std::endl;
	std::cout << GetSize("hello world") << std::endl;
	Dog dog;
	Cat cat;
	Stroke(&dog); // use pointer to reference, NOT a copy
	Stroke(&cat); // a copy will lose its information of original type
	return 0;
}
