/*with the help from boost.dll tutorial*/

#include <iostream>
#include <boost/config.hpp> // for BOOST_SYMBOL_EXPORT
#include "my_plugin_api.hpp"

namespace my_namespace {

class my_plugin : public my_plugin_api {
public:
    my_plugin() {
        std::cout << "Constructing my_plugin" << std::endl;
    }

    std::string name() const {
        return "factorial";
    }

    long long factorial(int x) {
        long long ans=1;
        for(int i=2;i<=x;++i)ans*=i;
        return ans;
    }
   
    ~my_plugin() {
        std::cout << "Destructing my_plugin"<< std::endl;
    }
};

// Exporting `my_namespace::plugin` variable with alias name `plugin`
// (Has the same effect as `BOOST_DLL_ALIAS(my_namespace::plugin, plugin)`)
extern "C" BOOST_SYMBOL_EXPORT my_plugin plugin;
my_plugin plugin;

} // namespace my_namespace

//]
