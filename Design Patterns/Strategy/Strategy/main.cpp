/*
#include <iostream>
#include <fstream>
#include <string.h>

class Strategy;

class TestBed
{
public:
	enum StrategyType
	{
		Dummy, Left, Right, Center
	};
	TestBed()
	{
		strategy_ = NULL;
	}
	void setStrategy(int type, int width);
	void doIt();
private:
	Strategy *strategy_;
};

class Strategy
{
public:
	Strategy(int width) : width_(width) {}
	void format()
	{
		char line[80], word[30];
		std::ifstream inFile("quote.txt", std::ios::in);
		line[0] = '\0';

		inFile >> word;
		strcat(line, word);
		while (inFile >> word)
		{
			if (strlen(line) + strlen(word) + 1 > width_)
				justify(line);
			else
				strcat(line, " ");
			strcat(line, word);
		}
		justify(line);
	}
protected:
	int width_;
private:
	virtual void justify(char *line) = 0;
};

class LeftStrategy : public Strategy
{
public:
	LeftStrategy(int width) : Strategy(width) {}
private:
	// virtual 
	void justify(char *line)
	{
		cout << line << endl;
		line[0] = '\0';
	}
};

class RightStrategy : public Strategy
{
public:
	RightStrategy(int width) : Strategy(width) {}
private:
	// virtual 
	void justify(char *line)
	{
		char buf[80];
		int offset = width_ - strlen(line);
		memset(buf, ' ', 80);
		strcpy(&(buf[offset]), line);
		cout << buf << endl;
		line[0] = '\0';
	}
};

class CenterStrategy : public Strategy
{
public:
	CenterStrategy(int width) : Strategy(width) {}
private:
	//virtual 
	void justify(char *line)
	{
		char buf[80];
		int offset = (width_ - strlen(line)) / 2;
		memset(buf, ' ', 80);
		strcpy(&(buf[offset]), line);
		cout << buf << endl;
		line[0] = '\0';
	}
};

void TestBed::setStrategy(int type, int width)
{
	delete strategy_;
	if (type == Left)
		strategy_ = new LeftStrategy(width);
	else if (type == Right)
		strategy_ = new RightStrategy(width);
	else if (type == Center)
		strategy_ = new CenterStrategy(width);
}

void TestBed::doIt()
{
	strategy_->format();
}

int main()
{
	TestBed test;
	int answer, width;
	cout << "Exit(0) Left(1) Right(2) Center(3): ";
	cin >> answer;
	while (answer)
	{
		cout << "Width: ";
		cin >> width;
		test.setStrategy(answer, width);
		test.doIt();
		cout << "Exit(0) Left(1) Right(2) Center(3): ";
		cin >> answer;
	}
	return 0;
}
*/

#include "stdafx.h"




int main(int argc, char** argv)
{
	iVec v{ 1,5,8,4,3,6,2,7,0,9,10,11,12,13,14,15 };

	HeapSort B(v);

	SpStrategy spBuble = std::make_shared<HeapSort>(v);
	SpStrategy spMerge = std::make_shared<MergeSort>(v);
	SpStrategy spQuick = std::make_shared<QuickSort>(v);
	
	Heap H1(spBuble);
	Heap H2(spMerge);
	Heap H3(spQuick);

	H1.doIt();	
	H2.doIt();
	H3.doIt();

	getchar();
	return 0;
}
