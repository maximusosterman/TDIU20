#include "catch.hpp"
#include "time.h"
#include <sstream>

using namespace std;

TEST_CASE ("Constructors and getters")
{
   SECTION("Default")
   {
      Time empty{};
      CHECK( empty.get_hour()   == 0 );
      CHECK( empty.get_minute() == 0 );
      CHECK( empty.get_second() == 0 );
   }
// /* ----- REMOVE THIS COMMENT WHEN PREVIOUS TEST PASSES -----

   SECTION("Integer")
   {
      Time t0{0,0,0};
      Time t1{12,30,30};
      Time t2{23,59,59};

      CHECK_THROWS( Time{13,35,60} );
      CHECK_THROWS( Time{13,60,35} );
      CHECK_THROWS( Time{24,35,35} );
             
      CHECK( t0.get_hour()   == 0 );
      CHECK( t0.get_minute() == 0 );
      CHECK( t0.get_second() == 0 );
      CHECK( t1.get_hour()   == 12 );
      CHECK( t1.get_minute() == 30 );
      CHECK( t1.get_second() == 30 );
      CHECK( t2.get_hour()   == 23 );
      CHECK( t2.get_minute() == 59 );
      CHECK( t2.get_second() == 59 );
   }

// /* ----- REMOVE THIS COMMENT WHEN PREVIOUS TEST PASSES -----

   SECTION("String")
   {
      Time t0{"00:00:00"};
      Time t1{"12:30:30"};
      Time t2{"23:59:59"};

      CHECK_THROWS( Time{"13:35:60"} );
      CHECK_THROWS( Time{"13:60:35"} );
      CHECK_THROWS( Time{"24:35:35"} );

      CHECK( t0.get_hour()   == 0 );
      CHECK( t0.get_minute() == 0 );
      CHECK( t0.get_second() == 0 );
      CHECK( t1.get_hour()   == 12 );
      CHECK( t1.get_minute() == 30 );
      CHECK( t1.get_second() == 30 );
      CHECK( t2.get_hour()   == 23 );
      CHECK( t2.get_minute() == 59 );
      CHECK( t2.get_second() == 59 );  
   }

}
// /* ----- REMOVE THIS COMMENT WHEN PREVIOUS TEST PASSES -----
TEST_CASE ("is_am") 
{
   Time t0{"05:00:00"};
   Time t1{"14:00:00"};
   CHECK       ( t0.is_am() );
   CHECK_FALSE ( t1.is_am() );

}

// /* ----- REMOVE THIS COMMENT WHEN PREVIOUS TEST PASSES -----

TEST_CASE ("to_string")
{
   Time t0{};
   Time t1{11, 59, 59};
   Time t2{12, 0, 0};
   Time t3{13, 0, 0};
   Time t4{23, 59, 59};
   SECTION("24 hour format no argument")
   {
      CHECK( t0.to_string() == "00:00:00" );
      CHECK( t1.to_string() == "11:59:59" );
      CHECK( t2.to_string() == "12:00:00" );
      CHECK( t3.to_string() == "13:00:00" );
      CHECK( t4.to_string() == "23:59:59" );
   }
   
   SECTION("24 hour format with argument") // true arg
   {
      CHECK( t0.to_string(true) == "00:00:00" );
      CHECK( t1.to_string(true) == "11:59:59" );
      CHECK( t2.to_string(true) == "12:00:00" );
      CHECK( t3.to_string(true) == "13:00:00" );
      CHECK( t4.to_string(true) == "23:59:59" );
   }

   SECTION("12 hour format") // flase arg
   {
      CHECK( t0.to_string(false) == "12:00:00am" );
      CHECK( t1.to_string(false) == "11:59:59am" );
      CHECK( t2.to_string(false) == "12:00:00pm" );
      CHECK( t3.to_string(false) == "01:00:00pm" );
      CHECK( t4.to_string(false) == "11:59:59pm" );
   }
}

TEST_CASE ("Operators")
{
   Time t0{"00:00:00"};
   Time t1{"12:00:00"};
   Time t2{"23:59:59"};

   Time t3{"00:00:00"};
   Time t4{"12:00:00"};
   Time t5{"23:59:59"};

   Time t6{"00:00:00"};
   Time t7{"12:00:00"};
   Time t8{"23:59:59"};

   SECTION("Equality")
   {
      CHECK( t0 == t3 );
      CHECK( t1 == t4 );
      CHECK( t2 == t5 );
   }
   SECTION("Inequality")
   {
      CHECK_FALSE( t0 != t3 );
      CHECK_FALSE( t1 != t4 );
      CHECK_FALSE( t2 != t5 );
   }
   SECTION("Less than")
   {
      CHECK_FALSE( t0 < t3 );
      CHECK_FALSE( t1 < t4 );
      CHECK_FALSE( t2 < t5 );

      CHECK( t0 < t1 );
      CHECK( t4 < t5 );
   }
   SECTION("Greater than")
   {
      CHECK_FALSE( t0 > t3 );
      CHECK_FALSE( t1 > t4 );
      CHECK_FALSE( t2 > t5 );

      CHECK( t1 > t0 );
      CHECK( t5 > t4 );
   }
   SECTION("Less than or equal to")
   {
      CHECK( t0 <= t3 );
      CHECK( t1 <= t4 );
      CHECK( t2 <= t5 );
   }
   SECTION("Greater than or equal to")
   {
      CHECK( t0 >= t3 );
      CHECK( t1 >= t4 );
      CHECK( t2 >= t5 );
   }

   SECTION("Pre-increment")
   {
      CHECK( (++t0).to_string() == "00:00:01" );
      CHECK( (++t1).to_string() == "12:00:01" );
      CHECK( (++t2).to_string() == "00:00:00" );
   }

   SECTION("Post-increment")
   {
      CHECK( (t0++).to_string() == "00:00:00" );
      CHECK( (t1++).to_string() == "12:00:00" );
      CHECK( (t2++).to_string() == "23:59:59" );

      CHECK( t0.to_string() == "00:00:01" );
      CHECK( t1.to_string() == "12:00:01" );
      CHECK( t2.to_string() == "00:00:00" );

   }

   SECTION("Pre-decremnt")
   {
      CHECK( (--t0).to_string() == "23:59:59" );
      CHECK( (--t1).to_string() == "11:59:59" );
      CHECK( (--t2).to_string() == "23:59:58" );
   }

   SECTION("Post-decrement")
   {
      CHECK( (t0--).to_string() == "00:00:00" );
      CHECK( (t1--).to_string() == "12:00:00" );
      CHECK( (t2--).to_string() == "23:59:59" );

      CHECK( t0.to_string() == "23:59:59" );
      CHECK( t1.to_string() == "11:59:59" );
      CHECK( t2.to_string() == "23:59:58" );
   }

   SECTION("Additon")
   {
      CHECK( (t0 + 1).to_string() == "00:00:01" );
      CHECK( (t1 + 1).to_string() == "12:00:01" );
      CHECK( (t2 + 1).to_string() == "00:00:00" );
      CHECK ( (t0 + 61).to_string() == "00:01:01" );

      CHECK ( (t0 += 1).to_string() == "00:00:01" );
      CHECK( (t1 += 1).to_string() == "12:00:01" );
      CHECK( (t2 += 1).to_string() == "00:00:00" );


      CHECK( (1 + t0).to_string() == "00:00:02" );
      CHECK( (1 + t1).to_string() == "12:00:02" );
      CHECK( (1 + t2).to_string() == "00:00:01" );
      CHECK ( (61 + t0).to_string() == "00:02:02" );
   }

   SECTION("Subtraction")
   {
      CHECK( (t6 - 1).to_string() == "23:59:59" );
      CHECK( (t7 - 1).to_string() == "11:59:59" );
      CHECK( (t8 - 1).to_string() == "23:59:58" );

      CHECK( (t6 -= 1).to_string() == "23:59:59" );
      CHECK( (t7 -= 1).to_string() == "11:59:59" );
      CHECK( (t8 -= 1).to_string() == "23:59:58" );
   }
}

TEST_CASE("Print out to stream") 
{
   Time t0{"00:00:00"};
   Time t1{"12:00:00"};
   Time t2{"23:59:59"};
   SECTION("24 hour format")
   {
      ostringstream oss;
      oss << t0;
      CHECK( oss.str() == "00:00:00" );
      oss.str("");
      oss << t1;
      CHECK( oss.str() == "12:00:00" );
      oss.str("");
      oss << t2;
      CHECK( oss.str() == "23:59:59" );
   }
   SECTION("12 hour format")
   {
      ostringstream oss;
      oss << t0.to_string(false);
      CHECK( oss.str() == "12:00:00am" );
      oss.str("");
      oss << t1.to_string(false);
      CHECK( oss.str() == "12:00:00pm" );
      oss.str("");
      oss << t2.to_string(false);
      CHECK( oss.str() == "11:59:59pm" );
   }
}

TEST_CASE("Input to stream")
{
   Time t0{}; 
   istringstream iss;
   SECTION("24 hour format")
   {
      iss.str("00:00:00");
      iss >> t0;
      CHECK( t0.to_string() == "00:00:00" );
   }
   SECTION("12 hour format")
   { 
      iss.str("00:00:00");
      iss >> t0;
      CHECK( t0.to_string(false) == "12:00:00am" );

   }

}

