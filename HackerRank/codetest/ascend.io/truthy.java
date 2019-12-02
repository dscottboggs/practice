class Truthy {
  public static void main(String[] args) {
    if (0) {
      System.out.println("0 was truthy");
    } else {
      System.out.println("0 was falsey");
    }
    if (-1) {
      System.out.println("-1 was truthy");
    } else {
      System.out.println("-1 was falsey");
    }
    if ("") {
      System.out.println("the empty string was truthy");
    } else {
      System.out.println("the empty string was falsey");
    }
    String[] var = null;
    if (var) {
      System.out.println("null was truthy");
    } else {
      System.out.println("an empty array was truthy");
    }
  }
}
