package Model;

import java.util.Set;

public interface IFaturacao {

    int getComprados();
    int getCompras0();
    float getFaturacaoTotal();
    int[] getComprasMes();
    float[][] getFaturacaoMesFil();
    Set<String> getKeys();
    int getUni(String code);
    float getFatTotalMes(String code,int month);
    float[][] getFatMesFilProd(String code);
    float getUniMes(String code,int month);
    boolean containsProd(String prodCode);
    void addSale(int branch,int month,float price,int uni,String prod);

}
