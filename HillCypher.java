import java.io.*;
import java.util.*;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextArea;
import javax.swing.JTextField;

import java.awt.*;
import java.awt.event.*;


public class HillCypher extends JFrame implements ActionListener{
    int matrixSize = 2;
    JButton encrypt = new JButton("Encrypt");
    JButton decrypt = new JButton("Decrypt");
    JButton twobytwo = new JButton("2x2");
    JButton threebythree = new JButton("3x3");
    JButton fourbyfour = new JButton("4x4");
    JButton fivebyfive = new JButton("5x5");
    JLabel inputLabel = new JLabel("Enter Input Text : ");
    JLabel outputLabel = new JLabel("Output Text : ");
    JLabel keyLabel = new JLabel("Key : ");
    JLabel Matrix = new JLabel("Key Matrix : ");
    JTextField input = new JTextField();
    JTextField output = new JTextField();
    JTextField key = new JTextField();
    JFrame f  = new JFrame("Hill Cypher Cryptography");
    public HillCypher(){
        
        
        f.setLayout(null);
        f.setSize(500,300);

        encrypt.setBounds(150, 220,100,20);
        decrypt.setBounds(250,220,100,20);
        inputLabel.setBounds(5, 5, 200, 20);
        input.setBounds(5,25,300, 20);
        keyLabel.setBounds(5, 50, 200, 20);
        key.setBounds(5, 80, 300, 20);
        outputLabel.setBounds(5,110,200,20);
        output.setBounds(5,130,300,20);
        Matrix.setBounds(325,10,100,20);
        twobytwo.setBounds(325, 30, 75, 20);
        threebythree.setBounds(325, 55, 75, 20);
        fourbyfour.setBounds(325,80,75,20);
        fivebyfive.setBounds(325, 105, 75, 20);
        

        f.add(input);
        f.add(output);
        f.add(inputLabel);
        f.add(outputLabel);
        f.add(encrypt);
        f.add(decrypt);
        f.add(twobytwo);
        f.add(threebythree);
        f.add(fourbyfour);
        f.add(fivebyfive);
        f.add(Matrix);
        f.add(key);
        f.add(keyLabel);

        encrypt.addActionListener(this);
        decrypt.addActionListener(this);
        twobytwo.addActionListener(this);
        threebythree.addActionListener(this);
        fourbyfour.addActionListener(this);
        fivebyfive.addActionListener(this);



        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setResizable(false);
        f.setVisible(true);
    }
    void encryption(){
        String ip = key.getText();
        int encKeyMatrix[][] = new int[matrixSize][matrixSize];
        int lastIndx = ip.length();
        int remaining = matrixSize - lastIndx%matrixSize;
        //adjust key matrix to square dimensions by adding 'x'
        for(int i=0;i<remaining;i++)
            ip.concat("x");
        int indx = 0;
        for(int i=0;i<matrixSize;i++){
            for(int j=0;j<matrixSize;j++){
                if(ip.charAt(indx)>='A' && ip.charAt(indx)<='Z')
                    encKeyMatrix[i][j] = (int)(ip.charAt(indx++) - 65)%26;
                else 
                    encKeyMatrix[i][j] = (int)(ip.charAt(indx++) - 97)%26;
            }
        }
        //adjust input matrix to square dimensions by adding 'x'
        ip = input.getText();
        lastIndx = ip.length();
        remaining = matrixSize - lastIndx%matrixSize;
        for(int i=0;i<remaining;i++)
            ip.concat("x");


        int ipMatrix[] = new int[matrixSize];
        String cipherText =  new String("");

        //pairing of input text to key dimensions and multiplication and converting to letters
        for(int i=0;i<ip.length();){
           for(int j=0;j<matrixSize;j++){
                if(ip.charAt(i)>='A' && ip.charAt(i)<='Z')
                    ipMatrix[j] = (int)(ip.charAt(i++) - 65)%26;
                else 
                    ipMatrix[j] = (int)(ip.charAt(i++) - 97)%26;
           }
           for(int j=0;j<matrixSize;j++){
                int cipher = 0;
                for(int k=0;k<matrixSize;k++)
                    cipher += ipMatrix[k]*encKeyMatrix[j][k];
                cipherText += (char)(cipher%26 + 65);
           }
        }
        //display output
        output.setText(cipherText);

        
    }
    public void actionPerformed(ActionEvent e){
        if(e.getActionCommand().equals("2x2"))
            matrixSize = 2;
        if(e.getActionCommand().equals("3x3"))
            matrixSize = 3;
        if(e.getActionCommand().equals("4x4"))
            matrixSize = 4;
        if(e.getActionCommand().equals("5x5"))
            matrixSize = 5;
        if(e.getActionCommand().equals("Encrypt"))
            encryption();
    }

    
    public static void main(String[] args) {
        HillCypher app = new HillCypher();

    }
}