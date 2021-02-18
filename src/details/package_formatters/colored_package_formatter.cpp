#include <butterfly/details/package_formatters/colored_package_formatter.hpp>


namespace butterfly
{

colored_package_formatter::colored_package_formatter(std::unique_ptr<package_formatter> p_formatter):
	package_formatter(),
	m_formatter(std::move(p_formatter))
{}

std::string colored_package_formatter::format(package p_package) const
{
	std::string s = m_formatter->format(p_package);
	
	std::string buffer;
	buffer.reserve(12 + s.size());

	buffer += start_color_flag(p_package.level);
	buffer += s;
	buffer += end_color_flag();

	return buffer;
}

std::string colored_package_formatter::start_color_flag(level::value p_level)
{
	switch(p_level)
	{
	case level::trace	:	return "\033[90m";
	case level::info	:	return "\033[97m";
	case level::warning	:	return "\033[33m";
	case level::error	:	return "\033[31m";
	case level::fatal	:	return "\033[91m";
	case level::debug	:	return "\033[35m";
	default : return "";
	}
}

} 