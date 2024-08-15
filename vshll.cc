#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>

#include <vector>
#include <array>
#include <map>

#define MX_argv 16
#define MN_arv 2

#include <thread>

enum div {
	terminal = 0,
	command = 1,
	instruction
};
enum syntax {
	do_something = 0,
	do_else = 1,
	do_that
};

namespace std {

	class vshll {

		int init_vsh(vector<string>* argv);
		int vshll_loop(char argv, char argc);

		string_view term{}, cmd{}, instruct{};
		//map<string, syntax> map_v;
		string *map_v = instr.data();

	public:
		vshll(vector<string_view> syntax_vect[3], string *construct_vect)
			: term{ syntax_vect->at(terminal) = _syn_.at(terminal) },
				cmd{ syntax_vect->at(command) = _syn_.at(command) },
				instruct{ syntax_vect->at(instruction) = _syn_.at(instruction) },
			map_v{ construct_vect = map_v }
		{

		}
		~vshll() {}
	private:
		array<string, 3> _syn_{ {"|proto.v0|>>", }};
		vector<string> instr = { "x","y","z" };
	
	};

	int vshll::init_vsh(vector<string>* argv) {
		jthread m_thrd(vshll_loop);

	}

	int vshll::vshll_loop(char argv, char argc) {

	}
}
