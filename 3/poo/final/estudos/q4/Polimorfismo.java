package estudos.q4;

public class Polimorfismo {

    interface ValorRetornoCalculavel {
        double calcularValorRetorno();
    }
    public class Titulo {
        private double valor;
        protected double getValor() {
            return valor;
        }
        protected void setValor(double valor) {
            this.valor = valor;
        }
    }
    public class DividaAgraria extends Titulo {}
    public class DividaPublica extends Titulo {}
    public class Agrocore extends DividaAgraria {}

    public class RuralMais extends DividaAgraria implements ValorRetornoCalculavel {
        private boolean semVencimento;
        private double adicional;
        public RuralMais(boolean semVencimento, double adicional) {
            super();
            this.semVencimento = semVencimento;
            this.adicional = adicional;
        }
        public boolean isSemVencimento() {
            return semVencimento;
        }
        public double getAdicional() {
            return adicional;
        }
        public double calcularValorRetorno() {
            if (semVencimento) {
                return getValor();
            } else {
                return adicional + getValor();
            }
        }
    }
    public class CBonds extends DividaPublica {}
    public class BrazilianBonds extends DividaPublica implements ValorRetornoCalculavel {
        private double agioRetorno;
        protected double getAgioRetorno() {
            return agioRetorno;
        }
        protected void setAgioRetorno(double agioRetorno) {
            this.agioRetorno = agioRetorno;
        }
        public double calcularValorRetorno() {
            return (1 + agioRetorno/100) * getValor();
        }
    }
    public class CalculadoraJuros {
        private static final int PRAZO_LIMITE = 180;
        private static final double AGIO = 0.02;
        public double calcularJurosRetorno(ValorRetornoCalculavel titulo,
                                           int prazo, double taxa) {

            double valorRetorno = titulo.calcularValorRetorno();
            if (prazo < PRAZO_LIMITE) {
                return valorRetorno * (taxa/100) * prazo;
            } else {
                return valorRetorno * ((taxa + AGIO)/100) * prazo;
            }
        }
    }
}
