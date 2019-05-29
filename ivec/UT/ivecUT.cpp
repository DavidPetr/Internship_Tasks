#include "ivecUT.h"
void ivecUT::test_constructor()
{
	{
		ivec v;
		if (&v == nullptr)
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}
	}
}

void ivecUT::test_constructor_copy()
{
	{
		ivec v1;
		ivec v2(v1);

		if (&v1 == nullptr || &v2 == nullptr)
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}
	}
	{
		ivec v1(10, 20);
		ivec v2(v1);

		if (v1.size() != v2.size())
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}
		if (v1.capacity() != v2.capacity())
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}
		for (int i = 0; i < v1.size(); ++i)
		{
			if (v1[i] != v2[i])
			{
				std::stringstream sstm;
				sstm << "Error on line " << __LINE__;
				throw std::logic_error(sstm.str());
			}
		}
	}
}

void ivecUT::test_assigment_operator()
{
	{
		ivec v1;
		ivec v2;

		v2 = v1;
		v2 = v2;
		if (&v1 == nullptr || &v2 == nullptr)
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}
	}
	{
		ivec v1(10, 20);
		ivec v2;

		v2 = v1;
		v2 = v2;
		if (v1.size() != v2.size())
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}
		if (v1.capacity() != v2.capacity())
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}
		for (int i = 0; i < v1.size(); ++i)
		{
			if (v1[i] != v2[i])
			{
				std::stringstream sstm;
				sstm << "Error on line " << __LINE__;
				throw std::logic_error(sstm.str());
			}
		}
	}
}

void ivecUT::test_reserve()
{
	{
		ivec v;
		v.reserve(15);
		if (v.capacity() < 15)
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}
		v.reserve(10);
		if (v.capacity() < 15)
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}
		v.reserve(15);
		if (v.capacity() < 15)
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}
	}
}

void ivecUT::test_resize()
{
	{
		ivec v;
		v.resize(10);
		if (v.size() < 10)
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}
		v.resize(5);
		if (v.size() < 5)
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}
		v.resize(0);
		if (!v.empty())
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}
	}
}

void ivecUT::test_push_back()
{
	{
		ivec v;
		v.push_back(10);
		if (v.size() != 1)
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}
		if (v[0] != 10)
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}
	}
}

void ivecUT::test_pop_back()
{

	{
		ivec v;
		v.push_back(10);
		v.pop_back();

		if (!v.empty())
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}

		try
		{
			v.pop_back();
		}
		catch (std::out_of_range &e)
		{
			std::string s = e.what();
			if (s != "Trying to pop from empty object!!!")
			{
				std::stringstream sstm;
				sstm << "Error on line " << __LINE__;
				throw std::logic_error(sstm.str());
			}
		}
	}
}

void ivecUT::test_index_operator()
{
	{
		ivec v(10, 4);

		if (v[0] != 4)
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}

		v.push_back(28);
		if (v.back() != 28)
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}

	}
}

void ivecUT::test_erase()
{
	{
		ivec v;
		ivec::iterator it = v.begin();
		try
		{
			v.erase(it);
		}
		catch (std::logic_error& e)
		{
			std::string s = e.what();
			if (s != "Trying erase null const iterator!!!")
			{
				std::stringstream sstm;
				sstm << "Error on line " << __LINE__;
				throw std::logic_error(sstm.str());
			}
		}
		v.push_back(1);
		it = v.begin();
		v.erase(it);
		if (!v.empty())
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);

		it = v.begin();
		++it;
		v.erase(it);
		if (v[1] != 3)
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}
	}
}

void ivecUT::test_insert()
{
	{
		ivec v;
		ivec::iterator it = v.begin();

		try
		{
			v.insert(it, 0);
		}
		catch (std::logic_error& e)
		{
			std::string s = e.what();
			if (s != "Trying insert null iterator!!!")
			{
				std::stringstream sstm;
				sstm << "Error on line " << __LINE__;
				throw std::logic_error(sstm.str());
			}
		}
	}
	{
		ivec v(2, 3);
		ivec::iterator it = v.begin();
		v.insert(it, 0);

		if (v[0] != 0)
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}

		it = v.begin();
		++it;
		v.insert(it, 1);

		if (v[1] != 1)
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}

		it = v.begin();
		it += 2;
		v.insert(it, 2);

		if (v[2] != 2)
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}


		it = v.end();
		v.insert(it, 6);

		if (v[5] != 6)
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}

		it = v.end();
		--it;
		v.insert(it, 5);

		if (v[5] != 5)
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}

		if (v[3] != 3 || v[4] != 3)
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}
	}

}

void ivecUT::test_empty()
{
	{
		ivec v;
		if (!v.empty())
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}

		v.push_back(10);
		if (v.empty())
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}

	}
}

void ivecUT::test_clear()
{
	{
		ivec v(3, 4);
		v.clear();

		if (!v.empty())
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}

		ivec v1;
		v1.clear();

		if (!v1.empty())
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}
	}
}

void ivecUT::test_back()
{
	{
		ivec v;

		try
		{
			v.back();
		}
		catch (std::logic_error& e)
		{
			std::string s = e.what();
			if (s != "Trying access to empty object!!!")
			{
				std::stringstream sstm;
				sstm << "Error on line " << __LINE__;
				throw std::logic_error(sstm.str());
			}
		}
	}
	{
		ivec v;
		v.push_back(1);
		if (v.back() != 1)
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}
	}
}

void ivecUT::test_front()
{
	{
		ivec v;

		try
		{
			v.front();
		}
		catch (std::logic_error& e)
		{
			std::string s = e.what();
			if (s != "Trying access to empty object!!!")
			{
				std::stringstream sstm;
				sstm << "Error on line " << __LINE__;
				throw std::logic_error(sstm.str());
			}
		}
	}
	{
		ivec v;
		v.push_back(1);
		if (v.front() != 1)
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}
	}
}

void ivecUT::test_at()
{
	{
		ivec v;

		try
		{
			v.at(0);
		}
		catch (std::out_of_range& e)
		{
			std::string s = e.what();
			if (s != "Trying to access via out of range index!!!")
			{
				std::stringstream sstm;
				sstm << "Error on line " << __LINE__;
				throw std::logic_error(sstm.str());
			}
		}
	}
	{
		ivec v(3, 2);

		try
		{
			v.at(3);
		}
		catch (std::out_of_range& e)
		{
			std::string s = e.what();
			if (s != "Trying to access via out of range index!!!")
			{
				std::stringstream sstm;
				sstm << "Error on line " << __LINE__;
				throw std::logic_error(sstm.str());
			}
		}
		v.push_back(10);
		if (v.at(3) != 10)
		{
			std::stringstream sstm;
			sstm << "Error on line " << __LINE__;
			throw std::logic_error(sstm.str());
		}
	}
}

void ivecUT::Test()
{
	bool testOK = true;

	try
	{
		test_constructor();
		test_constructor_copy();
		test_assigment_operator();
		test_reserve();
		test_resize();
		test_push_back();
		test_pop_back();
		test_index_operator();
		test_erase();
		test_insert();
		test_empty();
		test_clear();
		test_back();
		test_front();
		test_at();
	}
	catch (std::logic_error const& e)
	{
		testOK = false;
		std::cout << "Test failed: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unexpected Error" << std::endl;
	}

	if (testOK)
	{
		std::cout << "TestSucceeded!!!" << std::endl;
	}
}
