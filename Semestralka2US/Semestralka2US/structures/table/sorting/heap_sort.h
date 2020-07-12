#pragma once

#include "sort.h"
#include "../unsorted_sequence_table.h"

namespace structures
{

	/// <summary> Triedenie Heap sort. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T>
	class HeapSort : public Sort<K, T>
	{
	public:
		/// <summary> Utriedi tabulku triedenim Heap sort. </summary>
		/// <param name = "table"> NonortedSequenceTable, ktoru ma utriedit. </param>
		void sort(UnsortedSequenceTable<K, T>& table) override;
	};

	template<typename K, typename T>
	inline void HeapSort<K, T>::sort(UnsortedSequenceTable<K, T>& table)
	{
		//TODO 12: HeapSort
		bool swapped;
		// HALDA
		for (int i = 1; i < table.size() - 1; i++) {
			int spracovavany = i;
			do {
				swapped = false;
				int otec = (spracovavany - 1) / 2;
				if (spracovavany > 0 &&
					(table.getItemAtIndex(spracovavany).getKey() > table.getItemAtIndex(otec).getKey())) {
					table.swap(spracovavany, otec);
					spracovavany = otec;
					swapped = true;
				}
			} while (swapped);
		}

		for (int i = table.size() - 1; i > 0; i--)
		{
			table.swap(0, i);
			int spracovavany = 0;
			do {
				swapped = false;
				int lavy = spracovavany * 2 + 1;
				int pravy = spracovavany * 2 + 2;
				int max;
				if (lavy < i && pravy < i) {
					if (table.getItemAtIndex(lavy).getKey() > table.getItemAtIndex(pravy).getKey()) {
						max = lavy;
					}
					else {
						max = pravy;
					}
				}
				else {
					if (lavy < i) {
						max = lavy;
					}
					else {
						max = pravy;
					}
				}
				if (max < i && table.getItemAtIndex(max).getKey() >table.getItemAtIndex(spracovavany).getKey()) {
					table.swap(max, spracovavany);
					spracovavany = max;
					swapped = true;
				}
			} while (swapped);
		}
	}
}