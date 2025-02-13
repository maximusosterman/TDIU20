#include "catch.hpp"
#include "list.hpp"
#include <sstream>

TEST_CASE ("Constructors") {

    SECTION("DEFAULT") {
        List empty_list;
        List single_elemnt_list{1};
        List initialized_list{2,5,7};

        empty_list.insert(1);
        std::ostringstream outputStream;
        outputStream << empty_list;  // Capture stream output

        CHECK(outputStream.str() == "{1, 2, 3}");  // Expected sorted output
        
    }

}
