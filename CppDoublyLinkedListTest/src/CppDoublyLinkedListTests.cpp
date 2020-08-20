#include <include/CppDoublyLinkedList.hpp>

#include <gtest/gtest.h>

using namespace ::testing;

/**
 * @brief Test base class.
 */
class CContainerTest : public Test
{
public:

};

/**
 * Test for empty container.
 */
TEST_F(CContainerTest, empty)
{
    CDoublyLinkedList<int> container;
    // check size of empty container
    const unsigned int sizeEmptyActual = container.size();
    ASSERT_EQ(sizeEmptyActual, 0u);
    // check empty method
    const bool emptyActual = container.empty();
    ASSERT_TRUE(emptyActual);
    // check if empty container contains value
    const bool containsActual = container.contains(1);
    ASSERT_FALSE(containsActual);
    // get value from empty list
    const int* valueActual = container.get(0);
    ASSERT_EQ(valueActual, nullptr);
}

/**
 * Test for adding and removing object at the end.
 */
TEST_F(CContainerTest, oneElement_pushBack_popBack)
{
    const int expectedValue = 1;
    CDoublyLinkedList<int> container;
    // add object
    container.pushBack(expectedValue);
    // check size
    const unsigned int sizeOneObjectActual = container.size();
    ASSERT_EQ(sizeOneObjectActual, 1u);
    // check if container is not empty
    const bool emptyOneObjectActual = container.empty();
    ASSERT_FALSE(emptyOneObjectActual);
    // check if container contains added value
    const bool containsValueActual = container.contains(expectedValue);
    ASSERT_TRUE(containsValueActual);
    // check if container contains not added value.
    const bool containsFalseActual = container.contains(100);
    ASSERT_FALSE(containsFalseActual);
    // check the first item - already added item
    const int* valueActual = container.get(0);
    ASSERT_NE(valueActual, nullptr);
    ASSERT_EQ(*valueActual, expectedValue);

    // remove object
    const int popBackActual = container.popBack();
    
    ASSERT_EQ(popBackActual, expectedValue);
    // check if container contains value that was removed
    const bool containsAfterRemoveActual = container.contains(expectedValue);
    ASSERT_FALSE(containsAfterRemoveActual);
    // check size
    const unsigned int sizeAfterRemoveActual = container.size();
    ASSERT_EQ(sizeAfterRemoveActual, 0u);
    // check if container is empty
    const bool emptyAfterRemoveActual = container.empty();
    ASSERT_TRUE(emptyAfterRemoveActual);
    // check if first item is null because container is empty
    const int* valueAfterRemoveActual = container.get(0);
    ASSERT_EQ(valueAfterRemoveActual, nullptr);
}

/**
 * Test for adding and removing object at the beginnig.
 */
TEST_F(CContainerTest, oneElement_pushFront_popFront)
{
    const int expectedValue = 1;
    CDoublyLinkedList<int> container;
    // add object
    container.pushFront(expectedValue);
    // check size after adding value
    const unsigned int sizeOneObjectActual = container.size();
    ASSERT_EQ(sizeOneObjectActual, 1u);
    // check if container is not empty
    const bool emptyOneObjectActual = container.empty();
    ASSERT_FALSE(emptyOneObjectActual);
    // check if container contains added value
    const bool containsValueActual = container.contains(expectedValue);
    ASSERT_TRUE(containsValueActual);
    // check if container doesn't contain not added value
    const bool containsFalseActual = container.contains(100);
    ASSERT_FALSE(containsFalseActual);
    // check added value
    const int* valueActual = container.get(0);
    ASSERT_NE(valueActual, nullptr);
    ASSERT_EQ(*valueActual, expectedValue);
    
    // remove object
    const int popFrontActual = container.popFront();
    
    ASSERT_EQ(popFrontActual, expectedValue);
    // check if container doesn't contain value that was removed
    const bool containsAfterRemoveActual = container.contains(expectedValue);
    ASSERT_FALSE(containsAfterRemoveActual);
    // check size of container after removing item.
    const unsigned int sizeAfterRemoveActual = container.size();
    ASSERT_EQ(sizeAfterRemoveActual, 0u);
    // check if container is empty after removing item
    const bool emptyAfterRemoveActual = container.empty();
    ASSERT_TRUE(emptyAfterRemoveActual);
    // check if item that was removed, doesn't exist in the container.
    const int* valueAfterRemoveActual = container.get(0);
    ASSERT_EQ(valueAfterRemoveActual, nullptr);
}

/**
 * @brief Base class for GoogleTest parametrized tests.
 */
class CContainerParamTest : public TestWithParam<unsigned int>
{
};

/**
 * Tests for many pushBack and popBack.
 */
TEST_P(CContainerParamTest, pushBack_popBack)
{
    const unsigned int& size = GetParam();
    CDoublyLinkedList<int> container;
    
    // loop for adding items
    for (unsigned int i = 0; i < size; ++i)
    {
        const unsigned int sizeBeforePushBackExpected = i;
        const unsigned int sizeAfterPushBackExpected = i + 1;
        const int valueExpected = i + 1;
        const int valueNotInList = valueExpected * 2 + 10000;
        
        const unsigned int sizeBeforePushBackActual = container.size();
        ASSERT_EQ(sizeBeforePushBackExpected, sizeBeforePushBackActual);

        container.pushBack(valueExpected);
        // check if container is not empty after adding item
        const bool emptyAfterPushBackActual = container.empty();
        ASSERT_FALSE(emptyAfterPushBackActual);
        // check size after adding item
        const unsigned int sizeAfterPush = container.size();
        ASSERT_EQ(sizeAfterPushBackExpected, sizeAfterPush);
        // check if container contains already added value
        const bool containsAfterPushBackActual = container.contains(valueExpected);
        ASSERT_TRUE(containsAfterPushBackActual);
        // check if container doesn't contains item that wasn't added.
        const bool containsFalseAfterPushBackActual = container.contains(valueNotInList);
        ASSERT_FALSE(containsFalseAfterPushBackActual);
        // check added item
        const int* valueActual = container.get(i);
        ASSERT_NE(valueActual, nullptr);
        ASSERT_EQ(*valueActual, valueExpected);
    }
    
    // loop for removing items
    for (unsigned int i = size; i > 0; --i)
    {
        const unsigned int sizeBeforePopBackExpected = i;
        const unsigned int sizeAfterPopBackExpected = i - 1;
        const int valueExpected = i;
        // check if container is not empty
        const bool emptyBeforePopBackActual = container.empty();
        ASSERT_FALSE(emptyBeforePopBackActual);
        // check size of container
        const unsigned int sizeBeforePopBackActual = container.size();
        ASSERT_EQ(sizeBeforePopBackExpected, sizeBeforePopBackActual);
        
        // remove item from container
        const int valuePopBackActual = container.popBack();
        
        // check value of removed item
        ASSERT_EQ(valueExpected, valuePopBackActual);
        // check if size was changed after removing item
        const unsigned int sizeAfterPopBackActual = container.size();
        ASSERT_EQ(sizeAfterPopBackExpected, sizeAfterPopBackActual);
        // check if container doesn't contain already removed item.
        const bool containAfterPopBackActual = container.contains(valuePopBackActual);
        ASSERT_FALSE(containAfterPopBackActual);
        
        // check values of item that are still in the container
        for (unsigned int j = 0; j < i - 1; ++j)
        {
            const int* valueLeftAfterPopBackActual = container.get(j);
            ASSERT_NE(valueLeftAfterPopBackActual, nullptr);
            const int valueLeftAfterPopBackExpected = j + 1;
            ASSERT_EQ(*valueLeftAfterPopBackActual, valueLeftAfterPopBackExpected);
        }
        // check if there isn't item that were removed from container
        for (unsigned int j = i - 1; j < size; ++j)
        {
            const int* valueEmptyAfterPopBackActual = container.get(j);
            ASSERT_EQ(valueEmptyAfterPopBackActual, nullptr);
        }
    }
}

/**
 * Test for many pushFont, popFront
 */
TEST_P(CContainerParamTest, pushFront_popFront)
{
    const unsigned int& size = GetParam();
    CDoublyLinkedList<int> container;
    
    // loop for adding items
    for (unsigned int i = 0; i < size; ++i)
    {
        const unsigned int sizeBeforePushFrontExpected = i;
        const unsigned int sizeAfterPushFrontExpected = i + 1;
        const int valueExpected = i + 1;
        const int valueNotInList = valueExpected * 2 + 10000;
        
        // check size of container
        const unsigned int sizeBeforePushFrontActual = container.size();
        ASSERT_EQ(sizeBeforePushFrontExpected, sizeBeforePushFrontActual);
        
        // push new item
        container.pushFront(valueExpected);
        
        // check if container is not empty after adding item
        const bool emptyAfterPushFrontActual = container.empty();
        ASSERT_FALSE(emptyAfterPushFrontActual);
        // check if size was changed after pushing item
        const unsigned int sizeAfterPush = container.size();
        ASSERT_EQ(sizeAfterPushFrontExpected, sizeAfterPush);
        // check if container contains already added value
        const bool containsAfterPushFrontActual = container.contains(valueExpected);
        ASSERT_TRUE(containsAfterPushFrontActual);
        // check if container doesn't contain value that wasn't added.
        const bool containsFalseAfterPushFrontActual = container.contains(valueNotInList);
        ASSERT_FALSE(containsFalseAfterPushFrontActual);
        // check item that was already added
        const int* valueActual = container.get(0);
        ASSERT_NE(valueActual, nullptr);
        ASSERT_EQ(*valueActual, valueExpected);
    }
    
    // loop for removing items
    for (unsigned int i = size; i > 0; --i)
    {
        const unsigned int sizeBeforePopFrontExpected = i;
        const unsigned int sizeAfterPopFrontExpected = i - 1;
        const int valueExpected = i;
        
        // check if container is not empty
        const bool emptyBeforePopFrontActual = container.empty();
        ASSERT_FALSE(emptyBeforePopFrontActual);
        // check size of container
        const unsigned int sizeBeforePopFrontActual = container.size();
        ASSERT_EQ(sizeBeforePopFrontExpected, sizeBeforePopFrontActual);
        
        // removed item
        const int valuePopFrontActual = container.popFront();
        
        // check value of removed item
        ASSERT_EQ(valueExpected, valuePopFrontActual);
        // check size after removing item
        const unsigned int sizeAfterPopFrontActual = container.size();
        ASSERT_EQ(sizeAfterPopFrontExpected, sizeAfterPopFrontActual);
        // check if container doesn't contain value that was removed
        const bool containAfterPopFrontActual = container.contains(valuePopFrontActual);
        ASSERT_FALSE(containAfterPopFrontActual);
        
        if (sizeAfterPopFrontExpected > 0)
        {
            // check values that left in the list
            for (unsigned int j = 0; j < sizeAfterPopFrontExpected; ++j)
            {
                const int* valueLeftAfterPopFrontActual = container.get(j);
                ASSERT_NE(valueLeftAfterPopFrontActual, nullptr);
                const int valueLeftAfterPopFrontExpected = valuePopFrontActual - j;
                ASSERT_NE(*valueLeftAfterPopFrontActual, valueLeftAfterPopFrontExpected);
            }
        }
        else
        {
            // check values that were removed
            const int* valueNullAfterPopFrontActual = container.get(0);
            ASSERT_EQ(valueNullAfterPopFrontActual, nullptr);
        }
    }
}

/**
 * Test for insert method
 */
TEST_P(CContainerParamTest, insert)
{
    const unsigned int& size = GetParam(); // get param value

    for (unsigned int j = 0; j < size; ++j)
    {
        CDoublyLinkedList<int> container;
        // push some values
        for (unsigned int i = 0; i < size; ++i)
        {
            container.pushBack(i);
        }
        // check value before calling insert
        const int beforeInsertExpected = j;
        const int beforeInsertActual = *container.get(j);
        ASSERT_EQ(beforeInsertActual, beforeInsertExpected);

        // insert new value
        const int valueExpected = (j + size + 100);
        container.insert(j, valueExpected);

        // check value of inserted item
        const int* insertedValueActual = container.get(j);
        ASSERT_NE(insertedValueActual, nullptr);
        ASSERT_EQ(*insertedValueActual, valueExpected);
        
        // check value of next item
        const int* nextValueActual = container.get(j + 1);
        ASSERT_NE(nextValueActual, nullptr);
        const int nextValueExpected = j;
        ASSERT_EQ(*nextValueActual, nextValueExpected);
        
        if (j > 0)
        {
            // check previous items
            const int* prevValueActual = container.get(j - 1);
            ASSERT_NE(prevValueActual, nullptr);
            const int prevValueExpected = j - 1;
            ASSERT_EQ(*prevValueActual, prevValueExpected);
        }
    }
}

/**
 * Test for insert method
 */
TEST_P(CContainerParamTest, iterator)
{
    const unsigned int& size = GetParam(); // get param value

    CDoublyLinkedList<int> container;
    for (unsigned int j = 0; j < size; ++j)
    {
        container.pushBack(j);
    }

    typename CDoublyLinkedList<int>::DIterator it = container.begin();
    typename CDoublyLinkedList<int>::DIterator end = container.end();

    for (unsigned int j = 0; it != end; ++it, ++j)
    {
        const int value = *it;
        ASSERT_EQ(value, j);
    }

    typename CDoublyLinkedList<int>::DReverseIterator rit = container.rbegin();
    typename CDoublyLinkedList<int>::DReverseIterator rend = container.rend();

    for (unsigned int j = size - 1; rit != rend; ++rit, --j)
    {
        const int value = *rit;
        ASSERT_EQ(value, j);
    }
    if (size > 1)
    {
        {
            const typename CDoublyLinkedList<int>::DIterator itToFirstItem = container.begin();
            const typename CDoublyLinkedList<int>::DReverseIterator itToLastItem = container.rbegin();
            const typename CDoublyLinkedList<int>::DIterator calculatedLast = itToFirstItem + (size - 1);
            const typename CDoublyLinkedList<int>::DIterator calculatedFirst = calculatedLast - (size - 1);
            ASSERT_EQ(*calculatedLast, *itToLastItem);
            ASSERT_EQ(*calculatedFirst, *itToFirstItem);
        }
        {
            const typename CDoublyLinkedList<int>::DReverseIterator itToLastItem = container.rbegin();
            const typename CDoublyLinkedList<int>::DIterator itToFirstItem = container.begin();
            const typename CDoublyLinkedList<int>::DReverseIterator calculatedFirst = itToLastItem + (size - 1);
            const typename CDoublyLinkedList<int>::DReverseIterator calculatedLast = calculatedFirst - (size - 1);

            ASSERT_EQ(*calculatedLast, *itToLastItem);
            ASSERT_EQ(*calculatedFirst, *itToFirstItem);
        }
    }
}

/**
 * Test for insert method
 */
TEST_P(CContainerParamTest, ruleOf3)
{
    const unsigned int& size = GetParam(); // get param value

    CDoublyLinkedList<int> containerA1;
    CDoublyLinkedList<int> containerA2;
    CDoublyLinkedList<int> containerB1;

    for (unsigned int j = 0; j < size; ++j)
    {
        containerA1.pushBack(j);
        containerA2.pushBack(j);
        containerB1.pushBack(100 * j + 999);
    }

    ASSERT_TRUE(containerA1 == containerA1);
    ASSERT_TRUE(containerA1 != containerB1);
    ASSERT_FALSE(containerA1 != containerA1);
    ASSERT_FALSE(containerA1 == containerB1);

    CDoublyLinkedList<int> containerC1(containerA1);

    ASSERT_TRUE(containerA1 == containerC1);


    CDoublyLinkedList<int> containerD1;
    containerD1 = containerA1;
    ASSERT_TRUE(containerA1 == containerD1);

}
/**
 * @brief Function to display name of tests.
 * @param aInfo Param info.
 * @return Label
 */
std::string customMessage(testing::TestParamInfo<unsigned int> aInfo)
{
    std::stringstream ss;
    ss<<"Size_"<<aInfo.param;
    return ss.str();
};

const unsigned int minSize = 2u;
const unsigned int maxSize = 20u;
const unsigned int stepSize = 1u;

INSTANTIATE_TEST_CASE_P(ParamTest_Values,
                        CContainerParamTest,
                        Range(minSize, maxSize, stepSize),
                        customMessage);
