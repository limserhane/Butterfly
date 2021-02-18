#include <butterfly/details/package_formatter.hpp>

#include <butterfly/common.hpp>

#include <regex>

namespace butterfly
{

template<pattern P>
std::string Formatter<P>::FormatTime(time_t pRawTime) const
{
	char lTimeBuffer[21];

	strftime(lTimeBuffer, 21, "%F %T", localtime(&pRawTime));

	return lTimeBuffer;
}


template <> std::string Formatter<pattern::none>::format(package p_package) const
{
	constexpr size_t buffer_size = 512;
	char buffer[buffer_size];

	snprintf(
		buffer, buffer_size,
		"%s\n",
		p_package.message.c_str()
	);

	return buffer;
}

template <> std::string Formatter<pattern::minimal>::format(package p_package) const
{
	constexpr size_t buffer_size = 512;
	char buffer[buffer_size];

	snprintf(
		buffer, buffer_size,
		"[%s] %s\n",
		p_package.tag.c_str(),
		p_package.message.c_str()
	);

	return buffer;
}

template <> std::string Formatter<pattern::report>::format(package p_package) const
{
	constexpr size_t buffer_size = 512;
	char buffer[buffer_size];

	snprintf(
		buffer, buffer_size,
		"[%s] %s\n",
		to_string(p_package.level).c_str(),
		p_package.message.c_str()
	);

	return buffer;
}

template <> std::string Formatter<pattern::simple>::format(package p_package) const
{
	constexpr size_t buffer_size = 512;
	char buffer[buffer_size];

	snprintf(
		buffer, buffer_size,
		"[%s] [%s] %s\n",
		FormatLevel(p_package.level).c_str(),
		p_package.tag.c_str(),
		p_package.message.c_str()
	);

	return buffer;
}

template <> std::string Formatter<pattern::complete>::format(package p_package) const
{
	constexpr size_t buffer_size = 512;
	char buffer[buffer_size];

	snprintf(
		buffer, buffer_size,
		"[%s] [%s] [%s] %s\n",
		FormatTime(p_package.time).c_str(),
		FormatLevel(p_package.level).c_str(),
		p_package.tag.c_str(),
		p_package.message.c_str()
	);

	return buffer;
}

std::unique_ptr<package_formatter> create_package_formatter(pattern p_pattern)
{
	switch(p_pattern)
	{
		case pattern::none : return std::make_unique<Formatter<pattern::none>>();
		case pattern::minimal : return std::make_unique<Formatter<pattern::minimal>>();
		case pattern::report : return std::make_unique<Formatter<pattern::report>>();
		case pattern::simple : return std::make_unique<Formatter<pattern::simple>>();
		case pattern::complete : return std::make_unique<Formatter<pattern::complete>>();
		default : throw_exception(BFLY_SOURCE, "invalid argument, p_pattern is no valid pattern"); return nullptr;
	}
}

} 