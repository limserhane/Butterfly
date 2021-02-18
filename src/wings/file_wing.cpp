#include <butterfly/wings/file_wing.hpp>


namespace butterfly
{

file_wing::file_wing(std::string p_filename, level::value p_level, pattern p_pattern):
	wing(p_level, create_package_formatter(p_pattern)),
	m_file(p_filename, std::ios_base::app)
{
	if(!m_file.is_open())
	{
		throw_exception(BFLY_SOURCE, "failed, unable to open file p_filename");
	}
}

file_wing::file_wing(std::string p_filename, pattern p_pattern):
	file_wing(p_filename, level::minimal, p_pattern)
{}

file_wing::~file_wing()
{
	m_file.close();
}

}