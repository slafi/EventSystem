
#include "event_args.h"

namespace Events
{
	/**
	 * EventArgs class default constructor.
	 *
	 */
	EventArgs::EventArgs()
	{
		set_event_type(0);
		set_args(nullptr);

		// Assign timestamp automatically
		set_timestamp(format_timestamp());
	}

	/**
	 * EventArgs class custom constructor.
	 *
	 * @param event_type The event handler id.
	 * @param state a pointer to the AppState instance.
	 *
	 */
	EventArgs::EventArgs(int event_type, std::map<int, string>* args)
	{
		set_event_type(event_type);
		set_args(args);
		
		// Assign timestamp automatically
		set_timestamp(format_timestamp());
	}

	/**
	 * Sets the event type identifier.
	 *
	 * @param event_type the event type identifier.
	 *
	 */
	void EventArgs::set_event_type(int event_type)
	{
		this->_event_type = event_type;
	}

	/**
	 * Gets the event type identifier.
	 *
	 * @return the event type identifier.
	 *
	 */
	int EventArgs::get_event_type()
	{
		return this->_event_type;
	}

	/**
	 * Set the event arguments.
	 *
	 * @param state A pointer to an event arguments.
	 *
	 */
	void EventArgs::set_args(std::map<int, string>* args)
	{
		this->_args = args;
	}

	/**
	 * Get the event arguments.
	 *
	 * @return a pointer to event arguments.
	 *
	 */
	std::map<int, string>* EventArgs::get_args()
	{
		return this->_args;
	}

	/**
	 * Set the event timestamp.
	 *
	 * @param state A pointer to an event timestamp.
	 *
	 */
	void EventArgs::set_timestamp(string timestamp)
	{
		this->_timestamp = timestamp;
	}

	/**
	 * Get the event timestamp.
	 *
	 * @return A pointer to event timestamp.
	 *
	 */
	string EventArgs::get_timestamp()
	{
		return this->_timestamp;
	}
}
