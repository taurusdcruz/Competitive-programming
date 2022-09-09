/*
 * Next lexicographical permutation algorithm (C++)
 * by Project Nayuki, 2017. Public domain.
 * https://www.nayuki.io/page/next-lexicographical-permutation-algorithm
 */

#include <algorithm>
#include <cstddef>
#include <vector>


/*
 * (Template vector version)
 * Computes the next lexicographical permutation of the specified vector
 * of values in place, returning whether a next permutation existed.
 * (Returns false when the argument is already the last possible permutation.)

Algorithm:
1.Find largest index i such that array[i − 1] < array[i].
(If no such i exists, then this is already the last permutation.)

2.Find largest index j such that j ≥ i and array[j] > array[i − 1].

3.Swap array[j] and array[i − 1].

4.Reverse the suffix starting at array[i].
 */

template <typename T>
bool nextPermutation(std::vector<T> &vec) {
	// Find non-increasing suffix
	if (vec.empty())
		return false;
	typename std::vector<T>::iterator i = vec.end() - 1;
	while (i > vec.begin() && *(i - 1) >= *i)
		--i;
	if (i == vec.begin())
		return false;

	// Find successor to pivot
	typename std::vector<T>::iterator j = vec.end() - 1;
	while (*j <= *(i - 1))
		--j;
	std::iter_swap(i - 1, j);

	// Reverse suffix
	std::reverse(i, vec.end());
	return true;
}
