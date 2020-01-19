
#include "utils.h"

using namespace std;

namespace Events
{

	/**
	 * The custom exception constructor.
	 *
	 * @param message the exception message
	 *
	 */
	EventHandlerException::EventHandlerException(const char* message)
	{
		this->set_exception_message(message);
	}

	/**
	 * Overrides the standard exception what() method.
	 *
	 * @return the exception message.
	 *
	 * @throws IoError Thrown if something goes wrong.
	 *
	 * @exceptsafe Strong exception guarantee.
	 */
	const char* EventHandlerException::what() const throw()
	{
		return (const char*)this->get_exception_message();
	}

	/**
	 * Read an image from disk.
	 *
	 * @param message the exception message
	 *
	 */
	void EventHandlerException::set_exception_message(const char* message)
	{
		this->_message = message;
	}

	/**
	 * Returns the exception message.
	 *
	 * @return the exception message
	 *
	 */
	const char* EventHandlerException::get_exception_message() const
	{
		return this->_message;
	}

	/**
	 * Returns the local date and time as a string.
	 *
	 * @return the current local date and time (format: "%d-%m-%Y %H:%M:%S") as a std::string.
	 */
	std::string format_timestamp()
	{
		time_t rawtime;
		struct tm * timeInfo;
		char buffer[80];

		time(&rawtime);
		timeInfo = localtime(&rawtime);

		strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeInfo);
		std::string str(buffer);

		return str;
	}
}

