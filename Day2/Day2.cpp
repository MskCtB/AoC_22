#include <iostream>
#include <vector>
#include <fstream>

#define OFFSET_I 87 // A - rock, B - paper, C - scissors
#define OFFSET_U 64 // X - rock, Y - paper, Z - scissors || X - lose, Y - draw, Z - win

#define VERSION 1 // 0 - first part, 1 - second part

int main()
{
	std::ifstream stream("Resources/input.txt");
	char me, you;
	int a, b;

	int result = 0;

#if !VERSION
	while (!stream.eof()) {
		stream >> you >> me;
		if (!stream.eof()) {
			a = (int)you - OFFSET_U;
			b = (int)me - OFFSET_I;

			if (b % 3 == (a + 1) % 3) {
				result += b + 6;
			}
			else if (b == a) {
				result += b + 3;
			}
			else {
				result += b;
			}
		}
	}
#else
	while (!stream.eof()) {
		stream >> you >> me;
		if (!stream.eof()) {
			a = (int)you - OFFSET_U;
			b = (int)me - OFFSET_I;

			if (b == 3) {
				result += (a % 3 + 1) + 6;
			}
			else if (b == 2) {
				result += a + 3;
			}
			else {
				result += (a + 2) % 3;
				if (a == 1)
					result += 3;
			}
		}
	}
#endif
	std::cout << "Result: " << result << std::endl;
}
