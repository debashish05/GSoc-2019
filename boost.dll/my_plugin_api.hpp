/*with the help from boost.dll tutorial*/
#ifndef BOOST_DLL_MY_PLUGIN_API_HPP
#define BOOST_DLL_MY_PLUGIN_API_HPP

//[plugapi
#include <boost/config.hpp>
#include <string>

class BOOST_SYMBOL_VISIBLE my_plugin_api {
public:
   virtual std::string name() const = 0;
   virtual long long factorial(int x) = 0;

   virtual ~my_plugin_api() {}
};
//]
   
#endif // BOOST_DLL_MY_PLUGIN_API_HPP

