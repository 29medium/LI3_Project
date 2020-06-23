/**
 * Classe com a informação do carregamento dos ficheiros
 */

package Model;

import java.io.Serializable;

public class LoadInfo implements Serializable {
    private int vendasValidas;
    private int vendasInvalidas;
    private int CliValidos;
    private int CliLidos;
    private int cliComprador;
    private int ProdValidos;
    private int ProdLidos;
    private String CliPath;
    private String ProdPath;
    private String SalesPath;

    /**
     * Construtor da Classe LoadInfo
     */
    public LoadInfo() {
        vendasInvalidas = 0;
        vendasValidas = 0;
        ProdLidos = 0;
        CliLidos = 0;
        cliComprador = 0;
        CliPath = "Files/Clientes.txt";
        ProdPath = "Files/Produtos.txt";
        SalesPath = "Files/Vendas_1M.txt";
    }

    /**
     * Método que devolve o número de vendas válidas
     *
     * @return  Inteiro com o número de vendas válidas
     */
    public int getVendasValidas(){
        return vendasValidas;
    }

    /**
     * Método que devolve o número de vendas inválidas
     *
     * @return  Inteiro com o número de vendas inválidas
     */
    public int getVendasInvalidas(){
        return vendasInvalidas;
    }

    /**
     * Método que devolve o caminho do ficheiro de clientes
     *
     * @return  String com o caminho
     */
    public String getCliPath() {
        return CliPath;
    }

    /**
     * Método que devolve o caminho do ficheiro de produtos
     *
     * @return  String com o caminho
     */
    public String getProdPath() {
        return ProdPath;
    }

    /**
     * Método que devolve o caminho do ficheiro de vendas
     *
     * @return  String com o caminho
     */
    public String getSalesPath() {
        return SalesPath;
    }

    /**
     * Método que devolve o número de clientes válidos
     *
     * @return Inteiro com o número de clientes válidos
     */
    public int getCliValidos() {
        return CliValidos;
    }

    /**
     * Método que devolve o número de clientes compradores
     *
     * @return Inteiro com o número de clientes compradores
     */
    public int getCliComprador() {
        return cliComprador;
    }

    /**
     * Método que devolve o número de produtos válidos
     *
     * @return Inteiro com o número de produtos válidos
     */
    public int getProdValidos() {
        return ProdValidos;
    }

    /**
     * Método que incrementa o número de vendas válidas
     */
    public void incValidas(){
        vendasValidas++;
    }

    /**
     * Método que incrementa o número de vendas inválidas
     */
    public void incInvalidas(){
        vendasInvalidas++;
    }

    /**
     * Método que incrementa o número de produtos lidos
     */
    public void incProdLidos(){
        ProdLidos++;
    }

    /**
     * Método que incrementa o número de clientes lidos
     */
    public void incCliLidos(){
        CliLidos++;
    }

    /**
     * Método que incrementa o número de clientes compradores
     */
    public void incCliComprador() { cliComprador++; }

    /**
     * Método que atualiza o caminho do ficheiro de clientes
     *
     * @param cliPath   String com caminho
     */
    public void setCliPath(String cliPath) {
        CliPath = cliPath;
    }

    /**
     * Método que atualiza o caminho do ficheiro de produtos
     *
     * @param prodPath  String com caminho
     */
    public void setProdPath(String prodPath) {
        ProdPath = prodPath;
    }

    /**
     * Método que atualiza o caminho do ficheiro de vendas
     *
     * @param salesPath String com caminho
     */
    public void setSalesPath(String salesPath) {
        SalesPath = salesPath;
    }

    /**
     * Método que atualiza o número de clientes válidos
     *
     * @param cliValidos    Inteiro com o número de clientes válidos
     */
    public void setCliValidos(int cliValidos) {
        CliValidos = cliValidos;
    }

    /**
     * Método que atualiza o número de produtos válidos
     *
     * @param prodValidos   Inteiro com o número de produtos válidos
     */
    public void setProdValidos(int prodValidos) {
        ProdValidos = prodValidos;
    }
}