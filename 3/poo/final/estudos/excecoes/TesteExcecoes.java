package estudos.excecoes;

public class TesteExcecoes {
    public void moo(short valor) throws ExcecaoGama {
        if (valor < -100 || valor > 59999) {
            throw new ExcecaoAlfa();
        } else {
            System.out.println(valor);
        }
    }
    public void foo(String texto) {
        if (texto != null && texto.length() > 10) {
            throw new ExcecaoGama();
        } else {
            System.out.println(texto);
        }
    }
    public void goo(String texto) throws ExcecaoTipoA, ExcecaoBeta {
        if (texto == null || "".equals(texto.trim())) {
            throw new ExcecaoBeta();
        } else {
            System.out.println(texto);
        }
    }
    public void boo(long valor) throws ExcecaoAlfa{
        if (valor < 0 && valor > -20) {
            throw new ExcecaoGama();
        } else {
            System.out.println(valor);
        }
    }
}
