#include <gtest/gtest.h>
#include "../include/StringUtils.h"

TEST(StringUtilsTest, SliceTest){
    std::string base = "Hello";
    EXPECT_EQ(StringUtils::Slice(base, 0), "Hello");
    EXPECT_EQ(StringUtils::Slice(base, 1), "ello");
}

TEST(StringUtilsTest, Capitalize){
    std::string base = "hello";

    EXPECT_EQ(StringUtils::Capitalize(base), "Hello");
    EXPECT_EQ(StringUtils::Capitalize(std::string()), "");
    EXPECT_EQ(StringUtils::Capitalize(" hello"), " hello");
    EXPECT_EQ(StringUtils::Capitalize("HELLO"), "Hello");
}

TEST(StringUtilsTest, Upper){
    std::string base = "hello";

    EXPECT_EQ(StringUtils::Upper(base), "HELLO");
    EXPECT_EQ(StringUtils::Upper("HELLO"), "HELLO");
    EXPECT_EQ(StringUtils::Upper("HELLO123"), "HELLO123");
}

TEST(StringUtilsTest, Lower){
    std::string base = "HELLO";

    EXPECT_EQ(StringUtils::Lower(base), "hello");
    EXPECT_EQ(StringUtils::Lower("hello"), "hello");
    EXPECT_EQ(StringUtils::Lower("hello123"), "hello123");
}

TEST(StringUtilsTest, LStrip){
    std::string base = "  HELLO";
    EXPECT_EQ(StringUtils::LStrip(base), "HELLO");
    EXPECT_EQ(StringUtils::LStrip("  HELLO  "), "HELLO  ");
    EXPECT_EQ(StringUtils::LStrip("HELLO  "), "HELLO  ");
    EXPECT_EQ(StringUtils::LStrip("   "), "");
}

TEST(StringUtilsTest, RStrip){
    
}

TEST(StringUtilsTest, Strip){
    
}

TEST(StringUtilsTest, Center){
    
}

TEST(StringUtilsTest, LJust){
    
}

TEST(StringUtilsTest, RJust){
    
}

TEST(StringUtilsTest, Replace){
    
}

TEST(StringUtilsTest, Split){
    
}

TEST(StringUtilsTest, Join){
    
}

TEST(StringUtilsTest, ExpandTabs){
    
}

TEST(StringUtilsTest, EditDistance){
    
}