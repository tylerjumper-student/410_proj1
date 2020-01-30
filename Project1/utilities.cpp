/*
* utilities.cpp
*
*  Created on: Jan, 23 2020
*      Author: Jumper
*
*  Changelog
*  9/17/17 sort - clarified meaning - low to high
*          loadData - clarified behaviour - clears vector on load
*          saveData - clarified behaviour - overwrite file contents
*/
//#include <iostream>
#include<fstream>
#include <vector>
#include <iostream>
#include "utilities.h"


std::vector<process_stats> myVector;


//returns SUCCESS if all goes well or COULD_NOT_OPEN_FILE
int loadData(const char* filename){
	myVector.clear();

	std::ifstream inFile;
	inFile.open(filename);

	if(!inFile.is_open()){
		return COULD_NOT_OPEN_FILE;
	}

	//parse its rows
	while(inFile){
		process_stats tmp;
		std::string string_processNumber;
		std::string string_startTime;
		std::string string_cpuTime;

		//get each part from the text file and assign it to a string
		std::getline(inFile, string_processNumber, ',');
		std::getline(inFile, string_startTime, ',');
		std::getline(inFile, string_cpuTime, '\n');

		if(!inFile){
			break;
		}

		//turn string into an int and assign it to process_stats
		tmp.process_number = stoi(string_processNumber);
		tmp.start_time = stoi(string_startTime);
		tmp.cpu_time = stoi(string_cpuTime);

		//push process_stat object into the vector
		myVector.push_back(tmp);
	}

	//and add these structs to a vector

	inFile.close();
	return SUCCESS;
}

//attempt to open file 'filename' to write, and serialize a
//vector full of process_stats structs to it.  Should be in the same
//format as original file but not necessarily the same order or length
//if the file exists, overwrite its contents.
//returns SUCCESS if all goes well or COULD_NOT_OPEN_FILE
int saveData(const char* filename){
	std::ofstream outFile;
	outFile.open(filename);

	if(!outFile.is_open()){
			return COULD_NOT_OPEN_FILE;
		}
	if(!outFile.good()){
		outFile.clear();
	}
	//write to filename
	for(int i = 0 ; i < int(myVector.size()) ; i++){
		outFile<<myVector[i].process_number<<","<<myVector[i].start_time<<","<<myVector[i].cpu_time<<std::endl;
	}

	outFile.close();
	return SUCCESS;
}

//sorts the vector, returns nothing (thats what void means)
//sorts low to high
void sortData(SORT_ORDER mySortOrder){

	for(int i = 0 ; i < int(myVector.size())-1 ; i++){
		for(int j = 0 ; j <int(myVector.size())-i-1 ; j++){
			if(myVector[j].cpu_time > myVector[j+1].cpu_time){
			process_stats tmp = myVector[j];
			myVector[j] = myVector[j+1];
			myVector[j+1] = tmp;
			}
		}
	}
}

//return the first struct in the vector
//then deletes it from the vector
process_stats getNext(){
	process_stats tmp = myVector[0];
	//delete first process_stats obj in vector
	myVector.erase(myVector.begin());
	return tmp;
}
