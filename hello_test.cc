#include <cstdio>
#include <gtest/gtest.h>
#include "libmdbx/mdbx.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}


TEST(EnvTests, OpenEnv) {
  MDBX_env *env = NULL;
  int rc = mdbx_env_create(&env);
  ASSERT_EQ(rc, 0);
  ASSERT_NE(env, nullptr);
}