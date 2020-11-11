#include "catch.hpp"

#include "ResourceManager.hpp"

TEST_CASE("Move semantics", "[]")
{
    {
        ResourceManager rm1;
		const double storedValue = rm1.get();
		ResourceManager rm2{ std::move(rm1) };
		REQUIRE(storedValue == rm2.get());
		ResourceManager rm3 = std::move(rm2);
		REQUIRE(storedValue == rm3.get());
    }
    REQUIRE(ConstructionTracker::live == 0);
}
