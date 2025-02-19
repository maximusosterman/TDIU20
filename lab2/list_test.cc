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

        single_element_list.insert(2);
        outputStream << single_element_list;  // Capture stream output
        CHECK(outputStream.str() == "{1, 2}");  // Expected sorted output
        outputStream.str("");  // Reset stream buffer
        outputStream.clear();

    }

    SECTION("MULTIPLE ELEMENT LIST - INSERT, PRINT, INIT") {
        List multiple_element_list{1, 2, 3 };
        std::ostringstream outputStream;

        outputStream << multiple_element_list;  // Capture stream output
        CHECK(outputStream.str() == "{1, 2, 3}");  // Expected sorted output
        outputStream.str("");  // Reset stream buffer
        outputStream.clear();

        multiple_element_list.insert(3);
        outputStream << multiple_element_list;  // Capture stream output
        CHECK(outputStream.str() == "{1, 2, 3, 3}");  // Expected sorted output
        outputStream.str("");  // Reset stream buffer
        outputStream.clear();

        multiple_element_list.insert(6);
        outputStream << multiple_element_list;  // Capture stream output
        CHECK(outputStream.str() == "{1, 2, 3, 3, 6}");  // Expected sorted output
        outputStream.str("");  // Reset stream buffer
        outputStream.clear();

    }

    SECTION("ACCESS AT INDEX - INDEX_OF(INDEX))") {
        List multiple_element_list{1, 2, 3};
        List empty_list{};
        std::ostringstream outputStream;

        CHECK(multiple_element_list.index_of(0) == 1);
        CHECK(multiple_element_list.index_of(1) == 2);
        CHECK(multiple_element_list.index_of(2) == 3);

        REQUIRE_THROWS_WITH(multiple_element_list.index_of(3), "Index out of range!");
        REQUIRE_THROWS_WITH(multiple_element_list.index_of(-1), "Index out of range!");

        multiple_element_list.insert(5);
        CHECK(multiple_element_list.index_of(3) == 5);

        REQUIRE_THROWS_WITH(empty_list.index_of(0), "Index out of range!" );

    }

    SECTION("REMOVE AT INDEX - REMOVE(INDEX))") {
        List multiple_element_list{1, 2, 3, 4, 5};
        std::ostringstream outputStream;

        multiple_element_list.remove(2);
        outputStream << multiple_element_list;  // Capture stream output
        CHECK(outputStream.str() == "{1, 2, 4, 5}");
        outputStream.str("");  // Reset stream buffer
        outputStream.clear();

        multiple_element_list.remove(3);
        outputStream << multiple_element_list;  // Capture stream output
        CHECK(outputStream.str() == "{1, 2, 4}");
        outputStream.str("");  // Reset stream buffer
        outputStream.clear();

        multiple_element_list.remove(0);
        outputStream << multiple_element_list;  // Capture stream output
        CHECK(outputStream.str() == "{2, 4}");
        outputStream.str("");  // Reset stream buffer
        outputStream.clear();

        multiple_element_list.remove(1);
        outputStream << multiple_element_list;  // Capture stream output
        CHECK(outputStream.str() == "{2}");
        outputStream.str("");  // Reset stream buffer
        outputStream.clear();

        multiple_element_list.remove(0);
        outputStream << multiple_element_list;  // Capture stream output
        CHECK(outputStream.str() == "{}");
        outputStream.str("");  // Reset stream buffer
        outputStream.clear();

        // REQUIRE_THROWS_WITH(multiple_element_list.remove(0), "Index out of range!");

    }

    // SECTION("INSERT LIST IN CORRECT ORDER - RISING ORDER") {
    //     List unsorted_list{1, 2, 4};
    //     std::ostringstream outputStream;

    //     outputStream << unsorted_list;
    //     CHECK(outputStream.str() == "{1, 2, 4}");
    //     outputStream.str("");  // Reset stream buffer
    //     outputStream.clear();

    //     unsorted_list.insert(3);
    //     outputStream << unsorted_list;
    //     CHECK(outputStream.str() == "{1, 2, 3, 4}");
    //     outputStream.str("");  // Reset stream buffer
    //     outputStream.clear();

    //     unsorted_list.insert(0);
    //     outputStream << unsorted_list;
    //     CHECK(outputStream.str() == "{0, 1, 2, 3, 4}");
    //     outputStream.str("");  // Reset stream buffer
    //     outputStream.clear();

    //     unsorted_list.insert(5);
    //     outputStream << unsorted_list;
    //     CHECK(outputStream.str() == "{0, 1, 2, 3, 4, 5}");

    // }
}
