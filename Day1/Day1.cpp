#include <fstream>
#include <vector>
#include <string>
#include <iostream>

int main()
{
	std::ifstream stream;
	std::vector<int> elves = { 0 };
	std::string dump;
	int current_elf = 0;
	int top1 = 0, top2 = 0, top3 = 0;

	stream.open("Resources/input.txt");

	while (!stream.eof()) {
		std::getline(stream, dump);
		if (dump[0]) {
			elves[current_elf] += stoi(dump);
		}
		else {
			if (elves[current_elf] > top1) {
				top3 = top2;
				top2 = top1;
				top1 = elves[current_elf];
			}
			elves.push_back(0);
			current_elf++;
		}
	}
	std::cout << top1 + top2 + top3 << std::endl;
}