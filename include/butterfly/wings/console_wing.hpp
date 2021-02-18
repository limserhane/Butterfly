#pragma once

#include <butterfly/common.hpp>
#include <butterfly/wing.hpp>


namespace butterfly
{

/**
 * @brief A concrete wing used to log records into the standard output.
 */
class console_wing : public wing
{
public :

	console_wing(level::value p_level = level::minimal, pattern p_pattern = pattern::simple);
	console_wing(pattern p_pattern);
	
	virtual ~console_wing();

protected :
	console_wing(level::value p_level, std::unique_ptr<package_formatter> p_formatter);

private :
	/**
	 * @brief Writes a log into the standard output.
	 * @param p_record The record to be logged;
	 */
	inline virtual void write(const std::string p_record) override
	{
		std::cout << p_record;
	}

};

}