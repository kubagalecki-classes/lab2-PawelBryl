#include "catch.hpp"
#include "ResourceManager.hpp"

TEST_CASE("Сopy constructor", "[]")
{
    {
        auto* rm1 = new ResourceManager();
        ResourceManager rm2 = *rm1;
        REQUIRE(rm1->get() == rm2.get());
        ResourceManager rm3(rm2);
        REQUIRE(rm1->get() == rm3.get());
    }
    REQUIRE(ConstructionTracker::live == 0);
}
