#include "pch.h"
#include "..\FixedPoint\FixedPoint.h"

/*TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}*/

TEST(Create, default_constructor) {
	FixedPoint<8> p;
	EXPECT_EQ(p.toString(), std::string("0.00000000"));
}



TEST(Create, parameter_constructor) {
	FixedPoint<8> p(100500);
	EXPECT_EQ(p.toString(), std::string("100500.00000000"));
}

TEST(Create, negative_val_int) {
	FixedPoint<8> p(-273);
	EXPECT_EQ(p.toString(), std::string("-273.00000000"));
}


TEST(Create, compare_init) {
	FixedPoint<8> p1(-273);
	FixedPoint<8> p2(-273);
	EXPECT_EQ(p1.toString(), p2.toString());
}
