#include "catch.hpp"
#include "list.hpp"
#include <sstream>

// Komplettering: Ni saknar tester för Copy/Move Assignment/Constructor

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

        empty_list.insert(0);
        outputStream << empty_list;  // Capture stream output
        CHECK(outputStream.str() == "{0, 1}");  // Expected sorted output
        outputStream.str("");  // Reset stream buffer
        outputStream.clear();

        empty_list.insert(2);
        outputStream << empty_list;  // Capture stream output
        CHECK(outputStream.str() == "{0, 1, 2}");  // Expected sorted output
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

        REQUIRE_THROWS_WITH(multiple_element_list.remove(0), "Index out of range!");

    }

    SECTION("GET LENGTH") {
        List empty_list;

        CHECK(empty_list.get_length() == 0);

        empty_list.insert(1);
        CHECK(empty_list.get_length() == 1);

        empty_list.insert(1);
        CHECK(empty_list.get_length() == 2);

        empty_list.remove(1);
        CHECK(empty_list.get_length() == 1);
    }

    SECTION("INSERT LIST IN CORRECT ORDER - RISING ORDER") {
        List unsorted_list{1, 4, 2};
        List backwards_list{5, 4, 3, 2, 1};
        std::ostringstream outputStream;

        outputStream << unsorted_list;
        CHECK(outputStream.str() == "{1, 2, 4}");
        outputStream.str("");  // Reset stream buffer
        outputStream.clear();

        unsorted_list.insert(3);
        outputStream << unsorted_list;
        CHECK(outputStream.str() == "{1, 2, 3, 4}");
        outputStream.str("");  // Reset stream buffer
        outputStream.clear();

        unsorted_list.insert(0);
        outputStream << unsorted_list;
        CHECK(outputStream.str() == "{0, 1, 2, 3, 4}");
        outputStream.str("");  // Reset stream buffer
        outputStream.clear();

        unsorted_list.insert(5);
        outputStream << unsorted_list;
        CHECK(outputStream.str() == "{0, 1, 2, 3, 4, 5}");
        outputStream.str("");  // Reset stream buffer
        outputStream.clear();

        outputStream << backwards_list;
        CHECK(outputStream.str() == "{1, 2, 3, 4, 5}");
        outputStream.str("");  // Reset stream buffer
        outputStream.clear();

        backwards_list.insert(-2);
        outputStream << backwards_list;
        CHECK(outputStream.str() == "{-2, 1, 2, 3, 4, 5}");

    }

    SECTION(" MOVE ") {

        List list{1, 2, 3};
        List list2{std::move(list)};

        CHECK(list2.get_length() == 3);
        CHECK(list.get_length() == 0);

    }

    SECTION(" COPY ") {
        List original_list{1, 2, 3};
        List copied_list = original_list;  // Calls copy constructor

        std::ostringstream outputStream;

        outputStream << copied_list;
        CHECK(outputStream.str() == "{1, 2, 3}");
        outputStream.str(""); outputStream.clear();

        original_list.insert(4);

        outputStream << original_list;
        CHECK(outputStream.str() == "{1, 2, 3, 4}");
        outputStream.str(""); outputStream.clear();

        outputStream << copied_list;
        CHECK(outputStream.str() == "{1, 2, 3}");
    }

    SECTION(" COPY ASSIGNMENT ") {
        List list1{1, 2, 3};
        List list2{4, 5};

        list2 = list1;

        std::ostringstream outputStream;

        outputStream << list2;
        CHECK(outputStream.str() == "{1, 2, 3}");
        outputStream.str(""); outputStream.clear();

        list1.insert(4);

        outputStream << list1;
        CHECK(outputStream.str() == "{1, 2, 3, 4}");
        outputStream.str(""); outputStream.clear();

        outputStream << list2;
        CHECK(outputStream.str() == "{1, 2, 3}");
        outputStream.str(""); outputStream.clear();

        outputStream << list2;
        CHECK(outputStream.str() == "{1, 2, 3}");
    }

    SECTION(" MOVE ASSIGNMENT ") {

        List list1{1, 2, 3};
        List list2{4, 5};

        list2 = std::move(list1);  // Calls move assignment

        std::ostringstream outputStream;

        outputStream << list2;
        CHECK(outputStream.str() == "{1, 2, 3}");
        outputStream.str(""); outputStream.clear();

        CHECK(list1.is_empty());
    }

}
