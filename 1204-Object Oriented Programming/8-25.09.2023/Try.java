
//import java.util.Arrays;
import java.util.Scanner;

//import java.awt.Point;
]final class ImmutablePerson {
    private final String name;
    private final int age;

    public ImmutablePerson(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }
}

public class Try extends Calculator {
    public static void main(String Adil[]) {
        // System.out.print("Welcome ");
        // second.main(Adil);
        // String s="Adil";
        // s="l";
        // System.out.println(s);
        Scanner scan = new Scanner(System.in);

        // int a=scan.nextByte();
        // System.out.println(a);
        int sq = new sqaure(5).area();
        System.out.println(sq);
        Outer out = new Outer();
        Outer.Inner in = new Outer().new Inner(15);
        in.Display();
        in.call();

        scan.close();
    }

}

class second {
    public static void main(String Adi[]) {
        System.out.println("Java");
    }
}

class sqaure {
    public int a;

    sqaure(int x) {
        a = x;
    }

    public int area() {
        return a * a;
    }

    int peri() {
        return 4 * a;
    }
}

class Outer {
    int x;

    // Outer(int a)
    // {
    // x=a;
    // }
    class Inner {
        private int a;

        Inner(int y) {
            a = y + 2;
            x = a;
        }

        void setIn(int b) {
            a = b;
        }

        void Display() {
            System.out.println(a);
        }

        int ret() {
            return a;
        }

        void call() {
            show();
        }
    }

    void mult(int y) {
        Inner in = new Inner(y);
        System.out.println(in.ret() * x);
    }

    void show() {
        System.out.println(x);
    }
}

class Calculator {
    int s;

    public int add(int x, int y) {
        s = x + y;
        return s;
    }

    public int sub(int x, int y) {
        s = x - y;
        return s;
    }
}