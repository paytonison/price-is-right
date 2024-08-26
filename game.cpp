#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;

void greeter(){
	cout << "What is your name?" << endl;
	string name;
	cin >> name;

	cout << name << ", come on down!" << endl;
	cout << "You're the next contestant on The Price is Right!" << endl;
}

int main(){
	greeter();
	return 0;
}
