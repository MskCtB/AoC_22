#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream stream("Resources/input.txt");
	std::string containers[9];
	std::string dump = "";
	std::string to_flip;
	int initial_pos = 0;
	int pos_to_container;
	int amount = 0, from = 0, to = 0;

	while (dump.find("1") == std::string::npos) {
		std::getline(stream, dump);

		while (dump.rfind("]") != std::string::npos) {
			initial_pos = dump.rfind("]") - 1;
			pos_to_container = initial_pos / 4 + initial_pos % 4 - 1;
			containers[pos_to_container] += dump[initial_pos];

			dump.erase(initial_pos, std::string::npos);
		}
	}
	for (int i = 0; i < 9; i++) {
		to_flip = containers[i];
		containers[i].clear();
		for (unsigned int j = 0; j <= to_flip.length(); j++) {
			containers[i] += to_flip[to_flip.length() - j];
		}
	}
#if 0
	while (!stream.eof()) {
		std::getline(stream, dump);
		if (dump.find("move") != std::string::npos) {
			amount = std::stoi(dump.substr(dump.find("move") + 4 + 1, dump.find("from") - 1));
			from = std::stoi(dump.substr(dump.find("from") + 4 + 1, dump.find("to") - 1)) - 1;
			to = std::stoi(dump.substr(dump.find("to") + 2 + 1, dump.length() - 1)) - 1;

			for (int i = 0; i < amount; i++) {
				containers[to].push_back(containers[from].back());
				containers[from].pop_back();
			}
		}
	}
#else
	while (!stream.eof()) {
		std::getline(stream, dump);
		if (dump.find("move") != std::string::npos) {
			amount = std::stoi(dump.substr(dump.find("move") + 4 + 1, dump.find("from") - 1));
			from = std::stoi(dump.substr(dump.find("from") + 4 + 1, dump.find("to") - 1)) - 1;
			to = std::stoi(dump.substr(dump.find("to") + 2 + 1, dump.length() - 1)) - 1;

			containers[to] += containers[from].substr(containers[from].length() - amount, containers[from].length());
			containers[from].erase(containers[from].length() - amount, containers[from].length());
		}
	}
#endif
	for (int i = 0; i < 9; i++)
		std::cout << containers[i].back();
	std::cout << std::endl;
}
