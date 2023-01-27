#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <iterator>
#include "is_integral.hpp"

namespace ft
{
	template <class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2)
		{
			if (*first1 < *first2)
				return true;
			if (*first2 < *first1)
				return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template <class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
		for (; first1 != last1; ++first1, ++first2)
		{
			if (!(*first1 == *first2))
			{
				return false;
			}
		}
		return true;
	}

	template <typename, typename>
	struct __are_same
	{
		enum
		{
			__value = 0
		};
		typedef ft::false_type __type;
	};

	template <typename _Tp>
	struct __are_same<_Tp, _Tp>
	{
		enum
		{
			__value = 1
		};
		typedef ft::true_type __type;
	};

};
#endif