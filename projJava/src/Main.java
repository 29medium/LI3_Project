import Controller.Interpretador;

import java.io.*;

public class Main implements Serializable{

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        Interpretador i = new Interpretador();
        i.interpretador();
    }
}