#include <fstream>
#include <string>
#include <iostream>

int main()
{
	std::ifstream stream;
	int elf_cal = 0;
	std::string dump;
	int top1 = 0, top2 = 0, top3 = 0;

	stream.open("Resources/input.txt");

	while (!stream.eof()) {
		std::getline(stream, dump);
		if (dump[0]) {
			elf_cal += stoi(dump);
		}
		else {
			if (elf_cal > top1) {
				top3 = top2;
				top2 = top1;
				top1 = elf_cal;
			}
			elf_cal = 0;
		}
	}
	std::cout << top1 << " " << top2 << " " << top3 << std::endl;
	std::cout << top1 + top2 + top3 << std::endl;
}