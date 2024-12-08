#include <iostream>
#include <Windows.h>
#include <ctime>
#include <fstream>
#include <string>
#include <list>



std::string NewestTaskName;
int Choice;
std::string Tasktodelete;
std::list<std::string> TaskList;
struct Tasks
{
	std::string TaskName;
	std::string TaskDescription;
	std::string TaskCreationDate;
};

void newtask();
void tasklist();
void checkexists(std::string searchingfor);
void checkexistsbutdeletenow(std::string searchingfordelte);
void printlist();
void deletetask();

int main() 
{
	system("cls");
	std::cout << "1: New \n2: View List\n3: Delete Task" << std::endl;
	std::cout << "Choice: ";
	std::cin >> Choice;
	if (Choice > 3)
	{
		std::cout << "Not a valid option";
		Sleep(2000);
		main();
	}
	if (Choice == 1)
	{
		newtask();
	}
	else if (Choice == 2)
	{
		tasklist();
	}
	else if (Choice == 3)
	{
		deletetask();
	}


}



void newtask() 
{	
	std::cout << "Task Name: ";
	std::cin >> NewestTaskName;
	std::cout << "Checking list \n";
	checkexists(NewestTaskName);
	

	
}


void tasklist()
{
	std::cout << "Task List\n" << std::endl;
	printlist();
}

void checkexistsbutdeletenow(std::string searchingfordelte)
{
	std::cout << "Checking now \n";
	int tasksize = TaskList.size();
	if (tasksize <= 0)
	{
		std::cout << "There is nothing in list";
		main();
	}
	else if (tasksize >= 1)
	{
		auto it = std::find(TaskList.begin(), TaskList.end(), searchingfordelte);

		// Check if the string was found
		if (it != TaskList.end()) {
			std::cout << "Found: " << *it << std::endl;
			std::cout << "Deleting now" << std::endl;
			TaskList.remove(searchingfordelte);
			std::cout << "Deleted";
			Sleep(500);
			main();
		}
		else {
			std::cout << searchingfordelte << " not found in the list." << std::endl;
			Sleep(2000);
			deletetask();
		}

	}
}
void checkexists(std::string searchingfor)
{
	std::cout << "Checking now \n";
	int tasksize = TaskList.size();
	if (tasksize <= 0)
	{
		std::cout << "Inserted";
		TaskList.insert(TaskList.end(), searchingfor);
		main();
	}
	else if (tasksize >= 1)
	{
		auto it = std::find(TaskList.begin(), TaskList.end(), searchingfor);

		// Check if the string was found
		if (it != TaskList.end()) {
			std::cout << "Found: " << *it << std::endl;
		}
		else {
			std::cout << searchingfor << " not found in the list." << std::endl;
			TaskList.insert(TaskList.end(), searchingfor);
			std::cout << "Added " << searchingfor << " To the list of tasks.";
			main();
		}

	}
}


void printlist()
{
	for (std::list<std::string>::iterator i = TaskList.begin(); i != TaskList.end(); i++)
	{
		std::cout << *i << "\n";
	}
	Sleep(5000);
	main();
}


void deletetask()
{
	for (std::list<std::string>::iterator i = TaskList.begin(); i != TaskList.end(); i++)
	{
		std::cout << *i << "\n";
	}
	std::cout << "\n\n\n";
	Sleep(2500);
	std::cout << "What task do you want to delte?: ";
	std::cin >> Tasktodelete;
	checkexistsbutdeletenow(Tasktodelete);
	main();
}
