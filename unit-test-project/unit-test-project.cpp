#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_8/processing.h"
#include "../Lab_8/conference.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace unittestproject
{
	TEST_CLASS(unittestproject)
	{
	public:
		
		TEST_METHOD(Test_Data) // обычный
		{
			vector <CONFERENCE> reports;
			CONFERENCE r1;
			r1.start = "09:00";
			r1.end = "09:20";
			r1.surname = "Иванов";
			reports.push_back(r1);

			CONFERENCE r2;
			r1.start = "10:00";
			r1.end = "10:40";
			r1.surname = "Петров";
			reports.push_back(r2);
			
			int result = process(reports);
			Assert::AreEqual(40, result);
		}
		TEST_METHOD(Test_Empty) { // пустой 
			vector <CONFERENCE> reports;
			int result = process(reports);
			Assert::AreEqual(0, result);
		}
		TEST_METHOD(Test_Equal) { // для одинаковых значений
			vector <CONFERENCE> reports;
			CONFERENCE r1;
			r1.start = "09:00";
			r1.end = "09:20";
			r1.surname = "Иванов";
			reports.push_back(r1);

			CONFERENCE r2;
			r1.start = "10:00";
			r1.end = "10:20";
			r1.surname = "Петров";
			reports.push_back(r2);

			int result = process(reports);
			Assert::AreEqual(20, result);
		}
	};
}
