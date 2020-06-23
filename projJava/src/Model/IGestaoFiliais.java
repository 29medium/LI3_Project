package Model;

import java.util.List;
import java.util.Set;

public interface IGestaoFiliais {

    int getVendasFilial(int branch);
    int getClientesCompradoresFilial(int branch);
    Set<ParStringFloat> getCliSetCodUni(int branch, String code);
    Set<ParStringFloat> getProdSetCodUni(int branch,String code);
    List<String> getClientesMaisCompradoresFilial(int branch);
    float[] getFilCliCompradoresMes(int branch);
    boolean addSaleInfo(int month,float price,int uni,String prodCod,String cliCod,int branch);
    int clientesDiferentes(String prodCod,int month);
    int produtosDiferentes(String cliCod,int month);
    int produtosDiferentesTotal(String cliCod);
    int clientesDiferentesTotal(String prodCod);
    float gastoTotalMes(String code,int month);
    float numeroComprasMes(String code,int month);
    int clientesDiferentesMes(int month);
    int getVendasMes(int month);
}
