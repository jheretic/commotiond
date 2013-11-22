/* vim: set ts=2 expandtab: */
/**
 *       @file  test.cpp
 *      @brief  
 *
 *     @author  Josh King (jheretic), jking@chambana.net
 *
 *   @internal
 *      Created  11/17/2013 06:01:11 PM
 *     Compiler  gcc/g++
 * Organization  The Open Technology Institute
 *    Copyright  Copyright (c) 2013, Josh King
 *
 * This file is part of Commotion, Copyright (c) 2013, Josh King 
 * 
 * Commotion is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published 
 * by the Free Software Foundation, either version 3 of the License, 
 * or (at your option) any later version.
 * 
 * Commotion is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Commotion.  If not, see <http://www.gnu.org/licenses/>.
 *
 * =====================================================================================
 */
extern "C" {
#include "../src/obj.h"
#include "../src/list.h"
#include "../src/tree.h"
}
#include "gtest/gtest.h"

class CDTest : public ::testing::Test
{
  protected:
    co_obj_t *Tree;
    void InsertString();
    void InsertInt();

  CDTest()
  {
    Tree = co_tree16_create();
  }
  
  ~CDTest()
  {
    co_free((co_obj_t *)Tree);  
  }
};

void CDTest::InsertString()
{
  co_obj_t *TestString1 = co_bin8_create("1TESTVALUE1", 11, 0);
  int ret = co_tree_insert(Tree, "1TESTKEY1", 10, TestString1);
  ASSERT_EQ(1, ret);
  co_obj_t *ptr = co_tree_find(Tree, "1TESTKEY1", 10);
  ASSERT_EQ(TestString1, ptr);
  co_obj_t *TestString2 = co_bin8_create("2TESTVALUE2", 12, 0);
  ret = co_tree_insert(Tree, "2TESTKEY2", 10, TestString2);
  ASSERT_EQ(1, ret);
  ptr = co_tree_find(Tree, "2TESTKEY2", 10);
  ASSERT_EQ(TestString2, ptr);
}
  
TEST_F(CDTest, InsertStringTest)
{
  InsertString();
} 
