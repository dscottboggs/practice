import java.io.*;
import java.util.*;

public class PlusMinus {
	public static final boolean DEBUG = true;
	public Scanner KB = new Scanner(System.in);
	public String input;
	public int inputSize;
	public double POS, NEG, ZERO;
	public int debugCounter = 0;
  public static void main(String[] args) {
      PlusMinus a = new PlusMinus();
  }
  public PlusMinus(){
		getInput();
		String[] inputArray = new String[inputSize];
		double[] inputDoubleArray = new double[inputSize];
		for(int i =0; i<inputSize; i++){
			//inputArray[debugCounter] = val;
			//if(DEBUG){{System.out.println(val);}}
			//debugCounter++;
			//if(debugCounter>inputSize){System.out.println("error error");}
			inputDoubleArray[i] = Scanner.nextDouble();
		}

		//for(int i = 0; i<inputSize;i++){
			//if(DEBUG){	System.out.println(i + " " + inputArray[i]);}
			//inputDoubleArray[i] = Double.parseDouble(inputArray[i]);
		//}
		for(double i:inputDoubleArray){
			if 		(i<0){	NEG++;
										if(DEBUG){System.out.print("-");}}
			else if	(i==0){	ZERO++;
										if(DEBUG){System.out.print("0");}}
			else if	(i>0){	POS++;
										if(DEBUG){System.out.print("+");}}
			else	{		System.out.println("ERROR wr");	}
		}
		System.out.println(POS/inputSize);
		System.out.println(ZERO/inputSize);
		System.out.println(NEG/inputSize);
	}
	public void getInput(){
		inputSize = KB.nextInt();
		//input = KB.next();
	}
}
