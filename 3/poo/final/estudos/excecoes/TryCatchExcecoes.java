package estudos.excecoes;

import java.util.Scanner;
public class TryCatchExcecoes {
    private static final Scanner ENTRADA = new Scanner(System.in);
    static void testar1(String texto) throws ExcecaoGama, ExcecaoBeta {
        if (texto != null && texto.length() > 200) {
            throw new ExcecaoGama();
        } else if (texto.equals("ABC")) {
            throw new ExcecaoBeta();
        }
    }
    static void testar2(long valor) throws ExcecaoGama {
        if (valor <= 0) {
            throw new ExcecaoGama();
        }
    }
    static void testar3(int valor) throws ExcecaoGama {
        if (valor < 0) {
            throw new ExcecaoGama();
        }
    }
    static void simularTeste1(int valor) {
        try {
            testar2(valor);
        }
        catch (ExcecaoGama e) {
            System.out.println("Exceção Gama");
        }
    }
    static void simularTeste1(String texto) {
        try {
            testar1(texto);
        } catch (ExcecaoAlfa e) {
            System.out.println("Exceção tipo A");
        } catch (ExcecaoBeta e) {
            System.out.println("Exceção tipo B");
        } catch (ExcecaoGama e) {
            System.out.println("Exceção tipo C");
        }
    }
    static void simularTeste2(String texto) throws ExcecaoAlfa, ExcecaoBeta {
        testar1(texto);
    }
    static void simularTeste3(int valor) {
        try {
            testar2(valor);
        } catch (ExcecaoGama e) {
            System.out.println("Exceção tipo C");
        }
    }
    static void simularTeste3(String texto) {
        try {
            testar1(texto);
        } catch (ExcecaoBeta e) {
            System.out.println("Exceção tipo B");
        } catch (ExcecaoGama e) {
            System.out.println("Exceção gama");
        }
    }

    static void simularTeste4(String texto) {

        try {
            testar3(10);
        } catch (ExcecaoAlfa e) {
            System.out.println("Exceção tipo A");
        }
    }
    static void simularTeste5(String texto) {

        try {
            testar1(texto);
        } catch (ExcecaoAlfa e) {
            System.out.println("Exceção tipo A");
        } catch (ExcecaoBeta e) {
            System.out.println("Exceção tipo B");
        }
    }
    public static void main(String[] args) {
        String texto = ENTRADA.next();
        int valor = ENTRADA.nextInt();
        try {
            testar2(valor);
            testar1(texto);
        } catch (ExcecaoGama e) {
            System.out.println("Exceção tipo C");
        } catch (ExcecaoBeta e) {
            System.out.println("Exceção tipo B");
        }
    }
}
