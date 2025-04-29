#include"projection.h"
using namespace std;
int main()
{
	gauss_kruger gk;
	gk.set_coordinates();
	gk.transformation();
	while (true)
	{
		cout << "Do you want to continue? (y/n): ";
		char choice;
		cin >> choice;
		if (choice == 'n' || choice == 'N')
			break;
		else if (choice == 'y' || choice == 'Y')
			gk.set_coordinates();
			gk.transformation();
	}
	return 0;
}