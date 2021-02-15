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
	FileWing(std::string pFilename, Level::Value pLevel = Level::minimal, PackageFormatter pFormatter = PackageFormatter::CompletePattern);
	FileWing(std::string pFilename, PackageFormatter pFormatter);

	~FileWing();

private :
	/**
	 * @brief Writes a log into its file.
	 * @param pRecord The record to be logged;
	 */
	virtual void Write(std::string pRecord) override;

	std::ofstream mFile;

};

}