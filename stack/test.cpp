#include <iostream>


struct A {
	int var;
	A(const int &init) : var(init) { std::cout << "default ctor\n"; }
	A(const A &other)
	{
		std::cout << " copy ctor \n";
		// *this = other;
	}
	A &operator=(const A &x)
	{
			std::cout << " assignment ctor \n";
		return *this;
	}

};

int main(int argc, char const *argv[])
{
	A a(5);
	A a1(6);

	A a2 = a; // call the copy ctor
	a2 = a1; // call the assign ment  ctor
	// std::cout << a.var << '\n';
	// std::cout << &a << '\n';


	return 0;
}
