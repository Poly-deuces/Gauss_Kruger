#include"projection.h"
using namespace std;
int main() 
{ 
	gauss_kruger gk;
	gk.set_coordinates();
	gk.transformation();
	gk.run();
    return 0;  
}