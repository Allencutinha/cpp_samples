#include "../doubly_linked_list.hpp" // Include the header file for the doubly linked list implementation
#include <gtest/gtest.h>

TEST(DoublyLinkedListTest, TestPushFront)
{
    DoublyLinkedList list;
    list.pushFront(1);
    list.pushFront(2);
    list.pushFront(3);
    EXPECT_EQ(list.head->data, 3);
    EXPECT_EQ(list.tail->data, 1);
    EXPECT_EQ(list.size, 3);
}

TEST(DoublyLinkedListTest, TestPushBack)
{
    DoublyLinkedList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    EXPECT_EQ(list.head->data, 1);
    EXPECT_EQ(list.tail->data, 3);
    EXPECT_EQ(list.size, 3);
}

TEST(DoublyLinkedListTest, TestPopFront)
{
    DoublyLinkedList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.popFront();
    EXPECT_EQ(list.head->data, 2);
    EXPECT_EQ(list.tail->data, 3);
    EXPECT_EQ(list.size, 2);
}

TEST(DoublyLinkedListTest, TestPopBack)
{
    DoublyLinkedList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.popBack();
    EXPECT_EQ(list.head->data, 1);
    EXPECT_EQ(list.tail->data, 2);
    EXPECT_EQ(list.size, 2);
}

TEST(DoublyLinkedListTest, TestPrintList)
{
    DoublyLinkedList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    testing::internal::CaptureStdout();
    list.printList();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 2 3 \n");
}

TEST(DoublyLinkedListTest, TestSize)
{
    DoublyLinkedList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    EXPECT_EQ(list.size, 3);
    list.popFront();
    list.popBack();
    EXPECT_EQ(list.size, 1);
}

TEST(DoublyLinkedListTest, TestMultiplePushBack)
{
    DoublyLinkedList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    EXPECT_EQ(list.head->data, 1);
    EXPECT_EQ(list.tail->data, 3);
    EXPECT_EQ(list.size, 3);
}

TEST(DoublyLinkedListTest, TestMultiplePopFront)
{
    DoublyLinkedList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.popFront();
    list.popFront();
    EXPECT_EQ(list.head->data, 3);
    EXPECT_EQ(list.tail->data, 3);
    EXPECT_EQ(list.size, 1);
}

TEST(DoublyLinkedListTest, TestMultiplePopBack)
{
    DoublyLinkedList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.popBack();
    list.popBack();
    EXPECT_EQ(list.head->data, 1);
    EXPECT_EQ(list.tail->data, 1);
    EXPECT_EQ(list.size, 1);
}

TEST(DoublyLinkedListTest, TestPushFrontPointers)
{
    DoublyLinkedList list;
    list.pushFront(1);
    list.pushFront(2);
    list.pushFront(3);
    EXPECT_EQ(list.head->prev, nullptr);
    EXPECT_EQ(list.head->next->data, 2);
    EXPECT_EQ(list.tail->prev->data, 2);
    EXPECT_EQ(list.tail->next, nullptr);
}

TEST(DoublyLinkedListTest, TestPushBackPointers)
{
    DoublyLinkedList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    EXPECT_EQ(list.head->prev, nullptr);
    EXPECT_EQ(list.head->next->data, 2);
    EXPECT_EQ(list.tail->prev->data, 2);
    EXPECT_EQ(list.tail->next, nullptr);
}

TEST(DoublyLinkedListTest, TestPopFrontPointers)
{
    DoublyLinkedList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.popFront();
    EXPECT_EQ(list.head->prev, nullptr);
    EXPECT_EQ(list.head->next->data, 3);
    EXPECT_EQ(list.tail->prev->data, 2);
    EXPECT_EQ(list.tail->next, nullptr);
}
