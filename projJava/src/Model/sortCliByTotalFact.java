/**
 * Classe de comparador de ProdInfo
 */

package Model;

import Model.CliInfo;
import Model.ProdInfo;

import java.io.Serializable;
import java.util.Comparator;

public class sortCliByTotalFact implements Serializable, Comparator<ProdInfo> {

    /**
     * Método que compara dois ProdInfo por gasto total
     *
     * @param c1    ProdInfo usado para comparação
     * @param c2    ProdInfo usado para comparação
     * @return      Inteiro que representa o resultado da comparação
     */
    public int compare(ProdInfo c1, ProdInfo c2) {
        return (int) (((CliInfo) c2).getGastoTotal() - ((CliInfo) c1).getGastoTotal());
    }
}


