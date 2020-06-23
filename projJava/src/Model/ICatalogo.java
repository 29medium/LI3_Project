package Model;

import java.util.Set;

public interface ICatalogo {

    int getTotal();
    Set<String> getTree();
    void addCod(String cod);
    boolean valCli(String codCli);
    boolean valProd(String codProd);
    boolean contem(String cod);
}
