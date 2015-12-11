//	Shane Brown
//	CS 6490 - Network Security
//	Project: Lightweight Cryptographic Algorithms Comparison
//	Dec. 3, 2015
//
//	Description:
//	This is meant to drive and test all of the algorithms.
//	It measures the CPU time it takes to execute.
//


#include "Algorithm_RC5.h"
#include "XTea.h"
#include "Simon.h"
#include "Speck.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <string.h>
using namespace std;

//typedef unsigned int WORD; /* Should be 32-bit = 4 bytes        */
#define LOG ".log"
//#define RC5_LOGFILE	"RC5.log"     // RC5 Log File
#define LINE "-----------------------------------------------\n"
#define RC5_Summary "rc5_summary.csv"
#define XTEA_Summary "xtea_summary.csv"
#define SIMON_Summary "simon_summary.csv"
#define SPECK_Summary "speck_summary.csv"

//	Algorithms
#define RC5 "R"
#define XTEA "X"
#define SIMON "SI"
#define SPECK "SP"

void create_header(ofstream *file, const char * header)
{
	if(file->is_open())
	{
		*file << header << "\n";
		*file << LINE;
	}
}

void create_summary_header(ofstream *file, const char * header)
{
	if(file->is_open())
	{
		*file << header << "\n";
		*file << LINE;
	}
}

void create_summary(ofstream *file, double max, double min, double average, int iterations, int plaintext_length)
{
	if(file->is_open())
	{
		*file << LINE;
		*file << "Plaintext legnth = " << plaintext_length << " bytes\n";
		*file << "Number of iterations = " << iterations << "\n";
		*file << "Max Runtime = " << max << " microseconds\n";
		*file << "Min Runtime = " << min << " microseconds\n";
		*file << "Ave Runtime = " << average << " microseconds\n";
		*file << LINE;
	}
}

void create_table_header(ofstream *file)
{
	if(file->is_open())
		*file << "interations,plaintext length(bytes),min(microseconds [us]),max(us),average(us)\n";
}

void create_table_row(ofstream *file, int interations, int plaintextlength_bytes, int min, int max, int ave)
{
	if(file->is_open())
		*file << interations << "," << plaintextlength_bytes << "," << min << "," << max << "," << ave << "\n";
}


int main(int argc, char *argv[])
{

	//	TODO: Add argument for which algorithm to run perhaps?
	if(argc != 4)
	{
		cout << "USAGE: ./driver {number of iterations} {length of plaintext in bytes (8-byte sizes)} {algorithm to run}\n";
		cout << "algorithm to run = " << RC5 << "(RC5), " << XTEA << " (XTea), "<< SIMON <<" (Simon), " << SPECK << "(SPECK)"<<"\n";
		return -1;
	}

	//	User Defined Parameters
    int iterations = stoi(argv[1]);
	int plaintextlength_bytes = stoi(argv[2]);
	const char * algorithm = argv[3];

	int plaintextlength_segments = 1;
	
	//	Current Algorithm
	int IsRc5 = strcmp(algorithm, RC5) == 0 ? 1 : 0;
	int IsXtea = strcmp(algorithm, XTEA) == 0 ? 1 : 0;
	int IsSimon = strcmp(algorithm, SIMON) == 0 ? 1 : 0;
	int IsSpeck = strcmp(algorithm, SPECK) == 0 ? 1 : 0;

	if (plaintextlength_bytes % 8 != 0)
		cout << "USAGE: ./driver {number of iterations} {length of plaintext in bytes (8-byte sizes)}\n";
	else
		plaintextlength_segments = plaintextlength_bytes/8;

	//	Open/Create Files
	ofstream rc5File;
	ofstream rc5SummaryFile;
	ofstream xteaSummaryFile;
	ofstream simonSummaryFile;
	ofstream speckSummaryFile;

	//	RC5_Summary
	if(IsRc5)
	{
		/*
		//	Detailed Log file (Should Remove - It doesn't seem useful)
		const string RC5_LOGFILE = "RC5_" + to_string(iterations) + string("_") + to_string(plaintextlength_bytes) + string(LOG);
		rc5File.open(RC5_LOGFILE);       
		if(rc5File.is_open())
			create_header(&rc5File, "RC5 LOG FILE");
		*/

		//	Summary
		int CreateHeader = 1;
		if(std::ifstream(RC5_Summary))
			CreateHeader = 0;

		rc5SummaryFile.open(RC5_Summary, ios_base::app);

		if(CreateHeader)
			create_table_header(&rc5SummaryFile);
	}

	//XTEA_Summary
	if(IsXtea)
	{
		int CreateHeader = 1;
		if(std::ifstream(XTEA_Summary))
			CreateHeader = 0;

		xteaSummaryFile.open(XTEA_Summary, ios_base::app);

		if(CreateHeader)
			create_table_header(&xteaSummaryFile);
	}

	//SIMON_Summary
	if(IsSimon)
	{
		int CreateHeader = 1;
		if(std::ifstream(SIMON_Summary))
			CreateHeader = 0;

		simonSummaryFile.open(SIMON_Summary, ios_base::app);

		if(CreateHeader)
			create_table_header(&simonSummaryFile);
	}

	
	//SPECK_Summary
	if(IsSpeck)
	{
		int CreateHeader = 1;
		if(std::ifstream(SPECK_Summary))
			CreateHeader = 0;

		speckSummaryFile.open(SPECK_Summary, ios_base::app);

		if(CreateHeader)
			create_table_header(&speckSummaryFile);
	}

	//	Algorithms to be tested
  	Algorithm_RC5 rc5;
	XTea xtea;
	Simon simon;
	Speck speck;
    
    //  Declarations
    chrono::high_resolution_clock::time_point start_time;
    chrono::high_resolution_clock::time_point end_time;
    chrono::duration<long long int, ratio<1ll, 1000000000ll> > time;
    int current_interation = 0;
    double total_time = 0;
    double max_time = 0;
    double min_time = 0;
    double current_duration = 0;
    
	unsigned int PlainText[2] = {0,0};
	const char *keystr = "TheQuickBrownFox";

    while(iterations > current_interation)
    {
        //  Get Start Time
        start_time = chrono::high_resolution_clock::now();

        //////////////////////////////////////////////////////////
        // 	START:  Insert Algorithms to Run Here.  
		//	Within switch-case statement for which one to run
        //////////////////////////////////////////////////////////
		if(IsRc5)
        	rc5.Run(PlainText, keystr, plaintextlength_segments);

        if(IsXtea)
			xtea.Run(PlainText, keystr, plaintextlength_segments);

        if(IsSimon)
			simon.Run(PlainText, keystr, plaintextlength_segments);

        if(IsSpeck)
			speck.Run(PlainText, keystr, plaintextlength_segments);
		//////////////////////////////////////////////////////////
        // 	END
        //////////////////////////////////////////////////////////
        //  Get End Time
        end_time = chrono::high_resolution_clock::now();
        time = end_time - start_time;
        current_duration = chrono::duration_cast<chrono::microseconds>(time).count();

        //  Calculate Timing Stats
        total_time += current_duration;
        if(max_time == 0 || max_time < current_duration)
            max_time = current_duration;
        if(min_time == 0 || min_time > current_duration)
            min_time = current_duration;
        
		/*
		//	Record each interation time
		if(IsRc5)
		{
			if(rc5File.is_open())
        		rc5File << "Runtime (microseconds): " << chrono::duration_cast<chrono::microseconds>(time).count() << "\n";
		}
		*/
        current_interation++;
    }
    
	/*
	//	Write Summary to Log File
	if(IsRc5)
	{
		if(rc5File.is_open())
			create_summary(&rc5File, max_time, min_time, total_time/iterations, iterations, plaintextlength_bytes);
    
		//	Close Files
		if(rc5File.is_open())
			rc5File.close();
	}*/

	if(IsRc5)
	{
		//void create_table_row(ofstream *file, int interations, int plaintextlength_bytes, int min, int max, int ave)
		create_table_row(&rc5SummaryFile,iterations,plaintextlength_bytes,min_time,max_time,total_time/iterations); 
		rc5SummaryFile.close();
	}

	if(IsXtea)
	{
		//void create_table_row(ofstream *file, int interations, int plaintextlength_bytes, int min, int max, int ave)
		create_table_row(&xteaSummaryFile,iterations,plaintextlength_bytes,min_time,max_time,total_time/iterations);
		xteaSummaryFile.close();
	}

	if(IsSimon)
	{
		//void create_table_row(ofstream *file, int interations, int plaintextlength_bytes, int min, int max, int ave)
		create_table_row(&simonSummaryFile,iterations,plaintextlength_bytes,min_time,max_time,total_time/iterations);
		simonSummaryFile.close();
	}

	if(IsSpeck)
	{
		//void create_table_row(ofstream *file, int interations, int plaintextlength_bytes, int min, int max, int ave)
		create_table_row(&speckSummaryFile,iterations,plaintextlength_bytes,min_time,max_time,total_time/iterations);
		speckSummaryFile.close();
	}

  	return 0;
}

