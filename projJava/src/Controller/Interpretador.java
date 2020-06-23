/**
 * Classe com o Controlador do Programa
 */

package Controller;

import Model.DataFile;
import Model.GestVendas;
import Model.ParStringFloat;
import View.Apresentacao;

import java.io.IOException;
import java.io.Serializable;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Interpretador implements Serializable {
    Apresentacao a = new Apresentacao();

    /**
     * Método que recebe input de um Int
     *
     * @param message   String com mensagem a enviar à Apresentação
     * @param min       Inteiro com o limite mínimo
     * @param max       Inteiro com o limite máximo
     * @return          Inteiro lido
     */
    public int lerInt(String message,int min,int max){
        Scanner s = new Scanner(System.in);
        int n = -1;

        do{
            a.printMessage(message);
            try {
                String line = s.nextLine();
                n = Integer.parseInt(line);
            } catch (NumberFormatException nfe) {
                a.printErroLerInt();
            }
        } while (n < min || n > max);

        return n;
    }

    /**
     * Método que lê um código de produto ou cliente
     *
     * @param message   String com mensagem a enviar à Apresentação
     * @param type      Inteiro com o tipo
     * @param sgv       GestVendas
     * @return          String com o código lido
     */
    public String lerString(String message, int type, GestVendas sgv){
        Scanner s = new Scanner(System.in);
        String line;

        do{
            a.printMessage(message);
            line = s.nextLine();
        } while ((type == 0 && (!sgv.cliVal(line) || !sgv.getCatCcontains(line))) ||
                 (type == 1 && (!sgv.prodVal(line) || !sgv.getCatPcontains(line))));

        return line;
    }

    /**
     * Método que recebe input para a execução da querie 10
     *
     * @param sgv   GestVendas
     * @return      String com o tempo de execução
     */
    public String interpretaQ10(GestVendas sgv) {
        boolean r = true;
        int command;
        String prod;

        Crono.start();
        Map<String, float[][]> querie10 = sgv.getQ10();
        String time = Crono.getTime();

        while(r) {
            a.menuQ10();
            command = lerInt(a.pedirNumero(), 0, 1);
            switch (command) {
                case 1:
                    prod = lerString(a.pedirProduto(), 1, sgv);
                    a.printQ10(prod, querie10.get(prod));
                    break;
                case 0:
                    r=false;
                    break;
            }
        }

        return time;
    }

    /**
     * Método que recebe input para a execução das Consultas Interativas
     *
     * @param sgv   GestVendas
     */
    public void consultasIterativas(GestVendas sgv){
        boolean val = true;
        String line,time = "";
        int comand,num;

        while (val){
            a.menuConsultasInterativas();
            comand = lerInt(a.pedirNumero(),0,10);
            switch (comand){
                case 0:
                    val = false;
                    break;
                case 1:
                    Crono.start();
                    List<String> q1 = sgv.getQ1();
                    time = Crono.getTime();
                    a.printQ1(q1, q1.size());
                    break;
                case 2:
                    num = lerInt(a.pedirMes(),1,12);
                    Crono.start();
                    int[] q2 = sgv.getQ2(num - 1);
                    time = Crono.getTime();
                    a.printQ2(q2);
                    break;
                case 3:
                    line = lerString(a.pedirCliente(),0,sgv);
                    Crono.start();
                    Map<Integer, float[]> q3 = sgv.getQ3(line);
                    time = Crono.getTime();
                    a.printQ3(q3);
                    break;
                case 4:
                    line = lerString(a.pedirProduto(),1,sgv);
                    Crono.start();
                    Map<Integer, float[]> q4 = sgv.getQ4(line);
                    time = Crono.getTime();
                    a.printQ4(q4);
                    break;
                case 5:
                    line = lerString(a.pedirCliente(),0,sgv);
                    Crono.start();
                    List<ParStringFloat> q5 = sgv.getQ5(line);
                    time = Crono.getTime();
                    a.printArray(sgv.listParStringFloatToListString(q5,1), 95);
                    break;
                case 6:
                    num = lerInt(a.pedirLimite(),1,1000000);
                    Crono.start();
                    List<ParStringFloat> q6 = sgv.getQ6(num);
                    time = Crono.getTime();
                    a.printArray(sgv.listParStringFloatToListString(q6,0), 94);
                    break;
                case 7:
                    Crono.start();
                    Map<Integer, List<String>> q7 = sgv.getQ7();
                    time = Crono.getTime();
                    a.printQ7(q7);
                    break;
                case 8:
                    num = lerInt(a.pedirLimite(),1,1000000);
                    Crono.start();
                    List<ParStringFloat> q8 = sgv.getQ8(num);
                    time = Crono.getTime();
                    a.printArray(sgv.listParStringFloatToListString(q8,1), 85);
                    break;
                case 9:
                    num = lerInt(a.pedirLimite(),1,1000000);
                    line = lerString(a.pedirProduto(),1,sgv);
                    Crono.start();
                    List<ParStringFloat> q9 = sgv.getQ9(line, num);
                    time = Crono.getTime();
                    a.printArray(sgv.listParStringFloatToListString(q9,0), 91);
                    break;
                case 10:
                    time = interpretaQ10(sgv);
                    break;
            }

            if(comand != 0)
                a.printTime(time, "Querie " + comand);
        }
    }

    /**
     * Método que recebe input para a execução das Consultas Estatísticas
     *
     * @param sgv   GestVendas
     */
    public void consultasEstatisticas(GestVendas sgv){
        boolean val = true;
        int comand;
        int totalProdutos, produtosComprados, totalClientes, clientesCompradores;

        while (val){
            a.menuConsultasEstatisticas();
            comand = lerInt(a.pedirNumero(),0,4);

            switch (comand) {
                case 0:
                    val = false;
                    break;
                case 1:
                    totalProdutos = sgv.getLoadInfoProdValidos();
                    produtosComprados = sgv.getFactComprados();
                    totalClientes = sgv.getLoadInfoCliValidos();
                    clientesCompradores = sgv.getLoadInfoCliComprador();

                    a.printConsultasEstatisticas1(sgv.getLoadInfoSalesPath(), sgv.getLoadInfoVendasInvalidas(), totalProdutos,
                            produtosComprados, totalProdutos - produtosComprados, totalClientes, clientesCompradores, totalClientes - clientesCompradores,
                            sgv.getFactCompras0(), sgv.getFactFaturacaoTotal());
                    break;
                case 2:
                    a.printConsultasEstatisticas2(sgv.getFactComprasMes());
                    break;
                case 3:
                    a.printConsultasEstatisticas3(sgv.getFactFaturacaoMesFil(), 0);
                    break;
                case 4:
                    a.printConsultasEstatisticas3(sgv.getCompradoresMesFil(), 1);
                    break;
            }
        }
    }

    /**
     * Método que recebe input para a execução do programa
     *
     * @throws IOException              devolve um erro de IO (i.e. ficheiro não existir)
     * @throws ClassNotFoundException   devolve um erro se a classe do objeto não for compatível
     */
    public void interpretador() throws IOException, ClassNotFoundException {
        boolean val = true,load = false;
        Scanner scanner = new Scanner(System.in);
        int comand, n,erro = 0;
        String time;
        GestVendas sgv = new GestVendas();
        DataFile data = new DataFile();

        a.welcome();
        scanner.nextLine();
        a.clearScreen();

        while (val){
            a.menu();
            comand = lerInt(a.pedirNumero(),0,5);
            switch (comand){
                case 0:
                    val = false;
                    break;
                case 1:
                    if(load)
                        consultasEstatisticas(sgv);
                    else
                        a.printErroCarregar();
                    break;
                case 2:
                    if(load)
                        consultasIterativas(sgv);
                    else
                        a.printErroCarregar();
                    break;
                case 3:
                    if(!load) {
                        a.printErroCarregar();
                        break;
                    }
                    a.printMessage("Pretende guardar no ficheiro default? (S/N)");
                    String str = scanner.nextLine();
                    if (str.equals("S"))
                        data.guardaDados("gestVendas.dat", sgv);
                    else {
                        a.pedirNomeFicheiro();
                        str = scanner.nextLine();
                        if((n = data.guardaDados(str, sgv)) != 0)
                            a.printErroLerFicheiro(n);
                    }
                    break;
                case 4:
                    a.pedirNomeFicheiro();
                    String string = scanner.nextLine();
                    sgv = data.carregaDados(string);
                    load = true;
                    break;
                case 5:
                    if(load)
                        sgv = new GestVendas();

                    Crono.start();
                    if((n = sgv.loadCat(sgv.getLoadInfoCliPath(),0)) != 0 || (erro = sgv.loadCat(sgv.getLoadInfoProdPath(),1)) != 0) {
                        a.printErroLerFicheiro(n);
                        a.printErroLerFicheiro(erro);
                    }
                    else {
                        time = Crono.getTime();

                        n = lerInt(a.pedirTipoFicheiro(),1,3);
                        if(n == 2)
                            sgv.setLoadInfoSalesPath("Files/Vendas_3M.txt");
                        else if(n == 3)
                            sgv.setLoadInfoSalesPath("Files/Vendas_5M.txt");

                        Crono.start();
                        if ((n = sgv.loadSales(sgv.getLoadInfoSalesPath())) == 0)
                            load = true;
                        else
                            a.printErroLerFicheiro(n);

                        a.printTime(time, "Catalogos");
                        a.printTime(Crono.getTime(), "Vendas");
                    }

                    break;
            }
        }
    }
}
