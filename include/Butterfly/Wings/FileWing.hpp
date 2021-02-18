#pragma once

#include <Butterfly/Common.hpp>
#include <Butterfly/Wing.hpp>

#include <iostream>
#include <string>
#include <fstream>

namespace Butterfly
{

/**
 * @brief A concrete Wing used to log records into a given file.
 */
class FileWing : public Wing
{
public :
	FileWing(std::string pFilename, Level::Value pLevel = Level::minimal, Pattern pPattern = Pattern::complete);
	FileWing(std::string pFilename, Pattern pPattern);

	virtual ~FileWing();

private :
	/**
	 * @brief Writes a log into its file.
	 * @param pRecord The record to be logged;
	 */
	inline virtual void Write(const std::string pRecord) override
	{
		mFile << pRecord;
	}

	std::ofstream mFile;

};

}