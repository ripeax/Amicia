#include <iostream>

#include <vector>
#include <unordered_map>
#include <tuple>

#include <cstdint>

#include <string>
#include <string_view>
#include <format>

#include <chrono>


#define DEBUG true

class Lexer :
    protected SyntaxTokens
{
private:


};
class SyntaxTokens :
    private SynMap{
private:

    std::int_fast8_t tkn_call(char* tkn_name) {
        //debug msg
#if USING(DEBUG)

        namespace std {
            format("[DBG] {} ... \n", "token call initialised");
        }
#endif
        auto start = std::chrono::steady_clock::now();
        std::int_fast8_t callout = temp_call();
        auto end = std::chrono::steady_clock::now();
        auto exec_res = end - start;

#if USING(DEBUG)
        namespace std {
            if (...) {
                printf("[DBG] token fast call successful...");
                std::cout // print me CPU exec duration
                    << std::chrono::duration<double, std::nano>(diff).count()
                    << " ns" 
                    << std::endl;
            }
            else {
                printf("[DBG] token fast call failure...");
                return;
            }
    }
#endif
        return callout;
    }
protected:
    int_fast8_t temp_call();
    SynMap tokenic_mapper;
    std::tuple<short, std::string> tkn_key(int ptr_key);
};

class SynMap {
    SynMap() {}
    ~SynMap() {}
};
