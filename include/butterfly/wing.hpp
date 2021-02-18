#pragma once

#include <butterfly/common.hpp>
#include <butterfly/logger.hpp>
#include <butterfly/details/package_formatter.hpp>


#include <string>

namespace butterfly
{

/**
 * @brief An logger interface used to write a record.
 */
class wing : public logger
{
public :
	wing(level::value p_level = level::minimal, std::unique_ptr<package_formatter> p_formatter = create_package_formatter(pattern::simple));
	wing(std::unique_ptr<package_formatter> p_formatter);

	virtual ~wing();

	/**
	 * @brief Logs a record using the write function defined by the class.
	 * @param p_level The level to be logged;
	 * @param p_tag The tag of the record to log;
	 * @param p_message The message of the record to log;
	 * @param p_source The source of the call to the log function;
	 */
	inline virtual void log(level::value p_level, std::string_view p_tag, std::string_view p_message) override
	{
		if(p_level < m_level)
		{
			return ;
		}

		write(m_formatter->format(package(time(nullptr), p_level, p_tag, p_message)));
	}

protected :
	/**
	 * @brief Writes a record.
	 * @param p_record The record the be logged;
	 */
	virtual void write(std::string p_record) = 0;

	level::value m_level;
	std::unique_ptr<package_formatter> m_formatter;

}; 

} 