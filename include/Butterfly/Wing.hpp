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
	Wing(Level::Value pLevel = Level::minimal, std::unique_ptr<PackageFormatter> pFormatter = std::make_unique<PackageFormatter>(PackageFormatter::MinimalPattern));
	Wing(std::unique_ptr<PackageFormatter> pFormatter);

	virtual ~Wing();

	/**
	 * @brief Logs a record using the Write function defined by the class.
	 * @param pLevel The level to be logged;
	 * @param pTag The tag of the record to log;
	 * @param pMessage The message of the record to log;
	 * @param pSource The source of the call to the log function;
	 */
	inline virtual void Log(Level::Value pLevel, std::string_view pTag, std::string_view pMessage) override
	{
		if(pLevel < mLevel)
		{
			return ;
		}

		Write(mFormatter->Format(Package(time(nullptr), pLevel, pTag, pMessage)));
	}

protected :
	/**
	 * @brief Writes a record.
	 * @param pRecord The record the be logged;
	 */
	virtual void Write(std::string pRecord) = 0;

	Level::Value mLevel;
	std::unique_ptr<PackageFormatter> mFormatter;

}; 

} 