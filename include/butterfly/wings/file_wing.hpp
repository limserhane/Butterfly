#pragma once

#include <butterfly/common.hpp>
#include <butterfly/wing.hpp>

#include <iostream>
#include <string>
#include <fstream>

namespace butterfly
{

/**
 * @brief A concrete wing used to log records into a given file.
 */
class file_wing : public wing
{
public :
	file_wing(std::string p_filename, level::value p_level = level::minimal, pattern p_pattern = pattern::complete);
	file_wing(std::string p_filename, pattern p_pattern);

	virtual ~file_wing();

private :
	/**
	 * @brief Writes a log into its file.
	 * @param p_record The record to be logged;
	 */
	inline virtual void write(const std::string p_record) override
	{
		m_file << p_record;
	}

	std::ofstream m_file;

};

}