#include <iostream>

#include <cstdint>

#include <string>
#include <string_view>
#include <format>

#include <chrono>


#define DEBUG true
#define BUF_MX_SZ 32
#define BUF_MN_SZ 8

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

#include <vector>
#include <tuple>
#include <unordered_map>
#include <array>
namespace std{
    class SynMap :
    private Token
{  
    SynMap() {
        
    
    }
    ~SynMap() {}

private:
    unordered_map<string, string> tknz;
    void print_k_v(/*  ...  */ ) {
        //helper fx
        auto print_kv_tkn = [](const auto& key, const auto& value)
            {
                std::cout << "Key:[" << key << "] Value:[" << value << "]\n";
            };
        //C++17 itel & print
        for (const auto & [key, value] : tknz)
            print_kv_tkn(key, value);
        //using only 'auto'
        for (const auto& n : tknz)
            print_kv_tkn(n.first, n.second);
    }
protected:
    struct tkn_str {
        string_view tknStr;
        Tokenz obj_tkn{ Token::undef };

        [[ nodiscard ]]
        constexpr bool operator<(tkn_str const& rhs) const
        {
            return tknStr < rhs.tknStr;
        }
        template< typename T, size_t N >
        [[ nodiscard ]]
        constexpr array< T, N > sort(array< T, N > arr) noexcept
        {
            sort(begin(arr), end(arr));
            return arr;
        }

        constexpr array keywords
        {
            sort
            (
                array
                {
                    tknStr{ "False" , obj_tkn::KwFalse },
                    tknStr{ "None"  , obj_tkn::KwNone  },
                    tknStr{ "True"  , obj_tkn::KwTrue  },

                    tknStr{ "with"  , obj_tkn::KwWith  },
                    tknStr{ "yield" , obj_tkn::KwYield }
                }
            )
        };

        constexpr auto operators
        {
            sort
            (
                array
                {
                    tknStr{ "!"  , obj_tkn::OpLogicalNot },
                    tknStr{ "!=" , obj_tkn::OpNotEqual   },
                    tknStr{ "%"  , obj_tkn::OpMod        },
                    tknStr{ "%=" , obj_tkn::OpAssignMod  },

                    tknStr{ "&"  , obj_tkn::OpBitwiseAnd      },
                    tknStr{ "|"  , obj_tkn::OpBitwiseOr       },
                    tknStr{ "|=" , obj_tkn::OpAssignBitwiseOr },
                    tknStr{ "||" , obj_tkn::OpLogicalOr       },
                    tknStr{ "~"  , obj_tkn::OpBitwiseNot      }
                }
            )
        };
    };
};
}

enum class Token : uint8_t
{
    undef
};
