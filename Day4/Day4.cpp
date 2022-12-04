#include <iostream>
#include <string>
#include <fstream>

int main()
{
	std::string dump, sub_dump;
	int min, max, min2, max2;
	int dash_position, comma_position;
	int sum = 0;
	std::ifstream stream("Resources/input.txt");
	while (!stream.eof()) {
		std::getline(stream, dump);
		dash_position = dump.find("-");
		comma_position = dump.find(",");
		sub_dump = dump.substr(0, dash_position);
		min = std::stoi(sub_dump);
		sub_dump = dump.substr(dash_position + 1, comma_position);
		max = std::stoi(sub_dump);
		dash_position = dump.rfind("-");
		sub_dump = dump.substr(comma_position + 1, dash_position);
		min2 = std::stoi(sub_dump);
		sub_dump = dump.substr(dash_position + 1);
		max2 = std::stoi(sub_dump);

#if 1
		if ((min <= min2 && max >= max2) || (min2 <= min && max2 >= max)) {
			sum++;
		}
#else
		if ((min <= min2 && max >= min2) || (min2 <= min && max2 >= min)) {
			sum++;
		}
#endif
	}
	std::cout << sum << std::endl;
}