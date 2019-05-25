#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#define MEMORY_SIZE 255

using namespace std;

int main(int argc, char *argv[])
{
	ifstream fin(argv[1]);

	if (!fin) {
		return 1;
	}

	stringstream strstream;
	strstream << fin.rdbuf();
	fin.close();

	string data(strstream.str());

	cout << "Input(" << argv[1] << ")\n" << data << endl;
	cout << "Output" << endl;

	vector<char> mem(MEMORY_SIZE, 0);
	vector<char>::iterator ptr = mem.begin();

	for (int i = 0; i < data.size(); i++) {
		switch (data[i])
		{
		case '>':
			ptr++;
			break;
		case '<':
			ptr--;
			break;
		case '+':
			(*ptr)++;
			break;
		case '-':
			(*ptr)--;
			break;
		case '.':
			putchar(*ptr);
			break;
		case ',':
			*ptr = getchar();
			break;
		case '[':
			if (*ptr == 0) {
				for(int count = 1; count != 0; ) {
					i++;
					if (data[i] == ']') {
						count--;
					}
					else if (data[i] == '[') {
						count++;
					}
				}
			}
			break;
		case ']':
			if (*ptr != 0) {
				for(int count = 1; count != 0;) {
					i--;
					if (data[i] == '[') {
						count--;
					}
					else if (data[i] == ']') {
						count++;
					}
				}
			}
			break;
		default:
			break;
		}
	}

	return 0;
}

