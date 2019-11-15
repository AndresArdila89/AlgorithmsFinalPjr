#pragma once
#include <iostream>
#include <string>
using namespace std;
//---------------------------------------------------------//
//-------------------- ESSENTIAL --------------------------//
//---------------------------------------------------------//
void DisplayTitle(string title) {
	short strlenght;
	char line = '-';
	strlenght = title.length();


	for (short i = 0; i < strlenght; i++)
	{
		title[i] = toupper(title[i]);
	}
	cout << "\t\t" << title << "\n";
	cout << "\t\t";
	for (short i = 0; i < strlenght; i++)
	{
		cout << line;
	}
	cout << endl;
}

string ReadString(string label) {

	string text;
	do
	{
		cout << label;
		getline(cin, text);

	} while (text == "");

	return text;
}

char ReadCharacter(string label) {

	string text;
	char oneCharacter;
	do
	{
		cout << label;
		getline(cin, text);

	} while (text == "" || text.length()>1);

	oneCharacter = text[0];

	return oneCharacter;
}

void Display(string text, float value) {
	cout << text << value << endl;
}



//---------------------------------------------------------//
//------------------ Revenue quebec -----------------------//
//---------------------------------------------------------//


char ReadCharNdValidate(string label, char conditionOne, char conditionTwo) {

	char value;

	do
	{
		value = ReadCharacter(label);
		value = tolower(value);

	} while (value != conditionOne && value != conditionTwo);
	

	return value;
}

short ReadNBChildern(string label) {

	short NBChilder;
	
	do
	{
		NBChilder = stoi(ReadString(label));

	} while (NBChilder < 0 || NBChilder > 10);

	return NBChilder;

}


short ReadNdAssignDeduction(char condition, short deductionOne, short deductionTwo, char value ) {

	short deduction;
	

	deduction = ((value == condition) ? deductionOne : deductionTwo);

	return deduction;
}



float CalculateDeduction(float salary, short genPercent, short statusPercent, short NBChildren) {
	
	float deduction;

	if (genPercent == 30 && statusPercent == 20) {

		deduction = (genPercent + statusPercent)*0.01;
		cout << "this is the deduction: " << deduction << endl;
		
	}
	else {
		deduction = (NBChildren * -0.01) + (genPercent + statusPercent)*0.01;
	}

	deduction = salary * deduction;
	
	return deduction;
}

float CalculateRevenue(float salary, float deduction) {

	return salary - deduction;
}


void displayInfo(char gender, string name, float salary, float deduction, float revenue) {
	

	cout << ((gender == 'm')? "sir":"miss") << ", " << name << endl;

	Display("Your salary is ", salary);
	Display("Your deduction is ", deduction);
	Display("Your revenue is ", revenue);

}











//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
short ReadNBStudents(string parameter1, short min, short max) {
	short NBStudents;
	do
	{

		NBStudents = stoi(ReadString(parameter1));

	} while (NBStudents > max || NBStudents < min);
	
	return NBStudents;
}

string ReadName(string label, short counter) {
	string name;
	cout << "Student " << counter+1 << ": \n";
	name = ReadString(label);
	return name;
}

short ReadYearOfBirth(string label) {
	short yearOfBirth;

	yearOfBirth = stoi(ReadString(label));

	return yearOfBirth;
}

void ReadStudents(string tabNames[], short tabYearOfBirth[], short NBStudents) {
	for (short i = 0; i < NBStudents; i++) {
		tabNames[i] = ReadName("Name: ", i);
		tabYearOfBirth[i] = ReadYearOfBirth("Year of birth: ");
	}

}

void calculateAge(short NBStudents, short yearOfBirth[], short age[]) {
	
	for (short i = 0; i < NBStudents; i++)
	{
		age[i] = 2019 - yearOfBirth[i];
	}

}



void organizeStudents(short NBStudents, short age[], short year[], string name[])
{
	short tabTemp[25],tempStore;
	short ageTemp,yearTemp;
	string nameTemp;

	for (short i = 0; i < NBStudents; i++)
	{
		for (short j = i+1; j < NBStudents; j++)
		{
			if (age[i] < age[j])
			{
				ageTemp = age[i];
				age[i] = age[j];
				age[j] = ageTemp;

				nameTemp = name[i];
				name[i] = name[j];
				name[j] = nameTemp;

				yearTemp = year[i];
				year[i] = year[j];
				year[j] = yearTemp;

			}
		}
	}

	

}

void DisplayOldStudents(short NBStudents, short age[], short year[], string name[]) {
	cout << "oldes students \n";

	for (short i = 0; i < NBStudents; i++) {

		if (age[i] == age[0])
		{
			cout << name[i] << " \t " << year[i] << " \t " << age[i] << endl;
		}
	}

	cout << "young students \n";

	for (short i = 0; i < NBStudents; i++) {

		if (age[i] == age[NBStudents - 1])
		{
			cout << name[i] << " \t " << year[i] << " \t " << age[i] << endl;
		}
	}
}


void displayList(short NBStudents, string tabNames[], short tabYearOfBirth[],  short age[]) {
	cout << "students \t Born in \t Age \n";

	for (short i = 0; i < NBStudents; i++)
	{
		cout << tabNames[i] << " \t\t " << tabYearOfBirth[i] << " \t\t " << age[i]<<endl;
	}
}






float ReadOneGrade(string parameter1, float MinRange, float MaxRange, short counter) {
	float grade;
	do
	{
		cout << parameter1 << (counter + 1) << ": ";
		cin >> grade;


	} while (grade < MinRange || grade > MaxRange);

	return grade;
}

void ReadGrade(string parameter1, float Tab[], short nbStudent) {
	for (short i = 0; i < nbStudent; i++) {
		Tab[i] = ReadOneGrade(parameter1, 0, 100, i);
	}
}


void displayGrade(float Tab[],short nbStudents)
{
	cout << "Grade" << "\tResoult \n";
	for (short i = 0; i < nbStudents; i++)
	{
		
		cout << Tab[i]<<((Tab[i] < 60) ? "\tfail" : "\tpass")<<endl;
	}
}

float CalculateAverage(float Tab[], short nbStudents) {
	float average=0;
	for (short i = 0; i < nbStudents; i++)
	{
		average += Tab[i];
	}

	average = average / nbStudents;

	return average;
}



float FindBestGrade(float Tab[], short nbStudent) {
	float best = Tab[0];
	
	for (short i = 0; i < nbStudent; i++)
	{
		if (Tab[i] > best)
			best = Tab[i];
	}

	return best;
}

float FindWorstGrade(float Tab[], short nbStudent) {
	float worst = Tab[0];

	for (short i = 0; i < nbStudent; i++)
	{
		if (Tab[i] < worst)
			worst = Tab[i];
	}
	return worst;

}