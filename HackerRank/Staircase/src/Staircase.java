import java.io.*;
import java.util.*;

public class Staircase {
	public static final boolean DEBUG = false;
    public Scanner KB = new Scanner(System.in);
    public static void main(String[] args) {
        if(args.length>0){
			Staircase a = new Staircase(Integer.parseInt(args[0]));
		}
		else{
			Staircase a = new Staircase();
		}
    }
    public Staircase(){
        int input = getInput();
        printStaircaseOfSize(input);
	}
	public Staircase(Integer input){
		printStaircaseOfSize(input);
	}
    public void printStaircaseOfSize(int in){
		for(int row = 0; row < in; row++){
            int col = 0;
            while(col < (in-row-1)){
				//if(DEBUG){System.out.print(" " + col);}
				if(!DEBUG){System.out.print(" ");}
				col ++;
			}
			while(col >= (in - row-1) && col < in){
				//if(DEBUG){System.out.print(" " + col);}
				if(!DEBUG){System.out.print("#");}
				col++;
			}
			System.out.println("");
        }
    }
    public int getInput(){
        int input = KB.nextInt();
        return input;
    }
}
