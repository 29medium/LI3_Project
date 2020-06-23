/**
 * Classe com a informação do modelo do programa
 */

package Model;

import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class GestVendas implements Serializable, IGestVendas {
    private Catalogo catClientes;
    private Catalogo catProdutos;
    private Faturacao fact;
    private GestaoFiliais gFil;
    private LoadInfo loadInfo;

    /**
     * Construtor da Classe GestVendas
     */
    public GestVendas(){
        catClientes = new Catalogo(0);
        catProdutos = new Catalogo(1);
        fact = new Faturacao();
        gFil = new GestaoFiliais();
        loadInfo = new LoadInfo();
    }

    /**
     * Método que verifica se o Catalogo contém um cliente
     *
     * @param cliCode   String com o Cliente
     * @return          Resultado Booleano
     */
    public boolean getCatCcontains(String cliCode){
        return catClientes.contem(cliCode);
    }

    /**
     * Método que veridica se o Catalogo contém um produto
     *
     * @param prodCode  String com o Produto
     * @return          Resultado Booleano
     */
    public boolean getCatPcontains(String prodCode){
        return catProdutos.contem(prodCode);
    }

    /**
     * Método Get do Catalogo de produtos
     *
     * @return  Cópia do Set Catologo de produtos
     */
    public Set<String> getCatPtree(){
        return catProdutos.getTree();
    }

    /**
     * Método Get do Catalogo de clientes
     *
     * @return  Cópia do Set Catalogo de clientes
     */
    public Set<String> getCatCtree(){
        return catClientes.getTree();
    }

    /**
     * Método que verifica se um cliente é válido
     *
     * @param code  String com o Cliente
     * @return      Resultado Booleano
     */
    public boolean cliVal(String code) {
        return catClientes.valCli(code);
    }

    /**
     * Método que verifica se um produto é válido
     *
     * @param code  String com o Produto
     * @return      Resultado Booleano
     */
    public boolean prodVal(String code) {
        return catProdutos.valProd(code);
    }

    /**
     * Método que devolve o número de vendas de uma filial
     *
     * @param branch    Inteiro com o código da filial
     * @return          Inteiro com o número de vendas da filial
     */
    public int getFilialVendas(int branch){
        return gFil.getVendasFilial(branch);
    }

    /**
     * Método que devolve o número de clientes compradores de uma filial
     *
     * @param branch    Inteiro com o código da filial
     * @return          Inteiro com o número de clientes compradores da filial
     */
    public int getFilialClientesCompradores(int branch){
        return gFil.getClientesCompradoresFilial(branch);
    }

    /**
     * Método que devolve os Clientes, as unidades que compraram e a faturação (ParStringFloat) numa determinada Filial
     *
     * @param branch    Inteiro que representa a Filial
     * @param cod       String que representa o código de Cliente
     * @return          Set de ParStringFloat que representa o Cliente, as unidades que compraram e a faturação
     */
    public Set<ParStringFloat> getGFilCliSet(int branch, String cod){
        return gFil.getCliSetCodUni(branch, cod);
    }

    /**
     * Método que devolve os Produtos, as unidades que compraram e a faturação (ParStringFloat) numa determinada Filial
     *
     * @param branch    Inteiro que representa a Filial
     * @param cod       String que representa o código de Produto
     * @return          Set de ParStringFloat que representa o Produto, as unidades que compraram e a faturação
     */
    public Set<ParStringFloat> getGFilProdSet(int branch, String cod){
        return gFil.getProdSetCodUni(branch, cod);
    }

    /**
     * Método que devolve os clientes mais compradores de uma filial
     *
     * @param branch    Inteiro com o código da filial
     * @return          List com os clientes
     */
    public List<String> getFilialClientesMaisCompradores(int branch){
        return gFil.getClientesMaisCompradoresFilial(branch);
    }

    /**
     * Método que devolve o número vendas num mês
     *
     * @param month Inteiro com o mês
     * @return      Inteiro com o número de vendas
     */
    public int getGFilVendasMes(int month){
        return gFil.getVendasMes(month);
    }

    /**
     * Método que devolve o número de clientes diferentes num mês
     *
     * @param month Inteiro com o mês
     * @return      Inteiro com o número de clientes diferentes
     */
    public int getGFilClientesDiferentesMes(int month) {
        return gFil.clientesDiferentesMes(month);
    }

    /**
     * Método que devolve o número de compras num mês por um cliente
     *
     * @param cod   String com o cliente
     * @param month Inteiro com o mês
     * @return      Float com o número de compras num mês
     */
    public float getGFilNumeroComprasMes(String cod, int month) {
        return gFil.numeroComprasMes(cod, month);
    }

    /**
     * Método que devolce o número de produtos diferentes
     *
     * @param cod   String com o cliente
     * @param month Inteiro com o mês
     * @return      Float com o número de produtos diferentes
     */
    public float getGFilProdutosDiferentes(String cod, int month) {
        return gFil.produtosDiferentes(cod, month);
    }

    /**
     * Método que devolve o gasto total num mês
     *
     * @param cod   String com o cliente
     * @param month Inteiro com o mês
     * @return      Float com o gasto total
     */
    public float getGFilGastoTotalMes(String cod, int month) {
        return gFil.gastoTotalMes(cod, month);
    }

    /**
     * Método que devolve o número de clientes diferentes por mês
     *
     * @param cod   String com o produto
     * @param month Inteiro com o mês
     * @return      Float com o número de clientes diferentes
     */
    public float getGFilClientesDiferentes(String cod, int month) {
        return gFil.clientesDiferentes(cod, month);
    }

    /**
     * Método que devolve o número de clientes diferentes
     *
     * @param cod   String com o produto
     * @return      Inteiro com o número de clientes diferentes
     */
    public int getGFilClientesDiferentesTotal(String cod) {
        return gFil.clientesDiferentesTotal(cod);
    }

    /**
     * Método que devolve o número de produtos diferentes
     *
     * @param cod   String com o cliente
     * @return      Inteiro com o número de produtos diferentes
     */
    public int getGFilProdutosDiferentesTotal(String cod) {
        return gFil.produtosDiferentesTotal(cod);
    }

    /**
     * Método que devolve o número de clientes compradores por mês
     *
     * @param branch    Inteiro com o código da filial
     * @return          Array de Float com o número de clientes compradores por mês
     */
    public float[] getgFilCliCompradoresMes(int branch){
        return gFil.getFilCliCompradoresMes(branch);
    }

    /**
     * Método que devolve aa unidades vendidas de um produto num mês
     *
     * @param cod   String com o produto
     * @param month Inteiro com o mês
     * @return      Float com o número de unidades vendidas de um produto num mês
     */
    public float getFactUniMes(String cod,int month){
        return fact.getUniMes(cod,month);
    }

    /**
     * Método que devolve a faturação de um produto num mês
     *
     * @param cod   String com o produto
     * @param month Inteiro com o mês
     * @return      Float com a faturação
     */
    public float getFactTotalMes(String cod,int month){
        return fact.getFatTotalMes(cod,month);
    }

    /**
     * Método que devolve os códigos de produto da Faturação
     *
     * @return  Set com os códigos de produto
     */
    public Set<String> getFactKeys(){
        return fact.getKeys();
    }

    /**
     * Método que devolve o número de unidades vendidas de um produto
     *
     * @param cod   String com o produto
     * @return      Inteiro com o número de unidades vendidas
     */
    public int getFactUni(String cod){
        return fact.getUni(cod);
    }

    /**
     * Método que verifica se a Faturação contém um produto
     *
     * @param cod   String com o produto
     * @return      Resultado Boolenano
     */
    public boolean getFactContainsProd(String cod){
        return fact.containsProd(cod);
    }

    /**
     * Método que devolve a faturação por mês e por filial de um produto
     *
     * @param cod   String com o produto
     * @return      Matriz de Float com a faturação
     */
    public float[][] getFactMesFilProd(String cod){
        return fact.getFatMesFilProd(cod);
    }

    /**
     * Método que devolve o número de produtos comprados
     *
     * @return  Inteiro com o número de produtos comprados
     */
    public int getFactComprados(){
        return fact.getComprados();
    }

    /**
     * Método que devolve o número de produtos que não foram vendidos
     *
     * @return  Inteiro com o número de produtos
     */
    public int getFactCompras0(){
        return fact.getCompras0();
    }

    /**
     * Método que devolve a Faturação total do sistema
     *
     * @return  Float com a Faturação
     */
    public float getFactFaturacaoTotal(){
        return fact.getFaturacaoTotal();
    }

    /**
     * Método que devolve o número de compras por mês
     *
     * @return  Array de Int com o número de compras
     */
    public int[] getFactComprasMes(){
        return fact.getComprasMes();
    }

    /**
     * Método que devolve a Faturação por mês e por filial
     *
     * @return  Array de Float com a Faturação
     */
    public float[][] getFactFaturacaoMesFil(){
        return fact.getFaturacaoMesFil();
    }

    /**
     * Método que devolve o caminho do ficheiro das Vendas
     *
     * @return  String com o caminho
     */
    public String getLoadInfoSalesPath(){
        return loadInfo.getSalesPath();
    }

    /**
     * Método que devolve o caminho do ficheiro dos Clientes
     *
     * @return  String com o caminho
     */
    public String getLoadInfoCliPath(){
        return loadInfo.getCliPath();
    }

    /**
     * Método que devolve o caminho do ficheiro dos Produtos
     *
     * @return  String com o caminho
     */
    public String getLoadInfoProdPath(){
        return loadInfo.getProdPath();
    }

    /**
     * Método que devolve o número de vendas inválidas
     *
     * @return  Inteiro com o número de vendas inválidas
     */
    public int getLoadInfoVendasInvalidas(){
        return loadInfo.getVendasInvalidas();
    }

    /**
     * Método que devolve o número de produtos válidos
     *
     * @return  Inteiro com o número de produtos válidos
     */
    public int getLoadInfoProdValidos(){
        return loadInfo.getProdValidos();
    }

    /**
     * Método que devolve o número de clientes válidos
     *
     * @return  Inteiro com o número de clientes válidos
     */
    public int getLoadInfoCliValidos(){
        return loadInfo.getCliValidos();
    }

    /**
     * Método que devolve o número de clientes compradores
     *
     * @return  Inteiro com o número de clientes compradores
     */
    public int getLoadInfoCliComprador(){
        return loadInfo.getCliComprador();
    }

    /**
     * Método que guarda o caminho do ficheiro das vendas
     */
    public void setLoadInfoSalesPath(String path){
        loadInfo.setSalesPath(path);
    }

    /**
     * Método que verifica se uma venda é válida
     *
     * param branch    Inteiro com a filial
     * @param month     Inteiro com o mês
     * @param price     Float com o preço
     * @param uni       Inteiro com as unidades
     * @param type      Char com o tipo
     * @return          Resultado Booleano
     */
    private boolean valSale(int branch,int month,float price,int uni,char type){
        return (branch >= 1 && branch <= 3 && month >= 1 && month <= 12 &&
                price >= 0 && uni >= 0 && (type == 'N' || type == 'P'));
    }

    /**
     * Método que carrega um Catalogo a partir de um ficheiro
     *
     * @param filename  String com o caminho de ficheiro
     * @param type      Inteiro com o tipo de Catalogo
     * @return          Inteiro identificador de erro
     */
    public int loadCat(String filename, int type){
        String line;
        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader(filename));
        } catch (FileNotFoundException fnfex) {
            return (1);
        }
        try {
            while ((line = br.readLine()) != null) {
            if(type == 0) {
                loadInfo.incCliLidos();
                catClientes.addCod(line);
            }
            else {
                loadInfo.incProdLidos();
                catProdutos.addCod(line);
            }
        }
        } catch (IOException ioex) {
            return (1);
        }
        if(type == 0)
            loadInfo.setCliValidos(catClientes.getTotal());
        else
            loadInfo.setProdValidos(catProdutos.getTotal());

        return 0;
    }

    /**
     * Método que carrega a Faturação e as Filiais a partir de um ficheiro
     *
     * @param filename  String com caminho para o ficheiro
     * @return          Inteiro identificador de erro
     */
    public int loadSales(String filename){
        String[] venda;
        int branch,month;
        int uni;
        float price;
        char type;
        BufferedReader br = null;
        String line;

        try {
            br = new BufferedReader(new FileReader(filename));
        } catch (FileNotFoundException fnfex) {
            return (1);
        }
        try {
            while ((line = br.readLine()) != null) {
                venda = line.split(" ");
                branch = Integer.parseInt(venda[6]);
                month = Integer.parseInt(venda[5]);
                price = Float.parseFloat(venda[1]);
                uni = Integer.parseInt(venda[2]);
                type = venda[3].charAt(0);
                if(valSale(branch,month,price,uni,type) &&
                        catClientes.contem(venda[4]) && catProdutos.contem(venda[0])) {
                    loadInfo.incValidas();
                    fact.addSale((branch - 1), (month - 1), price, uni, venda[0]);
                    if (gFil.addSaleInfo((month - 1), price, uni, venda[0], venda[4], (branch - 1)))
                        loadInfo.incCliComprador();
                }
                else
                    loadInfo.incInvalidas();
                }
        } catch (IOException ioex) {
            return (2);
        }
        return 0;
    }

    /**
     * Função que devolce o número de clientes compradores por mês e por filial
     *
     * @return  Matriz de Float com os clientes compradores
     */
    public float[][] getCompradoresMesFil() {
        float[][] compradoresMesFil = new float[12][3];
        float [] array = getgFilCliCompradoresMes(0);
        float [] array2 = getgFilCliCompradoresMes(1);
        float [] array3 = getgFilCliCompradoresMes(2);
        for(int i = 0;i < 12; i++) {
            compradoresMesFil[i][0] = array[i];
            compradoresMesFil[i][1] = array2[i];
            compradoresMesFil[i][2] = array3[i];
        }

        return compradoresMesFil;
    }

    /**
     * Método que devolve o número de vendas de uma Filial num determinado mês
     *
     * @param branch    Inteiro que representa a Filial
     * @param month     Inteiro que represernta o mês
     * @return          Inteiro que representa as Vendas numa Filial num mês
     */
    public int getFilialVendasMes(int branch, int month) {
        return gFil.getFilialVendasMes(branch, month);
    }

    /**
     * Método que devolve o número de Clientes que compraram numa Filial num determinado mês
     *
     * @param branch    Inteiro que representa a Filial
     * @param month     Inteiro que representa o mês
     * @return          Inteiro que representa os Clientes compradores numa Filial num mês
     */
    public int getFilialClientesCompradoresMes(int branch, int month) {
        return gFil.getFilClientesCompradoresMes(branch, month);
    }

    /**
     * Método o número de Vendas de um produto num determinado mês
     *
     * @param prodCode      String que representa o Produto
     * @param month         Inteiro que representa o mês
     * @return              Inteiro que representa o número de Vendas de um Produto no mês
     */
    public int getFactNumeroVendasMes(String prodCode, int month) {
        return fact.getNumeroVendasMes(prodCode, month);
    }

    //--------------------------------------------------------------Consultas Interativas-------------------------------------------------------------\\

    /**
     * Método que passa uma Lista ParStringFloat para Lista String
     *
     * @param list  Lista ParStringFloat
     * @return      Lista String
     */
    public List<String> listParStringFloatToListString(List<ParStringFloat> list, int type){
        List<String> stringList = new ArrayList<>();
        if(type == 0)
            list.forEach(p -> stringList.add(p.toString()));
        else
            list.forEach(p -> stringList.add(p.toString2()));

        return stringList;
    }

    /**
     * Método que executa a querie 1
     *
     * @return  Lista String com o resultado da querie
     */
    public List<String> getQ1(){
        List<String> querie1 = new ArrayList<>();

        getCatPtree().stream().filter(cod -> !(getFactContainsProd(cod))).forEach(querie1::add);
        return querie1;
    }

    /**
     * Método que executa a querie 2
     *
     * @param month Inteiro com o mês
     * @return      Array de inteiros com o resultado da querie
     */
    public int[] getQ2(int month){
         int[] querie2 = new int[8];
        int i = 0;
        querie2[i++] = getGFilVendasMes(month);
        querie2[i++] = getGFilClientesDiferentesMes(month);
        for(int f = 0;f < 3;f++) {
            querie2[i++] = getFilialVendasMes(f, month);
            querie2[i++] = getFilialClientesCompradoresMes(f, month);
        }

        return querie2;
    }

    /**
     * Método que executa a querie 3
     *
     * @param cod   String com o cliente
     * @return      Map com o resultado da querie
     */
    public Map<Integer, float[]> getQ3(String cod){
        Map<Integer, float[]> querie3 = new HashMap<>();
        float[] res;
        for(int month = 0;month < 12;month++){
            res = new float[3];
            res[0] = getGFilNumeroComprasMes(cod, month);
            res[1] = getGFilProdutosDiferentes(cod, month);
            res[2] = getGFilGastoTotalMes(cod, month);
            querie3.put(month,res);
        }
        return querie3;
    }

    /**
     * Método que executa a querie 4
     *
     * @param cod   String com o produto
     * @return      Map com o resultado da querie
     */
    public Map<Integer, float[]> getQ4(String cod){
        Map<Integer, float[]> querie4 = new HashMap<>();
        float[] res;
        for(int month = 0;month < 12;month++){
            res = new float[3];
            res[0] = getFactNumeroVendasMes(cod,month);
            res[1] = getGFilClientesDiferentes(cod, month);
            res[2] = getFactTotalMes(cod,month);
            querie4.put(month,res);
        }
        return querie4;
    }

    /**
     * Método que executa a querie 5
     *
     * @param cod   String com o cliente
     * @return      List com o resultado da querie
     */
    public List<ParStringFloat> getQ5(String cod) {

        Set<ParStringFloat> set = getGFilCliSet(0, cod);
        int i;


        for(i=1; i<3; i++) {
            for (ParStringFloat p: getGFilCliSet(i, cod)) {
                if (set.contains(p)) {
                    Iterator<ParStringFloat> it = set.iterator();
                    boolean b = true;
                    ParStringFloat q;
                    while (it.hasNext() && b) {
                        q = it.next();
                        if (q.getCode().equals(p.getCode())) {
                            q.addUni(p.getValue(), p.getValue2());
                            b = false;
                        }
                    }
                } else
                    set.add(p);
            }
        }


        return set.stream().sorted(new sortParbyValue()).collect(Collectors.toList());
    }

    /**
     * Método que executa a querie 6
     *
     * @param limit Int com o limite
     * @return      List com o resultado da querie
     */
    public List<ParStringFloat> getQ6(int limit) {
        List<ParStringFloat> querie6 = new ArrayList<>();

        for(String cod: getFactKeys())
            querie6.add(new ParStringFloat(cod, getFactUni(cod),0));

        querie6 = querie6.stream().sorted(new sortParbyValue()).limit(limit).collect(Collectors.toList());

        querie6.forEach(q -> q.setValue2(getGFilClientesDiferentesTotal(q.getCode())));
        return querie6;
    }

    /**
     * Método que executa a querie 7
     *
     * @return  Map com o resultado da querie
     */
    public Map<Integer, List<String>> getQ7() {
        Map<Integer, List<String>> querie7 = new HashMap<>();

        for(int i = 0; i<3; i++)
            querie7.put(i, getFilialClientesMaisCompradores(i));
        return querie7;
    }

    /**
     * Método que executa a querie 8
     *
     * @param limit Inteiro com o limite
     * @return      List com o resultado da querie
     */
    public List<ParStringFloat> getQ8(int limit) {
        List<ParStringFloat> querie8 = new ArrayList<>();

        for (String s: getCatCtree())
            querie8.add(new ParStringFloat(s, getGFilProdutosDiferentesTotal(s)));

        querie8 = querie8.stream().sorted(new sortParbyValue()).limit(limit).collect(Collectors.toList());
        return querie8;
    }

    /**
     * Método que executa a querie 9
     *
     * @param codProd   String com o produto
     * @param limit     Inteiro com o limite
     * @return          List com o resultado da querie
     */
    public List<ParStringFloat> getQ9(String codProd,int limit) {

        Set<ParStringFloat> set = getGFilProdSet(0, codProd);

        for(int i=1; i<3; i++) {
            for (ParStringFloat p : getGFilProdSet(i, codProd)) {
                if (set.contains(p)) {
                    Iterator<ParStringFloat> it = set.iterator();
                    boolean b = true;
                    ParStringFloat q;
                    while (it.hasNext() && b) {
                        q = it.next();
                        if (q.getCode().equals(p.getCode())) {
                            q.addUni(p.getValue(), p.getValue2());
                            b = false;
                        }
                    }
                } else
                    set.add(p);
            }
        }

        return set.stream().sorted(new sortParbyValue()).limit(limit).collect(Collectors.toList());

    }

    /**
     * Método que executa a querie 10
     *
     * @return  Map com o resultado da querie
     */
    public Map<String, float[][]> getQ10() {
        Map<String, float[][]> querie10 = new HashMap<>();

        for(String cod: getCatPtree()){
            if(getFactContainsProd(cod))
                querie10.put(cod, getFactMesFilProd(cod));

            else
                querie10.put(cod, null);
        }
        return querie10;
    }
}
