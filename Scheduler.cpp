// Scheduler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <fstream>
#include <iostream>

using namespace std;
using namespace chrono;

struct process {
	char processId = 65;
	int arrivalTime = 0;
	int priority = 0;
	int burstTime = 0;
	int turnAround = 0;
};

int main()
{
	string fileName = ("C:/Users/Hadyn/source/repos/Scheduler/input.txt");
	
	ifstream input_file(fileName);

	int itemAmount;
	int duration = 0;
	input_file >> itemAmount;
	
	int bigQ;
	cout << "What is quantum? (Default is 2)\n";
	cin >> bigQ;
	
	int placeHolder = 0;
	int currPriority = 0;
	int q = bigQ;
	
	

	vector<process> processList(itemAmount);

	vector<process> turnAround;
	int turnAroundAvg = 0;

	process currProcess;

	for (int i = 0; i < itemAmount; i++)
	{
		processList[i].processId = processList[i].processId + i;
		input_file >> processList[i].arrivalTime;
		input_file >> processList[i].priority;
		input_file >> processList[i].burstTime;
		duration += processList[i].burstTime;
	}
	
	vector<vector<process>> readyQ(10);

	for (int i = 0; i <= duration; i++)
	{
		if (placeHolder < itemAmount)
		{
			if (processList[placeHolder].arrivalTime == i)
			{
				currPriority = processList[placeHolder].priority;
				readyQ[currPriority].push_back(processList[placeHolder]);
				cout << processList[placeHolder].processId << " has arrived at " << processList[placeHolder].arrivalTime << "\n";
				placeHolder++;
			}
		}


		if (!readyQ[0].empty())
		{

			if (currProcess.processId != readyQ[0][0].processId)
			{
				cout << readyQ[0][0].processId << " preempts " << currProcess.processId << " at " << i << "\n";
				q = bigQ;
			}
			currProcess.processId = readyQ[0][0].processId;
			--readyQ[0][0].burstTime;
			if (q == 0 && readyQ[0][0].burstTime != 0)
			{
				process temp = readyQ[0][0];
				readyQ[0].erase(readyQ[0].begin());
				readyQ[0].push_back(temp);
			}
			if (readyQ[0][0].burstTime == 0)
			{
				cout << readyQ[0][0].processId << " has finished at " << i + 1 << "\n";
				readyQ[0][0].turnAround = (i + 1) - readyQ[0][0].arrivalTime;
				turnAround.push_back(readyQ[0][0]);
				readyQ[0].erase(readyQ[0].begin());
			}

		}
		else if (!readyQ[1].empty())
		{

			if (currProcess.processId != readyQ[1][0].processId)
			{
				cout << readyQ[1][0].processId << " preempts " << currProcess.processId << " at " << i << "\n";
				q = bigQ;
			}
			currProcess.processId = readyQ[1][0].processId;
			--readyQ[1][0].burstTime;
			if (q == 0 && readyQ[1][0].burstTime != 0)
			{
				process temp = readyQ[1][0];
				readyQ[1].erase(readyQ[1].begin());
				readyQ[1].push_back(temp);
			}
			if (readyQ[1][0].burstTime == 0)
			{
				cout << readyQ[1][0].processId << " has finished at " << i + 1 << "\n";
				readyQ[1][0].turnAround = (i + 1) - readyQ[1][0].arrivalTime;
				turnAround.push_back(readyQ[1][0]);
				readyQ[1].erase(readyQ[1].begin());
			}

		}
		else if (!readyQ[2].empty())
		{

			if (currProcess.processId != readyQ[2][0].processId)
			{
				q = bigQ;
				cout << readyQ[2][0].processId << " preempts " << currProcess.processId << " at " << i << "\n";
			}
			currProcess.processId = readyQ[2][0].processId;
			--readyQ[2][0].burstTime;
			if (q == 0 && readyQ[2][0].burstTime != 0)
			{
				process temp = readyQ[2][0];
				readyQ[2].erase(readyQ[2].begin());
				readyQ[2].push_back(temp);
			}
			if (readyQ[2][0].burstTime == 0)
			{
				cout << readyQ[2][0].processId << " has finished at " << i + 1 << "\n";
				readyQ[2][0].turnAround = (i + 1) - readyQ[2][0].arrivalTime;
				turnAround.push_back(readyQ[2][0]);
				readyQ[2].erase(readyQ[2].begin());
			}

		}
		else if (!readyQ[3].empty())
		{

			if (currProcess.processId != readyQ[3][0].processId)
			{
				q = bigQ;
				cout << readyQ[3][0].processId << " preempts " << currProcess.processId << " at " << i << "\n";
			}
			currProcess.processId = readyQ[3][0].processId;
			--readyQ[3][0].burstTime;
			if (q == 0 && readyQ[3][0].burstTime != 0)
			{
				process temp = readyQ[3][0];
				readyQ[3].erase(readyQ[3].begin());
				readyQ[3].push_back(temp);
			}
			if (readyQ[3][0].burstTime == 0)
			{
				cout << readyQ[3][0].processId << " has finished at " << i + 1 << "\n";
				readyQ[3][0].turnAround = (i + 1) - readyQ[3][0].arrivalTime;
				turnAround.push_back(readyQ[3][0]);
				readyQ[3].erase(readyQ[3].begin());
			}

		}
		else if (!readyQ[4].empty())
		{

			if (currProcess.processId != readyQ[4][0].processId)
			{
				q = bigQ;
				cout << readyQ[4][0].processId << " preempts " << currProcess.processId << " at " << i << "\n";
			}
			currProcess.processId = readyQ[4][0].processId;
			--readyQ[4][0].burstTime;
			if (q == 0 && readyQ[4][0].burstTime != 0)
			{
				process temp = readyQ[4][0];
				readyQ[4].erase(readyQ[4].begin());
				readyQ[4].push_back(temp);
			}
			if (readyQ[4][0].burstTime == 0)
			{
				cout << readyQ[4][0].processId << " has finished at " << i + 1 << "\n";
				readyQ[4][0].turnAround = (i + 1) - readyQ[4][0].arrivalTime;
				turnAround.push_back(readyQ[4][0]);
				readyQ[4].erase(readyQ[4].begin());
			}

		}
		else if (!readyQ[5].empty())
		{
			
			if (currProcess.processId != readyQ[5][0].processId)
			{
				q = bigQ;
				cout << readyQ[5][0].processId << " preempts " << currProcess.processId << " at " << i << "\n";
			}
			currProcess.processId = readyQ[5][0].processId;
			--readyQ[5][0].burstTime;
			if (q == 0 && readyQ[5][0].burstTime != 0)
			{
				process temp = readyQ[5][0];
				readyQ[5].erase(readyQ[5].begin());
				readyQ[5].push_back(temp);
			}
			if (readyQ[5][0].burstTime == 0)
			{
				cout << readyQ[5][0].processId << " has finished at " << i + 1 << "\n";
				readyQ[5][0].turnAround = (i + 1) - readyQ[5][0].arrivalTime;
				turnAround.push_back(readyQ[5][0]);
				readyQ[5].erase(readyQ[5].begin());
			}
			
		}
		else if (!readyQ[6].empty())
		{

			if (currProcess.processId != readyQ[6][0].processId)
			{
				q = bigQ;
				cout << readyQ[6][0].processId << " preempts " << currProcess.processId << " at " << i << "\n";
			}
			currProcess.processId = readyQ[6][0].processId;
			--readyQ[6][0].burstTime;
			if (q == 0 && readyQ[6][0].burstTime != 0)
			{
				process temp = readyQ[6][0];
				readyQ[6].erase(readyQ[6].begin());
				readyQ[6].push_back(temp);
			}
			if (readyQ[6][0].burstTime == 0)
			{
				cout << readyQ[6][0].processId << " has finished at " << i + 1 << "\n";
				readyQ[6][0].turnAround = (i + 1) - readyQ[6][0].arrivalTime;
				turnAround.push_back(readyQ[6][0]);
				readyQ[6].erase(readyQ[6].begin());
			}

		}
		else if (!readyQ[7].empty())
		{

			if (currProcess.processId != readyQ[7][0].processId)
			{
				q = bigQ;
				cout << readyQ[7][0].processId << " preempts " << currProcess.processId << " at " << i << "\n";
			}
			currProcess.processId = readyQ[7][0].processId;
			--readyQ[7][0].burstTime;
			if (q == 0 && readyQ[7][0].burstTime != 0)
			{
				process temp = readyQ[7][0];
				readyQ[7].erase(readyQ[7].begin());
				readyQ[7].push_back(temp);
			}
			if (readyQ[7][0].burstTime == 0)
			{
				cout << readyQ[7][0].processId << " has finished at " << i + 1 << "\n";
				readyQ[7][0].turnAround = (i + 1) - readyQ[7][0].arrivalTime;
				turnAround.push_back(readyQ[7][0]);
				readyQ[7].erase(readyQ[7].begin());
			}

		}
		else if (!readyQ[8].empty())
		{

			if (currProcess.processId != readyQ[8][0].processId)
			{
				q = bigQ;
				cout << readyQ[8][0].processId << " preempts " << currProcess.processId << " at " << i << "\n";
			}
			currProcess.processId = readyQ[8][0].processId;
			--readyQ[8][0].burstTime;
			if (q == 0 && readyQ[8][0].burstTime != 0)
			{
				process temp = readyQ[8][0];
				readyQ[8].erase(readyQ[8].begin());
				readyQ[8].push_back(temp);
			}
			if (readyQ[8][0].burstTime == 0)
			{
				cout << readyQ[8][0].processId << " has finished at " << i + 1 << "\n";
				readyQ[8][0].turnAround = (i + 1) - readyQ[8][0].arrivalTime;
				turnAround.push_back(readyQ[8][0]);
				readyQ[8].erase(readyQ[8].begin());
			}

		}
		else if (!readyQ[9].empty())
		{

			if (currProcess.processId != readyQ[9][0].processId)
			{
				q = bigQ;
				cout << readyQ[9][0].processId << " preempts " << currProcess.processId << " at " << i << "\n";
			}
			currProcess.processId = readyQ[9][0].processId;
			--readyQ[9][0].burstTime;
			if (q == 0 && readyQ[9][0].burstTime != 0)
			{
				process temp = readyQ[9][0];
				readyQ[9].erase(readyQ[9].begin());
				readyQ[9].push_back(temp);
			}
			if (readyQ[9][0].burstTime == 0)
			{
				cout << readyQ[9][0].processId << " has finished at " << i + 1 << "\n";
				readyQ[9][0].turnAround = (i + 1) - readyQ[9][0].arrivalTime;
				turnAround.push_back(readyQ[9][0]);
				readyQ[9].erase(readyQ[9].begin());
			}

		}
		q--;
	}
	for (int i = 0; i < turnAround.size(); i++)
	{
		cout << "The turn around of " << turnAround[i].processId << " is " << turnAround[i].turnAround << "\n";
		turnAroundAvg += turnAround[i].turnAround;
	}

	cout << "Average turn around is " << turnAroundAvg / itemAmount;





}


