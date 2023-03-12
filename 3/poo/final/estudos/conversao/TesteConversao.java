package estudos.conversao;

public class TesteConversao {
    public class MeioPagamento {}
    public class MeioPagamentoFisico extends MeioPagamento {}
    public class Dinheiro extends MeioPagamentoFisico {}
    public class MeioPagamentoEletronico extends MeioPagamento {}
    public class Pix extends MeioPagamentoEletronico {}
    public class Tef extends MeioPagamentoEletronico {}
    public class ExemplosConversao {
        public static void boo() {
            MeioPagamento an1 = new Pix();
            MeioPagamentoEletronico m1 = new MeioPagamentoEletronico();
            Dinheiro g1 = m1;
            MeioPagamentoFisico a1 = new Dinheiro();
            MeioPagamentoEletronico m2 = new MeioPagamentoFisico();
            Dinheiro g2 = new Dinheiro();
            Tef h1 = m1;
            Tef h2 = new Tef();
            m1 = an1;
            an1 = a1;
            a1 = h1;
            an1 = h2;
            m1 = h2;
            h2 = g2;
        }

        public static void foo() {

            MeioPagamento a1 = new Pix();
            MeioPagamentoEletronico m1 = (Pix)a1;
            m1 = (MeioPagamentoEletronico)a1;
            Dinheiro g1 = (MeioPagamentoFisico)m1;
            Dinheiro g2 = (Dinheiro)a1;
            MeioPagamentoFisico av1 = new Dinheiro();
            Pix ma1 = new Pix();
            MeioPagamento a2 = new Tef();
            MeioPagamentoEletronico m2 = (MeioPagamentoEletronico)ma1;
            ma1 = (Tef)a2;
            Tef h1 = (Tef)a1;
            m2 = (Pix)a2;
            av1 = (Dinheiro)a2;
            m1 = (Dinheiro)av1;
        }
    }
}
