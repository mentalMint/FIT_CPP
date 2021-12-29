#include "gtest/gtest.h"
#include "../HashTable.h"

class HashTableUnitTests : public ::testing::Test {
protected:
    virtual void SetUp()
    {
        testTable = new HashTable();
    }
    
    virtual void TearDown() {
        delete testTable;
    }
    
    HashTable * testTable;
};

TEST_F(HashTableUnitTests, ConstructorTest) {
    HashTable a;
    ASSERT_TRUE(a.empty());
}

TEST_F(HashTableUnitTests, MoveTest) {
    HashTable a;
    Value v(1, 2);
    a.insert("Test", v);
    HashTable b = std::move(a);
    ASSERT_TRUE(b.contains("Test"));
}

TEST_F(HashTableUnitTests, CopyTest) {
    HashTable a;
    Value v(1, 2);
    a.insert("Test", v);
    HashTable b = a;
    ASSERT_TRUE(b.contains("Test"));
}

TEST_F(HashTableUnitTests, AssignmentMoveTest) {
    HashTable a, b;
    Value v(1, 2);
    Value v2(20, 60);
    a.insert("Test", v);
    b.insert("Test2", v2);    b = std::move(a);
    ASSERT_TRUE(b.contains("Test"));
}

TEST_F(HashTableUnitTests, AssignmentCopyTest) {
    HashTable a, b;
    Value v(1, 2);
    Value v2(20, 60);
    a.insert("Test", v);
    b.insert("Test2", v2);
    b = a;
    ASSERT_TRUE(b.contains("Test"));
}

TEST_F(HashTableUnitTests, SwapTest) {
    HashTable a, b;
    Value v(1, 2), v1(11, 22);
    a.insert("Test", v);
    b.insert("Test2", v1);
    a.swap(b);
    ASSERT_FALSE(a.contains("Test"));
    ASSERT_TRUE(a.contains("Test2"));
    ASSERT_TRUE(b.contains("Test"));
    ASSERT_FALSE(b.contains("Test2"));
}

TEST_F(HashTableUnitTests, ClearTest) {
    HashTable a;
    Value v(1, 2), v1(11, 22);
    a.insert("Test", v);
    a.insert("Test2", v1);
    a.clear();
    ASSERT_TRUE(a.empty() == 1);
}

TEST_F(HashTableUnitTests, InsertTest) {
    HashTable a;
    for (int i = 0; i < 100; ++i) {
        Value v(i, 2 * i);
        a.insert(std::to_string(i), v);
    }
    
    for (int i = 0; i < 100; ++i) {
        ASSERT_TRUE(a.contains(std::to_string(i)) == 1);
        Value v1 = a.at(std::to_string(i));
        ASSERT_TRUE(v1._age == i);
        ASSERT_TRUE(v1._weight == 2 * i);
    }
}

TEST_F(HashTableUnitTests, EraseTest) {
    HashTable a;
    for (int i = 0; i < 100; ++i) {
        Value v(i, 2 * i);
        a.insert(std::to_string(i), v);
    }
    
    for (int i = 0; i < 100; i += 2) {
        a.erase(std::to_string(i));
    }
    
    for (int i = 1; i < 100; i += 2) {
        ASSERT_TRUE(a.contains(std::to_string(i)));
    }
}

TEST_F(HashTableUnitTests, ContainsTest) {
    HashTable a;
    Value v(1, 2), v1(11, 22);
    a.insert("Test", v);
    a.insert("Test2", v1);
    ASSERT_TRUE(a.contains("Test2"));
    ASSERT_TRUE(a.contains("Test"));
    a.erase("Test2");
    ASSERT_TRUE(a.contains("Test"));
    ASSERT_FALSE(a.contains("Test2"));
}

TEST_F(HashTableUnitTests, AtTest) {
    HashTable a;
    Value v(1, 2), v1(11, 22);
    a.insert("Test", v);
    a.insert("Test2", v1);
    Value v3 = a.at("Test");
    const Value v2 = a.at("Test2");
    ASSERT_TRUE(v3._age == 1);
    ASSERT_TRUE(v3._weight == 2);
    ASSERT_TRUE(v2._age == 11);
    ASSERT_TRUE(v2._weight == 22);
}

TEST_F(HashTableUnitTests, BracketsTest) {
    HashTable a;
    Value v1(1, 2), v2(11, 22);
    a.insert("Test", v1);
    a.insert("Test2", v2);
    Value v3 = a["Test"];
    Value v4 = a["Test3"];
    ASSERT_TRUE(v3._age == 1);
    ASSERT_TRUE(v3._weight == 2);
    ASSERT_TRUE(v4._age == 0);
    ASSERT_TRUE(v4._weight == 0);
}

TEST_F(HashTableUnitTests, SizeTest) {
    HashTable a;
    ASSERT_TRUE(a.size() == 0);
    Value v(1, 2), v1(11, 22);
    a.insert("Test", v);
    a.insert("Test2", v1);
    ASSERT_TRUE(a.size() == 2);
}

TEST_F(HashTableUnitTests, EmptyTest) {
    HashTable a;
    ASSERT_TRUE(a.empty() == 1);
    Value v(1, 2), v1(11, 22);
    a.insert("Test", v);
    a.insert("Test2", v1);
    ASSERT_TRUE(a.empty() == 0);
}

TEST_F(HashTableUnitTests, EqualTest) {
    HashTable a, b;
    Value v(1, 2), v1(11, 22);
    a.insert("Test", v);
    a.insert("Test2", v1);
    b.insert("Test2", v1);
    b.insert("Test", v);
    ASSERT_TRUE((a == b) == 1);
    ASSERT_TRUE((a != b) == 0);
    b.erase("Test");
    ASSERT_TRUE((a == b) == 0);
    ASSERT_TRUE((a != b) == 1);
}
