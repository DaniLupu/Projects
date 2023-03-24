import javax.swing.JFrame;
import javax.swing.JButton;
import java.awt.Font;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class BenchmarkInterface extends JFrame{
    JTextField memAllocStaticC;
    JTextField memAllocStaticCPP;
    JTextField memAllocStaticJava;
    JTextField memAllocDynC;
    JTextField memAllocDynCPP;
    JTextField memAllocDynJava;
    JTextField memAccStaticC;
    JTextField memAccStaticCPP;
    JTextField memAccStaticJava;
    JTextField memAccDynC;
    JTextField memAccDynCPP;
    JTextField memAccDynJava;
    JTextField threadCreateC;
    JTextField threadCreateCPP;
    JTextField threadCreateJava;
    JTextField threadContextC;
    JTextField threadContextCPP;
    JTextField threadContextJava;
    JTextField threadMigrationC;
    JTextField threadMigrationCPP;
    JButton ceBtn;
    JButton memAllocStaticBtn;
    JButton memAllocDynBtn;
    JButton memAccStaticBtn;
    JButton memAccDynBtn;
    JButton threadCreateBtn;
    JButton threadContextBtn;
    JButton threadMigrationBtn;

    public JButton getCeBtn() {
        return ceBtn;
    }

    public JButton getMemAllocStaticBtn() {
        return memAllocStaticBtn;
    }

    public JButton getMemAllocDynBtn() {
        return memAllocDynBtn;
    }

    public JButton getMemAccStaticBtn() {
        return memAccStaticBtn;
    }

    public JButton getMemAccDynBtn() {
        return memAccDynBtn;
    }

    public JButton getThreadCreateBtn() {
        return threadCreateBtn;
    }

    public JButton getThreadContextBtn() {
        return threadContextBtn;
    }

    public JButton getThreadMigrationBtn() {
        return threadMigrationBtn;
    }

    public void setMemAllocStaticC(String s) {
        this.memAllocStaticC.setText(s);
    }

    public void setMemAllocStaticCPP(String s) {
        this.memAllocStaticCPP.setText(s);
    }

    public void setMemAllocStaticJava(String s) {
        this.memAllocStaticJava.setText(s);
    }

    public void setMemAllocDynC(String s) {
        this.memAllocDynC.setText(s);
    }

    public void setMemAllocDynCPP(String s) {
        this.memAllocDynCPP.setText(s);
    }

    public void setMemAllocDynJava(String s) {
        this.memAllocDynJava.setText(s);
    }

    public void setMemAccStaticC(String s) {
        this.memAccStaticC.setText(s);
    }

    public void setMemAccStaticCPP(String s) {
        this.memAccStaticCPP.setText(s);
    }

    public void setMemAccStaticJava(String s) {
        this.memAccStaticJava.setText(s);
    }

    public void setMemAccDynC(String s) {
        this.memAccDynC.setText(s);
    }

    public void setMemAccDynCPP(String s) {
        this.memAccDynCPP.setText(s);
    }

    public void setMemAccDynJava(String s) {
        this.memAccDynJava.setText(s);
    }

    public void setThreadCreateC(String s) {
        this.threadCreateC.setText(s);
    }

    public void setThreadCreateCPP(String s) {
        this.threadCreateCPP.setText(s);
    }

    public void setThreadCreateJava(String s) {
        this.threadCreateJava.setText(s);
    }

    public void setThreadContextC(String s) {
        this.threadContextC.setText(s);
    }

    public void setThreadContextCPP(String s) {
        this.threadContextCPP.setText(s);
    }

    public void setThreadContextJava(String s) {
        this.threadContextJava.setText(s);
    }

    public void setThreadMigrationC(String s) {
        this.threadMigrationC.setText(s);
    }

    public void setThreadMigrationCPP(String s) {
        this.threadMigrationCPP.setText(s);
    }


    public BenchmarkInterface() {
        getContentPane().setLayout(null);

        JLabel lblNewLabel = new JLabel("Programming Languages");
        lblNewLabel.setFont(new Font("Segoe UI", Font.BOLD, 35));
        lblNewLabel.setBounds(245, 11, 424, 54);
        getContentPane().add(lblNewLabel);

        JLabel lblPerformanceTest = new JLabel("Performance Test");
        lblPerformanceTest.setFont(new Font("Segoe UI", Font.BOLD, 35));
        lblPerformanceTest.setBounds(306, 55, 293, 54);
        getContentPane().add(lblPerformanceTest);

        memAllocStaticBtn = new JButton("Memory Allocation Static");
        memAllocStaticBtn.setFont(new Font("Segoe UI", Font.PLAIN, 18));
        memAllocStaticBtn.setBounds(10, 193, 264, 44);
        getContentPane().add(memAllocStaticBtn);

        memAllocDynBtn = new JButton("Memory Allocation Dynamic");
        memAllocDynBtn.setFont(new Font("Segoe UI", Font.PLAIN, 18));
        memAllocDynBtn.setBounds(10, 248, 264, 44);
        getContentPane().add(memAllocDynBtn);

        memAccStaticBtn = new JButton("Memory Access Static");
        memAccStaticBtn.setFont(new Font("Segoe UI", Font.PLAIN, 18));
        memAccStaticBtn.setBounds(10, 303, 264, 44);
        getContentPane().add(memAccStaticBtn);

        memAccDynBtn = new JButton("Memory Access Dynamic");
        memAccDynBtn.setFont(new Font("Segoe UI", Font.PLAIN, 18));
        memAccDynBtn.setBounds(10, 358, 264, 44);
        getContentPane().add(memAccDynBtn);

        threadCreateBtn = new JButton("Thread Creation");
        threadCreateBtn.setFont(new Font("Segoe UI", Font.PLAIN, 18));
        threadCreateBtn.setBounds(10, 413, 264, 44);
        getContentPane().add(threadCreateBtn);

        threadContextBtn = new JButton("Thread Context Switch");
        threadContextBtn.setFont(new Font("Segoe UI", Font.PLAIN, 18));
        threadContextBtn.setBounds(10, 468, 264, 44);
        getContentPane().add(threadContextBtn);

        threadMigrationBtn = new JButton("Thread Migration");
        threadMigrationBtn.setFont(new Font("Segoe UI", Font.PLAIN, 18));
        threadMigrationBtn.setBounds(10, 523, 264, 44);
        getContentPane().add(threadMigrationBtn);

        memAllocStaticC = new JTextField();
        memAllocStaticC.setBounds(314, 193, 169, 32);
        getContentPane().add(memAllocStaticC);
        memAllocStaticC.setColumns(10);

        memAllocStaticCPP = new JTextField();
        memAllocStaticCPP.setColumns(10);
        memAllocStaticCPP.setBounds(518, 193, 169, 32);
        getContentPane().add(memAllocStaticCPP);

        memAllocStaticJava = new JTextField();
        memAllocStaticJava.setColumns(10);
        memAllocStaticJava.setBounds(722, 193, 169, 32);
        getContentPane().add(memAllocStaticJava);

        JLabel lblNewLabel_1 = new JLabel("C");
        lblNewLabel_1.setFont(new Font("Segoe UI", Font.BOLD, 40));
        lblNewLabel_1.setBounds(384, 144, 31, 38);
        getContentPane().add(lblNewLabel_1);

        JLabel lblNewLabel_1_1 = new JLabel("C++");
        lblNewLabel_1_1.setFont(new Font("Segoe UI", Font.BOLD, 40));
        lblNewLabel_1_1.setBounds(563, 144, 81, 38);
        getContentPane().add(lblNewLabel_1_1);

        JLabel lblNewLabel_1_2 = new JLabel("Java");
        lblNewLabel_1_2.setFont(new Font("Segoe UI", Font.BOLD, 40));
        lblNewLabel_1_2.setBounds(763, 144, 93, 38);
        getContentPane().add(lblNewLabel_1_2);

        memAllocDynC = new JTextField();
        memAllocDynC.setColumns(10);
        memAllocDynC.setBounds(314, 248, 169, 32);
        getContentPane().add(memAllocDynC);

        memAllocDynCPP = new JTextField();
        memAllocDynCPP.setColumns(10);
        memAllocDynCPP.setBounds(518, 248, 169, 32);
        getContentPane().add(memAllocDynCPP);

        memAllocDynJava = new JTextField();
        memAllocDynJava.setColumns(10);
        memAllocDynJava.setBounds(722, 248, 169, 32);
        getContentPane().add(memAllocDynJava);

        memAccStaticC = new JTextField();
        memAccStaticC.setColumns(10);
        memAccStaticC.setBounds(314, 303, 169, 32);
        getContentPane().add(memAccStaticC);

        memAccStaticCPP = new JTextField();
        memAccStaticCPP.setColumns(10);
        memAccStaticCPP.setBounds(518, 303, 169, 32);
        getContentPane().add(memAccStaticCPP);

        memAccStaticJava = new JTextField();
        memAccStaticJava.setColumns(10);
        memAccStaticJava.setBounds(722, 303, 169, 32);
        getContentPane().add(memAccStaticJava);

        memAccDynC = new JTextField();
        memAccDynC.setColumns(10);
        memAccDynC.setBounds(314, 358, 169, 32);
        getContentPane().add(memAccDynC);

        memAccDynCPP = new JTextField();
        memAccDynCPP.setColumns(10);
        memAccDynCPP.setBounds(518, 358, 169, 32);
        getContentPane().add(memAccDynCPP);

        memAccDynJava = new JTextField();
        memAccDynJava.setColumns(10);
        memAccDynJava.setBounds(722, 358, 169, 32);
        getContentPane().add(memAccDynJava);

        threadCreateC = new JTextField();
        threadCreateC.setColumns(10);
        threadCreateC.setBounds(314, 413, 169, 32);
        getContentPane().add(threadCreateC);

        threadCreateCPP = new JTextField();
        threadCreateCPP.setColumns(10);
        threadCreateCPP.setBounds(518, 413, 169, 32);
        getContentPane().add(threadCreateCPP);

        threadCreateJava = new JTextField();
        threadCreateJava.setColumns(10);
        threadCreateJava.setBounds(722, 413, 169, 32);
        getContentPane().add(threadCreateJava);

        threadContextC = new JTextField();
        threadContextC.setColumns(10);
        threadContextC.setBounds(314, 468, 169, 32);
        getContentPane().add(threadContextC);

        threadContextCPP = new JTextField();
        threadContextCPP.setColumns(10);
        threadContextCPP.setBounds(518, 468, 169, 32);
        getContentPane().add(threadContextCPP);

        threadContextJava = new JTextField();
        threadContextJava.setColumns(10);
        threadContextJava.setBounds(722, 468, 169, 32);
        getContentPane().add(threadContextJava);

        threadMigrationC = new JTextField();
        threadMigrationC.setColumns(10);
        threadMigrationC.setBounds(314, 523, 169, 32);
        getContentPane().add(threadMigrationC);

        threadMigrationCPP = new JTextField();
        threadMigrationCPP.setColumns(10);
        threadMigrationCPP.setBounds(518, 523, 169, 32);
        getContentPane().add(threadMigrationCPP);

        ceBtn = new JButton("CE");
        ceBtn.setFont(new Font("Segoe UI", Font.BOLD, 35));
        ceBtn.setBounds(810, 563, 81, 44);
        getContentPane().add(ceBtn);

        this.setSize(920,800);
        this.setVisible(true);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        getContentPane().setLayout(null);

        this.revalidate();
        this.repaint();
    }


}
