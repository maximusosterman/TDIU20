#include "catch.hpp"
#include "list.hpp"
#include <sstream>

TEST_CASE ("Constructors") {

    SECTION("EMPTY LIST - INSERT, PRINT, INIT") {
        List empty_list;
        std::ostringstream outputStream;


        outputStream << empty_list;  // Capture stream output
        CHECK(outputStream.str() == "{}");  // Expected sorted output
        outputStream.str("");  // Reset stream buffer
        outputStream.clear();

        empty_list.insert(1);
        outputStream << empty_list;  // Capture stream output
        CHECK(outputStream.str() == "{1}");  // Expected sorted output
        outputStream.str("");  // Reset stream buffer
        outputStream.clear();

    }

    SECTION("SINGLE ELEMENT - LIST, INSERT, PRINT, INIT") {
        List single_element_list{1};
        std::ostringstream outputStream;


        outputStream << single_element_list;  // Capture stream output
        CHECK(outputStream.str() == "{1}");  // Expected sorted output
        outputStream.str("");  // Reset stream buffer
        outputStream.clear();

    }

    SECTION("MULTIPLE ELEMENT LIST - INSERT, PRINT, INIT") {
        List single_element_list{1, 2, 3 };
        std::ostringstream outputStream;

    }
}
