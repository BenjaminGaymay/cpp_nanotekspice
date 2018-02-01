#include "Component.hpp"

using namespace std;

int main()
{
	Component a(1);
	Component b(2);
	Component c(3);
	Component d(4);
	//WHAOU LES GIGA OPERATEURS POUR LIER LES NODE TRCUS DE OUF
	a >> b;
	a >> c;
	a >> d;
	cout << a << endl;
	b >> a;
	cout << b << endl;
	return 0;
}