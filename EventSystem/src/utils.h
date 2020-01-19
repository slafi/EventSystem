
#pragma once

#ifdef _MSC_VER
	#pragma warning(disable:4996)		// equivalent to: _CRT_SECURE_NO_WARNINGS 
#endif

#include <iostream>
#include <exception>
#include <regex>

using namespace std;

namespace Events
{
	 /**
	  * The class defines a custom exception object for event handlers
	  *
	  * It adds a custom message property and overrides the default what() function.
	  *
	  */
	class EventHandlerException : public exception
	{
	private:
		const char* _message;

	public:
		EventHandlerException(const char* message);

		virtual const char* what() const throw();
		void set_exception_message(const char* message);
		const char* get_exception_message() const;
	};

	/**
	 * Returns the local date and time as a string.
	 */
	std::string format_timestamp();
}
