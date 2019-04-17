#include <iostream>
#include <vector>

/*
 * Ask user to check 0,1,...,9 numbers, if have then how many, if not then 0
 */
int question(int number,int length)
{
	int matchCount, rightPlaceCount = 0;

	while (length--) // get the number in given length consist of only one digit
	{
		std::cout << number;
	}

	std::cout << "\nMatch count: ";
	std::cin >> matchCount;
	return matchCount;
}
void swap(int &a, int &b)
{
	a ^= b;
	b ^= a;
	a ^= b;
}
/*
 * For check print number
 */
void print(std::vector<std::pair<int,bool>> vector)
{
	std::cout << "\n";
	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i].first;
	}		
}
/* Debuging
void print1(std::vector<std::pair<int, bool>> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << "\n" << vector[i].first << " " << vector[i].second;
	}
}
*/

/*
 * Find all digits of number, in addition repetitive digits are repeated.
 */
void find_digits(std::vector<std::pair<int, bool>> &haveInNumber, int &notIncludedDigit, int length)
{
	for (int i = 0; i < 10 && (haveInNumber.size() < length); i++)
	{
		auto answer = question(i, length);
		if (answer == 0)notIncludedDigit = i;
		else 
			while (answer--)
			{
				haveInNumber.push_back(std::make_pair(i,false));
			}
	}
}
/*
 * Ask user to check, how many in right place digits are in given number.
 */
int check(std::vector<std::pair<int, bool>> &v)
{
	int rightPlaceCount;
	print(v);
	std::cout << "\nRight place count: ";
	std::cin >> rightPlaceCount;
	return rightPlaceCount;	
}
/*
 * There step() function swap two in wrong place digits
 * Begin searching wrong digit from current element (digit[j])  
 */
void step(std::vector<std::pair<int, bool>> &v, int &i, int &j)
{
	while (v[j].second == true && j < v.size())
	{
		j++;
	}
	while (v[j + i].second == true && i < v.size())
	{
		i++;
	}

	if (j == v.size() || i == v.size())
	{
		return;
	}

	if (v[j].first == v[j + i].first)
	{
		j += i;
		i = 1;		
		step(v, i, j);
	}
	else
	{
		swap(v[j], v[j + i]);
	}
}
/*
 *
 */
void know_in_place_digits(std::vector<std::pair<int, bool>> &digits, int rightPlaceCount, int notIncludedDigit)
{
	int count = 0;
	for (int i = 0; i < digits.size() && count < rightPlaceCount; i++)
	{
		swap(digits[i].first, notIncludedDigit);
		if (check(digits) != rightPlaceCount)
		{
			digits[i].second = true;
			count++;
		}
		swap(digits[i].first, notIncludedDigit);
	}
}
/*
 * 
 */
void guess_knowing_palce_exactly(std::vector<std::pair<int, bool>> &digits, int rightPlaceCount,int notIncludedDigit)
{
	int  j = 0, i = 1, current;
	if (rightPlaceCount >= digits.size() - 1)
	{
		return;
	}
	step(digits, i, j);
	j += i;

	while ((current = check(digits)) < digits.size() - 1)
	{
		if (current - rightPlaceCount == 0)
		{	
			step(digits, i, j);
			j += i;			
			/*
			std::cout << "\nDebug v ";
			print1(digits);
			std::cout << "\n";
			*/
		}
		else if (current - rightPlaceCount == 1)
		{			
			swap(notIncludedDigit, digits[j].first);
			if (check(digits) == current)
			{			
				swap(notIncludedDigit, digits[j].first);
				digits[j - i].second = true;
				rightPlaceCount++;
				i = 1;
			}
			else
			{
				swap(notIncludedDigit, digits[j].first);
				digits[j].second = true;
				rightPlaceCount++;
				j = 0;
				i = 1;
			}		
			if (rightPlaceCount < digits.size() - 1)
			{
				step(digits, i, j);
				j += i;
			}
		}
		else // two digits are in right place
		{
			digits[j].second = digits[j - i].second = true;
			rightPlaceCount += 2;
			j = 0;
			i = 1;
			if (rightPlaceCount < digits.size() - 1)
			{
				step(digits, i, j);
				j += i;
			}
		}		
		/*
		std::cout << "\nDebug v ";
		print1(digits);
		std::cout << "\n";
		*/
	}

}
/* Main Algorithm
 *
 * First we have to know number length, so we ask to know it.
 * After that we start check 0,1,...,9 digits, how many times they are repeated, using find_digits() function
 * Doing that we have already know number digits in unordered sequence(in vector).
 * Now we ask to check to know how many digits are in place, and using know_in_place_digits() function we know it.
 * Afterwards we call guess_knowing_palce_exactly() function that start to swap digits and ask to check count of in right place digits. 
 *
 * P.S. One digit from 0,1,...,9 must not be in kept number (example 1234567890 must not be)
 * And user must not lie. If user lie might "undefined behaviour".
 *
 */
int main() 
{
	std::cout << "Keep number in your mind and answer following questions. Don't lie!!!\n";
	
	int length;
	std::cout << "What is number length?\n";
	std::cin >> length;

	std::vector<std::pair<int, bool>> digits;	//int-digit, bool-in place or not
	int notIncluded;
	find_digits(digits, notIncluded, length);
	
	int rightPlaceCount = check(digits);
	if (rightPlaceCount == 0)
	{
		guess_knowing_palce_exactly(digits, rightPlaceCount, notIncluded);
	}
	else if (rightPlaceCount < digits.size() - 1)
	{
		know_in_place_digits(digits, rightPlaceCount, notIncluded);
		guess_knowing_palce_exactly(digits, rightPlaceCount, notIncluded);
	}
	
	std::cout << "Your number is: ";
	print(digits);

	getchar();
	getchar();
	return 0;
}