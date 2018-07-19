//Cs323 - Project#5: String Extraction & Characters Counting - Xiaomin Chen

#include<iostream>
#include<fstream>
using namespace std;

class countArray{
	private:
		int *countAry;																								//stores the count of each character
	
	public:
		countArray(){
			countAry = new int[94]();																				//there are 94 printable characters
		}
		void readChar(ifstream& in){																				//reads the extracted input file and count the number of chars
			char symbol;
			int index;
			while(in.get(symbol)){																					//while there are still character		
				index = ((int) symbol) - 33;																		//cast the character and get the ascii code
				countAry[index]++;																					//the first printable ascii code starts at 33
			}
		}
		void printCountAry(ofstream& out){																			//prints the count of each char into an output file
			out<<"<<The count of each character used in the input file>>"<<endl<<endl;
			for(int i=0; i<94; i++){																				//traverses through the array
				if(countAry[i] != 0){																				//only print if character exists
					out <<(char) (i+33) << "\t" <<countAry[i]<<endl;
				}
			}
		}
};

void stringExtraction(ifstream& in, ofstream& out){																	//reads the input file and reprint without spaces and non-printable characters
	string word;
	while(!in.eof()){																								//while not the end of the input file
		in >> word;																									//reads one word
		out << word;																								//writes one word
	}
}

int main(int argc, char** argv){
	ifstream inFile1;																								//to read the input file
	ofstream outFile1;																								//to write into output file #1
	ifstream inFile2;																								//to read outfile file
	ofstream outFile2;																								//to write into output file #2
	inFile1.open(argv[1]);																							//opens input file 
	outFile1.open(argv[2]);																							//opens output file #1
	countArray character;																							//declares class to count characters
	
	//check the number of arguments
	if (argc != 4) {																								//error from invalid number of arguments
        cerr << "Error: Number of arguments unsatisfied."<<endl;
        exit(1);
    }
    
    inFile1.seekg(0, std::ios::end);																				//first check if file is empty
	if (inFile1.tellg() == 0){
		cerr << "File is empty." << endl;
		exit(1);
	}
	inFile1.seekg(0, inFile1.beg);																					//returns to the beginning of the input file
	
	stringExtraction(inFile1, outFile1);																			//perform string extraction and write into output file #1
	outFile1.close();																								//close the output file #1 so it can be read afterward
	inFile2.open(argv[2]);																							//opens output file #1
	outFile2.open(argv[3]);																							//opens output file #2
	character.readChar(inFile2);																					//reads and count each character in the string extraction file
	character.printCountAry(outFile2);																				//print the result into an output file

	inFile1.close();																								//close the input file
	inFile2.close();																								//close the second input file
	outFile2.close();																								//close the output file #2
}
