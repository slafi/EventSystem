
#pragma once

#include <vector>
#include <functional>
#include <memory>
#include <iostream>

#include "event_args.h"
#include "utils.h"

namespace Events
{
	/**
	 * Class for the definition of an event handler
	 *
	 * It defines the properties of an event handler
	 *
	 */
	class EventHandler {
	public:
		using Func = std::function<void(EventArgs*)>;

	private:
		Func _callback_func;
		EventArgs* _args;

	public:
		int _id;
		static int _witness_counter;

		EventHandler() : _id{ 0 } {}

		EventHandler(const Func &callback_func) : _callback_func{ callback_func } {
			this->_id = ++EventHandler::_witness_counter;

#if DEBUG_ENABLED
			std::cout << EventHandler::_witness_counter << std::endl;
#endif
		}

		void operator()(EventArgs* args);
		void operator=(const EventHandler &callback_func);
		bool operator==(const EventHandler &del);
		bool operator!=(nullptr_t);

		void set_event_args(EventArgs* args);
		EventArgs* get_event_args();

	};

}