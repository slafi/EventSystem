
#pragma once

#include <map>
#include "utils.h"

using namespace std;

namespace Events
{
	/**
	 * A class which defines the event arguments properties
	 *
	 * It defines the arguments sent by an event.
	 *
	 */
	class EventArgs
	{
		int _event_type;
		map<int, string>* _args;
		string _timestamp;

	public:
		EventArgs();
		EventArgs(int sender_id, std::map<int, string>* args);

		void set_event_type(int sender_id);
		int get_event_type();

		void set_args(std::map<int, string> *state);
		std::map<int, string>* get_args();

		void set_timestamp(string timestamp);
		string get_timestamp();

	};
}