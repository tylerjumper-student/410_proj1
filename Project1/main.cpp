/*
 * fileio.cpp
 *
 *  Created on: Sep 16, 2017
 *      Author: keith
 */


#include <iostream>
#include "utilities.h"
//defaults
const char* 		SOURCE_FILE = "TestData.txt";

int main() {
	int total_points = 100; //assumme success
	int iRet = FAIL;

	//load data
	iRet = loadData(SOURCE_FILE);
	if (iRet != SUCCESS){
		total_points =total_points-10;
		std::cout<<"-10 failed to return SUCCESS on correct file"<<std::endl;
	}
	else
		std::cout<<"Success 2"<<std::endl;


	//get the next one in line
	process_stats myStats = getNext();
	if (myStats.process_number!=1 || myStats.start_time !=100 ||myStats.cpu_time !=110 ){
			total_points =total_points-20;
			std::cout<<"-20 failed getnext, expected 1,100,110 got "<<std::to_string(myStats.process_number) <<","<<std::to_string(myStats.start_time)<<","<<std::to_string(myStats.cpu_time)<<std::endl;
		}
		else
			std::cout<<"Success 3"<<std::endl;

	//sort the data
	sortData(START_TIME);


	//get the next one in line
	myStats = getNext();
	if (myStats.process_number!=10 || myStats.start_time !=10 ||myStats.cpu_time !=200 ){
		total_points =total_points-20;
		std::cout<<"-20 failed getnext after sort, expected 10,10,200 got "<<std::to_string(myStats.process_number) <<","<<std::to_string(myStats.start_time)<<","<<std::to_string(myStats.cpu_time)<<std::endl;
	}
	else
		std::cout<<"Success 4"<<std::endl;



	std::cout<<"TOTAL POINTS FOR STUDENT = "<<std::to_string(total_points)<<std::endl;
	return iRet;
}
