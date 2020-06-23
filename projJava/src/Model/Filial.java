/**
 * Classe com informação sobre uma Filial
 */

package Model;

import java.io.Serializable;
import java.util.*;
import java.util.stream.Collectors;

public class Filial implements Serializable {
    private Map<String,ProdInfo> mapProd;
    private Map<String,CliInfo> mapCli;
    private int clientesCompradores;
    private int[] cliCompradoresMes;
    private int[] vendasMes;

    //--------------------------------------------------------------Construtores--------------------------------------------------------------------------\\

    /**
     * Construtores da classe Filial
     */
    public Filial() {
        mapProd = new HashMap<>();
        mapCli = new HashMap<>();
        clientesCompradores = 0;
        cliCompradoresMes = new int[12];
        vendasMes = new int[12];
    }

    //--------------------------------------------------------------Getters/Setters--------------------------------------------------------------------------\\

    /*public Model.ProdInfo getCliInfo(String cliCode){
        return mapCli.get(cliCode);
    }*/

    /**
     * Método que devolve o número de Clientes compradores da Filial
     *
     * @return  Inteiro que representa o número de Clientes compradores
     */
    public int getClientesCompradores() {
        return clientesCompradores;
    }

    /**
     * Método que devolve o número de Clientes compradores da Filial por mês
     *
     * @return      Array de Inteiros(de tamanho 12) que representa o número de Clientes compradores associados ao mês
     */
    public int[] getCliCompradoresMes() {
        return cliCompradoresMes.clone();
    }

    /**
     * Método que devolve o número de Vendas de uma Filial num determinado mês
     *
     * @param month     Inteiro que representa o mês
     * @return          Inteiro que representa as Vendas de uma Filial num mês
     */
    public int getVendasMes(int month) {
        return vendasMes[month];
    }

    /**
     * Método que devolve o número de Vendas de um Filial
     *
     * @return  Inteiro que representa as Vendas de uma Filial
     */
    public int getVendasFil(){
        return Arrays.stream(vendasMes).sum();
    }

    /**
     * Método que devolve os Clientes compradores de um determinado mês
     *
     * @param month     Inteiro que representa o mês
     * @return          Inteiro que representa os Clientes compradores de um mês
     */
    public Set<String> getClientesMes(int month){
        Set<String> clientes = new TreeSet<>();

        for(ProdInfo p:mapProd.values())
            clientes.addAll(p.getCodeMonth(month));

        return clientes;
    }

    /**
     * Método que devolve o número de compras que um Cliente fez num mês
     *
     * @param cliCode       String que representa o código do Cliente
     * @param month         Inteiro que representa o mês
     * @return              Float que representa ao número de compras de um Cliente num mês
     */
    public float getNumeroCompras(String cliCode,int month){
        return (mapCli.get(cliCode)).getNumeroCompras(month);
    }

    /**
     * Método que devolve o gasto de um Cliente num determinado mês
     *
     * @param cliCode       String que representa o código de Cliente
     * @param month         Inteiro que representa o mês
     * @return              Float que representa o gasto de um Cliente num mês
     */
    public float getGastoTotal(String cliCode,int month){
        return (mapCli.get(cliCode)).getGastoTotal(month);
    }

    /**
     * Método que devolve os Clientes que compraram um determinado Produto num determinado mês
     *
     * @param month     Inteiro que representa um mês
     * @param code      String que representa o código do Produto
     * @return          Set de Clientes que compraram um Produto no mês
     */
    public Set<String> getClientesDiferentes(int month,String code) {
        if (!mapProd.containsKey(code))
            return new TreeSet<>();
        return mapProd.get(code).getCodeMonth(month);
    }

    /**
     * Método que devolve os Produtos diferentes que um Cliente comprou num determinado mês
     *
     * @param month     Inteiro que representa um mês
     * @param code      String que representa o código do Cliente
     * @return          Set de Produtos que o Cliente comprou no mês
     */
    public Set<String> getProdutosDiferentes(int month,String code) {
        return mapCli.get(code).getCodeMonth(month);
    }

    /**
     * Método que devolve os três Clientes mais compradores
     *
     * @return      Lista dos três Clientes mais compradores
     */
    public List<String> getClientesMaisCompradores() {
        return mapCli.values().stream().sorted().limit(3).map(CliInfo::getCode).collect(Collectors.toList());
    }

    /*public List<Model.ProdCliinfo> getProdCliList(String code){
        return mapProd.get(code).getMapList();
    }*/

    /**
     * Método que verifica se um Cliente existe na Filial
     *
     * @param code      String que representa o código de Cliente
     * @return          Booleano que representa a existência do Cliente na Filial
     */
    public boolean containsCliCode(String code){
        return mapCli.containsKey(code);
    }

    /**
     * Método que devolve um treeSet de ParStringFloat que guarda para cada código de produto que o cliente comprou as unidades e o gasto
     *
     * @param cliCode   String que representa o código do Cliente
     * @return          Set de ParStringFloat que para código de Produto que o Cliente comprou guarda as unidades e o gasto
     */
    public Set<ParStringFloat> getCliSetCodUni(String cliCode){
        return mapCli.get(cliCode).getSetCodUni();
    }

    /**
     * Método que devolve um treeSet de ParStringFloat que guarda para cada código de cliente que comprou o produto as unidades e a faturação
     *
     * @param prodCode  String que representa o código do Produto
     * @return          Set de ParStringFloat que para código de Cliente que comprou o Produto guarda as unidades e a faturação
     */
    public Set<ParStringFloat> getProdSetCodUni(String prodCode){
        return mapProd.get(prodCode).getSetCodUni();
    }

    /**
     * Método que devolve o número de Clientes compradores de um determinado mês
     *
     * @param month     Inteiro que representa um mês
     * @return          Inteiro que representa os
     */
    public int getClientesCompradoresMes(int month) {
        return cliCompradoresMes[month];
    }

    //--------------------------------------------------------------Outros métodos--------------------------------------------------------------------------\\

    /**
     * Método que adiciona uma Venda à Filial
     *
     * @param month         Inteiro que representa o mês
     * @param price         Float que representa o preço da Venda
     * @param uni           Inteiro que representa as unidades vendidas
     * @param prodCode      String que representa o código do Produto
     * @param cliCode       String que representa o código de Cliente
     * @return              Inteiro que representa se a Venda foi adiconada à Filial
     */
    public int addSale(int month,float price,int uni,String prodCode,String cliCode){
        int res = -1;

        vendasMes[month]++;
        if(!mapCli.containsKey(cliCode)) {
            clientesCompradores++;
            cliCompradoresMes[month]++;
            res = 1;
            mapCli.put(cliCode,new CliInfo(cliCode));
        }
        else {
            if(!mapCli.get(cliCode).containsMes(month))
                cliCompradoresMes[month]++;
        }
        if(!mapProd.containsKey(prodCode))
            mapProd.put(prodCode,new ProdInfo(prodCode));

        mapProd.get(prodCode).addCode(cliCode,month,price,uni);
        mapCli.get(cliCode).addProd(prodCode, month,uni,price);

        return res;
    }
}
