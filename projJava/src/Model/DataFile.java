package Model;

import Model.GestVendas;

import java.io.*;

public class DataFile extends IOException implements Serializable {

    public int guardaDados(String fileName, GestVendas load) {
        try {
            FileOutputStream file = new FileOutputStream(fileName);
            ObjectOutputStream oos = new ObjectOutputStream(file);
            oos.writeObject(load);
            oos.flush();
            oos.close();
        }
        catch (FileNotFoundException e) {
            return 1;
        }
        catch (IOException e) {
            return 2;
        }

        return 0;
    }

    public GestVendas carregaDados(String fileName) throws IOException, ClassNotFoundException {
        FileInputStream file = new FileInputStream(fileName);
        ObjectInputStream ois = new ObjectInputStream(file);
        GestVendas sgv = (GestVendas) ois.readObject();
        ois.close();
        return sgv;
    }
}
