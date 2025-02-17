#include "catch.hpp"
#include "list.hpp"
#include <sstream>

TEST_CASE ("Constructors") {

    SECTION("DEFAULT") {
        List empty_list;
        List single_element_list{1};
        List initialized_list{2,5,7};
        std::ostringstream outputStream;

        empty_list.insert(1);
        outputStream << empty_list;  // Capture stream output
        CHECK(outputStream.str() == "{}");  // Expected sorted output

        outputStream << single_element_list;  // Capture stream output
        CHECK(outputStream.str() == "{1}");  // Expected sorted output

    }

}
