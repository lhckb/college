package br.com.cesarschool.poo.geral;

public class Conta {
    long numero;
    double saldo = 0;
    int status; // TODO tornar obrigatória ??

    final int ATIVA = 1;
    final int ENCERRADA = 2;
    final int BLOQUEADA = 3;

    final int SUCESSO = 1;
    final int FRACASSO = 0;

    public long getCodigo() {
        return numero;
    }
    public void setCodigo(long codigo) {
        this.numero = codigo;
    }

    int creditar(double valor) {
        if (this.status == ENCERRADA || valor < 0) { return FRACASSO; }
        else {
            this.saldo += valor;
            return SUCESSO;
        }
    }

    int debitar(double valor) {
        if (this.status == BLOQUEADA || valor < 0) { return FRACASSO; }
        else {
            this.saldo -= valor;
            return SUCESSO;
        }
    }


}
