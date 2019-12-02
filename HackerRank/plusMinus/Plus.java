import java.io.*;
import java.util.*;

public class Plus{
	public static final boolean DEBUG = false;
	public static void main(String[] args){
		Scanner KB = new Scanner(System.in);
		Double POS, NEG, ZERO;
		POS=NEG=ZERO=0.0;
		int inputSize = KB.nextInt();
		double[] input = new double[inputSize];
		for(int i=0; i<inputSize; i++){
			input[i] = KB.nextDouble();
		}
		for(double i:input){
			if 		(i<0){	NEG++;		if(DEBUG){System.out.print("-");}}
			else if	(i==0){	ZERO++;		if(DEBUG){System.out.print("0");}}
			else if	(i>0){	POS++;		if(DEBUG){System.out.print("+");}}
			else	{		System.out.println("ERROR wr");	}
		}
		System.out.println(POS.intValue() + "/" + inputSize + "\n" + NEG.intValue() +"/" + inputSize + "\n" + ZERO.intValue() + "/" + inputSize);
	}
}
