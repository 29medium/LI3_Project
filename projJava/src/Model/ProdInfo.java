/**
 * Classe de ProdInfo
 */

package Model;

import java.io.Serializable;
import java.util.*;

public class ProdInfo implements Serializable {
    private String code;
    private Map<Integer,Map<String,ProdCliinfo>> mapMes;

    //--------------------------------------------------------------Construtores--------------------------------------------------------------------------\\

    /**
     * Construtor de ProdInfo
     *
     * @param code      String que representa o código do Produto
     */
    public ProdInfo(String code) {
        this.code = code;
        mapMes = new HashMap<>();
    }

    //--------------------------------------------------------------Getters/Setters--------------------------------------------------------------------------\\

    /**
     * Método que devolve o código de um Produto
     *
     * @return      String que representa o código do Produto
     */
    public String getCode() {
        return code;
    }

    /**
     * Método que devolve o código e os respetivos gasto/faturação e diferentes Clientes/Produtos (ParStringFloat) dos Clientes/Produtos
     *
     * @return      Set de ParStringFloat que representa o código e os respetivos gasto/faturação e diferentes Clientes/Produtos dos Clientes/Produtos
     */
    public Set<ParStringFloat> getSetCodUni(){
        Set<ParStringFloat> tree = new TreeSet<>();
        for(Map<String,ProdCliinfo> map: mapMes.values())
            for(Map.Entry<String,ProdCliinfo> entryProd: map.entrySet()) {
                ParStringFloat c = new ParStringFloat(entryProd.getKey(),entryProd.getValue().getUni(),entryProd.getValue().getFat());
                if (tree.contains(c)) {
                    Iterator<ParStringFloat> it = tree.iterator();
                    boolean b = true;
                    ParStringFloat q;
                    while (it.hasNext() && b) {
                        q = it.next();
                        if (q.getCode().equals(c.getCode())) {
                            q.addUni(c.getValue(),c.getValue2());
                            b = false;
                        }
                    }
                } else
                    tree.add(c);
            }
        return tree;
    }

    /**
     * Método que devolve os Clientes que compraram o Produto num determinado mês
     *
     * @param month     Inteiro que representa o mês
     * @return          Set de String que representa os CLientes compradores do Produto no mês
     */
    public Set<String> getCodeMonth(int month){
        Set<String> clientes = new TreeSet<>();

        if(mapMes.containsKey(month))
            clientes.addAll(mapMes.get(month).keySet());

        return clientes;
    }

    //--------------------------------------------------------------Outros métodos--------------------------------------------------------------------------\\

    /**
     * Método que adiciona uma Venda
     *
     * @param cliCode       String que representa o código do Cliente
     * @param month         Inteiro que representa o mês
     * @param price         Float que representa o preço
     * @param uni           Inteiro que representa o número de unidades
     */
    public void addCode(String cliCode,int month,float price,int uni) {
        mapMes.putIfAbsent(month,new HashMap<>());
        if(mapMes.get(month).containsKey(cliCode))
            mapMes.get(month).get(cliCode).add(uni,price);
        else
            mapMes.get(month).put(cliCode,new ProdCliinfo(month,price * uni,uni));
    }

    /**
     * Métod que verifica se um Produto foi vendido num determinado mês
     *
     * @param month     Inteiro que representa o mês
     * @return          Booleano que representa a venda do Produto no mẽs
     */
    public boolean containsMes(int month) {
        return mapMes.containsKey(month);
    }
}
