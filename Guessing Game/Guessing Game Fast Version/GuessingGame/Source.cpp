#include <iostream>
#include <unordered_set>
#include <algorithm>

#define FIRST_DIGIT(i) ((i)/1000)
#define SECOND_DIGIT(i) ((i)/100 % 10)
#define THIRD_DIGIT(i) ((i)/10%10)
#define FOURTH_DIGIT(i) ((i)%10)

void match_0_place_0(std::unordered_set<int> &set, int current)
{
	for (auto it = set.begin(); it != set.end();)
	{
		if (
			(
				FIRST_DIGIT(current) == FIRST_DIGIT(*it)	||
				FIRST_DIGIT(current) == SECOND_DIGIT(*it)	||
				FIRST_DIGIT(current) == THIRD_DIGIT(*it)	||
				FIRST_DIGIT(current) == FOURTH_DIGIT(*it)
				)
			||
			(
				SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
				SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
				SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
				SECOND_DIGIT(current) == FOURTH_DIGIT(*it)
				)
			||
			(
				THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
				THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
				THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
				THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
				)
			||
			(
				FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
				FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
				FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
				FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
				)
			)
		{
			auto it1 = it;
			++it;
			set.erase(it1);
		}
		else ++it;
	}
}
void match_1_place_0(std::unordered_set<int> &set, int current)
{
	for (auto it = set.begin(); it != set.end();)
	{
		if (
			(
				FIRST_DIGIT(current) == FIRST_DIGIT(*it)	||
				SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
				THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
				FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
			)
			||
			(
				(
					FIRST_DIGIT(current) != SECOND_DIGIT(*it)	&&
					FIRST_DIGIT(current) != THIRD_DIGIT(*it)	&&
					FIRST_DIGIT(current) != FOURTH_DIGIT(*it)	&&
					SECOND_DIGIT(current) != FIRST_DIGIT(*it)	&&
					SECOND_DIGIT(current) != THIRD_DIGIT(*it)	&&
					SECOND_DIGIT(current) != FOURTH_DIGIT(*it)	&&
					THIRD_DIGIT(current) != FIRST_DIGIT(*it)	&&
					THIRD_DIGIT(current) != SECOND_DIGIT(*it)	&&
					THIRD_DIGIT(current) != FOURTH_DIGIT(*it)	&&
					FOURTH_DIGIT(current) != FIRST_DIGIT(*it)	&&
					FOURTH_DIGIT(current) != SECOND_DIGIT(*it)	&&
					FOURTH_DIGIT(current) != THIRD_DIGIT(*it)
				)
				||
				(
					FIRST_DIGIT(current) == SECOND_DIGIT(*it) &&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					||
					FIRST_DIGIT(current) == THIRD_DIGIT(*it) &&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					||
					FIRST_DIGIT(current) == FOURTH_DIGIT(*it) &&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)
					)
					||
					SECOND_DIGIT(current) == FIRST_DIGIT(*it) &&
					(
						FIRST_DIGIT(current) == SECOND_DIGIT(*it)	||
						FIRST_DIGIT(current) == THIRD_DIGIT(*it)	||
						FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					||
					SECOND_DIGIT(current) == THIRD_DIGIT(*it) &&
					(
						FIRST_DIGIT(current) == FIRST_DIGIT(*it)	||
						FIRST_DIGIT(current) == SECOND_DIGIT(*it)	||
						FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	||
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					||
					SECOND_DIGIT(current) == FOURTH_DIGIT(*it) &&
					(
						FIRST_DIGIT(current) == FIRST_DIGIT(*it)	||
						FIRST_DIGIT(current) == SECOND_DIGIT(*it)	||
						FIRST_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)
					)
					||
					THIRD_DIGIT(current) == FIRST_DIGIT(*it) &&
					(
						FIRST_DIGIT(current) == SECOND_DIGIT(*it)	||
						FIRST_DIGIT(current) == THIRD_DIGIT(*it)	||
						FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					||
					THIRD_DIGIT(current) == SECOND_DIGIT(*it) &&
					(
						FIRST_DIGIT(current) == FIRST_DIGIT(*it)	||
						FIRST_DIGIT(current) == THIRD_DIGIT(*it)	||
						FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	||						
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					||
					FOURTH_DIGIT(current) == FIRST_DIGIT(*it) &&
					(
						FIRST_DIGIT(current) == SECOND_DIGIT(*it)	||
						FIRST_DIGIT(current) == THIRD_DIGIT(*it)	||
						FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	||						
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					||
					FOURTH_DIGIT(current) == SECOND_DIGIT(*it) &&
					(
						FIRST_DIGIT(current) == FIRST_DIGIT(*it)	||
						FIRST_DIGIT(current) == THIRD_DIGIT(*it)	||
						FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	||						
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					||
					FOURTH_DIGIT(current) == THIRD_DIGIT(*it) &&
					(
						FIRST_DIGIT(current) == FIRST_DIGIT(*it)	||
						FIRST_DIGIT(current) == SECOND_DIGIT(*it)	||
						FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	||						
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
			)
		)
		{
			auto it1 = it;
			++it;
			set.erase(it1);
		}
		else ++it;
	}
}
void match_1_place_1(std::unordered_set<int> &set, int current)
{
	for (auto it = set.begin(); it != set.end();)
	{
		if (
			(
				FIRST_DIGIT(current) != FIRST_DIGIT(*it)	&&
				SECOND_DIGIT(current) != SECOND_DIGIT(*it)	&&
				THIRD_DIGIT(current) != THIRD_DIGIT(*it)	&&
				FOURTH_DIGIT(current) != FOURTH_DIGIT(*it)
			)
			||
			(
				FIRST_DIGIT(current) == FIRST_DIGIT(*it) &&
				(
					SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
					SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
					SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
					THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
					THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
					THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
					FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
					FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
					FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
				)
				||
				SECOND_DIGIT(current) == SECOND_DIGIT(*it) &&
				(
					FIRST_DIGIT(current) == FIRST_DIGIT(*it)	||
					FIRST_DIGIT(current) == THIRD_DIGIT(*it)	||
					FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	||
					THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
					THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
					THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
					FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
					FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
					FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
				)
				||
				THIRD_DIGIT(current) == THIRD_DIGIT(*it) &&
				(
					FIRST_DIGIT(current) == FIRST_DIGIT(*it)	||
					FIRST_DIGIT(current) == SECOND_DIGIT(*it)	||
					FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	||
					SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
					SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
					SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
					FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
					FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
					FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
				)
				||
				FOURTH_DIGIT(current) == FOURTH_DIGIT(*it) &&
				(
					FIRST_DIGIT(current) == FIRST_DIGIT(*it)	||
					FIRST_DIGIT(current) == SECOND_DIGIT(*it)	||
					FIRST_DIGIT(current) == THIRD_DIGIT(*it)	||
					SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
					SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
					SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
					THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
					THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
					THIRD_DIGIT(current) == THIRD_DIGIT(*it)
				)
			)
		)
		{
			auto it1 = it;
			++it;
			set.erase(it1);
		}
		else ++it;
	}
}
void match_2_place_0(std::unordered_set<int> &set, int current)
{
	for (auto it = set.begin(); it != set.end();)
			{
				if (
					(
						(
							FIRST_DIGIT(current) == FIRST_DIGIT(*it)	&& 
							SECOND_DIGIT(current) == SECOND_DIGIT(*it)	&&
							THIRD_DIGIT(current) == THIRD_DIGIT(*it)
						)
						||
						(
							FIRST_DIGIT(current) == FIRST_DIGIT(*it)	&&
							SECOND_DIGIT(current) == SECOND_DIGIT(*it)	&&
							FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
						)
						||
						(
							FIRST_DIGIT(current) == FIRST_DIGIT(*it)	&&
							THIRD_DIGIT(current) == THIRD_DIGIT(*it)	&&
							FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
						)
						||
						(
							SECOND_DIGIT(current) == SECOND_DIGIT(*it)	&&
							THIRD_DIGIT(current) == THIRD_DIGIT(*it)	&&
							FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
						)
					)
					||
					!(//Not this (!)
						(
							FIRST_DIGIT(current) == SECOND_DIGIT(*it) &&
							(
								SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
								SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
								SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
								THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
								THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
								FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
								FOURTH_DIGIT(current) == THIRD_DIGIT(*it)
							)
						)
						||
						(
							FIRST_DIGIT(current) == THIRD_DIGIT(*it) &&
							(
								SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
								SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
								THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
								THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
								THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
								FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
								FOURTH_DIGIT(current) == SECOND_DIGIT(*it)
							)
						)
						||
						(
							FIRST_DIGIT(current) == FOURTH_DIGIT(*it) &&
							(
								SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
								SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
								THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
								THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||								
								FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
								FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
								FOURTH_DIGIT(current) == THIRD_DIGIT(*it) 
							)
						)
						||
						(
							SECOND_DIGIT(current) == FIRST_DIGIT(*it) &&
							(
								FIRST_DIGIT(current) == SECOND_DIGIT(*it)	||
								FIRST_DIGIT(current) == THIRD_DIGIT(*it)	||
								FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	||
								THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
								THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
								FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
								FOURTH_DIGIT(current) == THIRD_DIGIT(*it)
							)
						)
						||
						(
							SECOND_DIGIT(current) == THIRD_DIGIT(*it) &&
							(
								FIRST_DIGIT(current) == SECOND_DIGIT(*it)	||
								FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	||
								THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
								THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
								THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
								FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
								FOURTH_DIGIT(current) == SECOND_DIGIT(*it)
							)
						)
						||
						(
							SECOND_DIGIT(current) == FOURTH_DIGIT(*it) &&
							(
								FIRST_DIGIT(current) == SECOND_DIGIT(*it)	||
								FIRST_DIGIT(current) == THIRD_DIGIT(*it)	||
								THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
								THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
								FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
								FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
								FOURTH_DIGIT(current) == THIRD_DIGIT(*it)
							)
						)
						||
						(
							THIRD_DIGIT(current) == FIRST_DIGIT(*it) &&
							(
								FIRST_DIGIT(current) == SECOND_DIGIT(*it)	||
								FIRST_DIGIT(current) == THIRD_DIGIT(*it)	||
								FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	||
								SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
								SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
								FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
								FOURTH_DIGIT(current) == THIRD_DIGIT(*it)
							)
						)
						||
						(
							THIRD_DIGIT(current) == SECOND_DIGIT(*it) &&
							(
								FIRST_DIGIT(current) == THIRD_DIGIT(*it)	||
								FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	||
								SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
								SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
								SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
								FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
								FOURTH_DIGIT(current) == THIRD_DIGIT(*it)
							)
						)
						||
						(
							THIRD_DIGIT(current) == FOURTH_DIGIT(*it) &&
							(
								FIRST_DIGIT(current) == SECOND_DIGIT(*it)	||
								FIRST_DIGIT(current) == THIRD_DIGIT(*it)	||
								SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
								SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
								FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
								FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
								FOURTH_DIGIT(current) == THIRD_DIGIT(*it)
							)
						)
						||
						(
							FOURTH_DIGIT(current) == FIRST_DIGIT(*it) &&
							(
								FIRST_DIGIT(current) == SECOND_DIGIT(*it)	||
								FIRST_DIGIT(current) == THIRD_DIGIT(*it)	||
								FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	||
								SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
								SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
								THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
								THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
							)
						)
						||
						(
							FOURTH_DIGIT(current) == SECOND_DIGIT(*it) &&
							(
								FIRST_DIGIT(current) == THIRD_DIGIT(*it)	||
								FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	||
								SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
								SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
								SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
								THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
								THIRD_DIGIT(current) == THIRD_DIGIT(*it)
							)
						)
						||
						(
							FOURTH_DIGIT(current) == THIRD_DIGIT(*it) &&
							(
								FIRST_DIGIT(current) == SECOND_DIGIT(*it)	||
								FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	||
								SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
								SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
								THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
								THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
								THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
							)
						)
					 )
					||
					(
						FIRST_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				{
					auto it1 = it;
					++it;
					set.erase(it1);
				}
				else ++it;
			}
}
void match_2_place_1(std::unordered_set<int> &set, int current)
{
	for (auto it = set.begin(); it != set.end();)
	{
		if (
				(
					FIRST_DIGIT(current) == FIRST_DIGIT(*it) &&
					(
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					SECOND_DIGIT(current) == SECOND_DIGIT(*it) &&
					(
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					THIRD_DIGIT(current) == THIRD_DIGIT(*it) &&
					FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
				)
				||
				!(
					FIRST_DIGIT(current) == FIRST_DIGIT(*it) &&
					(
						(
							SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
							SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
							THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
							THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
							FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
							FOURTH_DIGIT(current) == THIRD_DIGIT(*it)
						)
						&&
						!(
							(
								SECOND_DIGIT(current) == THIRD_DIGIT(*it)	&&
								(
									THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
									THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||							
									FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
									FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
								)
							)
							||
							(
								SECOND_DIGIT(current) == FOURTH_DIGIT(*it) &&
								(
									THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
									THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
									FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
									FOURTH_DIGIT(current) == THIRD_DIGIT(*it)
								)
							)
							||
							(
								THIRD_DIGIT(current) == SECOND_DIGIT(*it) &&
								(
									SECOND_DIGIT(current) == THIRD_DIGIT(*it) ||
									SECOND_DIGIT(current) == FOURTH_DIGIT(*it) ||
									FOURTH_DIGIT(current) == THIRD_DIGIT(*it) ||
									FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
								)
							)
							||
							(
								THIRD_DIGIT(current) == FOURTH_DIGIT(*it) &&
								(
									SECOND_DIGIT(current) == SECOND_DIGIT(*it) ||
									SECOND_DIGIT(current) == THIRD_DIGIT(*it) ||
									FOURTH_DIGIT(current) == SECOND_DIGIT(*it) ||
									FOURTH_DIGIT(current) == THIRD_DIGIT(*it)
								)
							)
							||
							(
								FOURTH_DIGIT(current) == SECOND_DIGIT(*it) &&
								(
									SECOND_DIGIT(current) == THIRD_DIGIT(*it) ||
									SECOND_DIGIT(current) == FOURTH_DIGIT(*it) ||
									THIRD_DIGIT(current) == THIRD_DIGIT(*it) ||
									THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
								)
							)
							||
							(
								FOURTH_DIGIT(current) == THIRD_DIGIT(*it) &&
								(
									SECOND_DIGIT(current) == SECOND_DIGIT(*it) ||
									SECOND_DIGIT(current) == FOURTH_DIGIT(*it) ||
									THIRD_DIGIT(current) == SECOND_DIGIT(*it) ||
									THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
								)
							)
						)
					)
					||
					SECOND_DIGIT(current) == SECOND_DIGIT(*it) &&
					(
						(
							FIRST_DIGIT(current) == THIRD_DIGIT(*it)	||
							FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	||
							THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
							THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
							FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
							FOURTH_DIGIT(current) == THIRD_DIGIT(*it)
						)
						&&
						!(
							(
								FIRST_DIGIT(current) == THIRD_DIGIT(*it) &&
								(
									THIRD_DIGIT(current) == FIRST_DIGIT(*it) ||
									THIRD_DIGIT(current) == FOURTH_DIGIT(*it) ||
									FOURTH_DIGIT(current) == FIRST_DIGIT(*it) ||
									FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
								)
							)
							||
							(
								FIRST_DIGIT(current) == FOURTH_DIGIT(*it) &&
								(
									THIRD_DIGIT(current) == FIRST_DIGIT(*it) ||
									THIRD_DIGIT(current) == THIRD_DIGIT(*it) ||
									FOURTH_DIGIT(current) == FIRST_DIGIT(*it) ||
									FOURTH_DIGIT(current) == THIRD_DIGIT(*it)
								)
							)
							||
							(
								THIRD_DIGIT(current) == FIRST_DIGIT(*it) &&
								(
									FIRST_DIGIT(current) == THIRD_DIGIT(*it) ||
									FIRST_DIGIT(current) == FOURTH_DIGIT(*it) ||
									FOURTH_DIGIT(current) == THIRD_DIGIT(*it) ||
									FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
								)
							)
							||
							(
								THIRD_DIGIT(current) == FOURTH_DIGIT(*it) &&
								(
									FIRST_DIGIT(current) == FIRST_DIGIT(*it) ||
									FIRST_DIGIT(current) == THIRD_DIGIT(*it) ||
									FOURTH_DIGIT(current) == FIRST_DIGIT(*it) ||
									FOURTH_DIGIT(current) == THIRD_DIGIT(*it)
								)
							)
							||
							(
								FOURTH_DIGIT(current) == FIRST_DIGIT(*it) &&
								(
									FIRST_DIGIT(current) == THIRD_DIGIT(*it) ||
									FIRST_DIGIT(current) == FOURTH_DIGIT(*it) ||
									THIRD_DIGIT(current) == THIRD_DIGIT(*it) ||
									THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
								)
							)
							||
							(
								FOURTH_DIGIT(current) == THIRD_DIGIT(*it) &&
								(
									FIRST_DIGIT(current) == FIRST_DIGIT(*it) ||
									FIRST_DIGIT(current) == FOURTH_DIGIT(*it) ||
									THIRD_DIGIT(current) == FIRST_DIGIT(*it) ||
									THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
								)
							)
						)
					)
					||
					THIRD_DIGIT(current) == THIRD_DIGIT(*it) &&
					(
						(
							FIRST_DIGIT(current) == SECOND_DIGIT(*it)	||
							FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	||
							SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
							SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
							FOURTH_DIGIT(current) == FIRST_DIGIT(*it) ||
							FOURTH_DIGIT(current) == SECOND_DIGIT(*it)
						)
						&&
						!(
							(
								FIRST_DIGIT(current) == SECOND_DIGIT(*it) &&
								(
									SECOND_DIGIT(current) == FIRST_DIGIT(*it) ||
									SECOND_DIGIT(current) == FOURTH_DIGIT(*it) ||
									FOURTH_DIGIT(current) == FIRST_DIGIT(*it) ||
									FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
								)
							)
							||
							(
								FIRST_DIGIT(current) == FOURTH_DIGIT(*it) &&
								(
									SECOND_DIGIT(current) == FIRST_DIGIT(*it) ||
									SECOND_DIGIT(current) == SECOND_DIGIT(*it) ||
									FOURTH_DIGIT(current) == FIRST_DIGIT(*it) ||
									FOURTH_DIGIT(current) == SECOND_DIGIT(*it)
								)
							)
							||
							(
								SECOND_DIGIT(current) == FIRST_DIGIT(*it) &&
								(
									FIRST_DIGIT(current) == SECOND_DIGIT(*it) ||
									FIRST_DIGIT(current) == FOURTH_DIGIT(*it) ||
									FOURTH_DIGIT(current) == SECOND_DIGIT(*it) ||
									FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
								)
							)
							||
							(
								SECOND_DIGIT(current) == FOURTH_DIGIT(*it) &&
								(
									FIRST_DIGIT(current) == FIRST_DIGIT(*it) ||
									FIRST_DIGIT(current) == SECOND_DIGIT(*it) ||
									FOURTH_DIGIT(current) == FIRST_DIGIT(*it) ||
									FOURTH_DIGIT(current) == SECOND_DIGIT(*it)
								)
							)
							||
							(
								FOURTH_DIGIT(current) == FIRST_DIGIT(*it) &&
								(
									FIRST_DIGIT(current) == SECOND_DIGIT(*it) ||
									FIRST_DIGIT(current) == FOURTH_DIGIT(*it) ||
									SECOND_DIGIT(current) == SECOND_DIGIT(*it) ||
									SECOND_DIGIT(current) == FOURTH_DIGIT(*it)
								)
							)
							||
							(
								FOURTH_DIGIT(current) == SECOND_DIGIT(*it) &&
								(
									FIRST_DIGIT(current) == FIRST_DIGIT(*it) ||
									FIRST_DIGIT(current) == FOURTH_DIGIT(*it) ||
									SECOND_DIGIT(current) == FIRST_DIGIT(*it) ||
									SECOND_DIGIT(current) == FOURTH_DIGIT(*it)
								)
							)
						)						
					)
					||
					FOURTH_DIGIT(current) == FOURTH_DIGIT(*it) &&
					(
						(
							FIRST_DIGIT(current) == SECOND_DIGIT(*it)	||
							FIRST_DIGIT(current) == THIRD_DIGIT(*it)	||
							SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
							SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
							THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
							THIRD_DIGIT(current) == SECOND_DIGIT(*it)
						)
						&&
						!(
							(
								FIRST_DIGIT(current) == SECOND_DIGIT(*it) &&
								(
									SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
									SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
									THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
									THIRD_DIGIT(current) == THIRD_DIGIT(*it)
								)
							)
							||
							(
								FIRST_DIGIT(current) == THIRD_DIGIT(*it) &&
								(
									SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
									SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
									THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
									THIRD_DIGIT(current) == SECOND_DIGIT(*it)
								)
							)
							||
							(
								SECOND_DIGIT(current) == FIRST_DIGIT(*it) &&
								(
									FIRST_DIGIT(current) == SECOND_DIGIT(*it) ||
									FIRST_DIGIT(current) == THIRD_DIGIT(*it) ||
									THIRD_DIGIT(current) == SECOND_DIGIT(*it) ||
									THIRD_DIGIT(current) == THIRD_DIGIT(*it)
								)
							)
							||
							(
								SECOND_DIGIT(current) == THIRD_DIGIT(*it) &&
								(
									FIRST_DIGIT(current) == FIRST_DIGIT(*it) ||
									FIRST_DIGIT(current) == SECOND_DIGIT(*it) ||
									THIRD_DIGIT(current) == FIRST_DIGIT(*it) ||
									THIRD_DIGIT(current) == SECOND_DIGIT(*it)
								)
							)
							||
							(
								THIRD_DIGIT(current) == FIRST_DIGIT(*it) &&
								(
									FIRST_DIGIT(current) == SECOND_DIGIT(*it) ||
									FIRST_DIGIT(current) == THIRD_DIGIT(*it) ||
									SECOND_DIGIT(current) == SECOND_DIGIT(*it) ||
									SECOND_DIGIT(current) == THIRD_DIGIT(*it)
								)
							)
							||
							(
								THIRD_DIGIT(current) == SECOND_DIGIT(*it) &&
								(
									FIRST_DIGIT(current) == FIRST_DIGIT(*it) ||
									FIRST_DIGIT(current) == THIRD_DIGIT(*it) ||
									SECOND_DIGIT(current) == FIRST_DIGIT(*it) ||
									SECOND_DIGIT(current) == THIRD_DIGIT(*it)
								)
							)
						)						
					)					
				)
			)
		{
			auto it1 = it;
			++it;
			set.erase(it1);
		}
		else ++it;
	}
}
void match_2_place_2(std::unordered_set<int> &set, int current)
{
	for (auto it = set.begin(); it != set.end();)
	{
		if 
		(
			!(
				(
					FIRST_DIGIT(current) == FIRST_DIGIT(*it)	&&
					SECOND_DIGIT(current) == SECOND_DIGIT(*it)	&&
					(
						THIRD_DIGIT(current) != THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) != FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) != THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) != FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == FIRST_DIGIT(*it) &&
					THIRD_DIGIT(current) == THIRD_DIGIT(*it) &&
					(
						SECOND_DIGIT(current) != SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) != FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) != SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) != FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == FIRST_DIGIT(*it)	&&
					FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)	&&
					(
						SECOND_DIGIT(current) != SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) != THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) != SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) != THIRD_DIGIT(*it)
					)
				)
				||
				(
					SECOND_DIGIT(current) == SECOND_DIGIT(*it)	&&
					THIRD_DIGIT(current) == THIRD_DIGIT(*it)	&&
					(
						FIRST_DIGIT(current) != FIRST_DIGIT(*it)	||
						FIRST_DIGIT(current) != FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) != FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) != FOURTH_DIGIT(*it)
					) 
				)
				||
				(
					SECOND_DIGIT(current) == SECOND_DIGIT(*it)	&&
					FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)	&&
					(
						FIRST_DIGIT(current) != FIRST_DIGIT(*it)	||
						FIRST_DIGIT(current) != THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) != FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) != THIRD_DIGIT(*it)
					) 
				)
				||
				(
					THIRD_DIGIT(current) == THIRD_DIGIT(*it)	&&
					FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)	&&
					(
						FIRST_DIGIT(current) != FIRST_DIGIT(*it)	||
						FIRST_DIGIT(current) != SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) != FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) != SECOND_DIGIT(*it)
					) 
				)
			)
		)
		{
			auto it1 = it;
			++it;
			set.erase(it1);
		}
		else ++it;
	}

}
void match_3_place_0(std::unordered_set<int> &set, int current)
{
	for (auto it = set.begin(); it != set.end();)
	{
		if
		(
			(
				FIRST_DIGIT(current) == FIRST_DIGIT(*it)	||
				SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
				THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
				FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
			)
			||
			!(
				(
					FIRST_DIGIT(current) == FIRST_DIGIT(*it)	&&
					(	
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == FIRST_DIGIT(*it)	&&
					(	
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == SECOND_DIGIT(*it)	&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||	
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == SECOND_DIGIT(*it)	&&
					(	
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == SECOND_DIGIT(*it)	&&
					(	
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == SECOND_DIGIT(*it)	&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||	
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == THIRD_DIGIT(*it)	&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	
					)
					&&
					(						
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == THIRD_DIGIT(*it)	&&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it) 
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == THIRD_DIGIT(*it)	&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it) 
					)
				)
				||
				(
					FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	&&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	
					)
				)
				||
				(
					SECOND_DIGIT(current) == FIRST_DIGIT(*it) &&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					SECOND_DIGIT(current) == SECOND_DIGIT(*it) &&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					SECOND_DIGIT(current) == THIRD_DIGIT(*it) &&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					SECOND_DIGIT(current) == FOURTH_DIGIT(*it) &&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it) ||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it) ||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it) ||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it) ||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it) ||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it) ||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
			)
			||
			(
				FIRST_DIGIT(current) == FIRST_DIGIT(*it)	&&
				(
					SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
					THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
					FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
				)
			)
			||
			(
				SECOND_DIGIT(current) == SECOND_DIGIT(*it)	&&
				(
					THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
					FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
				)
			)
			||
			(
				THIRD_DIGIT(current) == THIRD_DIGIT(*it)	&&
				FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
			)
		)
		{
			auto it1 = it;
			++it;
			set.erase(it1);
		}
		else ++it;
	}
}
void match_3_place_1(std::unordered_set<int> &set, int current)
{
	for (auto it = set.begin(); it != set.end();)
	{
		if
		(
			(
				FIRST_DIGIT(current) != FIRST_DIGIT(*it)	&&
				SECOND_DIGIT(current) != SECOND_DIGIT(*it)	&&
				THIRD_DIGIT(current) != THIRD_DIGIT(*it)	&&
				FOURTH_DIGIT(current) != FOURTH_DIGIT(*it)
			)
			||
			(
				FIRST_DIGIT(current) == FIRST_DIGIT(*it)	&&
				(
					SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
					THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
					FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
				)
			)
			||
			(
				SECOND_DIGIT(current) == SECOND_DIGIT(*it)	&&
				(
					THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
					FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
				)
			)
			||
			(
				THIRD_DIGIT(current) == THIRD_DIGIT(*it)	&&
				FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
			)
			||
			!(
				(
					FIRST_DIGIT(current) == FIRST_DIGIT(*it)	&&
					(	
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == FIRST_DIGIT(*it)	&&
					(	
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == SECOND_DIGIT(*it)	&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||	
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == SECOND_DIGIT(*it)	&&
					(	
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == SECOND_DIGIT(*it)	&&
					(	
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == SECOND_DIGIT(*it)	&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||	
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == THIRD_DIGIT(*it)	&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	
					)
					&&
					(						
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == THIRD_DIGIT(*it)	&&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it) 
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == THIRD_DIGIT(*it)	&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it) 
					)
				)
				||
				(
					FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	&&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	
					)
				)
				||
				(
					SECOND_DIGIT(current) == FIRST_DIGIT(*it) &&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					SECOND_DIGIT(current) == SECOND_DIGIT(*it) &&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					SECOND_DIGIT(current) == THIRD_DIGIT(*it) &&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					SECOND_DIGIT(current) == FOURTH_DIGIT(*it) &&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it) ||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it) ||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it) ||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it) ||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it) ||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it) ||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
			)
			
		)
		{
			auto it1 = it;
			++it;
			set.erase(it1);
		}
		else ++it;
	}
}
void match_3_place_2(std::unordered_set<int> &set, int current)
{
	for (auto it = set.begin(); it != set.end();)
	{
		if
		(
			!(
				(
					FIRST_DIGIT(current) == FIRST_DIGIT(*it)	&&
					(
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					SECOND_DIGIT(current) == SECOND_DIGIT(*it)	&&
					(
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					THIRD_DIGIT(current) == THIRD_DIGIT(*it)	&&
					FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
				)
			)
			||
			!(
				(
					FIRST_DIGIT(current) == FIRST_DIGIT(*it)	&&
					(	
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == FIRST_DIGIT(*it)	&&
					(	
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == SECOND_DIGIT(*it)	&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||	
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == SECOND_DIGIT(*it)	&&
					(	
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == SECOND_DIGIT(*it)	&&
					(	
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == SECOND_DIGIT(*it)	&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||	
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == THIRD_DIGIT(*it)	&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	
					)
					&&
					(						
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == THIRD_DIGIT(*it)	&&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it) 
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == THIRD_DIGIT(*it)	&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it) 
					)
				)
				||
				(
					FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	&&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	
					)
				)
				||
				(
					SECOND_DIGIT(current) == FIRST_DIGIT(*it) &&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					SECOND_DIGIT(current) == SECOND_DIGIT(*it) &&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					SECOND_DIGIT(current) == THIRD_DIGIT(*it) &&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					SECOND_DIGIT(current) == FOURTH_DIGIT(*it) &&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it) ||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it) ||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it) ||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it) ||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it) ||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it) ||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
			)
			
		)
		{
			auto it1 = it;
			++it;
			set.erase(it1);
		}
		else ++it;
	}
}
void match_3_place_3(std::unordered_set<int> &set, int current)
{
	for (auto it = set.begin(); it != set.end();)
	{
		if
		(
			!(
				(
					FIRST_DIGIT(current) == FIRST_DIGIT(*it)	&&
					SECOND_DIGIT(current) == SECOND_DIGIT(*it)	&&
					(
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					THIRD_DIGIT(current) == THIRD_DIGIT(*it)	&&
					FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)	&&
					(
						FIRST_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)
					)
				)
			)
			||
			!(
				(
					FIRST_DIGIT(current) == FIRST_DIGIT(*it)	&&
					(	
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == FIRST_DIGIT(*it)	&&
					(	
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == SECOND_DIGIT(*it)	&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||	
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == SECOND_DIGIT(*it)	&&
					(	
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == SECOND_DIGIT(*it)	&&
					(	
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == SECOND_DIGIT(*it)	&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||	
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == THIRD_DIGIT(*it)	&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	
					)
					&&
					(						
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||	
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == THIRD_DIGIT(*it)	&&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it) 
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == THIRD_DIGIT(*it)	&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it) 
					)
				)
				||
				(
					FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	&&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					FIRST_DIGIT(current) == FOURTH_DIGIT(*it)	&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						SECOND_DIGIT(current) == FIRST_DIGIT(*it)	||
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						SECOND_DIGIT(current) == THIRD_DIGIT(*it)	||
						SECOND_DIGIT(current) == FOURTH_DIGIT(*it)	||
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)	
					)
				)
				||
				(
					SECOND_DIGIT(current) == FIRST_DIGIT(*it) &&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					SECOND_DIGIT(current) == SECOND_DIGIT(*it) &&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					SECOND_DIGIT(current) == THIRD_DIGIT(*it) &&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it)	||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it)	||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it)	||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					SECOND_DIGIT(current) == FOURTH_DIGIT(*it) &&
					(
						THIRD_DIGIT(current) == FIRST_DIGIT(*it) ||
						THIRD_DIGIT(current) == SECOND_DIGIT(*it) ||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it) ||
						THIRD_DIGIT(current) == FOURTH_DIGIT(*it)
					)
					&&
					(
						FOURTH_DIGIT(current) == FIRST_DIGIT(*it) ||
						FOURTH_DIGIT(current) == SECOND_DIGIT(*it) ||
						FOURTH_DIGIT(current) == THIRD_DIGIT(*it) ||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
			)
			
		)
		{
			auto it1 = it;
			++it;
			set.erase(it1);
		}
		else ++it;
	}
}
void match_4_place_0(std::unordered_set<int> &set, int current)
{
	for (auto it = set.begin(); it != set.end();)
	{
		if
		(
			(
				FIRST_DIGIT(current) == FIRST_DIGIT(*it)	||
				SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
				THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
				FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
			)
			||
			(
				FIRST_DIGIT(current) != FIRST_DIGIT(*it)	&&
				FIRST_DIGIT(current) != SECOND_DIGIT(*it)	&&
				FIRST_DIGIT(current) != THIRD_DIGIT(*it)	&&
				FIRST_DIGIT(current) != FOURTH_DIGIT(*it)	
			)
			||
			(
				SECOND_DIGIT(current) != FIRST_DIGIT(*it)	&&
				SECOND_DIGIT(current) != SECOND_DIGIT(*it)	&&
				SECOND_DIGIT(current) != THIRD_DIGIT(*it)	&&
				SECOND_DIGIT(current) != FOURTH_DIGIT(*it)
			)
			||
			(
				THIRD_DIGIT(current) != FIRST_DIGIT(*it)	&&
				THIRD_DIGIT(current) != SECOND_DIGIT(*it)	&&
				THIRD_DIGIT(current) != THIRD_DIGIT(*it)	&&
				THIRD_DIGIT(current) != FOURTH_DIGIT(*it)
			)
			||
			(
				FOURTH_DIGIT(current) != FIRST_DIGIT(*it)	&&
				FOURTH_DIGIT(current) != SECOND_DIGIT(*it)	&&
				FOURTH_DIGIT(current) != THIRD_DIGIT(*it)	&&
				FOURTH_DIGIT(current) != FOURTH_DIGIT(*it)
			)
		)
		{
			auto it1 = it;
			++it;
			set.erase(it1);
		}
		else ++it;
	}
}
void match_4_place_1(std::unordered_set<int> &set, int current)
{
	for (auto it = set.begin(); it != set.end();)
	{
		if
		(
			(
				FIRST_DIGIT(current) != FIRST_DIGIT(*it)	&&
				SECOND_DIGIT(current) != SECOND_DIGIT(*it)	&&
				THIRD_DIGIT(current) != THIRD_DIGIT(*it)	&&
				FOURTH_DIGIT(current) != FOURTH_DIGIT(*it)
			)
			||
			(
				FIRST_DIGIT(current) == FIRST_DIGIT(*it)	&&
				(
					SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
					THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
					FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
				)
			)
			||
			(
				SECOND_DIGIT(current) == SECOND_DIGIT(*it)	&&
				(
					THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
					FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
				)
			)
			||
			(
				THIRD_DIGIT(current) == THIRD_DIGIT(*it)	&&
				FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
			)
			||
			(
				FIRST_DIGIT(current) != FIRST_DIGIT(*it)	&&
				FIRST_DIGIT(current) != SECOND_DIGIT(*it)	&&
				FIRST_DIGIT(current) != THIRD_DIGIT(*it)	&&
				FIRST_DIGIT(current) != FOURTH_DIGIT(*it)	
			)
			||
			(
				SECOND_DIGIT(current) != FIRST_DIGIT(*it)	&&
				SECOND_DIGIT(current) != SECOND_DIGIT(*it)	&&
				SECOND_DIGIT(current) != THIRD_DIGIT(*it)	&&
				SECOND_DIGIT(current) != FOURTH_DIGIT(*it)
			)
			||
			(
				THIRD_DIGIT(current) != FIRST_DIGIT(*it)	&&
				THIRD_DIGIT(current) != SECOND_DIGIT(*it)	&&
				THIRD_DIGIT(current) != THIRD_DIGIT(*it)	&&
				THIRD_DIGIT(current) != FOURTH_DIGIT(*it)
			)
			||
			(
				FOURTH_DIGIT(current) != FIRST_DIGIT(*it)	&&
				FOURTH_DIGIT(current) != SECOND_DIGIT(*it)	&&
				FOURTH_DIGIT(current) != THIRD_DIGIT(*it)	&&
				FOURTH_DIGIT(current) != FOURTH_DIGIT(*it)
			)
		)
		{
			auto it1 = it;
			++it;
			set.erase(it1);
		}
		else ++it;
	}
}
void match_4_place_2(std::unordered_set<int> &set, int current)
{
	for (auto it = set.begin(); it != set.end();)
	{
		if
		(
			!(
				(
					FIRST_DIGIT(current) == FIRST_DIGIT(*it)	&&
					(
						SECOND_DIGIT(current) == SECOND_DIGIT(*it)	||
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					SECOND_DIGIT(current) == SECOND_DIGIT(*it)	&&
					(
						THIRD_DIGIT(current) == THIRD_DIGIT(*it)	||
						FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
					)
				)
				||
				(
					THIRD_DIGIT(current) == THIRD_DIGIT(*it)	&&
					FOURTH_DIGIT(current) == FOURTH_DIGIT(*it)
				)
			)
			||
			(
				FIRST_DIGIT(current) != FIRST_DIGIT(*it)	&&
				FIRST_DIGIT(current) != SECOND_DIGIT(*it)	&&
				FIRST_DIGIT(current) != THIRD_DIGIT(*it)	&&
				FIRST_DIGIT(current) != FOURTH_DIGIT(*it)	
			)
			||
			(
				SECOND_DIGIT(current) != FIRST_DIGIT(*it)	&&
				SECOND_DIGIT(current) != SECOND_DIGIT(*it)	&&
				SECOND_DIGIT(current) != THIRD_DIGIT(*it)	&&
				SECOND_DIGIT(current) != FOURTH_DIGIT(*it)
			)
			||
			(
				THIRD_DIGIT(current) != FIRST_DIGIT(*it)	&&
				THIRD_DIGIT(current) != SECOND_DIGIT(*it)	&&
				THIRD_DIGIT(current) != THIRD_DIGIT(*it)	&&
				THIRD_DIGIT(current) != FOURTH_DIGIT(*it)
			)
			||
			(
				FOURTH_DIGIT(current) != FIRST_DIGIT(*it)	&&
				FOURTH_DIGIT(current) != SECOND_DIGIT(*it)	&&
				FOURTH_DIGIT(current) != THIRD_DIGIT(*it)	&&
				FOURTH_DIGIT(current) != FOURTH_DIGIT(*it)
			)
		)
		{
			auto it1 = it;
			++it;
			set.erase(it1);
		}
		else ++it;
	}
}
int main()
{
	std::unordered_set<int> set;
	for (int i = 1000; i < 10000; i++)
		set.insert(i);
	int match, rightPlace, current = 0, nextIndex = 1;
	std::vector<int> setV, currentV;
	while (set.size() > 1)
	{
		if (currentV.size() == 0)
		{
			current = *set.begin();
			currentV.push_back(current);
		}
		else
		{
			auto it = set.begin();
			current = *it;
			for (auto i : currentV)
			{
				if (i == current)
				{
					if (++it != set.end())
					{
						current = *(it);
					}
					else
					{
						current = *set.begin();
						break;
					}
				}
			}
			currentV.push_back(current);
		}


		std::cout << "\nPlease tell how many matches and in right place digits have in \n"
			<< current << "\n";
		std::cout << "Match: ";
		std::cin >> match;
		std::cout << "\nRight in place: ";
		std::cin >> rightPlace;

		
		if (match == 0)
		{
			match_0_place_0(set,current);
		}
		
		else if (match == 1 && rightPlace == 0)
		{
			match_1_place_0(set,current);
		}
		else if (match == 1 && rightPlace == 1)
		{
			match_1_place_1(set, current);
		}
		else if (match == 2 && rightPlace == 0)
		{
			match_2_place_0(set, current);
		}
		else if (match == 2 && rightPlace == 1)
		{
			match_2_place_1(set, current);
		}
		else if (match == 2 && rightPlace == 2)
		{
			match_2_place_2(set, current);
		}
		else if (match == 3 && rightPlace == 0)
		{
			match_3_place_0(set, current);
		}
		else if (match == 3 && rightPlace == 1)
		{
			match_3_place_1(set, current);
		}
		else if (match == 3 && rightPlace == 2)
		{
			match_3_place_2(set, current);
		}
		else if (match == 3 && rightPlace == 3)
		{
			match_3_place_3(set, current);
		}
		else if (match == 4 && rightPlace == 0)
		{
			match_4_place_0(set, current);
		}
		else if (match == 4 && rightPlace == 1)
		{
			match_4_place_1(set, current);
		}
		else if (match == 4 && rightPlace == 2)
		{
			match_4_place_2(set, current);
		}
		else
		{
			set.clear();
			set.insert(current);
		}

		for (auto i : set)
		{
			
			setV.push_back(i);
		}
		std::sort(setV.begin(), setV.end());
		for (auto i : setV)
		{
			std::cout << i << " ";
		}
		setV.clear();
	}
	std::cout << "\nYour number: " << *set.begin() << "\n";
	getchar();
	getchar();
	return 0;
}