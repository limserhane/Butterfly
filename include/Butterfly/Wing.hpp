#pragma once

#include <Butterfly/Common.hpp>
#include <Butterfly/Logger.hpp>
#include <Butterfly/Details/PackageFormatter.hpp>


#include <string>

namespace Butterfly
{

/**
 * @brief An logger interface used to write a record.
 */
class Wing : public Logger
{
public :
	Wing(Level::Value pLevel = Level::minimal, PackageFormatter pFormatter = PackageFormatter::MinimalPattern);
	Wing(PackageFormatter pFormatter);

	virtual ~Wing();

	/**
	 * @brief Logs a record using the Write function defined by the class.
	 * @param pLevel The level to be logged;
	 * @param pTag The tag of the record to log;
	 * @param pMessage The message of the record to log;
	 * @param pSource The source of the call to the log function;
	 */
	virtual void Log(Level::Value pLevel, std::string pTag, std::string pMessage) override;

protected :
	/**
	 * @brief Writes a record.
	 * @param pRecord The record the be logged;
	 */
	virtual void Write(std::string pRecord) = 0;

	Level::Value mLevel;
	PackageFormatter mFormatter;

}; 

} 