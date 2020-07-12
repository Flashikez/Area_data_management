#pragma once

#include "sort.h"
#include "../unsorted_sequence_table.h"

namespace structures
{

	/// <summary> Triedenie Quick sort. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T>
	class QuickSort : public Sort<K, T>
	{
	public:
		/// <summary> Utriedi tabulku triedenim Quick sort. </summary>
		/// <param name = "table"> NonortedSequenceTable, ktoru ma utriedit. </param>
		void sort(UnsortedSequenceTable<K, T>& table) override;
		void quick(int min, int max, UnsortedSequenceTable<K, T>& table);
	};

	template<typename K, typename T>
	inline void QuickSort<K, T>::sort(UnsortedSequenceTable<K, T>& table)
	{
		quick(0, table.size() - 1, table);
	}

	template<typename K, typename T>
	inline void QuickSort<K, T>::quick(int min, int max, UnsortedSequenceTable<K, T>& table)
	{

		K pivot = table.getItemAtIndex((min + max) / 2).getKey();
		int left = min;
		int  right = max;
		do {
			while (table.getItemAtIndex(left).getKey() < pivot)
				left++;
			while (table.getItemAtIndex(right).getKey() > pivot)
				right--;
			if (left <= right) {
				table.swap(left, right);
				left++;
				right--;
			}
		} while (left <= right);
		if (min < right)
		{
			quick(min, right, table);
		}
		if (left < max)
		{
			quick(left, max, table);
		}
	}

}