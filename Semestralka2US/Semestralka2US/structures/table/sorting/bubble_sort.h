#pragma once

#include "sort.h"
#include "../unsorted_sequence_table.h"

namespace structures
{

	/// <summary> Triedenie Bubble sort. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T>
	class BubbleSort : public Sort<K, T>
	{
	public:
		/// <summary> Utriedi tabulku triedenim Bubble sort. </summary>
		/// <param name = "table"> NonortedSequenceTable, ktoru ma utriedit. </param>
		void sort(UnsortedSequenceTable<K, T>& table) override;
	};

	template<typename K, typename T>
	inline void BubbleSort<K, T>::sort(UnsortedSequenceTable<K, T>& table)
	{
		//TODO 12: BubbleSort
		for (int i = 0; i < table.size() - 1; i++)
		{
			for (int j = 0; j < table.size() - i - 1; j++)
			{
				if (table.getItemAtIndex(j + 1).getKey() > table.getItemAtIndex(j).getKey())
				{
					table.swap(j, j+1);
				}
			}
		}
	}

}