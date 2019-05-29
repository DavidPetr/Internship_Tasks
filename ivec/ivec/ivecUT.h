#pragma once
#include "ivec.h"
class ivecUT
{
private:
	void test_constructor();
	void test_constructor_copy();
	void test_assigment_operator();
	void test_reserve();
	void test_resize();
	void test_push_back();
	void test_pop_back();
	void test_index_operator();
	void test_erase();
	void test_insert();
	void test_empty();
	void test_clear();
	void test_back();
	void test_front();
	void test_at();
	//void test_destructor();
public:
	void Test();
};