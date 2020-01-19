
#pragma once
#include <vector>
#include <functional>
#include <memory>
#include <iostream>

#include "event_handler.h"

namespace Events
{
	/**
	 * A class which defines the properties of an event
	 *
	 * It captures the properties of an event.
	 *
	 */
	class Event
	{
	private:
		std::vector<std::unique_ptr<EventHandler>> _subscribed_handlers;

		void raise_event(EventArgs* args);

	public:
		void add_handler(const EventHandler &handler);
		void remove_handler(const EventHandler &handler);
		void operator()(EventArgs* args);
		Event &operator+=(const EventHandler &handler);
		Event &operator+=(const EventHandler::Func &handler);
		Event &operator-=(const EventHandler &handler);
		size_t get_number_of_subscribed_handlers() { return this->_subscribed_handlers.size(); }

	};
}
