#ifndef FT_ALGORITHM_TPP
# define FT_ALGORITHM_TPP

# ifndef FT_ALGORITHM_HPP
#  error algorithm_impl.tpp should only be included from algorithm.hpp.
# endif

namespace	ft
{
	/*=================================*/
	/*               Equal             */
	/*=================================*/

	template <typename InputIt1, typename InputIt2>
	bool	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

	/*====================================*/
	/*       Lexicographical_compare      */
	/*====================================*/

	template <typename InputIt1, typename InputIt2>
	bool	lexicographical_compare(InputIt1 first1, InputIt1 last1, \
									InputIt2 first2, InputIt2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			++first1;
			++first2;
		}
		return (first2 != last2);
	}
}

#endif
