#include<iostream>
#include<string>
#include<thread>

using namespace std;

/*
*Miltithreading
*A thread executes every command in a block of code.
*The example gives two thread for each core. 
*Multi-threading is multitasking. Can complete more tasks in a set amount of time.
*Three types of multi-threading: function, class function, lambda function.
*Example of a clock variable with tracks run time.
*
*/

void threadFunc1(int start, int end)
{
	for (int i = start; i <= end; i++)
	{
		cout << "Hello" << endl;
	}
}

void threadFunc2(int start, int end)
{
	for (int i = start; i <= end; i++)
	{
		cout << "Hi" << endl;
	}
}

//Multithreading with class function:
class test {

public:
	void threadFunc3(int start, int end)
	{
		for (int i = start; i <= end; i++)
		{
			cout << "Hello" << endl;
		}
	}

	void threadFunc4(int start, int end)
	{
		for (int i = start; i <= end; i++)
		{
			cout << "Hi" << endl;
		}
	}

};

int main()
{
	clock_t start, end;
	start = clock();

	//Original methods:
	threadFunc1(1, 25000);
	threadFunc2(25001, 50000);

	//Threaded Methods, pass the function to the thread.
	//thread funcTest1(threadFunc1, 1, 25000);
	//thread funcTest2(threadFunc2, 25001, 50000);
	//funcTest1.join(); // wait for thread to finish
	//funcTest2.join(); //these join functions executes the thread.

	end = clock();

	double totaltime = (end - start) / double(CLOCKS_PER_SEC);
	cout << "Total time taken " << totaltime;
	cout << endl << CLOCKS_PER_SEC;


	//MULTITHREADING WITH CLASSES
	test obj;
	thread th1(&test::threadFunc3, &obj, 1, 50); //Thread object

	thread th2(&test::threadFunc3, &obj, 50, 100); 
	th1.join();
	th2.join();

	//MULTITHREADING WITH LAMBDA FUNCTION
	thread t1([] {std::cout << "Vedinesh"; });
	thread t1([] {std::cout << " Academ"; });

	return 0;
}



/* clock_t clock(void) returns the number of clock ticks
   elapsed since the program was launched.

   To get the number of seconds used by the CPU,
   we have to divide by CLOCKS_PER_SEC,
   where CLOCKS_PER_SEC is 1000 for my 64 bit  */


   //pass a function to thread
	   //thread funcTest1(threadFunc1, 1, 25000);
	   //thread funcTest2(threadFunc2, 25001, 50000);
	   //funcTest1.join(); // wait for thread to finish
	   //funcTest2.join();



