
import java.util.Arrays;
import java.util.Scanner;
import java.io.*;
import java.nio.charset.Charset;

public class countChar {
	private int[] countAry;
	
	countChar(){																							//constructor to initialize a dynamic array
		countAry = new int[94];
		Arrays.fill(countAry, 0);
	}
	
	public void readChar(File in) throws FileNotFoundException {
		FileInputStream fis = new FileInputStream(in);
		InputStreamReader isr = new InputStreamReader(fis, Charset.forName("UTF-8"));
		BufferedReader readFile = new BufferedReader(isr);
		int x;
		char symbol;
		int index;
		try{
			while((x = readFile.read()) != -1){																//while not the end of the stream
				symbol = (char) x;																			//cast the input to character
				index = ((int) symbol) - 33;																//calculates the corresponding index that records the char's count
				countAry[index]++;																			//increment count
			}
			readFile.close();
		}
		catch(IOException e){
			System.err.println("File Error");
		}
	}
	
	public void printCountAry(FileWriter out){																//prints the count of each character in the input file
		PrintWriter write = new PrintWriter(out);	
		write.println("<<The count of each character used in the input file>>");
		write.println("");
		for(int i=0; i<94; i++){																			//traverses through the dynamic array
			if(countAry[i] != 0){																			//if this character exists
				write.println((char)(i + 33) + "\t" + countAry[i]);											//print it
			}
		}
		write.close();
	}
}
