/*with the help from boost.dll tutorial*/
#include "b2_workarounds.hpp"
#include <boost/dll/import.hpp> // for import_alias
#include <iostream>
#include "my_plugin_api.hpp"

namespace dll = boost::dll;

int main(int argc, char* argv[]) {
    b2_workarounds::argv_to_path_guard guard(argc, argv);
    // b2_workarounds::argv_to_path_guard guard(argc, argv); /*->*/
    boost::dll::fs::path lib_path(argv[1]);             // argv[1] contains path to directory with our plugin library
    boost::shared_ptr<my_plugin_api> plugin;            // variable to hold a pointer to plugin variable
    std::cout << "Loading the plugin" << std::endl;
     
    plugin = dll::import<my_plugin_api>(          // type of imported symbol is located between `<` and `>`
        lib_path / "my_plugin",                     // path to the library and library name
        "plugin",                                       // name of the symbol to import
        dll::load_mode::append_decorations              // makes `libmy_plugin_sum.so` or `my_plugin_sum.dll` from `my_plugin_sum`
    );

    std::cout << "plugin->factorial(5) call:  " << plugin->factorial(5) << std::endl;
}
//]
