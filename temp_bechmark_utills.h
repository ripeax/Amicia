#define DEBUG true


#include <tuple>
#include <cstdlib>
#include <iostream>


#include <chrono>
#include <ctime>

namespace std { 
	using namespace chrono_literals; 

class bechmark_utills
{
	bechmark_utills();
	~bechmark_utills();


public:
	template<typename T1, typename T2>
	using mul = ratio<T1, T2>;
	class probe {
	public:
		void set_now() {
			const auto now = chrono::system_clock::now();
			time_t t_now = chrono::system_clock::to_time_t(now);
#if USING(DEBUG)
			cout << "[DBG] system clock at " << ctime(&t_c) << endl;
#endif
			this->start_ptr = &t_now;
		}
		int set_fin() {
			const time_t t = time(nullptr); // usually has "1 second" precision

			const auto from = chrono::system_clock::from_time_t(t);

			auto diff = chrono::system_clock::to_time_t(from);
			//auto *res = &diff;
#if USING(DEBUG)
			cout << "[DBG] Execution time :  " << ctime(&t_c) << endl;
#endif

			this->duration_CPU_exec = &diff;
		}
	private:
		const int s10_test = 10; //test
		void ns_cpu_t() {
			cout << chrono::nanoseconds(s10_test).count() << " nanoseconds\n";
		}
		void ms_cpu_t() {
			cout << chrono::microseconds(s10_test).count() << " microseconds\n";
		}
	protected:
		time_t* duration_CPU_exec;
		time_t* start_ptr;
	};

};
}

