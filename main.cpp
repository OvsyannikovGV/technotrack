#include "bugs.h"

int main()
{
	srand(time(NULL));
	Integer a = 1, b = 1, c = 2, i = 0, m = 0;
	std::cin >> m;
	if (m == 0)
		std::cout << "\nerror\n";
	else if (m == 1)
		std::cout << a;
	else if (m == 2)
		std::cout << b;
	else if (m == 3)
		std::cout << c;
	else for (i = 3; i < m; i++)
		{
			a = b - Integer(10) * Integer(20) / Integer(3) + Integer(0);
			a = b;
			b = c + Integer(0);
			c = a + b;
		}
	a = +a;
	b = +a;
	std::cout << "Ответ: " << c;
	return 0;
}
