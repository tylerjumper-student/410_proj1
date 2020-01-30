//	 /* fileio.cpp
//	 *
//	 *  Created on: Jan, 2020
//	 *      Author: Jumper
//	 */
//
//	//============================================================================
//	// Name        : Proj1_410.cpp
//	// Author      :
//	// Version     :
//	// Copyright   : Your copyright notice
//	//============================================================================
//
//	#include <iostream>
//	#include "utilities.h"
//	//defaults
//	const char* 		SOURCE_FILE = "TestData.txt";
//	const char* 		SOURCE_FILE2 = "TestData2.txt";
//	const char* 		BOGUS_FILE = "BOGUS.txt";
//	const char*		 	RESULTS_FILE = "results.txt";
//	const char*		 	RESULTS_FILE2 = "results2.txt";
//
//	using namespace std;
//
//	int main() {
//		int total_points = 100; //assumme success
//		int iRet = FAIL;
//
//		//verify return COULD_NOT_OPEN_FILE
//		iRet = loadData(BOGUS_FILE);
//		if (iRet != COULD_NOT_OPEN_FILE){
//			total_points =total_points-10;
//			cout<<"-10 failed to return COULD_NOT_OPEN_FILE on bogus file"<<endl;
//		}
//		else
//			cout<<"Success 1"<<endl;
//
//		//load data
//		iRet = loadData(SOURCE_FILE);
//		if (iRet != SUCCESS){
//			total_points =total_points-10;
//			cout<<"-10 failed to return SUCCESS on correct file"<<endl;
//		}
//		else
//			cout<<"Success 2"<<endl;
//
//		iRet = loadData(SOURCE_FILE2);
//				if (iRet != SUCCESS){
//					total_points =total_points-10;
//					cout<<"-10 failed to return SUCCESS on correct file"<<endl;
//				}
//				else
//					cout<<"Success 2.1"<<endl;
//
//
//		//get the next one in line1
//		process_stats myStats = getNext();
//		if (myStats.process_number!=2 || myStats.start_time !=90 ||myStats.cpu_time !=300 ){
//				total_points =total_points-20;
//				cout<<"-20 failed getnext, expected 1,100,110 got "<<std::to_string(myStats.process_number) <<","<<std::to_string(myStats.start_time)<<","<<std::to_string(myStats.cpu_time)<<endl;
//			}
//			else
//			cout<<"Success 3"<<endl;
//
//		//sort the data
//		sortData(START_TIME);
//
//		//get the next one in line
//		myStats = getNext();
//		myStats = getNext();
//		myStats = getNext();
//		myStats = getNext();
//		myStats = getNext();
//		myStats = getNext();
//		myStats = getNext();
//		myStats = getNext();
//		myStats = getNext();
//		myStats = getNext();
//		myStats = getNext();
//		myStats = getNext();
//		myStats = getNext();
//		myStats = getNext();
//		myStats = getNext(); //returns the process_data in the 16th spot
//		if (myStats.process_number!=19 || myStats.start_time !=80 ||myStats.cpu_time !=500 ){
//			total_points =total_points-20;
//			cout<<"-20 failed getnext after sort, expected 10,10,200 got "<<std::to_string(myStats.process_number) <<","<<std::to_string(myStats.start_time)<<","<<std::to_string(myStats.cpu_time)<<endl;
//		}
//		else
//			cout<<"Success 4"<<endl;
//
//
//		//save remains
//		iRet = saveData(RESULTS_FILE);
//		if (iRet != SUCCESS){
//			total_points =total_points-10;
//			cout<<"-10 failed to return SUCCESS when saving data"<<endl;
//		}
//		else
//			cout<<"Success 1"<<endl;
//
//		iRet = saveData(RESULTS_FILE2);
//				if (iRet != SUCCESS){
//					total_points =total_points-10;
//					cout<<"-10 failed to return SUCCESS when saving data"<<endl;
//				}
//				else
//					cout<<"Success 1.1"<<endl;
//
//		cout<<"TOTAL POINTS FOR STUDENT = "<<std::to_string(total_points)<<endl;
//		return iRet;
//	}
