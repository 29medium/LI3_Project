/**
 * Classe CliInfo
 */

package Model;

import java.io.Serializable;

public class CliInfo extends ProdInfo implements Comparable<CliInfo>, Serializable {
    private int []numeroCompras;
    private float []gastoTotal;

    //--------------------------------------------------------------Construtores--------------------------------------------------------------------------\\

    /**
     * Construtor da Classe Filial
     *
     * @param code  String que representa o código do Cliente
     */
    public CliInfo(String code) {
        super(code);
        numeroCompras = new int[12];
        gastoTotal = new float[12];
    }

    //--------------------------------------------------------------Getters/Setters--------------------------------------------------------------------------\\

    /**
     * Método que devolve o número de compras de um determinado mês
     *
     * @param month     String que representa o código do Cliente
     * @return          Inteiro que representa as compras do Cliente no mês
     */
    public int getNumeroCompras(int month) {
        return numeroCompras[month];
    }

    /**
     * Método que devolve o gasto total num detereminado mês
     *
     * @param month     Inteiro que representa o mês
     * @return          Float que representa o gasto do Cliente no mês
     */
    public float getGastoTotal(int month) {
        return gastoTotal[month];
    }

    /**
     * Método que devolve o gasto total de um Cliente
     *
     * @return      Float que representa o gasto total do Cliente
     */
    public float getGastoTotal(){
        float gasto = 0;
        for (int i = 0;i< 12;i++)
            gasto+=getGastoTotal(i);
        return gasto;
    }

    /**
     * Método que adiciona um Produto comprado pelo Cliente
     *
     * @param prodCode      String que representa o código do Produto
     * @param month         Inteiro que representa o mês
     * @param uni           Inteiro que representa as unidades compradas pelo Cliente
     * @param price         Float que representa o preço do Produto
     */
    public void addProd(String prodCode, int month, int uni, float price) {
        super.addCode(prodCode,month,price,uni);
        numeroCompras[month]++;
        gastoTotal[month] += uni * price;
    }

    //--------------------------------------------------------------compareTo--------------------------------------------------------------------------\\

    /**
     * Comparador natural de CliInfo, que ordena por gsto total
     *
     * @param c     CliInfo usado para a comparação
     * @return      Inteiro que representa a comparação entre os dois CliInfo
     */
    public int compareTo(CliInfo c) {
        return (int) (c.getGastoTotal() - this.getGastoTotal());
    }
}
