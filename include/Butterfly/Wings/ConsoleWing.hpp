#pragma once

#include <Butterfly/Common.hpp>
#include <Butterfly/Wing.hpp>


namespace Butterfly
{

/**
 * @brief A concrete Wing used to log records into the standard output.
 */
class ConsoleWing : public Wing
{
public :

	ConsoleWing(Level::Value pLevel = Level::minimal, const char* pPattern = PackageFormatter::SimplePattern);
	ConsoleWing(const char* pPattern);
	
	virtual ~ConsoleWing();

protected :
	ConsoleWing(Level::Value pLevel, std::unique_ptr<PackageFormatter> pFormatter);

private :
	/**
	 * @brief Writes a log into the standard output.
	 * @param pRecord The record to be logged;
	 */
	virtual void Write(std::string pRecord) override;

};

}