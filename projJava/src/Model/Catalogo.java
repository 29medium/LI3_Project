/**
 * Classe Catalogo
 */

package Model;

import java.io.Serializable;
import java.util.*;

public class Catalogo implements Serializable, ICatalogo {
    private int type;
    private int total;
    private Map<String, Set<String>> list;

    /**
     * Construtor da Classe Catalogo
     *
     * @param t Inteiro com o tipo de Catalogo
     */
    public Catalogo(int t){
        this.type = t;
        this.total = 0;
        this.list = new HashMap<>();
    }

    /**
     * Método que devolve o número total de elementos do Catalogo
     *
     * @return  Inteiro com o número de elementos
     */
    public int getTotal() {
        return this.total;
    }

    /**
     * Método que devolve uma cópia do Catalogo
     *
     * @return  Set com cópia do Catalogo
     */
    public Set<String> getTree() {
        Set<String> set = new TreeSet<>();
        for (Set<String> s: list.values())
            set.addAll(s);
        return set;
    }

    /**
     * Método que adiciona um elemento ao Catalogo
     *
     * @param cod   String com o cliente/produto
     */
    public void addCod(String cod) {
        if((type == 0 && valCli(cod))||(type == 1 && valProd(cod))) {
            total++;
            String c = String.valueOf(cod.charAt(0));
            if(!list.containsKey(c))
                list.put(c, new TreeSet<>());
            list.get(c).add(cod);
        }
    }

    /**
     * Método que verifica se um cliente é válido
     *
     * @param codCli    String com o cliente
     * @return          Resultado Booleano
     */
    public boolean valCli(String codCli) {
        return codCli.matches("[A-Z]([1-4]\\d{3}|50{3})");
    }

    /**
     * Método que verifica se um produto é válido
     *
     * @param codProd   String com o produto
     * @return          Resultado Booleano
     */
    public boolean valProd(String codProd) {
        return codProd.matches("[A-Z]{2}([1-9]\\d{3})");
    }

    /**
     * Método que verifica se um elemento existe no Catalogo
     *
     * @param cod   String com o cliente/produto
     * @return      Resultado Booleano
     */
    public boolean contem(String cod) {
        String c = String.valueOf(cod.charAt(0));
        if (list.containsKey(c))
            return list.get(c).contains(cod);

        return false;
    }
}
