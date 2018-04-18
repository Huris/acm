

//地址:https://www.luogu.org/problemnew/show/P1045
//题意:求2^p-1的位数以及500位的值
//题解:java大发好
//代码:


import java.util.*;
import java.math.*;
public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int aa=cin.nextInt();
        BigInteger a = BigInteger.valueOf(aa);
        BigInteger er = BigInteger.valueOf(2);
        BigInteger mo = BigInteger.valueOf(1);
        BigInteger yi = BigInteger.valueOf(1);
        BigInteger shi = BigInteger.valueOf(10);
        for (int i = 0; i < 500; i++) mo = mo.multiply(shi);
        a = er.modPow(a, mo);
        a = a.subtract(yi);
        a = a.mod(mo);
        a = a.add(mo);
        a = a.mod(mo);
        int i = 0,o=0;
        String s=a.toString();
        double wei=aa*Math.log10(2)+1;
        int ww=(int)wei;
        System.out.println(ww);
        while(s.length()<500-i)
        {
            System.out.print(0);
            i++;
            o++;
            if(o%50==0)System.out.println();
        }
        for(int z=0;z<s.length();z++)
        {
            System.out.print(s.charAt(z));
            o++;
            if(o%50==0)System.out.println();
        }
    }
}

