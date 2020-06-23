/**
 * Classe com o cronómetro para a contagem de tempos de execução
 */

package Controller;

import java.io.Serializable;

import static java.lang.System.nanoTime;

public class Crono implements Serializable {
    private static long inicio = 0L;
    private static long fim = 0L;

    /**
     * Método que começa o cronómetro
     */
    public static void start() {
        fim = 0L; inicio = nanoTime();
    }

    /**
     * Método que para o cronómetro
     *
     * @return  Double com o tempo
     */
    public static double stop() {
        fim = nanoTime();
        long elapsedTime = fim - inicio;
        return elapsedTime / 1.0E09;
    }

    /**
     * Método que devolve o tempo em formato de String
     *
     * @return  String com o tempo
     */
    public static String getTime() {
        return "" + stop();
    }

    /**
     * Método que devolve o tempo em formato de String
     *
     * @return String com o tempo
     */
    public static String getTImeString() {
        return "Elapsed Time: " +getTime() + " s";
    }
}