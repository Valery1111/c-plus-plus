#include <iostream>
#include <sstream>
#include <vector>
#include "json.hpp
using nlohmann::json;
#include <nlohmann/json.hpp>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <istream>
#include <locale>
#include <ostream>
#include "struct_mapping/struct_mapping.h"

struct Pearson {
	std::string name;
	double age;
	std::vector<double> temperature;
};

typedef std::string  T_str;

void  make_file(const T_str&  file_name)
{
    std::ofstream  ofile(file_name.c_str());
}

int main() {
	struct_mapping::reg(&Pearson::name, "name");
	struct_mapping::reg(&Pearson::age, "age");
	struct_mapping::reg(&Pearson::temperature, "temperature");

	Pearson ivan;
	ivan.name = "Ivan";
	ivan.age = 25;
	ivan.temperature = std::vector<double>{38.6, 38.1, 36.6};

	Pearson fedor;
	fedor.name = "Fedor";
	fedor.age = 25;
	fedor.temperature = std::vector<double>{38.9, 38.5, 36.9};

	std::vector<Pearson> people = {ivan, fedor};
	for (int i=0;i!=people.size();++i){
		std::ostringstream json_data;
		struct_mapping::map_struct_to_json(people[i], json_data, "  ");
		std::ofstream file( std::string( "D:\\json" + std::to_string( i ) + ".json" ).c_str() );
		file << json_data.str() << std::endl;
		file.close();
}
