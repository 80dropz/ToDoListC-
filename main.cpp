#include <iostream>
#include <Windows.h>
#include <ctime>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <filesystem>

std::string taskfileline;
std::string NewestTaskName;
int Choice;
std::string Tasktodelete;
std::list<std::string> TaskList;
std::string Taskname;

struct Tasks
{
	std::string TaskName;
	std::string TaskDescription;
	std::string TaskCreationDate;
};

void newtask();
void tasklist();
void checkexists(std::string searchingfor);
void checkexistsbutdeletenow(std::string searchingfordelte, int length);
void printlist();
void deletetask();
void checktaskfile();
bool FirstRunThrough = true;



int main() 
{
	if (FirstRunThrough)
	{
		checktaskfile();
	};
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







void checkexistsbutdeletenow(std::string searchingfordelte, int length)
{
	std::cout << "Checking now \n";
	int tasksize = TaskList.size();
	if (tasksize <= 0)
	{
		std::cout << "There is nothing in the list";
		Sleep(5000);
		main();
	}
	else if (tasksize >= 1)
	{
		if (length < tasksize) {
			auto it = TaskList.begin();
			std::advance(it, length);  // Move iterator to the 'length' position

			if (*it == searchingfordelte) {
				std::cout << "Found: " << *it << std::endl;
				std::cout << "Deleting now" << std::endl;
				TaskList.erase(it);  // Remove the task
				std::cout << "Deleted";
				Sleep(500);
				main();
			}
			else {
				std::cout << searchingfordelte << " not found at index " << length << std::endl;
				Sleep(2000);
				main();
			}
		}
		else {
			std::cout << "Index out of bounds.\n";
		}
	}
}







void checkexists(std::string searchingfor)
{
	std::ofstream TaskFileAppend("tasks.txt");
	SYSTEMTIME st;
	GetSystemTime(&st);
	std::string TimeSettings = "       Day: " + std::to_string(st.wDay) + ", Hour: " + std::to_string(st.wHour) + ", Minuetes: " + std::to_string(st.wMinute) + ", Seconds: " + std::to_string(st.wSecond);
	std::cout << "Checking now \n";
	int tasksize = TaskList.size();
	if (tasksize <= 0)
	{
		std::cout << "Inserted";
		Taskname = searchingfor + TimeSettings;
		TaskList.insert(TaskList.end(), Taskname);
		TaskFileAppend << Taskname << std::endl;
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
			Taskname = searchingfor + TimeSettings;
			std::cout << searchingfor << " not found in the list." << std::endl;
			TaskList.insert(TaskList.end(), Taskname);
			TaskFileAppend << Taskname << std::endl;
			std::cout << "Added " << Taskname << " To the list of tasks.";
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
	checkexistsbutdeletenow(Tasktodelete, Tasktodelete.length());
	main();
}





void checktaskfile()
{
	std::cout << "Ts ran";
	Sleep(5000);
	FirstRunThrough = false;
	std::ifstream tasklistfile;
	tasklistfile.open("tasks.txt");
	if (tasklistfile)
	{
		std::cout << "Found Tasks file reading now";
		std::ifstream Taskfile("tasks.txt");
		while (std::getline(Taskfile, taskfileline))
		{
			TaskList.insert(TaskList.end(), taskfileline);
		}
	}
	else
	{
		std::cout << "Couldnt find tasks file writing over";
		std::ofstream taskfile("tasks.txt");
	}

}
