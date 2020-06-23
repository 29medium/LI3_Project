/**
 * Classe com a apresentação do programa
 */

package View;

import java.io.Serializable;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Apresentacao implements Serializable, IApresentacao {

    /**
     * Método que apresenta a mensagem de Boas Vindas
     */
    public void welcome() {
        System.out.print("   SSSSSSSSSSSSSSS           GGGGGGGGGGGG   VVVVVVVV           VVVVVVVV\n");
        System.out.print(" SS:::::::::::::::S       GGG::::::::::::G  V::::::V           V::::::V\n");
        System.out.print("S:::::SSSSSS::::::S     GG:::::::::::::::G  V::::::V           V::::::V\n");
        System.out.print("S:::::S     SSSSSSS    G:::::GGGGGGGG::::G  V::::::V           V::::::V\n");
        System.out.print("S:::::S               G:::::G       GGGGGG   V:::::V           V:::::V \n");
        System.out.print("S:::::S              G:::::G                  V:::::V         V:::::V  \n");
        System.out.print(" S::::SSSS           G:::::G                   V:::::V       V:::::V   \n");
        System.out.print("  SS::::::SSSSS      G:::::G    GGGGGGGGGG      V:::::V     V:::::V    \n");
        System.out.print("    SSS::::::::SS    G:::::G    G::::::::G       V:::::V   V:::::V     \n");
        System.out.print("       SSSSSS::::S   G:::::G    GGGGG::::G        V:::::V V:::::V      \n");
        System.out.print("            S:::::S  G:::::G        G::::G         V:::::V:::::V       \n");
        System.out.print("            S:::::S   G:::::G       G::::G          V:::::::::V        \n");
        System.out.print("SSSSSSS     S:::::S    G:::::GGGGGGGG::::G           V:::::::V         \n");
        System.out.print("S::::::SSSSSS:::::S     GG:::::::::::::::G            V:::::V          \n");
        System.out.print("S:::::::::::::::SS        GGG::::::::::::G             V:::V           \n");
        System.out.print(" SSSSSSSSSSSSSSS             GGGGGGGGGGGG               VVV            \n");
        System.out.print("\nBem Vindo ao Sistema de Gestão de Vendas. Durante a execução do programa\n");
        System.out.print("pode executar qualquer dos comandos do menu, tendo em atenção que os dados\n");
        System.out.print("têm de ser carregados antes das consultas.\n");
        System.out.print("Pressione qualquer tecla para continuar!\n");
    }

    /**
     * Método que imprime espaço no ecrã
     */
    public void clearScreen() {
        for (int i = 0; i < 3; ++i)
            System.out.println();
    }

    /**
     * Método que apresenta o Menu Inicial
     */
    public void menu(){
        StringBuilder sb = new StringBuilder();
        sb.append("\n-----------------------------------------------------\n");
        sb.append("                       INÍCIO\n");
        sb.append("-----------------------------------------------------\n");
        sb.append("1 | Consultas estatisticas\n");
        sb.append("2 | Consultas interativas\n");
        sb.append("3 | Gravar estado\n");
        sb.append("4 | Carregar estado a partir de um ficheiro\n");
        sb.append("5 | Carregar dados a partir do ficheiro de vendas\n");
        sb.append("0 | Sair\n");
        sb.append("-----------------------------------------------------\n");
        System.out.print(sb.toString());
    }

    /**
     * Método que apresenta o menu das Consultas Interativas
     */
    public void menuConsultasInterativas(){
        StringBuilder sb = new StringBuilder();
        sb.append("\n-------------------------------------------------------------------------------------------\n");
        sb.append("                                   CONSULTAS INTERATIVAS\n");
        sb.append("---+---------------------------------------------------------------------------------------\n");
        sb.append(" 1 | Códigos Produtos nunca comprados e total\n");
        sb.append(" 2 | Total vendas e clientes distintos para cada filial e para um dado mês\n");
        sb.append(" 3 | Número compras, produtos distintos e gasto total de um dado cliente para cada mês\n");
        sb.append(" 4 | Número compras, clientes distintos e faturação total de um dado produto para cada mês\n");
        sb.append(" 5 | Lista produtos que um cliente mais comprou(quantidade)\n");
        sb.append(" 6 | X produtos mais vendidos em todo o ano(unidades) e clientes distintos que os compraram\n");
        sb.append(" 7 | 3 maiores compradores em termos de faturação por filial\n");
        sb.append(" 8 | X clientes que compraram mais produtos diferentes\n");
        sb.append(" 9 | X clientes que mais compraram um produto e valor gasto para cada um\n");
        sb.append("10 | Faturação total de cada produto mês a mês e filial a filial\n");
        sb.append(" 0 | Voltar\n");
        sb.append("---+----------------------------------------------------------------------------------------\n");
        System.out.print(sb.toString());
    }

    /**
     * Método que apresenta o menu das Consultas Estatísticas
     */
    public void menuConsultasEstatisticas(){
        StringBuilder sb = new StringBuilder();
        sb.append("\n-----------------------------------------------------\n");
        sb.append("               CONSULTAS ESTATÍSTICAS\n");
        sb.append("-----------------------------------------------------\n");
        sb.append("1 | Dados relativos ao último ficheiro de vendas lido\n");
        sb.append("2 | Total compras por mês\n");
        sb.append("3 | Facturação total e por (Filial/Mês)\n");
        sb.append("4 | Clientes compradores distintos por (Filial/Mês)\n");
        sb.append("0 | Voltar\n");
        sb.append("-----------------------------------------------------\n");
        System.out.print(sb.toString());
    }

    /**
     * Método que apresenta o menu da Querie 10
     */
    public void menuQ10() {
        StringBuilder sb = new StringBuilder();
        sb.append("\n-----------------------------------------------------\n");
        sb.append("                      QUERIE 10\n");
        sb.append("-----------------------------------------------------\n");
        sb.append("1 | Ver tabela de faturação de um produto\n");
        sb.append("0 | Voltar\n");
        sb.append("-----------------------------------------------------\n");
        System.out.print(sb.toString());
    }

    /**
     * Método que apresenta uma mensagem
     *
     * @param message   String com a Mensagem
     */
    public void printMessage(String message) {
        System.out.println(message);
    }

    /**
     * Método que apresenta uma mensagem a pedir o nome do ficheiro
     */
    public void pedirNomeFicheiro(){
        System.out.println("Introduza o nome do ficheiro: ");
    }


    /**
     * Método que apresenta uma mensagem de aviso de erro a ler int
     */
    public void printErroLerInt(){
        System.out.println("Erro a ler int!");
    }

    /**
     * Método que apresenta uma mensagem de aviso de erro por estruturas não carregadas
     */
    public void printErroCarregar(){
        System.out.println("Carregue as estruturas primeiro!");
    }

    /**
     * Método que apresenta uma mensagem de aviso de erro ao ler ficheiro
     */
    public void printErroLerFicheiro(int i){
        if(i == 2)
            System.out.println("Erro a ler ficheiro!");
        else if (i == 1)
            System.out.println("Ficheiro não encontrado!");
    }

    /**
     * Método que apresenta o tempo
     *
     * @param time  String com o tempo
     * @param type  String com o tipo
     */
    public void printTime(String time,String type){
        System.out.println("Tempo carregamento " + type + ":" +time);
    }

    /**
     * Método que devolve mensagem a pedir cliente em formato de String
     *
     * @return  String com a mensagem
     */
    public String pedirCliente(){
        return "Introduza um cliente:";
    }

    /**
     * Método que devolve mensagem a pedir produto em formato de String
     *
     * @return  String com a mensagem
     */
    public String pedirProduto(){
        return "Introduza um produto:";
    }

    /**
     * Método que devolve mensagem a pedir mes em formato de String
     *
     * @return  String com a mensagem
     */
    public String pedirMes(){
        return "Introduza um mês:";
    }

    /**
     * Método que devolve mensagem a pedir limite em formato de String
     *
     * @return  String com a mensagem
     */
    public String pedirLimite(){
        return "Introduza um limite:";
    }

    /**
     * Método que devolve mensagem a pedir numero em formato de String
     *
     * @return  String com a mensagem
     */
    public String pedirNumero(){
        return "Introduza um número:";
    }

    /**
     * Método que devolve uma mensagem a pedir o nome do ficheiro
     *
     * @return String com a mensagem
     */
    public String pedirTipoFicheiro(){
        return "Pretende ler o ficheiro 1 milhão vendas (1) | 3 milhões vendas (2) | 5 milhões vendas (3)?";
    }

    /**
     * Método que apresenta a informação sobre o ficheiro lido
     *
     * @param salesPath         String com o caminho para o ficheiro
     * @param vendasInvalidas   Int com o número de vendas inválidas
     * @param totalProdutos     Int com o total de produtos
     * @param prodsComprados    Int com o número de produtos comprados
     * @param prodsNaoComprados Int com o número de produtos não comprados
     * @param totalClientes     Int com o número total de clientes
     * @param cliCompradores    Int com o número de clientes compradores
     * @param cliNaoCompradores Int com o número de clientes não compradores
     * @param comprasValor0     Int com o número de compras com o valor zero
     * @param fatTotal          Int com a faturação total
     */
    public void printConsultasEstatisticas1(String salesPath, int vendasInvalidas, int totalProdutos, int prodsComprados, int prodsNaoComprados,
                                            int totalClientes, int cliCompradores, int cliNaoCompradores, int comprasValor0, float fatTotal) {
        final StringBuilder sb = new StringBuilder();

        sb.append("-------------------------------------------------------\n");
        sb.append("       Informações sobre ficheiro de vendas lido \n");
        sb.append("----------------------------------+--------------------\n");
        sb.append(" Ficheiro vendas lido             | ").append(salesPath).append("\n");
        sb.append(" Vendas Inválidas                 | ").append(vendasInvalidas).append("\n");
        sb.append(" Total produtos                   | ").append(totalProdutos).append("\n");
        sb.append(" Número prodtutos comprados       | ").append(prodsComprados).append("\n");
        sb.append(" Número prodtutos nunca Comprados | ").append(prodsNaoComprados).append("\n");
        sb.append(" Total clientes                   | ").append(totalClientes).append("\n");
        sb.append(" Número clientes compradores      | ").append(cliCompradores).append("\n");
        sb.append(" Número clientes não compradores  | ").append(cliNaoCompradores).append("\n");
        sb.append(" Compras com valor 0              | ").append(comprasValor0).append("\n");
        sb.append(" Facturação total                 | ").append(fatTotal).append("\n");
        sb.append("----------------------------------+--------------------\n");

        clearScreen();

        System.out.println(sb.toString());
    }

    /**
     * Método que apresenta o número de compras efetuadas em cada mês
     *
     * @param comprasMes    Array de int com o número de compras por mês
     */
    public void printConsultasEstatisticas2(int[] comprasMes) {
        final StringBuilder sb = new StringBuilder();

        sb.append("Número de compras efetuadas em cada mês\n");
                for(int j = 0;j < 12;j++)
                    sb.append("\nMes ").append(j+1).append(":").append(comprasMes[j]);

        clearScreen();

        System.out.println(sb.toString());
    }

    /**
     * Método que apresenta a tabela de Faturação ou Clientes Compradores
     *
     * @param tabela    Array de Float com a tabela
     * @param type      Inteiro com o tipo
     */
    public void printConsultasEstatisticas3(float[][] tabela, int type) {

        if (type == 0) {
            System.out.println("Facturação (Filial/Mês)");
            System.out.println(String.format("%5s %7s %8s %10s %8s %10s %8s %10s", "Filial", "|", "1", "|", "2", "|", "3", "|"));
            System.out.println(String.format("%s", "--------------------------------------------------------------------------"));
        }
        else {
            System.out.println("Clientes compradores (Filial/Mês)");
            System.out.println(String.format("%5s %7s %7s %8s %7s %8s %7s %8s", "Filial" , "|", "1", "|", "2","|", "3","|"));
            System.out.println(String.format("%s", "-----------------------------------------------------------------"));
        }


        printTabela(tabela);

        clearScreen();
    }

    /**
     * Método que apresenta o resultado da querie 1
     *
     * @param list  List com o resultado da querie
     * @param size  Inteiro com o tamanho
     */
    public void printQ1(List<String> list, int size) {
        System.out.println("Produtos não comprados: " + size + "\n");
        printArray(list, 105);
    }

    /**
     * Método que apresenta o resultado da querie 2
     *
     * @param array Array de Int com o resultado da querie
     */
    public void printQ2(int [] array) {
        StringBuilder sb = new StringBuilder();
        sb.append("Vendas e clientes distintos que as fizeram para o mês dado\n\n");
        sb.append("Total vendas no mês dado ").append(":").append(array[0]).append("\n");
        sb.append("Clientes distintos no mês dado ").append(":").append(array[1]).append("\n");
        for(int i = 2;i < 8;i+=2) {
            sb.append("Total vendas filial ").append(i/2).append(":").append(array[i]).append("\n");
            sb.append("Clientes distintos filial ").append(i/2).append(":").append(array[i + 1]).append("\n");
        }
        System.out.println(sb.toString());
    }

    /**
     * Método que apresenta o resultado da querie 3
     *
     * @param querie3   Map com o resultado da querie
     */
    public void printQ3(Map<Integer,float[]> querie3) {
        float [][] res = new float[12][3];
        for(int mes = 0;mes < 12;mes++)
            res[mes] = querie3.get(mes);
        System.out.println(String.format("%5s %8s %8s %7s %8s %7s %8s %7s", "Mês" , "|", "Compras", "|", "Produtos","|", "Gasto","|"));
        System.out.println(String.format("%s", "-----------------------------------------------------------------"));
        printTabela(res);
    }

    /**
     * Método que apresenta o resultado da querie 4
     *
     * @param querie4   Map com o resultado da querie
     */
    public void printQ4(Map<Integer,float[]> querie4) {
        float [][] res = new float[12][3];
        for(int mes = 0;mes < 12;mes++)
            res[mes] = querie4.get(mes);
        System.out.println(String.format("%5s %8s %8s %7s %8s %7s %8s %6s", "Mês" , "|", "Vendas", "|", "Clientes","|", "Faturação","|"));
        System.out.println(String.format("%s", "-----------------------------------------------------------------"));
        printTabela(res);
    }

    /**
     * Método que apresenta o resultado da querie 7
     *
     * @param list  map com o resultado da querie
     */
    public void printQ7(Map<Integer,List<String>> list) {
        System.out.println("3 Maiores compradores por filial\n\n");
        System.out.println(String.format("%5s %4s %8s %7s %8s %7s %8s %7s", "Filial" , "|", "1º", "|", "2º","|", "3º","|"));
        System.out.println(String.format("%s", "--------------------------------------------------------------"));
        for(int i = 0;i < 3;i++) {
            System.out.println(String.format("%5d %5s %10s %5s %10s %5s %10s %5s", i+1 ,  "|", list.get(i).get(0),
                                                                                            "|",list.get(i).get(1), "|",list.get(i).get(2),"|"));
        }
    }

    /**
     * Método que apresenta o resultado de um produto da querie 10
     *
     * @param prod  String com o produto
     * @param arr   Array de Float com o resultado
     */
    public void printQ10(String prod, float[][] arr){

        System.out.println("Faturação produto "+prod+"\n");
        if (arr != null){
            System.out.println(String.format("%5s %7s %8s %7s %8s %7s %8s %7s", "Filial" , "|", "1", "|", "2","|", "3","|"));
            System.out.println(String.format("%s", "-----------------------------------------------------------------"));
            printTabela(arr);
        }
        else
            System.out.println("Produto não vendido\n");
    }


    /**
     * Método que imprime uma tabela com resultados de queries
     *
     * @param table Array de Float com o resultado a imprimir
     */
    private void printTabela(float[][] table){
        int mes = 1;

        for (final float[] row : table) {
            System.out.println(String.format("%5s %2d %5s %10.2f %5s %10.2f %5s %10.2f %5s", "Mes ",  mes, "|", row[0], "|",row[1], "|",row[2],"|"));
            mes++;
        }
    }

    /**
     * Método que imprime o cabeçalho de uma tabela
     *
     * @param message   Mensagem do cabeçalho
     * @param size      Inteiro com o comprimento da tabela
     */
    private void printLine(String message, int size) {
        for(int i=0; i<size; i++) {
            System.out.print("-");
        }
        System.out.println("");

        int headerSize = (size - message.length())/2;

        for(int i=0; i<headerSize; i++) {
            System.out.print(" ");
        }
        System.out.println(message);

        for(int i=0; i<size; i++) {
            System.out.print("-");
        }
        System.out.println("");
    }

    /**
     * Método que imprime uma página das tabelas dinamicas
     *
     * @param list      Lista a apresentar
     * @param page      Inteiro com o número da página
     * @param cols      Inteiro com o número de colunas
     * @param max       Inteiro com o número máximo de elementos por página
     * @param maxpage   Inteiro com o número máximo de páginas
     */
    private void printPagina(List<String> list, int page, int cols, int max, int maxpage, int lengthLine) {
        int i, j;
        int size = list.size();

        String header = "Página (" + (page+1) + "/" +(maxpage+1) +")";

        printLine(header, lengthLine);

        for(i=max * page; i<(max * (page+1)) && i<size; i+=cols) {
            for(j=i; (j<i+cols-1) && (j<size-1); j++)
                System.out.print(list.get(j) + "  |  ");
            System.out.println(list.get(j));
        }

        printLine("[N] Next | [P] Previous | [F] First | [L] Last | [#] Page Number | [Q] Quit", lengthLine);
    }

    /**
     * Método que verifica se o input é um numero
     *
     * @param strNum    String a verificar
     * @return          Resultado Booleano
     */
    private boolean isNumeric(String strNum) {
        if (strNum == null) {
            return false;
        }
        try {
            int d = Integer.parseInt(strNum);
        } catch (NumberFormatException nfe) {
            return false;
        }
        return true;
    }

    /**
     * Método que imprime uma tabela dinâmica
     *
     * @param list  Lista a imprimir
     */
    public void printArray(List<String> list, int lengthLine) {
        int page = 0, lines = 6, cols = (lengthLine + 5)/(list.get(0).length() + 5);
        int max = lines * cols, maxpage = (list.size()-1)/max;
        Scanner s = new Scanner(System.in);
        String line;
        boolean r=true;

        while(r) {
            printPagina(list, page, cols, max, maxpage, lengthLine);

            line = s.nextLine();

            if((line.equals("N") || line.equals("n")) && page<maxpage)
                page++;

            else if((line.equals("P") || line.equals("p")) && page>0)
                page--;

            else if(line.equals("F")  || line.equals("f"))
                page = 0;

            else if(line.equals("L") || line.equals("l"))
                page = maxpage;

            else if(isNumeric(line)) {
                int num = Integer.parseInt(line);
                if(num<=(maxpage + 1) && num>0)
                    page = num - 1;
            }

            else if(line.equals("Q") || line.equals("q"))
                r=false;
        }
    }
}
