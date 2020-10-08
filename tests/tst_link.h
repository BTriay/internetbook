#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../src/entity/Link.h"

using namespace testing;

TEST(LinkTest1, EntityTests)
{
    Link l("LinkName", "LinkUrl");
    l.add_keyword("keyword 1");
    ASSERT_EQ(l.list_keywords(), "keyword 1; ");
}

TEST(LinkTest2, EntityTests)
{
    Link l("LinkName", "LinkUrl");
    l.add_keyword("keyword 1");
    ASSERT_EQ(l.name(), "LinkName");
}


TEST(LinkTest3, EntityTests)
{
    Link l("LinkName", "LinkUrl");
    l.add_keyword("keyword 1");
    ASSERT_EQ(l.url(), "LinkUrl");
}
