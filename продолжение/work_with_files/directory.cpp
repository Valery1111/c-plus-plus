#include <fstream>
#include <iostream>
#include <filesystem>
#include <chrono>
#include <iomanip>
namespace fs = std::filesystem;

int main()
{
	fs::current_path(fs::temp_directory_path());
    for(auto& p: fs::recursive_directory_iterator("path"))
        std::cout << p.path() << fs::is_directory;
    	if(fs::is_regular_file("path")) std::cout << " is a regular file ";
        if(fs::is_directory("path")) std::cout << " is a directory  ";
        std::cout << " write time is " << fs::last_write_time("path") << '\n';
}
