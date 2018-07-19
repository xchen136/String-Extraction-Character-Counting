
import java.util.Scanner;
import java.io.*;

public class main {
	public static void main(String [] args)throws FileNotFoundException{
		try{
			File inFile1 = new File(args[0]);																	//gets input file #1
			File inFile2;
			FileWriter outFile1 = new FileWriter(args[1]);														//gets output file #1
			FileWriter outFile2 = new FileWriter(args[2]);
			
			Scanner read = new Scanner(inFile1);																//opens input file #1
			stringExtraction(inFile1, outFile1);																//output the data from the input file without spaces
			inFile2 = new File(args[1]);																		//gets output file #1 as input file #2
			countChar characters = new countChar();																//create a countChar object
			characters.readChar(inFile2);																		//reads and counts the characters in the input file without spaces
			characters.printCountAry(outFile2);																	//print the result into an output file
			read.close();
		}
		catch(IOException e){
			System.err.println("IOException");
		}
	}
	
	public static void stringExtraction(File input, FileWriter output)throws FileNotFoundException {
		String word;																							
		Scanner read = new Scanner(input);
		PrintWriter write = new PrintWriter(output);
		
		while(read.hasNext()){																					//while the are more inputs
			word = read.next();																					//read the input
			write.print(word);																					//output the input
		}
		read.close();
		write.close();
	}
	
}
