#include "PrintFunctor.h"

PrintFunctor::PrintFunctor(string c) : split(c)
{ }

void PrintFunctor::operator()(int n) const
{
	cout << n << split;
}
