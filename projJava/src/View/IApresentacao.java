package View;

import java.util.List;

public interface IApresentacao {
    void welcome();
    void clearScreen();
    void menu();
    void menuConsultasInterativas();
    void menuConsultasEstatisticas();
    void menuQ10();
    void printMessage(String message);
    void pedirNomeFicheiro();
    void printErroLerInt();
    void printErroCarregar();
    void printErroLerFicheiro(int i);
    void printTime(String time,String type);
    String pedirCliente();
    String pedirProduto();
    String pedirMes();
    String pedirLimite();
    String pedirNumero();
    String pedirTipoFicheiro();
    void printQ10(String prod, float[][] arr);
    void printConsultasEstatisticas1(String salesPath, int vendasInvalidas, int totalProdutos, int prodsComprados, int prodsNaoComprados,
                                            int totalClientes, int cliCompradores, int cliNaoCompradores, int comprasValor0, float fatTotal);
    void printConsultasEstatisticas2(int[] comprasMes);
    void printConsultasEstatisticas3(float[][] tabela, int type);
    void printArray(List<String> list, int size);
}
