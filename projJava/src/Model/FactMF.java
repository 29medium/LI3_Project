/**
 * Classe com a Faturção de um produto
 */

package Model;

import java.io.Serializable;
import java.util.Arrays;
import java.util.stream.Stream;

public class FactMF implements Serializable {
    private int[] unidadesMes;
    private int[] vendasMes;
    private float[][] faturacaoMesFill;

    /**
     * Construtor da Classe FactMF
     */
    public FactMF(){
        unidadesMes = new int[12];
        vendasMes = new int[12];
        faturacaoMesFill = new float[12][3];
    }

    public int getVendasMes(int month) {
        return vendasMes[month];
    }

    /**
     * Método que devolve o número de unidades vendidas num mês
     *
     * @param month Inteiro com o mês
     * @return      Inteiro com o número de unidades
     */
    public int getUnidadesMes(int month) {
        return unidadesMes[month];
    }

    /**
     * Método que devolve o número de unidades vendidas
     *
     * @return  Inteiro com o número de unidades vendidas
     */
    public int getUniTotal() {
        return Arrays.stream(unidadesMes).sum();
    }


    /**
     * Método que devolve a faturação num mês
     *
     * @param month Inteiro com o mês
     * @return      Float com a faturação
     */
    public float getFaturacaoMes(int month) {
        return faturacaoMesFill[month][0] + faturacaoMesFill[month][1] + faturacaoMesFill[month][2];
    }

    /**
     * Método que devolve a faturação por mês e filial
     *
     * @return  Matriz de Float com a faturação
     */
    public float[][] getFaturacaoMesFill() {
        return Arrays.stream(faturacaoMesFill).toArray(float[][]::new);
    }

    /**
     * Método que adiciona um produto
     *
     * @param branch    Inteiro com a filial
     * @param month     Inteiro com o mês
     * @param price     Float com o preço
     * @param uni       Inteiro com as unidades
     */
    public void setFact(int branch, int month, float price,int uni) {
        unidadesMes[month] += uni;
        vendasMes[month]++;
        faturacaoMesFill[month][branch] += price*uni;
    }
}
