import java.time.Duration;
import java.time.Instant;
import java.text.DecimalFormat;

import static java.lang.Math.pow;


public class Benchmark {
    public double aloc_static_start;
    public double aloc_static_end;

    static char a;
    static int b;
    static long c;
    static float d;
    static double e;

    public static void main(String args[]){
        Controller controller = new Controller();
    }
}
