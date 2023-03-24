import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.Scanner;
import java.util.concurrent.TimeUnit;

import static java.lang.Math.pow;

public class Controller{
    static char a;
    static int b;
    static long c;
    static float d;
    static double e;

    public Controller() {
        BenchmarkInterface view = new BenchmarkInterface();
        view.getMemAllocStaticBtn().addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String pattern = "#.############";
                DecimalFormat numberFormat = new DecimalFormat(pattern);

                /** Static Allocation **/
                double aloc_static_start = System.nanoTime();
                for(int i = 0; i < 1000000; i++) {
                    char f;
                    int g;
                    long h;
                    float j;
                    double k;
                }
                double aloc_static_end = System.nanoTime();
                double val = (aloc_static_end - aloc_static_start) / pow(10, 15);
                System.out.println("Static allocation:  " + numberFormat.format(val));
                view.setMemAllocStaticJava(String.valueOf(numberFormat.format(val)));

                try {
                    Process p = Runtime.getRuntime().exec("allocStaticC.exe");
                } catch (IOException ex) {
                    ex.printStackTrace();
                    System.out.println("Could not run exe.");
                }

                try {
                    TimeUnit.SECONDS.sleep(1);
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }

                try {
                    File fp = new File("allocStaticC.txt");
                    Scanner myReader = new Scanner(fp);
                    while (myReader.hasNextLine()) {
                        String data = myReader.nextLine();
                        view.setMemAllocStaticC(String.valueOf(data));
                    }
                    myReader.close();
                } catch (FileNotFoundException e2) {
                    System.out.println("File not found.");
                    e2.printStackTrace();
                }

                try {
                    Process p = Runtime.getRuntime().exec("allocStaticCPP.exe");
                } catch (Exception ex) {
                    ex.printStackTrace();
                    System.out.println("Could not run exe.");
                }

                try {
                    TimeUnit.SECONDS.sleep(1);
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }

                try {
                    File fp = new File("allocStaticCPP.txt");
                    Scanner myReader = new Scanner(fp);
                    while (myReader.hasNextLine()) {
                        String data = myReader.nextLine();
                        view.setMemAllocStaticCPP(String.valueOf(data));
                    }
                    myReader.close();
                } catch (FileNotFoundException e2) {
                    System.out.println("File not found.");
                    e2.printStackTrace();
                }
            }
        });

        view.getMemAllocDynBtn().addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String pattern = "#.############";
                DecimalFormat numberFormat = new DecimalFormat(pattern);

                /** Dynamic Allocation **/
                double aloc_dynamic_start = System.nanoTime();
                for(int i = 0; i < 1000000; i++) {
                    Benchmark obj = new Benchmark();
                }
                double aloc_dynamic_end = System.nanoTime();
                double val = (aloc_dynamic_end - aloc_dynamic_start) / pow(10, 15);
                System.out.println("Dynamic allocation: " + numberFormat.format(val));
                view.setMemAllocDynJava(String.valueOf(numberFormat.format(val)));

                try {
                    Process p = Runtime.getRuntime().exec("allocDynamicC.exe");
                } catch (IOException ex) {
                    ex.printStackTrace();
                    System.out.println("Could not run exe.");
                }

                try {
                    TimeUnit.SECONDS.sleep(1);
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }

                try {
                    File fp = new File("allocDynamicC.txt");
                    Scanner myReader = new Scanner(fp);
                    while (myReader.hasNextLine()) {
                        String data = myReader.nextLine();
                        view.setMemAllocDynC(String.valueOf(data));
                    }
                    myReader.close();
                } catch (FileNotFoundException e2) {
                    System.out.println("File not found.");
                    e2.printStackTrace();
                }

                try {
                    Process p = Runtime.getRuntime().exec("allocDynamicCPP.exe");
                } catch (IOException ex) {
                    ex.printStackTrace();
                    System.out.println("Could not run exe.");
                }

                try {
                    TimeUnit.SECONDS.sleep(1);
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }

                try {
                    File fp = new File("allocDynamicCPP.txt");
                    Scanner myReader = new Scanner(fp);
                    while (myReader.hasNextLine()) {
                        String data = myReader.nextLine();
                        view.setMemAllocDynCPP(String.valueOf(data));
                    }
                    myReader.close();
                } catch (FileNotFoundException e2) {
                    System.out.println("File not found.");
                    e2.printStackTrace();
                }
            }
        });

        view.getMemAccStaticBtn().addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String pattern = "#.############";
                DecimalFormat numberFormat = new DecimalFormat(pattern);

                /** Static Access **/
                char f, l = 'a';
                int g, m = 10;
                long h, n = 10;
                float j, o = 10;
                double k, p = 10;
                double access_static_start = System.nanoTime();
                for(int i = 0; i < 1000000; i++) {
                    f = l;
                    g = m;
                    h = n;
                    j = o;
                    k = p;
                }
                double access_static_end = System.nanoTime();
                double val = (access_static_end - access_static_start) / pow(10, 15);
                System.out.println("Static Access:      " + numberFormat.format(val));
                view.setMemAccStaticJava(String.valueOf(numberFormat.format(val)));

                try {
                    Process proc = Runtime.getRuntime().exec("accStaticC.exe");
                } catch (IOException ex) {
                    ex.printStackTrace();
                    System.out.println("Could not run exe.");
                }

                try {
                    TimeUnit.SECONDS.sleep(1);
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }

                try {
                    File fp = new File("accessStaticC.txt");
                    Scanner myReader = new Scanner(fp);
                    while (myReader.hasNextLine()) {
                        String data = myReader.nextLine();
                        view.setMemAccStaticC(String.valueOf(data));
                    }
                    myReader.close();
                } catch (FileNotFoundException e2) {
                    System.out.println("File not found.");
                    e2.printStackTrace();
                }

                try {
                    Process proc = Runtime.getRuntime().exec("accStaticCPP.exe");
                } catch (IOException ex) {
                    ex.printStackTrace();
                    System.out.println("Could not run exe.");
                }

                try {
                    TimeUnit.SECONDS.sleep(1);
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }

                try {
                    File fp = new File("accessStaticCPP.txt");
                    Scanner myReader = new Scanner(fp);
                    while (myReader.hasNextLine()) {
                        String data = myReader.nextLine();
                        view.setMemAccStaticCPP(String.valueOf(data));
                    }
                    myReader.close();
                } catch (FileNotFoundException e2) {
                    System.out.println("File not found.");
                    e2.printStackTrace();
                }
            }
        });

        view.getMemAccDynBtn().addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String pattern = "#.############";
                DecimalFormat numberFormat = new DecimalFormat(pattern);

                /** Dynamic Access **/
                char f;
                int g;
                long h;
                float j;
                double access_dynamic_start = System.nanoTime();
                for(int i = 0; i < 1000000; i++) {
                    f = a;
                    g = b;
                    h = c;
                    j = d;
                }
                double access_dynamic_end = System.nanoTime();

                double val = (access_dynamic_end - access_dynamic_start) / pow(10, 15);
                System.out.println("Dynamic Access:     " + numberFormat.format(val));
                view.setMemAccDynJava(String.valueOf(numberFormat.format(val)));

                try {
                    Process proc = Runtime.getRuntime().exec("accDynamicC.exe");
                } catch (IOException ex) {
                    ex.printStackTrace();
                    System.out.println("Could not run exe.");
                }

                try {
                    TimeUnit.SECONDS.sleep(1);
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }

                try {
                    File fp = new File("accessDynamicC.txt");
                    Scanner myReader = new Scanner(fp);
                    while (myReader.hasNextLine()) {
                        String data = myReader.nextLine();
                        view.setMemAccDynC(String.valueOf(data));
                    }
                    myReader.close();
                } catch (FileNotFoundException e2) {
                    System.out.println("File not found.");
                    e2.printStackTrace();
                }

                try {
                    Process p = Runtime.getRuntime().exec("accDynamicCPP.exe");
                } catch (IOException ex) {
                    ex.printStackTrace();
                    System.out.println("Could not run exe.");
                }

                try {
                    TimeUnit.SECONDS.sleep(1);
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }

                try {
                    File fp = new File("accessDynamicCPP.txt");
                    Scanner myReader = new Scanner(fp);
                    while (myReader.hasNextLine()) {
                        String data = myReader.nextLine();
                        view.setMemAccDynCPP(String.valueOf(data));
                    }
                    myReader.close();
                } catch (FileNotFoundException e2) {
                    System.out.println("File not found.");
                    e2.printStackTrace();
                }
            }
        });

        view.getThreadCreateBtn().addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String pattern = "#.############";
                DecimalFormat numberFormat = new DecimalFormat(pattern);

                /** Thread Creation **/
                double thread_creation_start = System.nanoTime();
                for(int i = 0; i < 10000; i++) {
                    Thread t1= new Thread("Thread1");
                    Thread t2= new Thread("Thread2");
                    Thread t3= new Thread("Thread3");
                    Thread t4= new Thread("Thread4");
                    Thread t5= new Thread("Thread5");
                }
                double thread_creation_end = System.nanoTime();
                double val = (thread_creation_end - thread_creation_start) / pow(10, 13);
                System.out.println("Thread Creation:    " + numberFormat.format(val));
                view.setThreadCreateJava(String.valueOf(numberFormat.format(val)));

                try {
                    Process proc = Runtime.getRuntime().exec("threadCreateC.exe");
                } catch (Exception ex) {
                    ex.printStackTrace();
                    System.out.println("Could not run exe.");
                }

                try {
                    TimeUnit.SECONDS.sleep(1);
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }

                try {
                    File fp = new File("threadCreateC.txt");
                    Scanner myReader = new Scanner(fp);
                    while (myReader.hasNextLine()) {
                        String data = myReader.nextLine();
                        view.setThreadCreateC(String.valueOf(data));
                    }
                    myReader.close();
                } catch (FileNotFoundException e2) {
                    System.out.println("File not found.");
                    e2.printStackTrace();
                }

                try {
                    Process proc = Runtime.getRuntime().exec("threadCreateCPP.exe");
                } catch (Exception ex) {
                    ex.printStackTrace();
                    System.out.println("Could not run exe.");
                }

                try {
                    TimeUnit.SECONDS.sleep(1);
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }

                try {
                    File fp = new File("threadCreateCPP.txt");
                    Scanner myReader = new Scanner(fp);
                    while (myReader.hasNextLine()) {
                        String data = myReader.nextLine();
                        view.setThreadCreateCPP(String.valueOf(data));
                    }
                    myReader.close();
                } catch (FileNotFoundException e2) {
                    System.out.println("File not found.");
                    e2.printStackTrace();
                }
            }
        });

        view.getThreadContextBtn().addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String pattern = "#.############";
                DecimalFormat numberFormat = new DecimalFormat(pattern);

                /** Thread Context Switch **/
                double thread_context_start = System.nanoTime();
                for(int i = 0; i < 10000; i++) {
                    try {
                        Thread.sleep(0);
                    } catch (InterruptedException ex) {
                        ex.printStackTrace();
                    }
                }
                double thread_context_end = System.nanoTime();
                double val = (thread_context_end - thread_context_start) / pow(10, 13);
                System.out.println("Thread Creation:    " + numberFormat.format(val));
                view.setThreadContextJava(String.valueOf(numberFormat.format(val)));

                try {
                    Process proc = Runtime.getRuntime().exec("threadContextC.exe");
                } catch (Exception ex) {
                    ex.printStackTrace();
                    System.out.println("Could not run exe.");
                }

                try {
                    TimeUnit.SECONDS.sleep(1);
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }

                try {
                    File fp = new File("threadContextC.txt");
                    Scanner myReader = new Scanner(fp);
                    while (myReader.hasNextLine()) {
                        String data = myReader.nextLine();
                        view.setThreadContextC(String.valueOf(data));
                    }
                    myReader.close();
                } catch (FileNotFoundException e2) {
                    System.out.println("File not found.");
                    e2.printStackTrace();
                }

                try {
                    Process proc = Runtime.getRuntime().exec("threadContextCPP.exe");
                } catch (Exception ex) {
                    ex.printStackTrace();
                    System.out.println("Could not run exe.");
                }

                try {
                    TimeUnit.SECONDS.sleep(1);
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }

                try {
                    File fp = new File("threadContextCPP.txt");
                    Scanner myReader = new Scanner(fp);
                    while (myReader.hasNextLine()) {
                        String data = myReader.nextLine();
                        view.setThreadContextCPP(String.valueOf(data));
                    }
                    myReader.close();
                } catch (FileNotFoundException e2) {
                    System.out.println("File not found.");
                    e2.printStackTrace();
                }
            }
        });

        view.getThreadMigrationBtn().addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                /** Thread Migration **/

                try {
                    Process proc = Runtime.getRuntime().exec("threadMigrationC.exe");
                } catch (Exception ex) {
                    ex.printStackTrace();
                    System.out.println("Could not run exe.");
                }

                try {
                    TimeUnit.SECONDS.sleep(1);
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }

                try {
                    File fp = new File("threadMigrationC.txt");
                    Scanner myReader = new Scanner(fp);
                    while (myReader.hasNextLine()) {
                        String data = myReader.nextLine();
                        view.setThreadMigrationC(String.valueOf(data));
                    }
                    myReader.close();
                } catch (FileNotFoundException e2) {
                    System.out.println("File not found.");
                    e2.printStackTrace();
                }

                try {
                    Process proc = Runtime.getRuntime().exec("threadMigrationCPP.exe");
                } catch (Exception ex) {
                    ex.printStackTrace();
                    System.out.println("Could not run exe.");
                }

                try {
                    TimeUnit.SECONDS.sleep(1);
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }

                try {
                    File fp = new File("threadMigrationCPP.txt");
                    Scanner myReader = new Scanner(fp);
                    while (myReader.hasNextLine()) {
                        String data = myReader.nextLine();
                        view.setThreadMigrationCPP(String.valueOf(data));
                    }
                    myReader.close();
                } catch (FileNotFoundException e2) {
                    System.out.println("File not found.");
                    e2.printStackTrace();
                }
            }
        });

        view.getCeBtn().addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                view.setMemAllocStaticC("");
                view.setMemAllocStaticCPP("");
                view.setMemAllocStaticJava("");

                view.setMemAllocDynC("");
                view.setMemAllocDynCPP("");
                view.setMemAllocDynJava("");

                view.setMemAccStaticC("");
                view.setMemAccStaticCPP("");
                view.setMemAccStaticJava("");

                view.setMemAccDynC("");
                view.setMemAccDynCPP("");
                view.setMemAccDynJava("");

                view.setThreadCreateC("");
                view.setThreadCreateCPP("");
                view.setThreadCreateJava("");

                view.setThreadContextC("");
                view.setThreadContextCPP("");
                view.setThreadContextJava("");

                view.setThreadMigrationC("");
                view.setThreadMigrationCPP("");
            }
        });
    }
}
