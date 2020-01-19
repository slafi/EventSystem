
#include "event_handler.h"


namespace Events
{
	int EventHandler::_witness_counter;

	/**
	 * Calls the EventHandler callback function.
	 *
	 */
	void EventHandler::operator()(EventArgs* args) {
		this->_callback_func(this->get_event_args());
	}

	/**
	 * Assigns a callback to the event handler.
	 *
	 * @param func the reference to a callback function.
	 *
	 * @throws EventHandlerException Thrown if a callback function is 
	 * already assigned to the event handler.
	 *
	 */
	void EventHandler::operator=(const EventHandler &callback_func) {
		if (this->_callback_func == nullptr) {
			this->_callback_func = callback_func;
			this->_id = ++EventHandler::_witness_counter;
		}
		else {
			// Throw an exception to complain!
#if DEBUG_ENABLED
			std::cerr << "You cannot assign the event handler function again." << std::endl;
#endif
			throw new EventHandlerException("You cannot assign the event handler function again.");
		}
	}

	/**
	 * Checks if the event handler is equal to another one.
	 *
	 * @param del Event handler.
	 * @return True if the identifiers match, false otherwise.
	 *
	 */
	bool EventHandler::operator==(const EventHandler &del) {
		return this->_id == del._id;
	}

	/**
	 * Checks whether the event handler callback function is equal to null.
	 *
	 * @return True if null, false otherwise.
	 *
	 */
	bool EventHandler::operator!=(nullptr_t) {
		return this->_callback_func != nullptr;
	}

	/**
	 * Sets the event arguments.
	 *
	 * @param args The event arguments.
	 *
	 */
	void EventHandler::set_event_args(EventArgs* args)
	{
		this->_args = args;
	}

	/**
	 * Gets the event arguments.
	 *
	 * @return the event arguments.
	 *
	 */
	EventArgs* EventHandler::get_event_args()
	{
		return this->_args;
	}	

}