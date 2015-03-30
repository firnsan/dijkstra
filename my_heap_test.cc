#define BOOST_TEST_MODULE heaptest

#include <boost/test/included/unit_test.hpp>

#include "my_heap.h"

BOOST_AUTO_TEST_SUITE(heaptest)

BOOST_AUTO_TEST_CASE (test1)
{
    MyHeap heap;
	heap.push(3);
	heap.push(2);
	heap.push(5);
	heap.push(4);
	heap.push(6);

	heap.build();
	
	BOOST_CHECK(heap.pop()==2);
	BOOST_CHECK(heap.size()==4);
	
}

BOOST_AUTO_TEST_SUITE_END()
