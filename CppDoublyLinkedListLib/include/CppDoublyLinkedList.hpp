#ifndef CPP_DOUBLY_LINKED_LIST_HPP_
#define CPP_DOUBLY_LINKED_LIST_HPP_

/*----------------------------------------------------------------------
                                Include
 *----------------------------------------------------------------------*/
#include <cassert>
#include <exception>

/**
 * @brief Doubly Linked List. Holds pointers to the beginning, end of the list and size of the list.
 * Therefore some operations have constant complexity.
 * @tparam T Type of items.
 */
template<typename T>
class CDoublyLinkedList
{
    /*----------------------------------------------------------------------
                                Helper Classes
     *----------------------------------------------------------------------*/
    template<typename TItem>
    class CDoublyLinkedListItem;
    /**
     * @brief List item. Each list's value is hold in this class.
     * It wraps value by adding pointer to next and previous element.
     * @tparam TItem Type of items stored in a list.
     */
    template<typename TItem>
    class CDoublyLinkedListItem
    {
    public:

        /*----------------------------------------------------------------------
                                Constructors & Destructors
         *----------------------------------------------------------------------*/
        explicit CDoublyLinkedListItem(const TItem& aValue)
            : mNext(nullptr)
            , mPrevious(nullptr)
            , mValue(aValue)
        {}

        CDoublyLinkedListItem(  CDoublyLinkedListItem<TItem>* const aPrevious, 
                                CDoublyLinkedListItem<TItem>* const aNext,
                                const TItem& aValue)
            : mNext(aNext)
            , mPrevious(aPrevious)
            , mValue(aValue)
        {}

        CDoublyLinkedListItem(const CDoublyLinkedListItem& iTem)
            : mNext(iTem.mNext)
            , mPrevious(iTem.mPrevious)
            , mValue(iTem.mValue)
        {}

        CDoublyLinkedListItem(CDoublyLinkedListItem&& iTem)
            : mNext(iTem.mNext)
            , mPrevious(iTem.mPrevious)
            , mValue(iTem.mValue)
        {
            iTem.mPrevious = nullptr;
            iTem.mNext = nullptr;
            mValue = NULL;
        }

        ~CDoublyLinkedListItem() = default;

        /*----------------------------------------------------------------------
                                Overload operators
         *----------------------------------------------------------------------*/
        /**
         * @brief Operator ->
         */
        T* operator->()
        {
            return &(this);
        }

        /**
         * @brief Pointer to previous Item.
         */
        CDoublyLinkedListItem<TItem>* mPrevious;

        /**
         * @brief Pointer to next item.
         */
        CDoublyLinkedListItem<TItem>* mNext;

        /**
         * @brief Value.
         */
        TItem mValue;
    };

    // /////////////////////////////////////////////////////////////////////
    // /////////////////////////////////////////////////////////////////////
    // /////////////////////////////////////////////////////////////////////
public:

    /**
     * @brief Iterator for DoublyLinked container. It is a random access iterator.
     * @tparam T Type of items.
     */
    class CDoublyLinkedListIterator
    {
        /**
         * @brief Pointer to data.
         */
        CDoublyLinkedListItem<T>* mPtr;

    public:

        /*----------------------------------------------------------------------
                                Constructors & Destructors
         *----------------------------------------------------------------------*/
        explicit CDoublyLinkedListIterator(CDoublyLinkedListItem<T>* aPtr)
            : mPtr(aPtr)
        {}

        ~CDoublyLinkedListIterator() = default;

        CDoublyLinkedListIterator(const CDoublyLinkedListIterator&) = default;

        CDoublyLinkedListIterator(CDoublyLinkedListIterator&&) = default;

        /*----------------------------------------------------------------------
                                Overload operators
         *----------------------------------------------------------------------*/

        /**
         * @brief Operator add
         */
        CDoublyLinkedListIterator operator +(const int aDiffIndex)const
        {
            CDoublyLinkedListItem<T>* arg = mPtr;

            for (int i = 0; i < aDiffIndex; i++)
            {
                arg = arg->mNext;
            }
            CDoublyLinkedListIterator it(arg);

            return it;
        }

        /**
         * @brief Operator sub
         */
        CDoublyLinkedListIterator operator -(const int aDiffIndex)const
        {
            CDoublyLinkedListItem<T>* arg = mPtr;
            for (int i = 0; i < aDiffIndex; i++)
            {
                arg = arg->mPrevious;
            }
            CDoublyLinkedListIterator it(arg);

            return it;
        }

        /**
         * @brief Operator increment
         */
        CDoublyLinkedListIterator& operator ++()
        {
            mPtr = mPtr->mNext;
            return *this;
        }

        /**
         * @brief Operator pre increment
         */
        CDoublyLinkedListIterator operator ++(int)
        {
            CDoublyLinkedListIterator it(mPtr);
            mPtr = mPtr->mNext;
            return it;
        }

        /**
         * @brief Operator decrement
         */
        CDoublyLinkedListIterator& operator --()
        {
            mPtr = mPtr->mPrevious;
            return *this;
        }

        /**
         * @brief Operator pre decrement.
         */
        CDoublyLinkedListIterator operator --(int)
        {
            CDoublyLinkedListIterator it(mPtr);
            mPtr = mPtr->mPrevious;
            return it;
        }

        /**
         * @brief Operator *
         */
        const T& operator*()const
        {
            return mPtr->mValue;
        }

        /**
         * @brief Operator ->
         */
        const T* operator->()const
        {
            return &(mPtr);
        }

        /**
         * @brief Operator compare.If this object compare with param. return true
         */
        bool operator==(const CDoublyLinkedListIterator& alt)const
        {
            return (mPtr == alt.mPtr);
        }

        /**
         * @brief Operator compare
         */
        bool operator!=(const CDoublyLinkedListIterator& alt)const
        {
            return !(*this == alt);
        }

        /*----------------------------------------------------------------------
                                        Methods
         *----------------------------------------------------------------------*/

        /**
         * @brief return pointer to iterator item
         */
        CDoublyLinkedListItem<T>* getItem()
        {
            return mPtr;
        }

        /**
         * @brief return value of iterator item;
         */
        const T& getValueItem()const
        {
            return mPtr->mValue;
        }

    };

    // /////////////////////////////////////////////////////////////////////
    // /////////////////////////////////////////////////////////////////////
    // /////////////////////////////////////////////////////////////////////

    /**
     * @brief Reverse iterator for DoublyLinked container. It is a random access iterator.
     * @tparam T Type of items.
     */
    class CReverseDoublyLinkedListIterator
    {
        /**
         * @brief Pointer to data.
         */
        CDoublyLinkedListItem<T>* mPtr;
    public:

        /*----------------------------------------------------------------------
                               Constructors & Destructors
         *----------------------------------------------------------------------*/
        explicit CReverseDoublyLinkedListIterator(CDoublyLinkedListItem<T>* aPtr)
            : mPtr(aPtr)
        {}

        ~CReverseDoublyLinkedListIterator() = default;

        CReverseDoublyLinkedListIterator(const CReverseDoublyLinkedListIterator&) = default;

        CReverseDoublyLinkedListIterator(CReverseDoublyLinkedListIterator&&) = default;

        /*----------------------------------------------------------------------
                                Overload operators
         *----------------------------------------------------------------------*/

        /**
         * @brief Operator +
         */
        CReverseDoublyLinkedListIterator operator +(const int aDiffIndex)const
        {
            CDoublyLinkedListItem<T>* arg = mPtr;

            for (int i = 0; i < aDiffIndex; i++)
            {
                arg = arg->mPrevious;
            }
            CReverseDoublyLinkedListIterator it(arg);

            return it;
        }

        /**
         * @brief Operator -
         */
        CReverseDoublyLinkedListIterator operator -(const int aDiffIndex)const
        {
            CDoublyLinkedListItem<T>* arg = mPtr;

            for (int i = 0; i < aDiffIndex; i++)
            {
                arg = arg->mNext;
            }
            CReverseDoublyLinkedListIterator it(arg);

            return it;
        }

        /**
         * @brief Operator increment
         */
        CReverseDoublyLinkedListIterator& operator ++()
        {
            mPtr = mPtr->mPrevious;
            return *this;
        }

        /**
         * @brief Operator pre increment
         */
        CReverseDoublyLinkedListIterator operator ++(int)
        {
            CReverseDoublyLinkedListIterator it(mPtr);
            mPtr = mPtr->mPrevious;
            return it;
        }

        /**
         * @brief Operator decrement
         */
        CReverseDoublyLinkedListIterator& operator --()
        {
            mPtr = mPtr->mNext;
            return *this;
        }

        /**
         * @brief Operator pre decrement
         */
        CReverseDoublyLinkedListIterator operator --(int)
        {
            CReverseDoublyLinkedListIterator it(mPtr);
            mPtr = mPtr->mNext;
            return it;
        }

        /**
         * @brief Operator *
         */
        const T& operator*()const
        {
            return mPtr->mValue;
        }

        /**
         * @brief Operator ->
         */
        const T* operator->()const
        {
            return &mPtr;
        }

        /**
         * @brief Operator compare
         */
        bool operator==(const CReverseDoublyLinkedListIterator& alt)const
        {
            return (mPtr == alt.mPtr);
        }

        /**
         * @brief Operator compare.If this object not compare with param. return true;
         * @param NULL.
         */
        bool operator!=(const CReverseDoublyLinkedListIterator& alt)const
        {
            return !(*this == alt);
        }

        /*----------------------------------------------------------------------
                                        Methods
         *----------------------------------------------------------------------*/

        /**
         * @brief Method which return pointer to item of iterator
         */
        CDoublyLinkedListItem<T>* getItem()
        {
            return mPtr;
        }

        /**
         * @brief Method which return value of iterator item;
         */
        const T& getValueItem()const
        {
            return mPtr->mValue;
        }
    };

    // /////////////////////////////////////////////////////////////////////
    // /////////////////////////////////////////////////////////////////////
    // /////////////////////////////////////////////////////////////////////

    using DIterator = CDoublyLinkedListIterator;
    using DReverseIterator = CReverseDoublyLinkedListIterator;

    /*----------------------------------------------------------------------
                           Constructors & Destructors
     *----------------------------------------------------------------------*/
    CDoublyLinkedList()
        : mBegin(nullptr)
        , mTail(nullptr)
        , n(nullptr)
        , mSize(NULL)
    {}

    CDoublyLinkedList(const CDoublyLinkedList<T>& aObj)
    {
        IniEmptyList();
        if (!aObj.empty())
        {
            DIterator iterator(aObj.mBegin);
            for (int i = 0; i < aObj.mSize; i++)
            {
                T arg = iterator.getValueItem();
                iterator++;
                pushBack(arg);
            }
        }
    }

    ~CDoublyLinkedList()
    {
        ClearList();
    }

    /*----------------------------------------------------------------------
                                Overload operators
     *----------------------------------------------------------------------*/

    CDoublyLinkedList<T>& operator=(const CDoublyLinkedList<T>& aObj)
    {
        if (!aObj.empty())
        {
            if (empty())
            {
                IniEmptyList();
            }
            else
            {
                ClearList();
            }

            DIterator iterator(aObj.mBegin);
            for (int i = 0; i < aObj.mSize; i++)
            {
                T arg = iterator.getValueItem();
                iterator++;
                pushBack(arg);
            }
        }
 
        return *this;
    }

    /**
     * @brief Compares vectors
     */
    bool operator==(const CDoublyLinkedList<T>& aObj)
    {
        if (mBegin == aObj.mBegin)
        {
            return true;
        }

        if (mSize != aObj.mSize)
        {
            return false;
        }
       
        DIterator thisIter(mBegin);
        DIterator aObjIter(aObj.mBegin);
        for (int i = 0; i < mSize; i++)
        {
            if ((thisIter.getValueItem()) != (aObjIter.getValueItem()))
            {
                return false;
            }
            thisIter++;
            aObjIter++;
        }
        return true;
    }

    /**
     * @brief Compare operator
     */
    bool operator!=(const CDoublyLinkedList<T>& aObj)
    {
        return !(*this == aObj);
    }

    /*----------------------------------------------------------------------
                                Methods
     *----------------------------------------------------------------------*/

    /**
     * @brief Returns a number of items.
     * Complexity: O(n) - because it has to pass for all item.
     * @return Number of items.
     */
    uintmax_t size() const
    {
        return mSize;
    }

    /**
     * @brief Adds value to list.
     * Complexity: O(1) - because the list holds pointer to the last item.
     * @param aValue Value to add.
     */
    void pushBack(const T& aValue)
    {
        if (empty())
        {
            n = new CDoublyLinkedListItem<T>(nullptr, nullptr, aValue);
            mBegin = n;
            mTail = n;
            mSize++;
        }
        else
        {
            n = new CDoublyLinkedListItem<T>(mTail, nullptr, aValue);
            mTail->mNext = n;
            mTail = n;
            mSize++;
        }
    }

    /**
     * @brief Removes last item from list.
     * Complexity: O(n) - because it has to pass through all items
     * @return Last item fropushFrontm list.
     */
    T popBack()
    {
        if (!empty())
        {
            if (mSize == 1)
            {
                T returnItem = mBegin->mValue;
                delete mBegin;
                mBegin = nullptr;
                mTail = nullptr;
                n = nullptr;
                mSize = 0;

                return returnItem;
            }

            CDoublyLinkedListItem<T>* newTail = mTail->mPrevious;
            T returnItem = mTail->mValue;
            delete mTail;
            mSize--;

            mTail = newTail;
            mTail->mNext = nullptr;
            newTail = nullptr;

            return returnItem;
        }
        else
        {
            throw std::exception("Try to delate item from empty List");
        }
    }

    /**
     * @brief Puts new item at the beginning of the list.
     * Complexity: O(1) - because the list holds pointer to the beginning.
     * @param aValue Value.
     */
    void pushFront(const T& aValue)
    {
        if (empty())
        {
            n = new CDoublyLinkedListItem<T>(nullptr, nullptr, aValue);
            mBegin = n;
            mTail = n;
            mSize++;
        }
        else
        {
            n = new CDoublyLinkedListItem<T>(nullptr, mBegin, aValue);
            mBegin = n;
            mSize++;
        }
    }

    /**
     * @brief Remove the first element from the list.
     * Complexity: O(1) - because list has pointer to beginning.
     * @return The first item from list.
     */
    T popFront()
    {
        if (mSize == 1)
        {
            T returnItem = mBegin->mValue;
            delete mBegin;
            mBegin = nullptr;
            mTail = nullptr;
            n = nullptr;
            mSize = 0;

            return returnItem;
        }

        if (!empty())
        {
            mBegin->mNext->mPrevious = nullptr;
            CDoublyLinkedListItem<T>* newBegin = mBegin->mNext;

            DIterator deleteIterator(mBegin);
            T returnItem = mBegin->mValue;
            delete deleteIterator.getItem();
            mSize--;

            mBegin = newBegin;
            newBegin = nullptr;

            return returnItem;
        }
        else
        {
            throw std::exception("Try to delate item from empty List");
        }
    }

    /**
     * @brief Checks the list contains object.
     * Complexity: O(n) - because it has to check all items. In the worst case entire list will be checked.
     * The worst case takes place if there isn't the value in the list or it is on the last position.
     * @param aValue Value to check.
     * @return true if list contains value, otherwise false.
     */
    bool contains(const T& aValue)
    {
        if (!empty())
        {
            DIterator iterator(mBegin);
            for (int i = 0; i < mSize; i++)
            {
                T arg = iterator.getValueItem();
                if (arg == aValue)
                {
                    return true;
                }
                iterator++;
            }
        }
        return false;
    }

    /**
     * @brief Indicates if the list empty.
     * Complexity: O(1)
     * @return true if list is empty, otherwise false.
     */
    bool empty() const
    {
        return (mSize == 0);
    }

    /**
     * @brief Get pointer to the value at given position. Complexity: O(n) - because it has to check all items in the worst case.
     * @param aIndex Position of value.
     * @return Pointer to value or null if there isn't value at given position.
     */
    const T* get(const uintmax_t aIndex)const
    {
        if (aIndex >= mSize)
        {
            return nullptr;
        }

        DIterator iterator(mBegin);
        iterator = iterator + aIndex;
        return &(iterator.getValueItem());
    }

    /**
     * @brief Inserts value at given position.
     * @param aIndex Position of value. Must be lower than size.
     * @param aValue Value to insert.
     */
    void insert(const uintmax_t aIndex, const T& aValue)
    {
        if (aIndex == 0)
        {
            pushFront(aValue);
        }
        else if (aIndex < mSize)
        {
            DIterator iterator(mBegin);
            iterator = iterator + aIndex;
            CDoublyLinkedListItem<T>* indexItem = iterator.getItem();
            n = new CDoublyLinkedListItem<T>(indexItem->mPrevious, indexItem, aValue);
            indexItem->mPrevious->mNext = n;
            indexItem->mPrevious = n;
            mSize++;
            indexItem = nullptr;
        }
    }

    /**
     * @brief Returns a random access iterator that points to the beginning.
     * @return Iterator to the beginning.
     */
    DIterator begin() const
    {
        DIterator iterator(mBegin);
        return iterator;
    }

    /**
     * @brief Returns a random access iterator that points to the item after the last one.
     * @return Iterator to the item after the last one.
     */
    DIterator end() const
    {
        DIterator iterator(nullptr);
        return iterator;
    }

    /**
     * @brief Returns a reverse random access iterator that points to the last item.
     * @return Reverse iterator to the last item.
     */
    DReverseIterator rbegin() const
    {
        DReverseIterator iterator(mTail);
        return iterator;
    }

    /**
     * @brief Returns a reverse random access iterator that points to the item before the first one.
     * @return Reverse iterator to the item before the first one.
     */
    DReverseIterator rend() const
    {
        DReverseIterator iterator(nullptr);
        return iterator;
    }

private:

    /**
     * @brief Pointer to the first item of the list.
     */
    CDoublyLinkedListItem<T>* mBegin;
    CDoublyLinkedListItem<T>* mTail;
    CDoublyLinkedListItem<T>* n;
    uintmax_t mSize;

    /**
     * @brief Method for initialization empty List
     */
    void IniEmptyList()
    {
        n = nullptr;
        mBegin = nullptr;
        mTail = nullptr;
        mSize = 0;
    }

    /**
     * @brief Method which at all clear List
     */

    void ClearList()
    {
        if (empty())
        {
            return;
        }

        for (DIterator iterator(mBegin); iterator != end(); iterator++)
        {
            delete iterator.getItem();
        }

        n = nullptr;
        mBegin = nullptr;
        mTail = nullptr;
        mSize = 0;
    }

};

#endif
