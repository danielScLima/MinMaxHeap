// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "minmaxheap.h"


bool checkEquality
(
	const std::vector<int> vec1,
	const std::vector<int> vec2
)
{
	if (vec1.size() != vec2.size())
		return false;
	
	for (int index = 0; index < vec1.size(); ++index)
	{
		if (vec1.at(index) != vec2.at(index))
			return false;
	}
	
	return true;
}

TEST_CASE( "Testing the insert call in the MINMAXHEAP with each element", "[single-file]" )
{
	MinMaxHeap minMaxHeap;
	
	REQUIRE( minMaxHeap.getNumberOfElementsInTheVector() == 0 );
	
	minMaxHeap.insertInterface(40);
	
	REQUIRE( minMaxHeap.getNumberOfElementsInTheVector() == 1 );
	
	minMaxHeap.insertInterface(50);
	
	REQUIRE( minMaxHeap.getNumberOfElementsInTheVector() == 2 );
	
	minMaxHeap.insertInterface(75);
	
	REQUIRE( minMaxHeap.getNumberOfElementsInTheVector() == 3 );
	
	minMaxHeap.insertInterface(35);
	
	REQUIRE( minMaxHeap.getNumberOfElementsInTheVector() == 4 );
	
	minMaxHeap.insertInterface(20);
	
	REQUIRE( minMaxHeap.getNumberOfElementsInTheVector() == 5 );
	
	minMaxHeap.insertInterface(60);
	
	REQUIRE( minMaxHeap.getNumberOfElementsInTheVector() == 6 );
	
	minMaxHeap.insertInterface(4);
	
	REQUIRE( minMaxHeap.getNumberOfElementsInTheVector() == 7 );
	
	minMaxHeap.insertInterface(2);
	
	REQUIRE( minMaxHeap.getNumberOfElementsInTheVector() == 8 );
}

TEST_CASE( "Testing the insert call in the MINMAXHEAP", "[single-file]" )
{
	MinMaxHeap minMaxHeap;
	
	REQUIRE( minMaxHeap.getNumberOfElementsInTheVector() == 0 );
	bool ret = checkEquality
	(
		minMaxHeap.getHeapAsAVector(),
		{}
	);
	REQUIRE(ret);
	
	minMaxHeap.insertInterface(40);
	REQUIRE( minMaxHeap.getNumberOfElementsInTheVector() == 1 );
	ret = checkEquality
	(
		minMaxHeap.getHeapAsAVector(),
		{40}
	);
	REQUIRE(ret);
	
	
	minMaxHeap.insertInterface(50);
	REQUIRE( minMaxHeap.getNumberOfElementsInTheVector() == 2 );
	ret = checkEquality
	(
		minMaxHeap.getHeapAsAVector(),
		{40,50}
	);
	REQUIRE(ret);
	
	minMaxHeap.insertInterface(75);
	REQUIRE( minMaxHeap.getNumberOfElementsInTheVector() == 3 );
	ret = checkEquality
	(
		minMaxHeap.getHeapAsAVector(),
		{40,50,75}
	);
	REQUIRE(ret);
	
	minMaxHeap.insertInterface(35);
	REQUIRE( minMaxHeap.getNumberOfElementsInTheVector() == 4 );
	ret = checkEquality
	(
		minMaxHeap.getHeapAsAVector(),
		{35,50,75,40}
	);
	REQUIRE(ret);
	
	minMaxHeap.insertInterface(20);
	REQUIRE( minMaxHeap.getNumberOfElementsInTheVector() == 5 );
	ret = checkEquality
	(
		minMaxHeap.getHeapAsAVector(),
		{20,50,75,40,35}
	);
	REQUIRE(ret);

	minMaxHeap.insertInterface(60);	
	REQUIRE( minMaxHeap.getNumberOfElementsInTheVector() == 6 );
	ret = checkEquality
	(
		minMaxHeap.getHeapAsAVector(),
		{20,50,75,40,35,60}
	);
	REQUIRE(ret);
	
	minMaxHeap.insertInterface(4);
	REQUIRE( minMaxHeap.getNumberOfElementsInTheVector() == 7 );
	ret = checkEquality
	(
		minMaxHeap.getHeapAsAVector(),
		{4,50,75,40,35,60,20}
	);
	REQUIRE(ret);
	
	minMaxHeap.insertInterface(2);
	REQUIRE( minMaxHeap.getNumberOfElementsInTheVector() == 8 );
	ret = checkEquality
	(
		minMaxHeap.getHeapAsAVector(),
		{2,50,75,4,35,60,20,40}
	);
	REQUIRE(ret);
}

TEST_CASE( "Testing the remove min call in the MINMAXHEAP", "[single-file]" )
{
	MinMaxHeap minMaxHeap;
	minMaxHeap.insertInterface(40);
	minMaxHeap.insertInterface(50);
	minMaxHeap.insertInterface(75);
	minMaxHeap.insertInterface(35);
	minMaxHeap.insertInterface(20);
	minMaxHeap.insertInterface(60);
	minMaxHeap.insertInterface(4);
	minMaxHeap.insertInterface(2);
	
	bool ret = checkEquality
	(
		minMaxHeap.getHeapAsAVector(),
		{2,50,75,4,35,60,20,40}
	);
	REQUIRE(ret);
	
	minMaxHeap.removeTheSmallerNumber();
	ret = checkEquality
	(
		minMaxHeap.getHeapAsAVector(),
		{4,50,75,40,35,60,20}
	);
	REQUIRE(ret);
	
	minMaxHeap.removeTheSmallerNumber();
	ret = checkEquality
	(
		minMaxHeap.getHeapAsAVector(),
		{20,50,75,40,35,60}
	);
	REQUIRE(ret);
	
	minMaxHeap.removeTheSmallerNumber();
	ret = checkEquality
	(
		minMaxHeap.getHeapAsAVector(),
		{35,60,75,40,50}
	);
	REQUIRE(ret);
	
	minMaxHeap.removeTheSmallerNumber();
	ret = checkEquality
	(
		minMaxHeap.getHeapAsAVector(),
		{40,60,75,50}
	);
	REQUIRE(ret);
	
	minMaxHeap.removeTheSmallerNumber();
	ret = checkEquality
	(
		minMaxHeap.getHeapAsAVector(),
		{50,60,75}
	);
	REQUIRE(ret);
	
	minMaxHeap.removeTheSmallerNumber();
	ret = checkEquality
	(
		minMaxHeap.getHeapAsAVector(),
		{60,75}
	);
	REQUIRE(ret);
	
	minMaxHeap.removeTheSmallerNumber();
	ret = checkEquality
	(
		minMaxHeap.getHeapAsAVector(),
		{75}
	);
	REQUIRE(ret);
	
	minMaxHeap.removeTheSmallerNumber();
	ret = checkEquality
	(
		minMaxHeap.getHeapAsAVector(),
		{}
	);
	REQUIRE(ret);

}

TEST_CASE( "Testing the remove max call in the MINMAXHEAP", "[single-file]" )
{
	MinMaxHeap minMaxHeap;
	minMaxHeap.insertInterface(40);
	minMaxHeap.insertInterface(50);
	minMaxHeap.insertInterface(75);
	minMaxHeap.insertInterface(35);
	minMaxHeap.insertInterface(20);
	minMaxHeap.insertInterface(60);
	minMaxHeap.insertInterface(4);
	minMaxHeap.insertInterface(2);
	
	bool ret = checkEquality
	(
		minMaxHeap.getHeapAsAVector(),
		{2,50,75,4,35,60,20,40}
	);
	REQUIRE(ret);
	
	minMaxHeap.removeTheHiguestNumber();
	ret = checkEquality
	(
		minMaxHeap.getHeapAsAVector(),
		{2,50,60,4,35,40,20}
	);
	REQUIRE(ret);
	
	minMaxHeap.removeTheHiguestNumber();
	ret = checkEquality
	(
		minMaxHeap.getHeapAsAVector(),
		{2,50,40,4,35,20}
	);
	REQUIRE(ret);
	
	minMaxHeap.removeTheHiguestNumber();
	ret = checkEquality
	(
		minMaxHeap.getHeapAsAVector(),
		{2,35,40,4,20}
	);
	REQUIRE(ret);
	
	minMaxHeap.removeTheHiguestNumber();
	ret = checkEquality
	(
		minMaxHeap.getHeapAsAVector(),
		{2,35,20,4}
	);
	REQUIRE(ret);
	
	minMaxHeap.removeTheHiguestNumber();
	ret = checkEquality
	(
		minMaxHeap.getHeapAsAVector(),
		{2,4,20}
	);
	REQUIRE(ret);
	
	minMaxHeap.removeTheHiguestNumber();
	ret = checkEquality
	(
		minMaxHeap.getHeapAsAVector(),
		{2,4}
	);
	REQUIRE(ret);
	
	minMaxHeap.removeTheHiguestNumber();
	ret = checkEquality
	(
		minMaxHeap.getHeapAsAVector(),
		{2}
	);
	REQUIRE(ret);
	
	minMaxHeap.removeTheHiguestNumber();
	ret = checkEquality
	(
		minMaxHeap.getHeapAsAVector(),
		{}
	);
	REQUIRE(ret);

}


