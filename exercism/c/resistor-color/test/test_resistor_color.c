#include "../src/resistor_color.h"
#include "vendor/unity.h"

#define ARRAY_LENGTH(A) (sizeof(A) / sizeof(A[0]))

void
setUp(void)
{}

void
tearDown(void)
{}

static void
test_black(void)
{
  TEST_ASSERT_EQUAL_UINT16(0, colorCode(BLACK));
}

static void
test_white(void)
{
  TEST_ASSERT_EQUAL_UINT16(9, colorCode(WHITE));
}

static void
test_orange(void)
{
  TEST_ASSERT_EQUAL_UINT16(3, colorCode(ORANGE));
}

static void
test_colors(void)
{
  const resistor_band_t expected[] = { BLACK, BROWN, RED,    ORANGE, YELLOW,
                                       GREEN, BLUE,  VIOLET, GREY,   WHITE };
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, colors(), ARRAY_LENGTH(expected));
  TEST_ASSERT_EQUAL_INT_ARRAY(expected, colors(), ARRAY_LENGTH(expected));
}

int
main(void)
{
  UnityBegin("test/test_resistor_color.c");

  RUN_TEST(test_black);
  RUN_TEST(test_white);
  RUN_TEST(test_orange);
  RUN_TEST(test_colors);

  return UnityEnd();
}
