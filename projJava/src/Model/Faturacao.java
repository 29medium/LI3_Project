/**
 * Classe com a Faturação do programa
 */

package Model;

import java.io.Serializable;
import java.util.*;

public class Faturacao implements Serializable, IFaturacao {
    private Map<String,FactMF> listaProd;
    private int comprados;
    private int compras0;
    private float faturacaoTotal;
    private float [][] faturacaoMesFil;
    private int [] comprasMes;

    /**
     * Contrutor da Classe Faturação
     */
    public Faturacao() {
        listaProd = new HashMap<>();
        comprados = 0;
        compras0 = 0;
        faturacaoTotal = 0;
        comprasMes = new int[12];
        faturacaoMesFil = new float[12][3];
    }

    /**
     * Método que devolve o número de produtos vendidos
     *
     * @return  Inteiro com o número de produtos vendidos
     */
    public int getComprados() {
        return comprados;
    }

    /**
     * Método que devolve o número de produtos que não foram vendidos
     *
     * @return  Inteiro com o número de produtos
     */
    public int getCompras0() {
        return compras0;
    }

    /**
     * Método que devolve a faturação do sistema
     *
     * @return  Float com a faturação
     */
    public float getFaturacaoTotal() {
        return faturacaoTotal;
    }

    /**
     * Método que devolve o número de compras por mês
     *
     * @return  Array de Int com o número de compras
     */
    public int[] getComprasMes() {
        return comprasMes.clone();
    }

    /**
     * Método que devolve a faturação por mês e por filial
     *
     * @return  Matriz de Float com a faturação
     */
    public float[][] getFaturacaoMesFil() {
        return faturacaoMesFil.clone();
    }

    /**
     * Método que devolve os produtos da Faturação
     *
     * @return  Set com os produtos
     */
    public Set<String> getKeys() {
        return new TreeSet<>(listaProd.keySet());
    }

    /**
     * Método que devilve o número de unidades vendidas de um produto
     *
     * @param code  String com o produto
     * @return      Inteiro com o número de unidades
     */
    public int getUni(String code) {
        return listaProd.get(code).getUniTotal();
    }

    /**
     * Método que devolve a faturação total de um produto num mês
     *
     * @param code  String com o produto
     * @param month Inteiro com o mês
     * @return      Float com a faturação
     */
    public float getFatTotalMes(String code,int month){
        return listaProd.get(code).getFaturacaoMes(month);
    }

    /**
     * Método que devolve a Faturação de um produto por mês e filial
     *
     * @param code  String com o produto
     * @return      Matriz de Float com a faturação
     */
    public float[][] getFatMesFilProd(String code){
        return listaProd.get(code).getFaturacaoMesFill();
    }

    /**
     * Método que devolve o número de unidades vendidas de um produto num mês
     *
     * @param code  String com o produto
     * @param month Inteiro com o mês
     * @return      Inteiro com o número de unidades
     */
    public float getUniMes(String code,int month){
        return listaProd.get(code).getUnidadesMes(month);
    }

    /**
     * Método que verifica se um produto existe na Faturação
     *
     * @param prodCode  String com o produto
     * @return          Resultado Booleano
     */
    public boolean containsProd(String prodCode){
        return listaProd.containsKey(prodCode);
    }

    /**
     * Método que adiciona uma venda à faturação
     *
     * @param branch    Inteiro com a filial
     * @param month     Inteiro com o mês
     * @param price     Float com o preço
     * @param uni       Inteiro com as unidades
     * @param prod      String com o produto
     */
    public void addSale(int branch,int month,float price,int uni,String prod){

        if(!listaProd.containsKey(prod)) {
            comprados++;
            listaProd.put(prod,new FactMF());
        }
        if(price * uni == 0.0)
            compras0++;

        float f = price * uni;
        faturacaoTotal += f;
        comprasMes[month]++;
        faturacaoMesFil [month][branch]+= f;
        listaProd.get(prod).setFact(branch,month,price,uni);
    }

    /**
     * Método que devolve o número de Vendas de um Produto num determinadop mês
     *
     * @param prodCode      string que representa o código do Produto
     * @param month         Inteiro que representa o mês
     * @return              Inteiro que representa o número do de Vendas do Produto no mês
     */
    public int getNumeroVendasMes(String prodCode, int month) {
        return listaProd.get(prodCode).getVendasMes(month);
    }
}
