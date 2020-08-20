#include <include/CppDoublyLinkedList.hpp>
#include <include/CppCommon.hpp>

#include <benchmark/benchmark.h>
#include <cmath>
#include <cstring>

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

/**
 * Minimal length of container to benchmark.
 */
const unsigned int rangeMin = 8u;
/**
 * Maximal length of container to benchmark.
 */
const unsigned int rangeMax = 1u << 10u;
/**
 * Range multiplier
 */
const unsigned int rangeMultiplier = 2u;


const unsigned int oneObjectSizeBytes1 = 1u;
const unsigned int oneObjectSizeBytes4 = 4u;
const unsigned int oneObjectSizeBytes8 = 8u;
const unsigned int oneObjectSizeBytes16 = 16u;
const unsigned int oneObjectSizeBytes512 = 512u;
const unsigned int oneObjectSizeBytes1024 = 1024u;
const unsigned int oneObjectSizeBytes2048 = 2048u;
const unsigned int oneObjectSizeBytes16384 = 16384u;
const unsigned int oneObjectSizeBytes32768 = 32768u;

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

/////////////////////////// PUSH_BACK /////////////////////////////

/**
 * Complexity to compare or auto detect
 */
const benchmark::BigO complexityPushBack = benchmark::oAuto;

/**
 * @brief Fills container with objects. Adds items to the end.
 * @tparam T type of object.
 * @param aContainer Container to fill.
 * @param aSize Number of items to fill.
 * @return Size of container. Required return value by benchmark.
 * Without return value, compiler can remove method completely
 * while optimizing - it could detect that method doesn't have
 * side effect, so it can throw away.
 */
template<unsigned int TSize>
unsigned int pushBack(unsigned int aSize)
{
    using Type = CObject<TSize>;
    CDoublyLinkedList<Type> container;
    for (unsigned int i = 0; i < aSize; ++i)
    {
      Type item(i);
      container.pushBack(item);
    }
    return container.size();
}

/**
 * @brief Benchmark method.
 * @tparam TSize size object.
 * @param aState benchmark state argument.
 */
template<unsigned int TSize>
void doubly_linked_list_pushBack(benchmark::State& aState)
{
    const int64_t value = aState.range(0);
    // set base for detecting big-O notation.
    aState.SetComplexityN(value);
    // keep running benchmark
    while (aState.KeepRunning())
    {
        // prevent optimizer to get cached value instead of calculating it.
        benchmark::DoNotOptimize(pushBack<TSize>(value));
    }
}

///////////////////////////////////////////////////////////////////

BENCHMARK_TEMPLATE(doubly_linked_list_pushBack, oneObjectSizeBytes1)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityPushBack);

///////////////////////////////////////////////////////////////////

BENCHMARK_TEMPLATE(doubly_linked_list_pushBack, oneObjectSizeBytes4)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityPushBack);

///////////////////////////////////////////////////////////////////

BENCHMARK_TEMPLATE(doubly_linked_list_pushBack, oneObjectSizeBytes8)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityPushBack);

///////////////////////////////////////////////////////////////////

BENCHMARK_TEMPLATE(doubly_linked_list_pushBack, oneObjectSizeBytes16)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityPushBack);

///////////////////////////////////////////////////////////////////

BENCHMARK_TEMPLATE(doubly_linked_list_pushBack, oneObjectSizeBytes512)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityPushBack);

///////////////////////////////////////////////////////////////////

BENCHMARK_TEMPLATE(doubly_linked_list_pushBack, oneObjectSizeBytes1024)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityPushBack);

///////////////////////////////////////////////////////////////////

BENCHMARK_TEMPLATE(doubly_linked_list_pushBack, oneObjectSizeBytes2048)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityPushBack);

///////////////////////////////////////////////////////////////////

BENCHMARK_TEMPLATE(doubly_linked_list_pushBack, oneObjectSizeBytes16384)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityPushBack);

///////////////////////////////////////////////////////////////////

BENCHMARK_TEMPLATE(doubly_linked_list_pushBack, oneObjectSizeBytes32768)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityPushBack);

////////////////////////////////////////////////////////////////////
/////////////////////////// PUSH_FRONT /////////////////////////////

/**
 * Complexity to compare or auto detect
 */
const benchmark::BigO complexityPushFront = benchmark::oAuto;

/**
 * @brief Fills container with objects. Adds items at the beginning side.
 * @tparam TSize size object.
 * @param aSize Number of items to fill.
 * @return Size of container. Required return value by benchmark.
 * Without return value, compiler can remove method completely
 * while optimizing - it could detect that method doesn't have
 * side effect, so it can throw away.
 */
template<unsigned int TSize>
unsigned int pushFront(unsigned int aSize)
{
    using Type = CObject<TSize>;
    CDoublyLinkedList<Type> container;
    for (unsigned int i = 0; i < aSize; ++i)
    {
      Type item(i);
      container.pushFront(item);
    }
    return container.size();
}

/**
 * @brief Benchmark method.
 * @tparam TSize size object.
 * @param aState benchmark state argument.
 */
template<unsigned int TSize>
void doubly_linked_list_pushFront(benchmark::State& aState)
{
    const int64_t value = aState.range(0);
    const unsigned int valueCast = static_cast<unsigned int>(value);

    aState.SetComplexityN(value);
    while (aState.KeepRunning())
    {
        benchmark::DoNotOptimize(pushFront<TSize>(valueCast));
    }
}

///////////////////////////////////////////////////////////////////

BENCHMARK_TEMPLATE(doubly_linked_list_pushFront, oneObjectSizeBytes1)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityPushFront);

///////////////////////////////////////////////////////////////////

BENCHMARK_TEMPLATE(doubly_linked_list_pushFront, oneObjectSizeBytes4)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityPushFront);

///////////////////////////////////////////////////////////////////

BENCHMARK_TEMPLATE(doubly_linked_list_pushFront, oneObjectSizeBytes8)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityPushFront);

///////////////////////////////////////////////////////////////////

BENCHMARK_TEMPLATE(doubly_linked_list_pushFront, oneObjectSizeBytes16)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityPushFront);

///////////////////////////////////////////////////////////////////

BENCHMARK_TEMPLATE(doubly_linked_list_pushFront, oneObjectSizeBytes512)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityPushFront);

///////////////////////////////////////////////////////////////////

BENCHMARK_TEMPLATE(doubly_linked_list_pushFront, oneObjectSizeBytes1024)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityPushFront);

///////////////////////////////////////////////////////////////////

BENCHMARK_TEMPLATE(doubly_linked_list_pushFront, oneObjectSizeBytes2048)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityPushFront);

///////////////////////////////////////////////////////////////////

BENCHMARK_TEMPLATE(doubly_linked_list_pushFront, oneObjectSizeBytes16384)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityPushFront);

///////////////////////////////////////////////////////////////////

BENCHMARK_TEMPLATE(doubly_linked_list_pushFront, oneObjectSizeBytes32768)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityPushFront);

/////////////////////////////////////////////////////////////////
/////////////////////////// GET /////////////////////////////////

/**
 * Complexity to compare or auto detect
 */
const benchmark::BigO complexityGet100 = benchmark::oAuto;

/**
 * Complexity to compare or auto detect
 */
const benchmark::BigO complexityGet75 = benchmark::oAuto;

/**
 * Complexity to compare or auto detect
 */
const benchmark::BigO complexityGet50 = benchmark::oAuto;

/**
 * Complexity to compare or auto detect
 */
const benchmark::BigO complexityGet25 = benchmark::oAuto;


/**
 * @brief Benchmark for get method.
 * @tparam Type Type of objects
 * @param aState Benchmark state.
 * @param aFactor Factor used to calculate index for get method.
 */
template<unsigned int TSizeObject, unsigned int TPercentage>
void doubly_linked_list_get(benchmark::State& aState)
{
    const unsigned int size = static_cast<unsigned int>(aState.range(0));
    CDoublyLinkedList<CObject<TSizeObject>> container;
    for (unsigned int i = 0; i < size; ++i)
    {
        container.pushBack(CObject<TSizeObject>(i));
    }
    const float factor = static_cast<float>(TPercentage) / 100.0f;
    const float part = (container.size() - 1u) * factor;

    const unsigned int index = static_cast<unsigned int>(std::round(part));
    
    aState.SetComplexityN(index);
    while (aState.KeepRunning())
    {
        benchmark::DoNotOptimize(container.get(index));
    }
}

/////////////////////////
/////////// 4/4 /////////

BENCHMARK_TEMPLATE(doubly_linked_list_get, oneObjectSizeBytes1, 100u)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityGet100);

BENCHMARK_TEMPLATE(doubly_linked_list_get, oneObjectSizeBytes4, 100u)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityGet100);

BENCHMARK_TEMPLATE(doubly_linked_list_get, oneObjectSizeBytes1024, 100u)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityGet100);

BENCHMARK_TEMPLATE(doubly_linked_list_get, oneObjectSizeBytes16384, 100u)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityGet100);

/////////////////////////
/////////// 3/4 /////////

BENCHMARK_TEMPLATE(doubly_linked_list_get, oneObjectSizeBytes1, 75u)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityGet75);

BENCHMARK_TEMPLATE(doubly_linked_list_get, oneObjectSizeBytes4, 75u)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityGet75);

BENCHMARK_TEMPLATE(doubly_linked_list_get, oneObjectSizeBytes1024, 75u)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityGet75);

BENCHMARK_TEMPLATE(doubly_linked_list_get, oneObjectSizeBytes16384, 75u)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityGet75);

/////////////////////////
/////////// 1/2 /////////

BENCHMARK_TEMPLATE(doubly_linked_list_get, oneObjectSizeBytes1, 50u)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityGet50);

BENCHMARK_TEMPLATE(doubly_linked_list_get, oneObjectSizeBytes4, 50u)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityGet50);

BENCHMARK_TEMPLATE(doubly_linked_list_get, oneObjectSizeBytes1024, 50u)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityGet50);

BENCHMARK_TEMPLATE(doubly_linked_list_get, oneObjectSizeBytes16384, 50u)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityGet50);

/////////////////////////
/////////// 1/4 /////////

BENCHMARK_TEMPLATE(doubly_linked_list_get, oneObjectSizeBytes1, 25u)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityGet25);

BENCHMARK_TEMPLATE(doubly_linked_list_get, oneObjectSizeBytes4, 25u)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityGet25);

BENCHMARK_TEMPLATE(doubly_linked_list_get, oneObjectSizeBytes1024, 25u)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityGet25);

BENCHMARK_TEMPLATE(doubly_linked_list_get, oneObjectSizeBytes16384, 25u)
->RangeMultiplier(rangeMultiplier)->Range(rangeMin, rangeMax)->Complexity(complexityGet25);

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

BENCHMARK_MAIN();
