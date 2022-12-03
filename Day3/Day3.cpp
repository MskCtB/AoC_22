#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream stream("Resources/input.txt");
	int sum = 0;
	
#if 0
	std::string dump;
	std::string duplicates = "";
	bool skip = false;
	while (!stream.eof()) {
		std::getline(stream, dump);
		duplicates = "";
		for (unsigned int i = 0; i < dump.length() / 2; i++) {
			for (unsigned int j = dump.length() / 2; j < dump.length(); j++) {
				if (dump[i] == dump[j]) {
					for (int s = 0; s < duplicates.length(); s++) {
						if (dump[i] == duplicates[s]) {
							skip = true;
						}
					}
					duplicates += dump[i];
					if (!skip) {
						if (dump[i] >= 'a') {
							sum += dump[i] - 'a' + 1;
						}
						else {
							sum += dump[i] - 'A' + 27;
						}
					}
					skip = false;
				}
			}
		}
	}
#else
	bool found1 = false, found2 = false;
	std::string dump[3];
	while (!stream.eof()) {
		std::getline(stream, dump[0]);
		std::getline(stream, dump[1]);
		std::getline(stream, dump[2]);

		for (unsigned int i = 0; i < dump[0].length(); i++) {
			if (dump[1].find(dump[0][i]) != std::string::npos && dump[2].find(dump[0][i]) != std::string::npos) {
				if (dump[0][i] >= 'a') {
					sum += dump[0][i] - 'a' + 1;
				}
				else {
					sum += dump[0][i] - 'A' + 27;
				}
				i = dump[0].length();
			}
		}
	}
#endif

	std::cout << sum << std::endl;
}