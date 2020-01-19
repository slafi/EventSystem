
#include "event.h"

using std::vector;
using std::unique_ptr;

namespace Events {
	
	/**
	 * Notifies the subscribed event handlers when the event is fired.
	 *
	 * @param args A pointer to the event arguments instance.
	 *
	 */
	void Event::raise_event(EventArgs* args) {
		vector<unique_ptr<EventHandler>>::iterator func = this->_subscribed_handlers.begin();
		for (; func != this->_subscribed_handlers.end(); ++func) {
			if (*func != nullptr && (*func)->_id != 0) {
				(*func)->set_event_args(args);
				(*(*func))((*func)->get_event_args());
#if DEBUG_ENABLED
				std::cout << "Notifying event handler #: " << (*func)->_id << std::endl;
#endif
			}
		}
	}

	/**
	 * Adds an event handler to the handlers array.
	 *
	 * @param handler An event handler.
	 *
	 */
	void Event::add_handler(const EventHandler &handler) {
		this->_subscribed_handlers.push_back(unique_ptr<EventHandler>(new EventHandler{ handler }));
	}

	/**
	 * Removes an event handler to the handlers array.
	 *
	 * @param handler An event handler.
	 *
	 */
	void Event::remove_handler(const EventHandler &handler) {
		vector<unique_ptr<EventHandler>>::iterator to_remove = this->_subscribed_handlers.begin();
		for (; to_remove != this->_subscribed_handlers.end(); ++to_remove) {
			if (*(*to_remove) == handler) {
#if DEBUG_ENABLED
				std::cout << "Removing event handler #: " << (*to_remove)->_id << std::endl;
#endif
				this->_subscribed_handlers.erase(to_remove);
				break;
			}
		}
	}

	/**
	 * Runs the notifyHandlers() function to notify all handlers.
	 *
	 * @param args A pointer to the EventArgs instance.
	 *
	 */
	void Event::operator()(EventArgs* args) {
		this->raise_event(args);
	}

	/**
	 * Adds an event handler to the handlers array.
	 *
	 * @param handler An event handler.
	 *
	 */
	Event &Event::operator+=(const EventHandler &handler) {
		this->add_handler(handler);

		return *this;
	}

	/**
	 * Adds an event handler to the handlers array using a function callback.
	 *
	 * @param handler A function callback.
	 *
	 */
	Event &Event::operator+=(const EventHandler::Func &handler) {
		this->add_handler(EventHandler{ handler });

		return *this;
	}

	/**
	 * Removes an event handler from the handlers array.
	 *
	 * @param handler An event handler.
	 *
	 */
	Event &Event::operator-=(const EventHandler &handler) {
		this->remove_handler(handler);

		return *this;
	}
	

}