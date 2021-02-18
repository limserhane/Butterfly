#include <butterfly/wing.hpp>

#include <iostream>

namespace butterfly
{

wing::wing(level::value p_level, std::unique_ptr<package_formatter> p_formatter):
	logger(),
	m_level(p_level),
	m_formatter(std::move(p_formatter))
{}

wing::wing(std::unique_ptr<package_formatter> p_formatter):
	wing(level::minimal, std::move(p_formatter))
{}

wing::~wing()
{}

} 