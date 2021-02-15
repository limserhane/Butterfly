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
	
	ConsoleWing(Level::Value pLevel = Level::minimal, PackageFormatter pFormatter = PackageFormatter::SimplePattern);
	ConsoleWing(PackageFormatter pFormatter);
	
	~ConsoleWing();

private :
	/**
	 * @brief Writes a log into the standard output.
	 * @param pRecord The record to be logged;
	 */
	virtual void Write(std::string pRecord) override;

};

}