#include "Spider.h"
#include <gtest/gtest.h>

TEST(SpiderTest, Initialization) {
    Spider spider;
    spider.init("Black Widow", 100.0, 10.0);
    EXPECT_EQ(spider.isAlive(), true);
    EXPECT_EQ(spider.created, 1);
}

TEST(SpiderTest, Attack) {
    Spider spider;
    spider.init("Tarantula", 150.0, 20.0);
    spider.attack();
    EXPECT_GT(spider.hitpoints, 0.0);
}

TEST(SpiderTest, GetDamage) {
    Spider spider;
    spider.init("Brown Recluse", 80.0, 15.0);
    spider.getDamage(20);
    EXPECT_LT(spider.hitpoints, 80.0);
}
add_executable(check ${tests})
target_link_libraries(check gtest_main gmock_main object)
add_test(NAME check COMMAND check)
