/**
 * Classe de comparador de PaStringFloat
 */

package Model;

import Model.ParStringFloat;

import java.io.Serializable;
import java.util.Comparator;

public class sortParbyValue implements Serializable, Comparator<ParStringFloat>{

    /**
     * Método que compara dois ParStringFloat por gasto/faturação
     *
     * @param normal    ParStringFloat usado para comparação
     * @param aux       ParStringFloat usado para comparação
     * @return          Inteiro que representa o resultado da comparação
     */
    public int compare(ParStringFloat normal, ParStringFloat aux) {
        int i = (int) (aux.getValue() - normal.getValue());
        if (i == 0)
            return normal.getCode().compareTo(aux.getCode());
        return i;
    }
}