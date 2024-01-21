#include <gtest/gtest.h>
#include "../include/StringUtils.h"

TEST(StringUtilsTest, SliceTest){
    std::string base = "Hello";
    EXPECT_EQ(StringUtils::Slice(base, 0), "Hello");
    EXPECT_EQ(StringUtils::Slice(base, 1), "ello");
    EXPECT_EQ(StringUtils::Slice(base, 0, 2), "He");
    EXPECT_EQ(StringUtils::Slice(base, 0, -3), "He");
    EXPECT_EQ(StringUtils::Slice(base, 1, -2), "el");
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
    std::string base = "HELLO  ";
    EXPECT_EQ(StringUtils::RStrip(base), "HELLO");
    EXPECT_EQ(StringUtils::RStrip("  HELLO  "), "  HELLO");
    EXPECT_EQ(StringUtils::RStrip("  HELLO"), "  HELLO");
    EXPECT_EQ(StringUtils::LStrip("   "), "");
}

TEST(StringUtilsTest, Strip){
    std::string base = "  HELLO  ";
    EXPECT_EQ(StringUtils::Strip(base), "HELLO");
    EXPECT_EQ(StringUtils::Strip("  HELLO"), "HELLO");
    EXPECT_EQ(StringUtils::Strip("HELLO  "), "HELLO");
    EXPECT_EQ(StringUtils::Strip("   "), "");
}

TEST(StringUtilsTest, Center){
    std::string base = "HELLO";
    EXPECT_EQ(StringUtils::Center(base,15), "     HELLO     ");
    EXPECT_EQ(StringUtils::Center(base,15,'-'), "-----HELLO-----");
    EXPECT_EQ(StringUtils::Center(base,13), "    HELLO    ");
    EXPECT_EQ(StringUtils::Center(base,13,'-'), "----HELLO----");
    EXPECT_EQ(StringUtils::Center(base,14), "     HELLO    ");
    EXPECT_EQ(StringUtils::Center(base,14,'-'), "-----HELLO----");
}

TEST(StringUtilsTest, LJust){
    std::string base = "HELLO";
    EXPECT_EQ(StringUtils::LJust(base,10), "HELLO     ");
    EXPECT_EQ(StringUtils::LJust(base,10,'-'), "HELLO-----");
}

TEST(StringUtilsTest, RJust){
    std::string base = "HELLO";
    EXPECT_EQ(StringUtils::RJust(base,10), "     HELLO");
    EXPECT_EQ(StringUtils::RJust(base,10,'-'), "-----HELLO");
}

TEST(StringUtilsTest, Replace){
    std::string base = "HELLO HI";
    EXPECT_EQ(StringUtils::Replace(base,"HI","HELLO"), "HELLO HELLO");
    EXPECT_EQ(StringUtils::Replace(base,"HELLO","HI"), "HI HI");
}

TEST(StringUtilsTest, Split){
    std::string base1 = "HELLO HI";
    std::string base2 = "HELLO,HI";
    EXPECT_EQ(StringUtils::Split(base1).size(), 2);
    EXPECT_EQ(StringUtils::Split(base1)[0], "HELLO");
    EXPECT_EQ(StringUtils::Split(base1)[1], "HI");
    EXPECT_EQ(StringUtils::Split(base2,",").size(), 2);
    EXPECT_EQ(StringUtils::Split(base2,",")[0], "HELLO");
    EXPECT_EQ(StringUtils::Split(base2,",")[1], "HI");
}

TEST(StringUtilsTest, Join){
    std::vector<std::string> vects = {"Hello", "Hi"};
    std::string base1 = StringUtils::Join(" ", vects);
    EXPECT_EQ(base1, "Hello Hi");
    std::string base2 = StringUtils::Join(",", vects);
    EXPECT_EQ(base2, "Hello,Hi");
}

TEST(StringUtilsTest, ExpandTabs){
    std::string base = "HELLO\tHI";
    EXPECT_EQ(StringUtils::ExpandTabs(base), "HELLO   HI");
    EXPECT_EQ(StringUtils::ExpandTabs(base,10), "HELLO     HI");
}

TEST(StringUtilsTest, EditDistance){
    
}