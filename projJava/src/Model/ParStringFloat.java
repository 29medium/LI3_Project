/**
 * Classe que contém um código(Produto ou Cliente) e valores da gasto/faturaçao e o número de diferentes Clientes/Produtos
 */

package Model;

import java.io.Serializable;

public class ParStringFloat implements Serializable, Comparable<ParStringFloat>{
    private String code;
    private float[] value;

    /**
     * Contrutor de ParStringFloat
     *
     * @param code      String que representa o código co Cliente/Produto
     * @param value     Float que representa os diferentes Clientes/Produtos
     */
    public ParStringFloat(String code, float value) {
        this.code = code;
        this.value = new float[1];
        this.value[0] = value;
    }

    /**
     * Construtor de ParStringFloat
     *
     * @param code      String que representa o código de Cliente/Produto
     * @param value     Float que representa os diferentes Clientes/Produto
     * @param value2    Float que representa o gasto/faturação do Cliente/Produto
     */
    public ParStringFloat(String code, float value,float value2) {
        this.code = code;
        this.value = new float[2];
        this.value[0] = value;
        this.value[1] = value2;
    }

    /**
     * Construtor de ParStringFloat
     *
     * @param q     ParStringFloat usado para construção de um novo
     */
    public ParStringFloat(ParStringFloat q) {
        this.code = q.getCode();
        this.value = q.getArray();
    }

    /**
     * Método que devolve o código de Cliente/Produto
     *
     * @return      String que representa o código do Cliente/Produto
     */
    public String getCode() {
        return code;
    }

    /**
     * Método que atribui os diferentes Clientes/Produtos
     *
     * @param dif       Float que representa os diferentes Clientes/Produtos
     */
    public void setValue2(float dif) {
        this.value[1] = dif;
    }

    /**
     * Método que devolve o gasto/faturação de um Cliente/Produto
     *
     * @return      FLloat que representa o gasto/faturaçao do Cliente/Produto
     */
    public float getValue() {
        return value[0];
    }

    /**
     * Método que devolve o número de diferentes Clientes/Produtos
     *
     * @return      Float que representa os diferentes Clientes/Produtos
     */
    public float getValue2() {
        return value[1];
    }

    /**
     * Método que devolve o gasto/faturação de um Cliente/Produto e o número de diferentes Clietnes/Produtos
     *
     * @return      Array de Float(de tamanho 2) que representa o gasto/faturação do Cliente/Produto e dos diferentes Clientes/Produtos
     */
    public float[] getArray(){
        return value;
    }

    /**
     * Método que adiciona o gasto/faturação e o númeroe de diferentes Clientes/Produtos
     *
     * @param value         Float que represeta o gasto/faturação do Cliente/Produto
     * @param value2        Float que representa os diferentes Clientes/Produtos
     */
    public void addUni(float value,float value2) {
        this.value[0] += value;
        this.value[1] += value2;
    }

    /**
     * Comparador de ParStringFloat que ordena por ordem alfabética
     *
     * @param aux   ParstringFloat usado para comparação
     * @return      Inteiro que representa o resultado da comparação
     */
    public int compareTo(ParStringFloat aux) {
        return this.getCode().compareTo(aux.getCode());
    }

    /**
     * Equals da classe ParStringFloat
     *
     * @param o     Objeto usado para ver a igualdade
     * @return      Booleano que representa a igualdade dos dois objetos
     */
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        ParStringFloat ParStringFloat = (ParStringFloat) o;
        return this.getCode().equals(ParStringFloat.getCode());
    }

    /**
     * Método que transforma o ParStringFloat numa String
     *
     * @return  String que representa o ParStringFloat
     */
    @Override
    public String toString() {
        return String.format("%1s %1s %7.2f %1s %9.2f", code , " ", value[0] , " ", value[1]);
    }

    public String toString2() {
        return String.format("%5s %1s %5.2f", code , " ", value[0] );
    }

    /**
     * Método que clona o ParStringFloat
     *
     * @return  ParStringFloat que representa o clone
     */
    public ParStringFloat clone() {
        return new ParStringFloat(this);
    }
}
