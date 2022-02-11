#pragma once
#include<iostream>
#include<string>
using namespace std;

class PrintFunctor
{
private:
	string split;
public:
	explicit PrintFunctor(string c = " / ");
	void operator()(int n) const;
};