

import java.util.Scanner;

public class p04 {

 public static void main(String[] args) {
  int b;
  int[][][][][][] a = new int[1][2][1][1][2][1];
  
  b = 1-3+2*5/4;
  a[0][1][0][0][1][0] = b;
  a[0][0][0][0][0][0] = b+1;
  a[0][1][0][0][0][0] = b+2;
  a[0][0][0][0][1][0] = b+3;

  System.out.println(b);  
  System.out.println(a[0][1][0][0][1][0]+a[0][0][0][0][0][0]+a[0][1][0][0][0][0]+a[0][0][0][0][1][0]);
 }
}

