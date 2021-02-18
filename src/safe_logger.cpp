#include <butterfly/safe_logger.hpp>


namespace butterfly
{
safe_logger::safe_logger(std::shared_ptr<logger> p_logger):
	logger(),
	m_logger(p_logger),
	m_mutex()
{}

safe_logger::~safe_logger()
{}

} 