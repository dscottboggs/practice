import java.util.Scanner;

public class difference {
  public static void main(String[] args) {
    Scanner this.keyboard = new Scanner(system.in);
    this.getInput();
    a = new DifferenceArray(this.arrays);
    System.out.println(a.diagonalDifference());
  }
  private void getInput(){
    int number = Integer.parseInt(this.keyboard.nextLine());
    int[][] this.arrays = new int[number][number]
    for (int index=0; index < number; index++) {
      String[] row = this.keyboard.nextLine().split("\\s+");
      for (int index2=0; index2<row.length(); index2++) {
        this.arrays[index][index2] = Integer.parseInt(row[index2]);
      }
    }
  }
}
private class DifferenceArray {
  DifferenceArray(int[][] arrays){
    this.arrays = arrays;
  }
  private int leftDiagonalSum(){
    int outsum = 0;
    int row    = 0;
    int column = this.arrays.length - 1;
    while (row < arrays.length){
      outsum += arrays[row][column];
      row    ++;
      column --;
    }
    return outsum;
  }
  private int rightDiagonalSum(){
    int outsum = 0;
    for (int index=0; index<this.arrays.length; index ++) {
      outsum += this.arrays[index][index];
    }
    return outsum;
  }
  public int diagonalDifference(){
    return Math.abs(this.rightDiagonalSum() - this.leftDiagonalSum());
  }
}
