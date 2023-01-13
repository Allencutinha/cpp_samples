#include "../singly_linked_list.hpp"
#include <gtest/gtest.h>

// Test fixture for the singly linked list
class SinglyLinkedListTest : public ::testing::Test {
protected:
    SinglyLinkedList<int> list;
};

// Test that the list is initially empty
TEST_F(SinglyLinkedListTest, IsInitiallyEmpty)
{
    EXPECT_TRUE(list.empty());
}

// Test inserting an element at the front of the list
TEST_F(SinglyLinkedListTest, InsertFront)
{
    list.insert_front(10);
    EXPECT_EQ(list.front(), 10);
    EXPECT_FALSE(list.empty());
}

// Test inserting an element at the back of the list
TEST_F(SinglyLinkedListTest, InsertBack)
{
    list.insert_back(20);
    EXPECT_EQ(list.back(), 20);
    EXPECT_FALSE(list.empty());
}

// Test removing an element from the front of the list
TEST_F(SinglyLinkedListTest, RemoveFront)
{
    list.insert_front(10);
    list.insert_front(20);
    list.remove_front();
    EXPECT_EQ(list.front(), 10);
    EXPECT_FALSE(list.empty());
}

// Test removing an element from the back of the list
TEST_F(SinglyLinkedListTest, RemoveBack)
{
    list.insert_back(10);
    list.insert_back(20);
    list.remove_back();
    EXPECT_EQ(list.back(), 10);
    EXPECT_FALSE(list.empty());
}

// Test searching for an element in the list
TEST_F(SinglyLinkedListTest, Search)
{
    list.insert_back(10);
    list.insert_back(20);
    list.insert_back(30);
    EXPECT_TRUE(list.search(20));
    EXPECT_FALSE(list.search(40));
}

// Test clearing the list
TEST_F(SinglyLinkedListTest, Clear)
{
    list.insert_back(10);
    list.insert_back(20);
    list.clear();
    EXPECT_TRUE(list.empty());
}
