#include <iostream>
#include <memory>

template <typename S>
S&& forward(typename std::remove_reference<S>::type& a) noexcept

{
	using x = decltype(a);
	return static_cast<S&&>(a);
}

template<typename T, typename Arg>
std::shared_ptr<T> factory(Arg&& arg)
{
	return std::shared_ptr<T>(new T(std::forward<Arg>(arg)));
}

int main()
{
	int a = 5;
	factory<int>(a);
	/* I think it works like that
	* In factory,
	* T is int, Arg type is int&, so arg type is int&
	* so we call std::forward<int&>(a)
	*
	* In forward,
	* S is int&, so S&& -> int&,
	* a is lvalue, after std::remove_reference<int&>::type& it becomes int&
	* so static_cast<int &>(a) that cast to lvalue
	* and finally forward return lvalue via universal reference
	*/

	factory<int>(5);
	/* I think it works like that
	* In factory,
	* T is int, Arg is int, so arg type is int&&
	* so we call std::forward<int>(a)
	*
	* In forward,
	* S is int&&, so S&& -> int&&,
	* a is rvalue, after std::remove_reference<int&>::type& it becomes int
	* so static_cast<int &&>(a) that returns rvalue
	* and finally forward return rvalue via universal reference
	*/
}