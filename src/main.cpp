#include <iostream>
#include <string>
#include "..\mainlist\list.h"
using namespace std;
using namespace mainset;

int main() {
	List<int> TestList(10);
	print_list(TestList);
	cout << TestList << endl;
}