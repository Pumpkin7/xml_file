#include <vector>
#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
 #include <iostream>
using boost::property_tree::xml_writer_settings;
namespace fs =boost::filesystem;
using namespace fs;
using boost::property_tree::ptree;
void all_files(const fs::path& p, std::vector<fs::path>& files)
{
    for (fs::directory_iterator pos(p); pos != fs::directory_iterator(); ++pos)
    {
        if (fs::is_directory(*pos)) all_files(*pos, files);
        else
            files.push_back(*pos);
		complete(*pos).string();
		
    }
}
int main()
{ 
    setlocale(LC_ALL, "Russian");
	std::string L;
	std::cout<<"Введите путь:";
	std::cin>>L;
    fs::path directory_path(L);
	
    std::vector<fs::path> files;
    all_files(directory_path, files);
	ptree pt;
	ptree way;
    std::cout<<"Все файлы директории "<<directory_path<<"Находятся в:\n\n";
    for (const auto& file : files) {
	auto&a=file.filename();
	auto&b=complete(file).string();
	uintmax_t file_size(const path& file);
	auto settings = boost::property_tree::xml_writer_make_settings<std::string>('\t', 1);
	way.put("name",a);
	way.put("adress",b);
	way.put("size",file_size(file));
	pt.push_back(make_pair("file", way));
	}
	auto settings = boost::property_tree::xml_writer_make_settings<std::string>('\t', 1);
	std::ofstream f("files of directory.xml");
	write_xml(f, pt, settings);
	auto &v=complete("files of directory.xml").string();
	std::cout<<v;
	std::cin.get();  
	system("pause");
    return 0;
}
