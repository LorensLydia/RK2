#include <iostream>
#include "Spider.h"
#include "Spider.cpp"
#include "EnemyPool.h"
#include "EnemyPool.cpp"

#include <gtest/gtest.h> // Пример использования Google Test

TEST(SpiderTest, InitTest) {
    Spider spider;
    spider.init("Black Widow", 100.0, 10.0);
    EXPECT_EQ(spider.isAlive(), true);
}

TEST(SpiderTest, AttackTest) {
    Spider spider;
    spider.init("Tarantula", 80.0, 15.0);
    testing::internal::CaptureStdout();
    spider.attack();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Tarantula1 hits Player with 15 damage.\n");
}

TEST(SpiderTest, GetDamageTest) {
    Spider spider;
    spider.init("Jumping Spider", 50.0, 20.0);
    testing::internal::CaptureStdout();
    spider.getDamage(25);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Jumping Spider1 gets 25 damage.\n");
    EXPECT_EQ(spider.isAlive(), true);
}

TEST(SpiderTest, DeathTest) {
    Spider spider;
    spider.init("Wolf Spider", 30.0, 5.0);
    testing::internal::CaptureStdout();
    spider.getDamage(35);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Wolf Spider1 gets 35 damage.\nWolf Spider1 dies\n");
    EXPECT_EQ(spider.isAlive(), false);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

