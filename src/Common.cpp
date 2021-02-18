#include <butterfly/common.hpp>


namespace butterfly
{

source::source():
	file(),
	line(),
	function(),
	pretty_function()
{}

source::source(std::string p_file, int p_line, std::string p_function, std::string p_pretty_function):
	file(p_file),
	line(p_line),
	function(p_function),
	pretty_function(p_pretty_function)
{} 

source::source(const source& p_other):
	source(p_other.file, p_other.line, p_other.function, p_other.pretty_function)
{} 

exception::exception(source p_source, std::string p_details)
{
	m_description = format(p_source, p_details);
} 

const char* exception::what() const throw()
{
	return m_description.c_str();
} 

std::string exception::format(source p_source, std::string p_details)
{
	constexpr size_t bufferSize = 256;
	char buffer[bufferSize];
	snprintf(
		buffer, bufferSize,
		"butterfly : (%s) : %s",
		p_source.pretty_function.c_str(),
		p_details.c_str()
	);
	return buffer;
} 

void throw_exception(source p_source, std::string p_details)
{
	throw exception(p_source, p_details);
}

void print_exception(source p_source, std::string p_details)
{
	std::cerr << exception(p_source, p_details).what() << std::endl;
} 

} 