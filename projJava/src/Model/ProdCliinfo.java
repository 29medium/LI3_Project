/**
 * Classe de ProdCliinfo
 */

package Model;

import java.io.Serializable;

public class ProdCliinfo implements Serializable {
    private int month;
    private float fat;
    private int uni;

    //--------------------------------------------------------------Construtores--------------------------------------------------------------------------\\

    /**
     * Construtor de ProdCliinfo
     *
     * @param month     Inteiro que representa o mês do ProdCliinfo
     * @param fat       Float que representa a faturação do ProdCliinfo
     * @param uni       Inteiro que representa as unidades do ParStringFloat
     */
    public ProdCliinfo(int month,float fat,int uni) {
        this.month = month;
        this.fat = fat;
        this.uni = uni;
    }

    /**
     * Contrutor de ParStringFloat
     *
     * @param p     ProdCliinfo usado para a contrução
     */
    public ProdCliinfo(ProdCliinfo p) {
        this.month = p.getMonth();
        this.fat = p.getFat();
        this.uni = p.getUni();
    }

    //--------------------------------------------------------------Getters/Setters--------------------------------------------------------------------------\\

    /**
     * Método que devolve o mês do ProdCliinfo
     *
     * @return  Inteiro que representa o mês do ProdCliinfo
     */
    public int getMonth() {
        return month;
    }

    /**
     * Método que devolve a faturação do ProdCliinfo
     *
     * @return      Float que representa a faturação do ProdCliinfo
     */
    public float getFat() {
        return fat;
    }

    /**
     * Método que devolve as unidades do ProdCliinfo
     *
     * @return      Inteiro que representa as unidades do PrdoCliinfo
     */
    public int getUni() {
        return uni;
    }

    /**
     * Método que adiciona unidades e faturação ao ProdCliinfo
     *
     * @param uni       Inteiro que representa as unidades
     * @param price     Float que representa o preço
     */
    public void add(int uni,float price){
        this.uni += uni;
        this.fat += uni * price;
    }

    //--------------------------------------------------------------toString, equals e clone--------------------------------------------------------------------------\\

    /**
     * Equals de ProdCliinfo
     *
     * @param o     Objeto usado para vet a igualdade
     * @return      Inteiro que representa a igualdade dos dois objetos
     */
    @Override
    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || getClass() != o.getClass())
            return false;
        ProdCliinfo that = (ProdCliinfo) o;
        return month == that.month &&
                Double.compare(that.fat, fat) == 0 &&
                uni == that.uni;
    }

    /**
     * Método que tranforma o ProdCliinfo numa String
     *
     * @return      String que representa o ProdCliinfo
     */
    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("Model.ProdCliinfo{");
        sb.append(", month=").append(month);
        sb.append(", price=").append(fat);
        sb.append(", uni=").append(uni);
        sb.append('}');
        return sb.toString();
    }

    /**
     * Clone do ProdCliinfo
     *
     * @return      ProdCliinfo que representa o clone
     */
    public ProdCliinfo clone() {
        return new ProdCliinfo(this);
    }

}